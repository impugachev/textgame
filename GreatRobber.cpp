#include <iostream>
#include "GreatRobber.h"

GreatRobber::GreatRobber(int HP, int speed, int accuracy, int luck, int damage)
    : Robber(HP, speed, accuracy, luck, damage)
{}

GreatRobber::GreatRobber(int HP, int speed, int accuracy, int luck, int damage, int strenght)
    : Robber(HP, speed, accuracy, luck, damage, strenght)
{}

void GreatRobber::speakHello()
{
  std::cout << "Главарь разбойников: ";
  std::cout << "Ну давай, Герой! Тебе никогда не справиться со мной!\n";
}

std::ostream &operator<<(std::ostream &out, const GreatRobber &robber)
{
  out << "GREAT\n"
      << "HP " << robber.HP << "\n"
      << "speed " << robber.speed << "\n"
      << "accuracy " << robber.accuracy << "\n"
      << "luck " << robber.luck << "\n"
      << "damage " << robber.weapon.damage << "\n"
      << "weapon " << robber.weapon.strenght << "\n";
  return out;
}