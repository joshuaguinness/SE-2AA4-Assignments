/*
TODO:
- Exception for constructor
- Exception for valid tab move
- Exception for valid waste move
- Exception for tab_mv
- Exception for waste_mv
*/
// May need an initializer list

#include "../include/GameBoard.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

// Public Methods

BoardT::BoardT(std::vector<CardT> s)
{

    // https://en.cppreference.com/w/cpp/container/vector/vector and got some help from Tim Choy
    std::vector<CardT> front_of_deck(s.begin(), s.begin() + 40);
    std::vector<CardT> end_of_deck(s.begin()+41, s.end());

    CardStackT initial_deck = CardStackT(end_of_deck);
    CardStackT initial_waste = CardStackT();

    this->t = tab_deck(front_of_deck);
    this->f = init_seq(8);
    this->f = temp;
    this->w = initial_waste;
}

bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1)
{
    if (c == 0)
    {
        return valid_tab_tab(n_0, n_1);
    } else if (c == 1)
    {
        return valid_tab_foundation(n_0, n_1);
    } else if (c == 2)
    {
        return false;
    } else if (c == 3)
    {
        return false;
    }
}
bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n)
{
    if (c == 0)
    {
        return valid_waste_tab(n);
    } else if (c == 1)
    {
        return valid_waste_foundation(n);
    } else if (c == 2)
    {
        return false;
    } else if (c == 3)
    {
        return false;
    }
}
bool BoardT::is_valid_deck_mv()
{
    if (this->d.size() > 0)
    {
        return true;
    } else
    {
        return false;
    }
    
}

// Moves it from tableau ...?
void BoardT::tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1)
{
    if (c == 0)
    {
        this->t[n_0] = this->t[n_0].pop();
        this->t[n_1] = this->t[n_1].push(this->t[n_0].top());
    } else if (c == 1)
    {
        this->t[n_0] = this->t[n_0].pop();
        this->f[n_1] = this->f[n_1].push(this->t[n_0].top());
    }
}

// Moves it from the waste ...?
void BoardT::waste_mv(CategoryT c, unsigned int n)
{
    if (c == 0)
    {
        this->w = this->w.pop();
        this->t[n] = this->t[n].push(this->w.top());
    } else if (c == 1)
    {
        this->w = this->w.pop();
        this->f[n] = this->f[n].push(this->w.top());
    }
}

// Deck move ??
void BoardT::deck_mv()
{
    // Have to do w first so that by changing d, w isn't affected
    this->w = this->w.push(this->d.top());
    this->d = this->d.pop();
}

// Gets a particular tab
CardStackT BoardT::get_tab(unsigned int i)
{
    CardStackT s = this->t[i];
    return s;
}

// Gets a particular foundation
CardStackT BoardT::get_foundation(unsigned int a)
{
    CardStackT s = this->f[i];
    return s;
}

// Gets the entire deck
CardStackT BoardT::get_deck()
{
    CardStackT s = this->d;
    return s;
}

// Gets the entire waste
CardStackT BoardT::get_waste()
{
    CardStackT s = this->w;s
    return s;
}

// A valid mv actuall exists
bool BoardT::valid_mv_exists()
{
    return valid_tab_mv() || valid_waste_mv || is_valid_deck_mv();
}

// The state is in a win state
bool BoardT::is_win_state()
{

}

// Private Methods

// Take in a sequence of CardT, a deck, then creates the Tableau which is 10 card stacks, each having a stack of 4 cards
SeqCrdStckT BoardT::tab_deck(std::vector<CardT> a)
{
    SeqCrdStckT s(10);

    for (int i = 0; i < 10; i++)
    {
        std::vector<CardT> section_of_cards(s.begin() + 4*i, s.begin() + 4*(i+1)-1);
        CardStackT stack = CardStackT(section_of_cards);
        s.push_back(stack);
    }

    return s;
}

// Makes a sequence of CardStacks that are empty. Used for initializing the tableau
SeqCrdStckT BoardT::init_seq(unsigned int n)
{
    // https://en.cppreference.com/w/cpp/container/vector
    // Creates a sequence of length n of card stacks
    SeqCrdStckT s(n);

    // Creates an empty CardStackT
    CardStackT empty_stack = CardStackT();

    for (int i = 0; i < n; i++)
    {
        s.push_back(empty_stack);
    }

    return s;

}

// Checks to see if it is a valid tab to tab move
bool BoardT::valid_tab_tab(unsigned int n_0, unsinged int n_1)
{
    // https://www.geeksforgeeks.org/decision-making-c-c-else-nested-else/
    if (this->t[n_0].size() > 0)
    {
        if (this->t[n_1].size() > 0)
        {
            return tab_placeable(this->t[n_0].top(), t[n_1].top());
        } else if (this->t[n_1].size() == 0)
        {
            return true;
        }
    } else if (this->t[n_0].size() == 0)
    {
        if (this->t[n_1].size() > 0)
        {
            return false;
        } else if (this->t[n_1].size() == 0)
        {
            return false;
        }
    }
}

// Checks to see if it is a valid tab to foundation move
bool BoardT::valid_tab_foundation(unsigned int n_0, unsigned int n_1)
{
    if (this->t[n_0].size() > 0)
    {
        if (this->f[n_1].size() > 0)
        {
            return foundation_placeable(this->t[n_0].top(), f[n_1].top());
        } else if (this->f[n_1].size() == 0)
        {
            if (this->t[n_0].top().r == ACE){
                return true;
            } else 
            {
                return false;
            }
        }
    } else if (this->t[n_0].size() == 0)
    {
        if (this->f[n_1].size() > 0)
        {
            return false;
        } else if (this->f[n_1].size() == 0)
        {
            return false;
        }
    }
    
}

// Checks to see if a card is placeable on that tab
bool BoardT::tab_placeable(CardT c, CardT d)
{
   //  http://www.cplusplus.com/doc/tutorial/operators/
    if (c.s == d.s && c.r == (d.r - 1) )
    {
        return true;
    } else 
    {
        return false;
    }
}

// Legal move to place on foundation
bool BoardT::foundation_placeable(CardT c, CardT d)
{
    if (c.s == d.s && c.r == (d.r + 1) )
    {
        return true;
    } else 
    {
        return false;
    }
}

// Legal move from waste to tableau
bool BoardT::valid_waste_tab(unsigned int n)
{
    if (this->t[n].size() > 0)
    {
        tab_placeable(this->w.top(), this->t[n].top());
    } else if (this->t[n].size() == 0)
    {
        return true;
    }
}

// Legal move from waste to foundation
bool BoardT::valid_waste_foundation(unsigned int n)
{
    if (this->f[n].size() > 0)
    {
        foundation_placeable(this->w.top(), this->f[n].top());
    } else if (this->f[n].size() == 0)
    {
        if (this->w.top().r == ACE)
        {
            return true;
        } else{
            return false;
        }
    }
}

// There is a valid tab mv
bool BoardT::valid_tab_mv()
{

}

// There is a valid waste mv
bool BoardT::valid_waste_mv()
{

}
