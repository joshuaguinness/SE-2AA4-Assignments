// May need an initializer list

#include "../include/GameBoard.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

// Public Methods

BoardT::BoardT(std::vector<CardT> s)
{
    std::vector<CardT> front_of_deck(s.begin(), s.begin() + 40);
    std::vector<CardT> end_of_deck(s.begin()+41, s.end());

    CardStackT initial_deck = CardStackT(end_of_deck);
    CardStackT initial_waste = CardStackT();

    this->t = tab_deck(front_of_deck);
    this->f = init_seq(8);
    this->f = temp;
    this->w = initial_waste;
}

bool BoardT::is_valid_tab_mv(CategoryT a, unsigned int b, unsigned int c)
{

}
bool BoardT::is_valid_waste_mv(CategoryT a, unsigned int b)
{

}
bool BoardT::is_valid_deck_mv()
{

}
void BoardT::tab_mv(CategoryT a, unsigned int b, unsigned int c)
{

}
void BoardT::waste_mv(CategoryT a, unsigned int b)
{

}
void BoardT::deck_mv()
{

}
CardStackT BoardT::get_tab(unsigned int a)
{

}
CardStackT BoardT::get_foundation(unsigned int a)
{

}
CardStackT BoardT::get_deck()
{

}
CardStackT BoardT::get_waste()
{

}
bool BoardT::valid_mv_exists()
{

}
bool BoardT::is_win_state()
{

}

// Private Methods
std::vector<CardStackT> tab_deck(std::vector<CardT> a)
{

}
