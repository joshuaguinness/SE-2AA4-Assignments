/**
 * \file CardTypes.h
 * \author
 * \brief
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

enum SuitT {Heart, Diamond, Club, Spade};

enum CategoryT {Tableau, Foundation, Deck, Waste};

// int RankT = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];

struct CardT
{
    SuitT s;
    int r;
};

#endif
