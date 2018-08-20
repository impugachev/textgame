#include <cstdlib>
#include <iostream>
#include "Hero.h"

Hero::Hero(int HP, int speed, int accuracy, int luck, int damage)
    : Living(HP, speed, accuracy, luck, damage)
{}

Hero::Hero(int HP, int speed, int accuracy, int luck, int damage, int strenght)
    : Living(HP, speed, accuracy, luck, damage, strenght)
{}

void Hero::speakHello()
{
  std::cout << "Герой: ";
  switch (rand() % 3)
  {
    case ikillu:
      std::cout << "Жалкий разбойник! Я убью тебя!\n";
      break;
    case wheremoney:
      std::cout << "Где деньги, которые ты украл?!\n";
      break;
    case dontstopme:
      std::cout << "Ты меня не остановишь! Я все равно доберусь до вашего главаря!\n";
  }
}

std::ostream &operator<<(std::ostream &out, const Hero &hero)
{
  out << "HERO\n"
      << "HP " << hero.HP << "\n"
      << "speed " << hero.speed << "\n"
      << "accuracy " << hero.accuracy << "\n"
      << "luck " << hero.luck << "\n"
      << "damage " << hero.weapon.damage << "\n"
      << "weapon " << hero.weapon.strenght << "\n";
  return out;
}
