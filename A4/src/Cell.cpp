#include "../include/Cell.h"
#include <exception>
#include <stdexcept>
#include <iostream>

Cell::Cell()
{
    this->S = false;
    this->N = 0;
}

Cell::Cell(bool s)
{
    this->S = s;
    this->N = 0;
}

bool Cell::get_life()
{
    return this->S;
}

int Cell::get_neighbours()
{
    return this->N;
}

void Cell::set_life(bool s)
{
    this->S = s;
}

void Cell::set_neighbours(int n)
{
    if (n > 8)
    {
        throw std::out_of_range("Our of Range. Can't have more than 8 neighbours!");
    }
    else
    {
        this->N = n;
    }
}