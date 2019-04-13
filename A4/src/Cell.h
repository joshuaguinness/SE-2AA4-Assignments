/**
 * \file Cell.h
 * \author Joshua Guinness, guinnesj, 400134735
 * \brief Module for a Cell ADT
 * \version 0.1
 * \date 2019-04-13
 * 
 * \copyright Copyright (c) 2019
 * 
 */

#ifndef A4_CELL_H_
#define A4_CELL_H_

class Cell{
    private:

        /// State - Alive or Dead
        bool S;

        /// Number of neighbours
        int N;

    public:

        /**
         * \brief Construct a new Cell object
         * 
         */
        Cell();

        /**
         * \brief Construct a new Cell object
         * 
         * \param s State - Alive or Dead
         */
        Cell(bool s);

        /**
         * \brief Get the whether the Cell is alive or dead
         * 
         * \return true Cell is alive
         * \return false Cell is dead
         */
        bool get_life();

        /**
         * \brief Get the the number of alive neighbours
         * the cell has
         * 
         * \return int Number of neighbours
         */
        int get_neighbours();

        /**
         * \brief Set the state of the cell, alive or dead
         * 
         * \param s new state
         */
        set_life(bool s);

        /**
         * \brief Set the number of alive neighbours the cell has
         * 
         * \param n Number of neighbours
         */
        set_neighbours(int n);
};

#endif