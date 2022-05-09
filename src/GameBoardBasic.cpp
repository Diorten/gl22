//
// Created by najma on 26.04.2022.
//
#include "GameBoardBasic.hpp"


int GameBoardBasic::countNeighbours(int row, int col)
{
    if (row < 0 || row > height - 1 || col < 0 || col > width - 1)
    {
        return -1;
    }
    else
    {
        int cells = 0;

        for (int y = row - 1; y <= row + 1; y++)
        {
            for (int x = col - 1; x <= col + 1; x++)
            {
                {
                    if ((y != row || x != col) && ((y >= 0 && y <= height - 1) && (x >= 0 && x <= width - 1)))
                    {
                        if (board[y][x].isAlive == true)
                        {
                            cells++;
                        }
                    }
                }
            }
        }
        return cells;
    }
}