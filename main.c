#include <pthread.h>
#include <signal.h>
#include "defines.h"
#include "sender.h"
#include "reciever.h"

void reaper()
{
  printf("\nEXITING\n");
  delete_queue(QUEUE_NAME);
  exit(EXIT_SUCCESS);
}

int main()
{
  signal(SIGINT, reaper);

  pthread_t sender_pid;
  pthread_t reciever_pid;
  int res;

  res = pthread_create(&sender_pid, NULL, (void*)sender_thread, NULL);
  ERROR_CHECK(res, 0, "sender_thread_create");

  res = pthread_create(&reciever_pid, NULL, (void*)reciever_thread, NULL);
  ERROR_CHECK(res, 0, "reciever_thread_create");

  res = pthread_join(sender_pid, NULL);
  ERROR_CHECK(res, 0, "sender_thread_join");

  res = pthread_join(reciever_pid, NULL);
  ERROR_CHECK(res, 0, "reciever_thread_join");
}
