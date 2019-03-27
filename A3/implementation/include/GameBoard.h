/**
 * \file GameBoard.h
 * \author Joshua Guinness, guinnesj
 * \brief Module for defining a GameBoard class
 * \version 0.1
 * \date 2019-03-26
 * 
 * \copyright Copyright (c) 2019
 * 
 */

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

// SeqCrdStckT is just a vector of objects of type CardStackT
// Done to increase clarity in code
typedef std::vector<CardStackT> SeqCrdStckT;

/**
 * \brief Class representing a Gameboard
 * 
 */
class BoardT {

    /// Private Methods and Variables
    private:

        /// Private Variables
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
        unsigned int hashing_function(CardT card);

    /// Public Methods
    public:

        /**
         * \brief Construct a new Board T object
         * 
         * \param vector of type CardT, meant to be the deck
         */
        BoardT(std::vector<CardT> s);

        /**
         * \brief Checks to see if moving a card from the tableau to
         * another game element is valid
         * 
         * \param CategoryT, the game element (Tableau, Foundation, Deck, Waste)
         * for the card to be moved to
         * \param n_0 the stack in the tableau where the card is
         * \param n_1 the stack in the game element where the card
         * is to be moved to
         * \return true if the move is valid
         * \return false if the move is not valid
         */
        bool is_valid_tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);

        /**
         * \brief Checks to see if moving a card from the waste to
         * another game element is valid
         * 
         * \param Game element that the card is to be moved to
         * \param Stack in the game element
         * \return true if the move is valid
         * \return false if the move is not valid
         */
        bool is_valid_waste_mv(CategoryT c, unsigned int n);

        /**
         * \brief Checks to see if there is a valid move from the deck
         * to another game element
         * 
         * \return true if there is a valid move
         * \return false if there is not a valid move
         */
        bool is_valid_deck_mv();

        /**
         * \brief Moves a card from the tableau to the specified game
         * element
         * 
         * \param The specified game element (either tableau or foundation)
         * \param n_0 the stack in the tableau
         * \param n_1 the stack in the specified game element
         */
        void tab_mv(CategoryT c, unsigned int n_0, unsigned int n_1);

        /**
         * \brief Moves a card from the waste to the specified 
         * game element
         * 
         * \param c Specified game element (either tableau or foundation)
         * \param n the stack in the specified game element
         */
        void waste_mv(CategoryT c, unsigned int n);

        /**
         * \brief Moves a card from the deck to the waste
         * 
         */
        void deck_mv();

        /**
         * \brief Gets a specified stack in the tableau
         * 
         * \param Index of stack
         * \return CardStackT 
         */
        CardStackT get_tab(unsigned int i);

        /**
         * \brief Gets a specified stack in the foundation
         * 
         * \param Index of stack
         * \return CardStackT 
         */
        CardStackT get_foundation(unsigned int i);

        /**
         * \brief Gets the stack of deck cards
         * 
         * \return CardStackT 
         */
        CardStackT get_deck();

        /**
         * \brief Gets the stack of waste cards
         * 
         * \return CardStackT 
         */
        CardStackT get_waste();

        /**
         * \brief Checks to see if a valid move exists
         * 
         * \return true if a valid move exists
         * \return false if a valid move exists
         */
        bool valid_mv_exists();

        /**
         * \brief Checks to see if the state of the game board
         * is in a win state
         * 
         * \return true if the game is in win state
         * \return false if the game is not in a win state
         */
        bool is_win_state();
};

#endif
