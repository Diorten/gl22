//
// Created by najma on 27.04.2022.
//

#pragma once
#include "BoardSource.hpp"

class GameBoardTorus : public BoardSource
{
public:
    int height, width = 40;

    std::vector<std::vector<cell>> board;

    GameBoardTorus(int height, int width) : height(height), width(width), board(height, std::vector<cell>(width, cell{false, false})) {reviveRandomCellsAtBegining();};

    int countNeighbours(int row, int col) override;

    ~GameBoardTorus() {};
};