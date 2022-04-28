#include "reciever.h"
#include "msg_ctrl.h"
#include "vehicle.h"
#include <stdlib.h>
#include "defines.h"
#include <time.h>
#include <errno.h>

void reciever_thread(void)

{
  int u_errno = 0;
  sleeptime reciever_sleeptime = {RECEIVER_DELAY_SEC, 0};

  int mqdt = open_mqueue(QUEUE_NAME);
  ssize_t bytes_read;
  while(1)
  {
    veh_message_t* cargo;
    u_errno = 0;
    bytes_read = mq_receive(mqdt, (char*)&cargo,(size_t)QUEUE_MSGSIZE, 0);
    u_errno = errno;
    if (bytes_read > 0)
    {
      print_cargo(cargo);
      free(cargo);
    }
    else
    {
      if (u_errno == EAGAIN)
      {
        printf("RECIEVER -> empty queue\n");
      }
      else
      {
        perror("mq_recieve");
        printf("RECIEVER -> ERRNO = %d\n", u_errno);
      }
    }
    nanosleep(&reciever_sleeptime, NULL);
  }

}



