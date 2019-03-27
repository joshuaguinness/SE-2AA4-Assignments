#include "catch.h"

#include "Stack.h"
#include "CardTypes.h"
#include "CardStack.h"
#include "GameBoard.h"

TEST_CASE( "Tests for GameBoard", "[GameBoard]" )
{

    std::vector<CardT> d;
    for (RankT rank = ACE; rank <= KING; rank++) {
        for (unsigned int suit = 0; suit < 4; suit++) {
            CardT n = { static_cast<SuitT>(suit), rank };
                d.push_back(n);
                d.push_back(n);
        }
    }

    CardStackT deck = CardStackT(d);
    CardStackT empty_deck = CardStackT();

    BoardT board(d);

    SECTION( "Testing for is_valid_tab_mv" )
    {
        bool valid = board.is_valid_tab_mv(Tableau, 1, 3);
        REQUIRE(valid == false);
    }

    SECTION( "Testing for is_valid_deck_mv" )
    {
        REQUIRE(board.is_valid_deck_mv());
    }

}