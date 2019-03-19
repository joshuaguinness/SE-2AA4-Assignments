#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

class BoardT {

    private:
        // Private Variables
        // https://www.cpp.edu/~elab/ECE114/Array.html
        CardStackT t [8];
        CardStack f [10];
        CardStackT d;
        CardStack w;


        // Private Methods
        bool two_decks();

    protected:

    // Public Methods
    public:
        
        BoartT BoardT (std::vector<T> s);
        bool is_valid_tab_mv(CategoryT a, unsigned int b, unsigned int c);
        bool is_valid_waste_mv(CategoryT a, unsigned int b);
        bool is_valid_deck_mv();
        tab_mv(CategoryT a, unsigned int b, unsigned int c);
        waste_mv(CategoryT a, unsigned int b);
        deck_mv();
        CardStackT get_tab(unsigned int a);
        CardStackT get_foundation(unsigned int a);
        CardStackT get_deck();
        CardStackT get_waste();
        bool valid_mv_exists();
        bool is_win_state();


};

#endif
