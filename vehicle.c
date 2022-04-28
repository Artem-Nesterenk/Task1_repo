#include "vehicle.h"
#include <stdio.h>
#include <string.h>

static void print_car(veh_message_t* p_message);
static void print_truck(veh_message_t* p_message);

void print_cargo(veh_message_t* p_message)
{
  switch(p_message->type)
  {
    case eCar:
      print_car(p_message);
    break;

    case eTruck:
      print_truck(p_message);
    break;

    default:
      printf("CARGO PRINTER -> Ooops, something went wrong!");
      exit(EXIT_FAILURE);
    break;
  }
}

veh_message_t* create_cargo(cargo_creator_t cargo_object)
{
  veh_message_t* p_message = NULL;
  // countng how much memory we need for names
  size_t name_size = 0;
  size_t cargo_size = 0;
  name_size = strlen(cargo_object.name_ptr);

  if (cargo_object.type == eTruck)
  {
    cargo_size = strlen(cargo_object.cP_cargo);
  }

  // allocating memory for the message
  int total_size = (sizeof(veh_message_t)) + (sizeof(char) * (name_size + cargo_size));
  p_message = malloc(total_size);

  // initing fields
  p_message->name_len = name_size;
  p_message->name_ptr = cargo_object.name_ptr;
  p_message->wheels = rand() % 5;
  p_message->color = rand() % 20;
  p_message->type = cargo_object.type;

  switch(cargo_object.type)
  {
    case eCar:
      p_message->vP_vechical.car.u8_passangers = rand() % 100;
    break;

    case eTruck:
      p_message->vP_vechical.track.u8_cargo_len = cargo_size;
      p_message->vP_vechical.track.cP_cargo = cargo_object.cP_cargo;
    break;

    default:
      printf("CARGO CREATOR -> Ooops, something went wrong!");
      exit(EXIT_FAILURE);
    break;
  }

  return p_message;
}

static void print_car(veh_message_t* p_message)
{

  printf("Car :\n"
         "\t name -> %s\n"
         "\t color -> %d\n"
         "\t wheels -> %d\n"
         "\t passangers -> %d\n",
         p_message->name_ptr, p_message->color, p_message->wheels, p_message->vP_vechical.car.u8_passangers);

}

static void print_truck(veh_message_t* p_message)
{
  printf("TRUCK:\n"
         "\t color -> %d\n"
         "\t name -> %s\n"
         "\t wheels -> %d\n"
         "\t cargo name -> %s\n",
         p_message->color, p_message->name_ptr, p_message->wheels, p_message->vP_vechical.track.cP_cargo);

}
