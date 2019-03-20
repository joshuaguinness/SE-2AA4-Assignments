#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

typedef std::vector<CardStackT> SeqCrdStckT;

class BoardT {

    private:
        // Private Variables
        // https://www.cpp.edu/~elab/ECE114/Array.html
        std::vector<CardStackT> t;
        std::vector<CardStackT> f;
        CardStackT d;
        CardStackT w;

        // Private Local Methods
        //https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
        bool two_decks(CardStackT t[8], CardStackT f[10], CardStackT d, CardStackT w);
        //unsigned int cnt_cards_seq(CardStackT S[], LAMBDA func);
        //unsigned int cnt_cards_stack(CardStackT s, LAMBDA func);
        //unsigned int cnt_cards(CardStackT t[8], CardStack f[10], CardStackT d, CardStackT w, LAMBDA func);
        // https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
        CardStackT * init_seq(unsigned int n);
        std::vector<CardStackT> tab_deck(std::vector<CardT> a);
        bool is_valid_pos(CategoryT a, unsigned int b);
        bool valid_tab_tab(unsigned int a, unsigned int b);
        bool valid_tab_foundation(unsigned int a, unsigned int b);
        bool valid_waste_tab(unsigned int a);
        bool valid_waste_foundation(unsigned int a);
        bool tab_placeable (CardT a, CardT b);
        bool foundation_placeable(CardT a, CardT b);

    // Public Methods
    public:
        BoardT(std::vector<CardT> s);
        bool is_valid_tab_mv(CategoryT a, unsigned int b, unsigned int c);
        bool is_valid_waste_mv(CategoryT a, unsigned int b);
        bool is_valid_deck_mv();
        void tab_mv(CategoryT a, unsigned int b, unsigned int c);
        void waste_mv(CategoryT a, unsigned int b);
        void deck_mv();
        CardStackT get_tab(unsigned int a);
        CardStackT get_foundation(unsigned int a);
        CardStackT get_deck();
        CardStackT get_waste();
        bool valid_mv_exists();
        bool is_win_state();
};

#endif
