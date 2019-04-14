/**
 * @file GameBoard.h
 * @author Joshua Guinness, guinnesj, 400134735
 * @brief Module for defining a GameBoard class
 * @version 0.1
 * @date 2019-04-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include "Cell.h"
#include "View.h"

class BoardT {

    private:

        Cell *C;
        void update_neighbours_leftside();
        void update_neighbours_rightside();
        void update_neighbours_top();
        void update_neighbours_bottom();
        void update_neighbours_middle();
        void update_neighbours_corners();
        void update_cells();

    public:

        /**
         * @brief Construct a new Board T object
         * 
         * @param s 2D array of Cells
         */
        BoardT(Cell *s);

        /**
         * @brief Gets the next iteration of the game
         * 
         */
        void next();

        /**
         * @brief Calls the View module which will output the game state to a file
         * 
         */
        void view();

};


#endif