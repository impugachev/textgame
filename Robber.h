#ifndef TEXTGAME_ROBBER_H
#define TEXTGAME_ROBBER_H

#include "Living.h"
#include <string>

enum
{
  killme,
  money,
  greatrobber
};

class Robber : public Living // Класс разбойника
{
public:
  Robber();
  Robber(int HP, int speed, int accuracy, int luck, int damage);
  Robber(int HP, int speed, int accuracy, int luck, int damage, int strenght);
  virtual void speakHello(); // Приветствие
  friend std::ostream& operator<<(std::ostream& out, const Robber& robber);
};


#endif //TEXTGAME_ROBBER_H
