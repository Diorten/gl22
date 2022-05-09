//
// Created by robert on 09.05.2022.
//

#pragma once
#include <vector>
#include <string>
#include "CommandSource.hpp"
#include <iostream>

struct cell
{
    bool isAlive;
    bool shouldChange;
};

class BoardSource
{
public:
    int height = 40;
    int width = 40;

    std::vector<std::vector<cell>> board;

    void reviveRandomCellsAtBegining();

    void display() const;

    void reviveCellsByIndex();

    int getBoardWidth();
    int getBoardHeight();

    virtual int countNeighbours(int row, int col) = 0;

    void shouldChangeStatus(int row, int col);

    void changeStatus(int row, int col);

    char getSign(int row, int col) const;

    bool checkStatus(int row, int col) const;

    void changeCellStatus(int row, int col);

    void play(CommandSource& c_source);

    virtual ~BoardSource() { };
};