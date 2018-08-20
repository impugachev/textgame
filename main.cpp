#include <iostream>
#include "Game.h"

int main()
{
  srand(time(0));
  int temp = 0;
  Game game;
  std::cout << "Загрузить игру или начать новую? (0 - новая игра, 1 - загрузка)\n";
  std::cin >> temp;
  if (temp == 1)
  {
    game.load("savegame");
  }
  std::cout << "Банда головорезов терроризирует мирный город.\n"
            << "Вам предстоит убить несколько разбойников и разделаться с их главарем.\n";
  for (int i = 0; i != 3; ++i)
    switch (game.battle(false))
    {
      case -2:
        std::cout << "Вас убили! Игра окончена!\n";
        return 0;
      case -1:
        std::cout << "Вы успешно убежали!\n";
        break;
      case 0:
        std::cout << "Противник убит!\n";
        break;
      case 4:
        sl = &Game::save;
        game.save("savegame");
        return 0;
    }
  switch (game.battle(true))
  {
    case -2:
      std::cout << "Вас убили! Игра окончена!\n";
      return 0;
    case -1:
      std::cout << "Вы успешно убежали!\n";
      break;
    case 0:
      std::cout << "Противник убит!\n";
      break;
  }
}