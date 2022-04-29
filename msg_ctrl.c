#include "msg_ctrl.h"
#include <stdio.h>
#include "string.h"
#include "defines.h"
#include <errno.h>
int open_mqueue(const char* key_path)
{
  static struct mq_attr attr;
  memset(&attr, 0, sizeof(struct mq_attr));
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = QUEUE_MSGSIZE;
  attr.mq_flags = 0;
  attr.mq_curmsgs = 0;

   mqd_t mqdt;
   int open_attempts = 0;
   do
   {
     mqdt = mq_open(key_path, O_RDWR | O_CREAT | O_NONBLOCK, 0666, &attr);
     if (mqdt == -1)
     {
       perror("mq_open");
       if (open_attempts++ >= 5)
       {
         exit(EXIT_FAILURE);
       }
     }
   } while (mqdt == -1);

return mqdt;
}

int delete_mqueue(const char* key_path)
{
  int res;
  res = mq_unlink(key_path);
  ERROR_CHECK(res, 0, "mq_unlink");
  return 0;
}

void mqueue_send(mqd_t mqdt, packet_t* p_packet)
{
  int res;
  res = mq_send(mqdt, (const char*)&p_packet, sizeof(p_packet), 0);
  ERROR_CHECK(res, 0, "mq_send");
}

packet_t* mqueue_recieve(mqd_t mqdt)
{
  int u_errno = 0;
  ssize_t bytes_read;
  packet_t* p_packet;
  bytes_read = mq_receive(mqdt, (char*)&p_packet,(size_t)QUEUE_MSGSIZE, 0);
  u_errno = errno;
  if (bytes_read > 0)
  {
      return p_packet;
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
  return NULL;
}
