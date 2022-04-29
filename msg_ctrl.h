#ifndef MSG_CTRL_H
#define MSG_CTRL_H
#include "vehicle.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

typedef enum PackageType
{
  eCargo = 1,
} ePackadge_t;

typedef struct Packadge
{
  uint32_t msg_type;
  void* p_message;
} packet_t;

int open_mqueue(const char* key);

int delete_mqueue(const char* key_path);

void mqueue_send(mqd_t mqdt, packet_t* p_packet);

packet_t* mqueue_recieve(mqd_t mqdt);
#endif // MSG_CTRL_H
