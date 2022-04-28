#ifndef MSG_CTRL_H
#define MSG_CTRL_H
#include "vehicle.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
typedef struct Packadge
{
  enum eVehicleType packet_type;
  veh_message_t* p_message;
} packet_t;

int open_mqueue(const char* key);

int delete_queue(const char* key_path);
#endif // MSG_CTRL_H
