#include "Weapon.h"

Weapon::Weapon(int damage)
    : damage(damage), strenght(100)
{}

Weapon::Weapon(int damage, int strenght)
    : damage(damage), strenght(strenght)
{}

void repairWeapon(Weapon &weapon)
{
  weapon.strenght = 100;
}