//
// Created by najma on 27.04.2022.
//
#include "GameBoardCylinder.hpp"

int GameBoardCylinder::countNeighbours(int row, int col)
{
    int cells = 0;

    if (row > 0 && row < height - 1 && col > 0 && col < width - 1)
    {
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
    }
// left arm


    if (row > 0 && row < height - 1 && col == 0)
    {
        if (board[row - 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][width - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row][width - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][width - 1].isAlive == true)
        {
            cells++;
        }
    }

//right arm

    if (row > 0 && row < height - 1 && col == width - 1)
    {
        if (board[row - 1][col - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][0].isAlive == true)
        {
            cells++;
        }
        if (board[row][0].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][0].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row][col - 1].isAlive == true)
        {
            cells++;
        }
    }

//left upper corner

    if (row == 0 && col == 0)
    {
        if (board[row][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][width - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row][width - 1].isAlive == true)
        {
            cells++;
        }
    }

//left down corner

    if (row == height - 1 && col == 0)
    {
        if (board[row][width - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][width - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row - 1][col + 1].isAlive == true)
        {
            cells++;
        }
        if (board[row][col + 1].isAlive == true)
        {
            cells++;
        }
    }

//right upper corner

    if (row == 0 && col == width - 1)
    {
        if (board[row][col - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col - 1].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][col].isAlive == true)
        {
            cells++;
        }
        if (board[row + 1][0].isAlive == true)
        {
            cells++;
        }
        if (board[row][0].isAlive == true)
        {
            cells++;
        }
    }

//right down corner

    if (row = height - 1 && col == width - 1) {
        if (board[row][col - 1].isAlive == true) {
            cells++;
        }
        if (board[row - 1][col - 1].isAlive == true) {
            cells++;
        }
        if (board[row - 1][col].isAlive == true) {
            cells++;
        }
        if (board[row - 1][width - 1].isAlive == true) {
            cells++;
        }
        if (board[row][width - 1].isAlive == true) {
            cells++;
        }
    }

    if ((row == 0 && (col == 0 || col == width - 1)) || (row == height - 1 && (col == 0 || col == width - 1)))
    {
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
    }

    return cells;
}
