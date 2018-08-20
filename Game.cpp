#include <fstream>
#include <iostream>
#include "Game.h"
#include "GreatRobber.h"

Game::Game()
    : player(50, 5, 5, 5, 4)
{}

Game::Game(int HP, int speed, int accuracy, int luck, int damage)
    : player(HP, speed, accuracy, luck, damage)
{}

void Game::save(const char *fileName)
{
  std::fstream file(fileName, std::ios::out);
  auto rob  = dynamic_cast<GreatRobber*>(enemy);
  if (rob == nullptr)
  {
    auto robG  = dynamic_cast<Robber*>(enemy);
    file << player << *robG;
  }
  else
    file << player << *rob;
}

void Game::load(const char *fileName)
{
  std::fstream file(fileName, std::ios::in);
  std::string buffer;
  getline(file,buffer);
  int sv[6];
  for (int i = 0; i < 6; ++i)
  {
    getline(file,buffer);
    size_t space = buffer.find(' ')+1;
    sv[i] = std::stoi(buffer.substr(space));
  }
  this->player = Hero(sv[0],sv[1],sv[2],sv[3],sv[4],sv[5]);
  getline(file,buffer);
  std::string classRob = buffer;
  for (int i = 0; i < 6; ++i)
  {
    getline(file,buffer);
    size_t space = buffer.find(' ')+1;
    sv[i] = std::stoi(buffer.substr(space));
  }
  if (classRob.c_str() == "ROBBER")
    this->enemy = new Robber(sv[0],sv[1],sv[2],sv[3],sv[4],sv[5]);
  this->enemy = new GreatRobber(sv[0],sv[1],sv[2],sv[3],sv[4],sv[5]);
}

int Game::battle(bool type)
{
  if (type)
    enemy = new GreatRobber(30, 7, 7, 7, 10);
  else
    enemy = new Robber();
  enemy->speakHello();
  player.speakHello();
  short temp = 0;
  for (;;)
  {
    std::cout << "0 - сдаться\n"
              << "1 - ударить\n"
              << "2 - починить оружие\n"
              << "3 - попытаться сбежать\n"
              << "4 - сохранить игру и выйти\n";
    std::cin >> temp;
    switch (temp)
    {
      case 0:
        return -2;
      case 1:
        switch (player.hit(enemy))
        {
          case 0:
            std::cout << "Вы промазали!\n";
            break;
          case 1:
            std::cout << "Вы попали!\n";
            break;
          case 2:
            std::cout << "Вы нанесли критический урон!\n";
            break;
          case 3:
            std::cout << "Вы убили противника!\n";
            delete enemy;
            return 0;
        }
      case 2:
        repairWeapon(player.weapon);
        break;
      case 3:
        if ((1 + rand() % 10) <= player.speed)
        return -1;
      case 4:
        return 4;
      default:
        std::cout << "ERROR\n";
    }
    switch (enemy->hit(&player))
    {
      case 0:
        std::cout << "Противник промазал!\n";
        break;
      case 1:
        std::cout << "Противник попал!\n";
        break;
      case 2:
        std::cout << "Противник нанес критический урон!\n";
        break;
      case 3:
        std::cout << "Вы мертвы!\n";
        return -2;
    }
  }
}

Game::~Game()
{
  if (enemy != nullptr)
    delete enemy;
}
