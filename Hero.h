#ifndef TEXTGAME_HERO_H
#define TEXTGAME_HERO_H


#include "Living.h"

enum
{
  ikillu,
  wheremoney,
  dontstopme
};

class Hero : public Living // Класс игрока
{
public:
  Hero(int HP, int speed, int accuracy, int luck, int damage);
  Hero(int HP, int speed, int accuracy, int luck, int damage, int strenght);
  void speakHello(); // Приветствие
  friend std::ostream& operator<<(std::ostream& out, const Hero& hero);
};


#endif //TEXTGAME_HERO_H
