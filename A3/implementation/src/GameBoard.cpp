#include "../include/GameBoard.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <algorithm>

// Public Methods

BoardT::BoardT(std::vector<CardT> deck)
{

    //std::cout << "Deck Size 2" << CardStackT(deck).size() << "\n";

    if (!two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT()))
    {
        throw std::invalid_argument("Invalid Argument");
    }

    // https://en.cppreference.com/w/cpp/container/vector/vector and got some help from Tim Choy
    std::vector<CardT> front_of_deck(deck.begin(), deck.begin() + 40);
    std::vector<CardT> end_of_deck(deck.begin()+41, deck.end());

    CardStackT initial_deck = CardStackT(end_of_deck);
    CardStackT initial_waste = CardStackT();

    this->t = tab_deck(front_of_deck);
    this->f = init_seq(8);
    this->d = initial_deck;
    this->w = initial_waste;

}

bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1)
{

    // Exception Handling
    if (c == CategoryT::Tableau)
    {
        if (is_valid_pos(CategoryT::Tableau, n_0) && is_valid_pos(CategoryT::Tableau, n_1) == false)
        {
            throw std::out_of_range("Out of Range");
        }
    }
    if (c == CategoryT::Foundation)
    {
        if (is_valid_pos(CategoryT::Tableau, n_0) && is_valid_pos(CategoryT::Foundation, n_1) == false)
        {
            throw std::out_of_range("Out of Range");
        }
    } 

    // What fn is actually supposed to do
    if (c == CategoryT::Tableau)
    {
        return valid_tab_tab(n_0, n_1);
    } else if (c == CategoryT::Foundation)
    {
        return valid_tab_foundation(n_0, n_1);
    } else if (c == CategoryT::Deck)
    {
        return false;
    } else  // If it is waste
    {
        return false;
    }
}

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n)
{
    // Exception handling
    if (this->w.size() == 0)
    {
        throw std::invalid_argument("Invalid Argument");
    }
    if (c == CategoryT::Tableau && (is_valid_pos(CategoryT::Tableau, n) == false))
    {
        throw std::out_of_range("Out of Range");
    }
    if (c == CategoryT::Tableau && (is_valid_pos(CategoryT::Foundation, n) == false))
    {
        throw std::out_of_range("Out of Range");
    }

    // Actual function functionality
    if (c == CategoryT::Tableau)
    {
        return valid_waste_tab(n);
    } else if (c == CategoryT::Foundation)
    {
        return valid_waste_foundation(n);
    } else if (c == CategoryT::Deck)
    {
        return false;
    } else // Waste
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
    // Exception handling
    if (is_valid_tab_mv(c, n_0, n_1) == false)
    {
        throw std::invalid_argument("Invalid Argument");
    }


    if (c == CategoryT::Tableau)
    {
        this->t[n_0] = this->t[n_0].pop();
        this->t[n_1] = this->t[n_1].push(this->t[n_0].top());
    } else if (c == CategoryT::Foundation)
    {
        this->t[n_0] = this->t[n_0].pop();
        this->f[n_1] = this->f[n_1].push(this->t[n_0].top());
    }
}

// Moves it from the waste ...?
void BoardT::waste_mv(CategoryT c, unsigned int n)
{
    // Exception handling
    if (is_valid_waste_mv(c, n) == false)
    {
        throw std::invalid_argument("Invalid Argument");
    }

    if (c == CategoryT::Tableau)
    {
        this->t[n] = this->t[n].push(this->w.top());
        this->w = this->w.pop();
    } else if (c == CategoryT::Foundation)
    {
        this->f[n] = this->f[n].push(this->w.top());
        this->w = this->w.pop();
    }
}

// Deck move ??
void BoardT::deck_mv()
{
    // Exception handling
    if (is_valid_deck_mv() == false)
    {
        throw std::invalid_argument("Invalid Argument");
    }

    // Have to do w first so that by changing d, w isn't affected
    this->w = this->w.push(this->d.top());
    this->d = this->d.pop();
}

// Gets a particular tab
CardStackT BoardT::get_tab(unsigned int i)
{
    // Exception handling
    if (is_valid_pos(CategoryT::Tableau, i) == false)
    {
        throw std::out_of_range("Out of Range");
    }

    CardStackT s = this->t[i];
    return s;
}

// Gets a particular foundation
CardStackT BoardT::get_foundation(unsigned int i)
{
    // Exception handling
    if (is_valid_pos(CategoryT::Foundation, i) == false)
    {
        throw std::out_of_range("Out of Range");
    }

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
    CardStackT s = this->w;
    return s;
}

// A valid mv actuall exists
bool BoardT::valid_mv_exists()
{
    return valid_tab_mv() || valid_waste_mv() || is_valid_deck_mv();
}

// The state is in a win state
bool BoardT::is_win_state()
{

    bool return_statement = true;

    for (unsigned int i = 0; i < 8; i++)
    {
        if (this->f[i].size() > 0 && this->f[i].top().r == KING)
        {
            return_statement &= true;
        } else
        {
            return false;
        }
    }

    return return_statement;
}





// Private Methods

// Take in a sequence of CardT, a deck, then creates the Tableau which is 10 card stacks, each having a stack of 4 cards
SeqCrdStckT BoardT::tab_deck(std::vector<CardT> deck)
{
    SeqCrdStckT s(10);

    for (unsigned int i = 0; i < 10; i++)
    {
        std::vector<CardT> section_of_cards(deck.begin() + 4*i, deck.begin() + 4*(i+1)-1);
        CardStackT stack = CardStackT(section_of_cards);
        s.push_back(stack);
    }

    return s;
}

bool BoardT::is_valid_pos(CategoryT c, unsigned int n)
{
    // Got a lil help from sam on this
    if (c == CategoryT::Tableau)
    {
        if (n >= 0 && n <= 9)
        {
            return true;
        } else
        {
            return false;
        }
        
    }
    else if (c == CategoryT::Foundation)
    {
        if (n >= 0 && n <= 7)
        {
            return true;
        } else
        {
            return false;
        }
    } else 
    {
        return true;
    }
}

// Makes a sequence of CardStacks that are empty. Used for initializing the tableau
SeqCrdStckT BoardT::init_seq(unsigned int n)
{
    // https://en.cppreference.com/w/cpp/container/vector
    // Creates a sequence of length n of card stacks
    SeqCrdStckT s;

    for (unsigned int i = 0; i < n; i++)
    {
        // Adds an empty Card Stack
        s.push_back(CardStackT());
    }

    return s;

}

// Checks to see if it is a valid tab to tab move
bool BoardT::valid_tab_tab(unsigned int n_0, unsigned int n_1)
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

    return false;
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

    return false;
    
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
    } else // if (this->t[n].size() == 0)
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
    } else //if (this->f[n].size() == 0)
    {
        if (this->w.top().r == ACE)
        {
            return true;
        } else
        {
            return false;
        }
    }
}

// There is a valid tab mv
bool BoardT::valid_tab_mv()
{
    bool valid_tab_mv_boolean = false;
    for (unsigned int i = 0; i < 10; i++) {
        for (unsigned int j = 0; j < 10; j++) {
            if (is_valid_pos(CategoryT::Tableau, i) &&  is_valid_pos(CategoryT::Tableau, j))    {
                valid_tab_mv_boolean |= is_valid_tab_mv(CategoryT::Tableau, i, j);
            }
        }
    }
    for (unsigned int i = 0; i < 10; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if (is_valid_pos(CategoryT::Tableau, i) &&  is_valid_pos(CategoryT::Foundation, j)){
                valid_tab_mv_boolean |= is_valid_tab_mv(CategoryT::Foundation, i, j);
            }
        }
    }
    return valid_tab_mv_boolean;
}

// There is a valid waste mv
bool BoardT::valid_waste_mv()
{
    bool return_boolean;
    bool valid_pos_boolean = false;
    bool valid_waste_mv_boolean = false;

    for (unsigned int i = 0; i < 10; i++)
    {
        valid_pos_boolean |=  is_valid_pos(CategoryT::Tableau, i);
        valid_waste_mv_boolean |=  is_valid_pos(CategoryT::Tableau, i);
    }

    for (unsigned int i = 0; i < 8; i++)
    {
        valid_pos_boolean |=  is_valid_pos(CategoryT::Foundation, i);
        valid_waste_mv_boolean |=  is_valid_pos(CategoryT::Foundation, i);
    }

    return_boolean = valid_pos_boolean && valid_waste_mv_boolean;
    return return_boolean;
}

// Function which will return true if 104 cards in the deck and each card appears twice
bool BoardT::two_decks(SeqCrdStckT t, SeqCrdStckT f, CardStackT d, CardStackT w)
{
    bool total_cards_boolean;
    bool deck_valid_boolean = true;
    unsigned int total_cards = 0;

    // Checks to see whether there is 104 cards in the deck
    for (unsigned int i = 0; i < t.size(); i++)
    {
        total_cards += t[i].size();
    }

    for (unsigned int j = 0; j < f.size(); j++)
    {
        total_cards += f[j].size();
    }

    total_cards += d.size() + w.size();

    if (total_cards == 104)
    {
        total_cards_boolean = true;
    } else 
    {
        total_cards_boolean = false;
    }

    /* The method for determining whether there are two of each card in the deck would be to 
    iterate througha ll the cards passed via the paramters, and hash each one to a value in
    the new array, if all the values in the array are two, then two of each cards exists */

    // Hasing Function: Rank of card - 1 * 4 +  (0 (Heart), 1 (Diamond), 2 (Club), 3 (Spade})

    int card_exists[52] = { 0 };
    unsigned int current_index;

    SeqCrdStckT t_temp = t;
    SeqCrdStckT f_temp = f;
    CardStackT d_temp = d;
    CardStackT w_temp = w;

    for (unsigned int i = 0; i < t.size(); i++)
    {
        for (unsigned int j = 0; j < t[i].size(); j++)
        {
            current_index = hashing_function(t_temp.at(i).top());
            card_exists[current_index] += 1;
            t_temp.at(i) = t_temp.at(i).pop();
        }
    }

    for (unsigned int i = 0; i < f.size(); i++)
    {
        for (unsigned int j = 0; j < f[i].size(); j++)
        {
            current_index = hashing_function(f_temp.at(i).top());
            card_exists[current_index] += 1;
            f_temp.at(i) = f_temp.at(i).pop();
        }
    }

    for (unsigned int i = 0; i < d.size(); i++)
    {
        current_index = hashing_function(d_temp.top());
        card_exists[current_index] += 1;
        d_temp = d_temp.pop();

    }

    for (unsigned int i = 0; i < w.size(); i++)
    {
        current_index = hashing_function(w_temp.top());
        card_exists[current_index] += 1;
        w_temp = w_temp.pop();
    }

    for (unsigned int i = 0; i < 52; i++)
    {
        if (card_exists[i] == 2)
        {
            deck_valid_boolean &= true;
        }
        else
        {
            deck_valid_boolean &= false;
        }
        
    }

    return total_cards_boolean && deck_valid_boolean;

}

// Gets the current index
unsigned int BoardT::hashing_function(CardT card)
{
    // Hasing function which will return the index of where to add one, helps with 
    // information hiding
    unsigned int index;

    // https://www.programiz.com/cpp-programming/switch-case
    switch (card.s)
    {
        case SuitT::Heart:
            index = (card.r - 1)*4 + 0;
            break;

        case SuitT::Diamond:
            index = (card.r - 1)*4 + 1;
            break;

        case SuitT::Club:
            index = (card.r - 1)*4 + 2;
            break;

        case SuitT::Spade:
            index = (card.r - 1)*4 + 3;
            break;
    }

    return index;

}