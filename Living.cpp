#include <cstdlib>
#include "Living.h"

Living::Living()
    : HP(10), speed(5), accuracy(5), luck(2), weapon(1)
{}

Living::Living(int HP, int speed, int accuracy, int luck, int damage)
    : HP(HP), speed(speed), accuracy(accuracy), luck(luck), weapon(damage)
{}

Living::Living(int HP, int speed, int accuracy, int luck, int damage, int strenght)
    : HP(HP), speed(speed), accuracy(accuracy), luck(luck), weapon(damage)
{}

int Living::hit(Living *target)
{
  int temp = miss;
  this->weapon.strenght -= 5;
  if ((1 + rand() % 10) <= this->accuracy)
  {
    target->HP -= this->weapon.damage;
    temp += hits;
  }
  if ((1 + rand() % 10) <= luck)
  {
    target->HP -= this->weapon.damage;
    temp += hits;
  }
  if (target->HP <= 0)
    return kill;
  return temp;
}
