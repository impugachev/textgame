#ifndef TEXTGAME_LIVING_H
#define TEXTGAME_LIVING_H

#include "Weapon.h"

enum battle
{
  miss,
  hits,
  crit,
  kill
};

class Living // Общий класс для живых объектов
{
  friend class Game;
protected:
  int HP, accuracy, luck, speed; // Количество очков жизни, точность, удача, скорость
  Weapon weapon; // Оружие
public:
  Living();
  Living(int HP, int speed, int accuracy, int luck, int damage);
  Living(int HP, int speed, int accuracy, int luck, int damage, int strenght);
  virtual void speakHello() = 0; // Приветствие
  int hit(Living *target); // Ударить
};


#endif //TEXTGAME_LIVING_H
