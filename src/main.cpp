#include <iostream>
#include "AlwaysNextTurn.hpp"
#include "GameBoardBasic.hpp"

int main()
{
    GameBoardBasic gbb{40, 40};
    AlwaysNextTurn alwaysNextTurn;

    gbb.play(alwaysNextTurn);
    return 0;
}