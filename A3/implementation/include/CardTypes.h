/**
 * @file CardTypes.h
 * @author Joshua Guinness, guinnesj
 * @brief Module for defining card types and constants
 * @version 0.1
 * @date 2019-03-26
 * 
 * @copyright Copyright (c) 2019
 * 
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

/**
 * \brief  Enumerated type of Suits (Heart, Diamond, Club, Spade)
 */
enum SuitT {Heart, Diamond, Club, Spade};

/**
 * \brief Enumerated type of game elements (Tableau, Foundation, Deck, Waste)
 */
enum CategoryT {Tableau, Foundation, Deck, Waste};

/**
 * \brief Struct for each card, contains a suit and a rank.
 */
struct CardT
{
    SuitT s;
    int r;
};

#endif
