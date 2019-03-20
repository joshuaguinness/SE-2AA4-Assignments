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

        // Private Local Methods
        //https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
        bool two_decks(CardStackT t[8], CardStack f[10], CardStackT d, CardStackT w);
        //unsigned int cnt_cards_seq(CardStackT S[], LAMBDA func);
        //unsigned int cnt_cards_stack(CardStackT s, LAMBDA func);
        //unsigned int cnt_cards(CardStackT t[8], CardStack f[10], CardStackT d, CardStackT w, LAMBDA func);
        // https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
        CardStackT * init_seq(unsigned int n);
        CardStackT * tab_deck(CardT a);
        bool is_valid_pos(CategoryT a, unsigned int b);
        bool valid_tab_tab(unsigned int a, unsigned int b);
        bool valid_tab_foundation(unsigned int a, unsigned int b);
        bool valid_waste_tab(unsigned int a);
        bool valid_waste_foundation(unsigned int a);
        bool tab_placeable (CardT a, CardT b);
        bool foundation_placeable(CardT a, CardT b);

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
