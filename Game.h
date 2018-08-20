#ifndef TEXTGAME_GAME_H
#define TEXTGAME_GAME_H

#include "Hero.h"

class Game // Класс игры
{
private:
  Hero player; // Игрок
  Living* enemy; // Текущий враг
public:
  Game();
  Game(int HP, int speed, int accuracy, int luck, int damage);
  void save(const char *fileName); // Сохранить игру в файл
  void load(const char *fileName); // Загрузить игру из файла
  int battle(bool type); // Битва игрока и врага
  ~Game();
};


#endif //TEXTGAME_GAME_H
