#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

// Use SeqCrdStckT a lot so putting it in a typedef makes the code clearer
typedef std::vector<CardStackT> SeqCrdStckT;

class BoardT {

    // Private Methods and Variables
    private:
        // Private Variables
        SeqCrdStckT t;
        SeqCrdStckT f;
        CardStackT d;
        CardStackT w;
        // Private Local Methods
        bool two_decks(SeqCrdStckT, SeqCrdStckT f, CardStackT d, CardStackT w);
        SeqCrdStckT init_seq(unsigned int n);
        SeqCrdStckT tab_deck(std::vector<CardT> deck);
        bool is_valid_pos(CategoryT c, unsigned int n);
        bool valid_tab_tab(unsigned int n_0, unsigned int n_1);
        bool valid_tab_foundation(unsigned int n_0, unsigned int n_1);
        bool valid_waste_tab(unsigned int n);
        bool valid_waste_foundation(unsigned int n);
        bool tab_placeable (CardT c, CardT d);
        bool foundation_placeable(CardT c, CardT d);
        bool valid_tab_mv();
        bool valid_waste_mv();
        unsigned int hasing_function(CardT card);

    // Public Methods
    public:
        BoardT(std::vector<CardT> s);
        bool is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);
        bool is_valid_waste_mv(CategoryT c, unsigned int n);
        bool is_valid_deck_mv();
        void tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);
        void waste_mv(CategoryT c, unsigned int n);
        void deck_mv();
        CardStackT get_tab(unsigned int i);
        CardStackT get_foundation(unsigned int i);
        CardStackT get_deck();
        CardStackT get_waste();
        bool valid_mv_exists();
        bool is_win_state();
};

#endif
