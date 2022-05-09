//
// Created by robert on 09.05.22.
//
#include "BoardSource.hpp"
#include <random>
#include <iostream>
#include <unistd.h>

void BoardSource::reviveRandomCellsAtBegining()
{
    int v1;
    int v;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib_row(0, height-1);
    std::uniform_int_distribution<> distrib_column(0,width-1);
    int i=0;
    while(i<400)
    {
        v1=distrib_row(gen);
        v=distrib_column(gen);
        if (board[v1][v].isAlive == false)
        {
            board[v1][v].isAlive = true;
            i++;
        }
    }
}

/*BoardSource
 *Board::BoardSource
 *Board(int width, int height): width(width), height(height), board(width * height, cell{false,false})
{
    reviveRandomCellsAtBegining();
    std::cout << "Plansza zwykła";
}*/

void BoardSource::display() const
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            std::cout << getSign(row,col);
        }
        std::cout << std::endl;
    }
}


char BoardSource::getSign(int row, int col) const
{
    if(board[row][col].isAlive)
    {
        return '*';
    }
    else
    {
        return ' ';
    }
}

bool BoardSource::checkStatus(int row, int col) const
{
    if(row < 0 || row > height - 1 || col < 0 || col > width - 1)
    {
        return false;
    }
    else if(board[row][col].isAlive == true)
    {return true;}
    return false;
}

void BoardSource::shouldChangeStatus(int row, int col)
{
    if (board[row][col].isAlive == true)
    {
        if (countNeighbours(row, col) == 2 || countNeighbours(row, col) == 3 )
        {
            board[row][col].shouldChange = false;
        }
        else
        {
            board[row][col].shouldChange = true;
        }
    }
    else
    {
        if (countNeighbours(row,col)==3)
        {
            board[row][col].shouldChange = true;
        }
        else
        {
            board[row][col].shouldChange = false;
        }
    }
}

int BoardSource::getBoardHeight()
{
    return height;
}

int BoardSource::getBoardWidth()
{
    return width;
}

void BoardSource::changeStatus(int row, int col)
{
    if (board[row][col].shouldChange == true)
    {
        if (board[row][col].isAlive == true)
        {board[row][col].isAlive = false;}
        else
        {board[row][col].isAlive = true;}
    }
    else
    {
        return;
    }
}

void BoardSource::changeCellStatus(int row, int col) {
    if (board[row][col].isAlive == true)
    {
        board[row][col].isAlive = false;
    }
    board[row][col].isAlive = true;
}


void BoardSource::play(CommandSource &c_source) {
    while (true) {
        std::string command = c_source.next_command();

        if (command == "quit") {
            return;
        }
        else if (command == "next")
        {
            system("clear");
            display();
            for (int row = 0; row < getBoardHeight(); row++)
            {
                for (int col = 0; col < getBoardWidth(); col++)
                {
                    shouldChangeStatus(row,col);
                }
            }
            for (int row = 0; row < getBoardHeight(); row++)
            {
                for (int col = 0; col < getBoardWidth(); col++)
                {
                    changeStatus(row,col);
                }
            }

            sleep(0.5);
        }
        else if (command == "change")
        {
            std::cout << "Podaj wiersz zmiany:\n";
            int row, col;
            std::cin >> row;
            std::cout << "Podaj kolumne zmiany:\n";
            std::cin >> col;
            changeCellStatus(row, col);
        }
    }
}