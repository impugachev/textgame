#ifndef TEXTGAME_GREATROBBER_H
#define TEXTGAME_GREATROBBER_H

#include "Robber.h"

class GreatRobber : public Robber // Класс главаря разбойников
{
public:
  GreatRobber(int HP, int speed, int accuracy, int luck, int damage);
  GreatRobber(int HP, int speed, int accuracy, int luck, int damage, int strenght);
  void speakHello(); // Приветствие
  friend std::ostream& operator<<(std::ostream& out, const GreatRobber& greatRobber);
};

#endif //TEXTGAME_GREATROBBER_H
