#include <stdio.h>
#include "car.h"

#define amount_of_cars 6

struct CarImplementation{
  Type type;
  Color color;
  double fill_level;
  double acceleration_rate;
  int speed;
  bool is_rent;
};

static struct CarImplementation car1 = {AIXAM, RED, 16.0, 0.0,0,false};
static struct CarImplementation car2 = {FIAT_MULTIPLA, GREEN, 65.0, 0.0,0,false};
static struct CarImplementation car3 = {FIAT_MULTIPLA, BLUE, 65.0,0.0,0,false};
static struct CarImplementation car4 = {FIAT_MULTIPLA, ORANGE, 65.0,0.0,0,false};
static struct CarImplementation car5 = {JEEP, SILVER, 80.0,0.0,0,false};
static struct CarImplementation car6 = {JEEP, BLACK, 80.0,0.0,0,false};
static struct CarImplementation car_park[amount_of_cars] = {car1, car2, car3, car4, car5, car6};

Car get_car(Type type)
{

    for (int i = 0; i < amount_of_cars; i++) {
        if(car_park[i].type == type && car_park[i].is_rent == false)
        {
          car_park[i].is_rent = true;
          return &car_park[i];
        }
    }
    return 0;
}
Type get_type(Car car1)
{
  return car1->type;
}
Color get_color(Car car1)
{
  return car1->color;
}
double get_fill_level(Car car1)
{
  return car1->fill_level;
}
double get_acceleration_rate(Car car1)
{
  return car1->acceleration_rate;
}
int get_speed(Car car1)
{
  return round(car1->speed);
}
void set_acceleration_rate(Car car1, double acceleration_rate)
{
  car1->acceleration_rate = acceleration_rate;
  if(car1->acceleration_rate > 1 && car1->type == AIXAM)
  {
    car1->acceleration_rate = 1;
  }
  if(car1->acceleration_rate > 3.14 && car1->type == JEEP)
  {
    car1->acceleration_rate = 3.14;
  }
  if(car1->acceleration_rate > 2.26 && car1->type == FIAT_MULTIPLA)
  {
    car1->acceleration_rate = 2.26;
  }
  if(car1->acceleration_rate < -8)
  {
    car1->acceleration_rate = -8;
  }
}
void accelerate(Car car1)
{
  car1->speed= (car1->acceleration_rate*3.6 + round(car1->speed));
  if(car1->type == AIXAM && car1->speed > 45)car1->speed = 45;
  if(car1->type == JEEP && car1->speed > 196)car1->speed = 196;
  if(car1->type == FIAT_MULTIPLA && car1->speed > 170) car1->speed = 170;
}
void init()
{
  for (int i = 0; i < amount_of_cars; i++) {
      car_park[i].is_rent = false;
      car_park[i].speed = 0;
      car_park[i].acceleration_rate = 0;
  }
}
double round(double speed)
{
  return (speed + 0.5);
}
