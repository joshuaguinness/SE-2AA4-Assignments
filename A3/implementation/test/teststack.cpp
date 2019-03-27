#include "catch.h"

#include "Stack.h"
#include "CardTypes.h"
#include "CardStack.h"

TEST_CASE( "Tests for Stack", "[Stack]" )
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

    SECTION( "Testing Top - Normal" )
    {
        REQUIRE(deck.top().s == Spade);
    }

    SECTION( "Testing Push - Normal" )
    {
        deck = deck.push({SuitT::Heart, 3});
        REQUIRE(deck.top().r == 3);
        REQUIRE(deck.top().s == Heart);
    }

    SECTION( "Testing Pop - Normal" )
    {
        deck = deck.pop();
        deck = deck.pop();
        REQUIRE(deck.top().s == Club);
    }

    SECTION( "Testing Size - Normal" )
    {
        REQUIRE(deck.size() == 104);
    }

    SECTION( "Testing toSeq - Normal" )
    {
        std::vector<CardT> d = deck.toSeq();
        REQUIRE(d.size() == 104);
        REQUIRE(d.back().s == Spade);
        REQUIRE(d.back().r == KING);
        REQUIRE(d.front().s == Heart);
        REQUIRE(d.front().r == ACE);
    }

    SECTION( "Testing Top - Empty Stack" )
    {

    }

    SECTION( "Testing Pop - Empty Stack" )
    {

    }

    SECTION( "Testing Size - Empty Stack" )
    {

    }

    SECTION( "Testing toSeq - Empty Stack" )
    {

    }

}