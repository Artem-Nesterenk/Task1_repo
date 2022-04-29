#include "reciever.h"
#include "msg_ctrl.h"
#include "vehicle.h"
#include <stdlib.h>
#include "defines.h"
#include <time.h>
#include <errno.h>

static uint8_t reciever_allowed_to_run = 0;

void set_reciever_allowence_ro_run(uint8_t allowence)
{
  reciever_allowed_to_run = allowence;
}

void reciever_thread(void)

{
  static const sleeptime reciever_sleeptime = {RECEIVER_DELAY_SEC, 0};
  int mqdt = open_mqueue(QUEUE_NAME);

  while(reciever_allowed_to_run == eThreadAllowedToRun)
  {
    packet_t* p_packet;
    p_packet = mqueue_recieve(mqdt);
    if (p_packet != NULL)
    {
        print_cargo(p_packet->p_message);
        free(p_packet->p_message);
        free(p_packet);
    }
    nanosleep(&reciever_sleeptime, NULL);
  }
}



