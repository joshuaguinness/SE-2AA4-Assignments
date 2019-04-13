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
    this->N = n;
}