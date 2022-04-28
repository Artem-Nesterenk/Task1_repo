#include <stdio.h>
#include "sender.h"
#include "msg_ctrl.h"
#include "vehicle.h"
#include <stdlib.h>
#include "defines.h"
#include <time.h>
#include <errno.h>
#include<string.h>

// predefined list of cargo
static cargo_creator_t cargo_list[10] =
{
  {eCar, "car_1\0", NULL}, {eTruck, "truck_1\0", "cargo_truck_1\0"},
  {eCar, "car_2\0", NULL}, {eCar, "car_3\0", NULL},
  {eTruck, "truck_2\0", "cargo_truck_2\0"}, {eTruck, "truck_3\0", "cargo_truck_3\0"},
  {eTruck, "truck_4\0", "cargo_truck_1\0"}, {eCar, "car_4\0", NULL},
  {eCar, "car_5\0", NULL}, {eTruck, "truck_5\0", "cargo_truck_5\0"}
};

void sender_thread(void)
{
  sleeptime sender_sleeptime = {SENDER_DELAY_SEC, 0};
  int cargo_num;
  int mqdt = open_mqueue(QUEUE_NAME);
  int res;

  while(1)
  {
    cargo_num = rand() % 10;
    veh_message_t* cargo = create_cargo(cargo_list[cargo_num]);
    res = mq_send(mqdt, (const char*)&cargo, sizeof(cargo), 0);
    ERROR_CHECK(res, 0, "mq_send");
    nanosleep(&sender_sleeptime,NULL);
  }
}
