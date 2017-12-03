#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "car.h"

typedef struct CarImplementation* Car;

#define clear() printf("\033[H\033[J")
struct CarImplementation{
  Type type;
  Color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool is_rent;
  int position;
  bool won;
};

static struct CarImplementation C1 = {AIXAM, RED, 16.0, 0.0,0,false,0,false};
static struct CarImplementation C2 = {FIAT_MULTIPLA, GREEN, 65.0, 0.0,0,false,0,false};
static struct CarImplementation C3 = {FIAT_MULTIPLA, BLUE, 65.0,0.0,0,false,0,false};
static struct CarImplementation C4 = {FIAT_MULTIPLA, ORANGE, 65.0,0.0,0,false,0,false};
static struct CarImplementation C5 = {JEEP, SILVER, 80.0,0.0,0,false,0,false};
static struct CarImplementation C6 = {JEEP, BLACK, 80.0,0.0,0,false,0,false};
static struct CarImplementation car_park[] = {C1,C2,C3,C4,C5,C6};

bool is_finished = false;
void print_field();
void race();
void set_rate(Car car);
void end();

int main(int argc, char const *argv[]) {

  while(!is_finished)
  {
    clear();
    print_field();
    race();
    usleep(5000);
  }
  printf("\n");

  return 0;
}
void print_field()
{
  int position1 = C1.position;
  int position2 = C2.position;
  int position3 = C3.position;
  int position4 = C4.position;
  int position5 = C5.position;
  int position6 = C6.position;
  for (int i = 0; i < 7; i++) {

    if(i < 6){printf("|");}
      for (int a = 0; a < 80; a++) {

          switch(i)
          {
            case 0:
              if(a == position1){printf("C1");}
              else{printf("*");}break;
            case 1:
              if(a == position2){printf("C2");}
              else{printf("*");}break;
            case 2:
              if(a == position3){printf("C3");}/* expression */
              else{printf("*");}break;
            case 3:
              if(a == position4){printf("C4");}
              else{printf("*");}break;
            case 4:
              if(a == position5){printf("C5");}
              else{printf("*");}break;
            case 5:
              if(a == position6){printf("C6");}
              else{printf("*");}break;
            case 6:printf("=");break;
          }
      }
      if(i < 6){printf("|\n");}
  }
}
void race()
{
  set_rate(&C1);
  accelerate(&C1);
  C1.position += C1.acceleration_rate;
  if(C1.position >= 79)
  {
    C1.won = true;
    is_finished = true;
    clear();
    printf("Winner: C1");
  }
  set_rate(&C2);
  accelerate(&C2);
  C2.position += C2.acceleration_rate;
  if(C2.position >= 79)
  {
    C2.won = true;
    is_finished = true;
    clear();
    printf("Winner: C2");
  }
  set_rate(&C3);
  accelerate(&C3);
  C3.position += C3.acceleration_rate;
  if(C3.position >= 79)
  {
    C3.won = true;
    is_finished = true;
    clear();
    printf("Winner: C3");
  }
  set_rate(&C4);
  accelerate(&C4);
  C4.position += C4.acceleration_rate;
  if(C4.position >= 79)
  {
    C4.won = true;
    is_finished = true;
    clear();
    printf("Winner: C4");
  }
  set_rate(&C5);
  accelerate(&C5);
  C5.position += C5.acceleration_rate;
  if(C5.position >= 79)
  {
    C5.won = true;
    is_finished = true;
    clear();
    printf("Winner: C5");
  }
  set_rate(&C6);
  accelerate(&C6);
  C6.position += C6.acceleration_rate;
  if(C6.position >= 79)
  {
    C6.won = true;
    is_finished = true;
    clear();
    printf("Winner: C6");
  }

}
void set_rate(Car car){
  for (int i = 0; i < 6; i++) {
      double r = rand()%5;
      set_acceleration_rate(car, r);
}
}
