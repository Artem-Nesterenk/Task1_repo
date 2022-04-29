#include <pthread.h>
#include <signal.h>
#include "defines.h"
#include "sender.h"
#include "reciever.h"
#include "msg_ctrl.h"

void reaper()
{
  set_sender_allowence_ro_run(eThreadDisallowedToRun);
  set_reciever_allowence_ro_run(eThreadDisallowedToRun);
}

int main()
{
  int res;

  pthread_t sender_pid;
  pthread_t reciever_pid;

  signal(SIGINT, reaper);

  set_sender_allowence_ro_run(eThreadAllowedToRun);
  set_reciever_allowence_ro_run(eThreadAllowedToRun);

  res = pthread_create(&sender_pid, NULL, (void*)sender_thread, NULL);
  ERROR_CHECK(res, 0, "sender_thread_create");

  res = pthread_create(&reciever_pid, NULL, (void*)reciever_thread, NULL);
  ERROR_CHECK(res, 0, "reciever_thread_create");

  res = pthread_join(sender_pid, NULL);
  ERROR_CHECK(res, 0, "sender_thread_join");

  res = pthread_join(reciever_pid, NULL);
  ERROR_CHECK(res, 0, "reciever_thread_join");

  delete_mqueue(QUEUE_NAME);
  return (EXIT_SUCCESS);
}
