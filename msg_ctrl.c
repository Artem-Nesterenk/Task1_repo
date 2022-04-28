#include "msg_ctrl.h"
#include <stdio.h>
#include "string.h"
#include "defines.h"

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

int delete_queue(const char* key_path)
{
  int res;
  res = mq_unlink(key_path);
  ERROR_CHECK(res, 0, "mq_unlink");
  return 0;
}
