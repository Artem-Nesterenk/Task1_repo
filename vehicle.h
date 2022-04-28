#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdlib.h>
#include <stdint.h>

typedef enum eVehicleType
{
  eCar = 0,
  eTruck = 1,
} eVehicleType;

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
} vehicle_t;

typedef struct SentenceStruct
{
  char* name_ptr; // vech name
  uint8_t name_len;
  uint8_t wheels;
  uint8_t color;
  eVehicleType type;
  vehicle_t vP_vechical;
} veh_message_t;

typedef struct CargoCreator
{
  eVehicleType type;
  char* name_ptr;
  char* cP_cargo;
} cargo_creator_t;


veh_message_t* create_cargo(cargo_creator_t cargo_object);
void print_cargo(veh_message_t* p_message);
veh_message_t* create_car(void);
void create_truck(void);
#endif // VEHICLE_H
