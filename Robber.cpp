#include <iostream>
#include "Robber.h"

Robber::Robber() : Living()
{}

Robber::Robber(int HP, int speed, int accuracy, int luck, int damage)
    : Living(HP, speed, accuracy, luck, damage)
{}

Robber::Robber(int HP, int speed, int accuracy, int luck, int damage, int strenght)
    : Living(HP, speed, accuracy, luck, damage, strenght)
{}

void Robber::speakHello()
{
  std::cout << "Разбойник: ";
  switch (rand() % 3)
  {
    case killme:
      std::cout << "Ну давай, Герой! Ударь меня!\n";
      break;
    case money:
      std::cout << "Ты никогда не получишь МОИХ денег!\n";
      break;
    case greatrobber:
      std::cout << "Даже если ты убьешь меня, то наш главарь расправится с тобой!\n";
  }
}

std::ostream &operator<<(std::ostream &out, const Robber &robber)
{
  out << "ROBBER\n"
      << "HP " << robber.HP << "\n"
      << "speed " << robber.speed << "\n"
      << "accuracy " << robber.accuracy << "\n"
      << "luck " << robber.luck << "\n"
      << "damage " << robber.weapon.damage << "\n"
      << "weapon " << robber.weapon.strenght << "\n";
  return out;
}