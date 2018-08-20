#ifndef TEXTGAME_WEAPON_H
#define TEXTGAME_WEAPON_H

class Weapon // Класс оружия
{
public:
  int damage; // Урон оружия
  int strenght; // Прочность оружия
  Weapon(int damage);
  Weapon(int damage, int strenght);
  friend void repairWeapon(Weapon &weapon); // Отремонтировать оружие
};


#endif //TEXTGAME_WEAPON_H
