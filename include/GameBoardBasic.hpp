//
// Created by najma on 26.04.2022.
//
#pragma once
#include "BoardSource.hpp"

class GameBoardBasic : public BoardSource
{
public:
    int height, width = 40;

    std::vector<std::vector<cell>> board;

    GameBoardBasic(int height, int width) : height(height), width(width), board(height, std::vector<cell>(width, cell{false, false})) {std::cout << "Tutaj"; reviveRandomCellsAtBegining();};

    int countNeighbours(int row, int col) override;

    ~GameBoardBasic() { };
};