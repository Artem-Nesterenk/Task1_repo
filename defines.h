#ifndef DEFINES_H
#define DEFINES_H
#include <stdio.h>

#define ERROR_CHECK(res, positive_val, msg) \
  if(res != positive_val) \
  { ERROR(msg, res) }

#define ERROR(msg, err_num) \
  perror(msg);\
  printf("Err_num -> %d", err_num);

#define QUEUE_NAME "/cargo_queue"

#define QUEUE_MSGSIZE (256)

#define SENDER_DELAY_SEC 2

#define RECEIVER_DELAY_SEC 1

typedef struct timespec sleeptime;

enum eThreadAllowence
{
  eThreadDisallowedToRun = 0,
  eThreadAllowedToRun = 1,
};

#endif // DEFINES_H
