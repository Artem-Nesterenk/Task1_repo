#include <stdlib.h>
typedef struct CarStructDetails
{
  uint8_t u8_passangers;
} car_t;
typedef struct TrackStructDetails
{
  char* cP_cargo; // truck cargo naming;
  uint8_t u8_cargo_len;
} track_t;
typedef union VechicleUnionType
{
  track_t track;
  car_t car;
} vechical_t;
typedef struct SentenceStruct
{
  char* name_ptr; // vech name 
  uint8_t name_len;
  uint8_t wheels;
  uint8_t color;
  vechical_t vP_vechical;
//  ...
} vech_message_t;
// funcs
queue_send(vech_message_t* objL_vech);
queue_receive(vech_message_t* objL_vech);
queue_init();
queue_deinit();
void main(void)
{
  // usage example, can be in one thread
  // create thread 1
  // create thread 2
}
void tread_1_processor ()
{
  // 1. allocate memory and send message message
  // 2. allocate memory and send message message
}
void tread_2_processor ()
{
  // 1. receive message and and free memory
  // 2. receive message and and free memory
}
