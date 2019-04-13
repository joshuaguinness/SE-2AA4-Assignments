#include "../include/Cell.h"
#include "../catch/catch.h"
#include <stdexcept>


TEST_CASE("Tests for Cell", "[Cell]") {

    SECTION("Testing Cell ADT created properly using default constructor") {
        Cell cell;
        REQUIRE(cell.get_life() == false);
        REQUIRE(cell.get_neighbours() == 0);
    }

    SECTION("Testing Cell ADT created properly") {
        Cell cell(true);
        REQUIRE(cell.get_life() == true);
        REQUIRE(cell.get_neighbours() == 0);
    }

    SECTION("Testing get_life") {
        Cell cell_one(true);
        Cell cell_two(false);
        REQUIRE(cell_one.get_life() == true);
        REQUIRE(cell_two.get_life() == false);
    }

    SECTION("Testing get_neighbours") {
        Cell cell(true);
        REQUIRE(cell.get_neighbours() == 0);
    }

    SECTION("Testing set_life") {
        Cell cell(true);
        REQUIRE(cell.get_life() == true);
        cell.set_life(false);
        REQUIRE(cell.get_life() == false);
    }

    SECTION("Testing set_neighbours") {
        Cell cell(false);
        REQUIRE(cell.get_neighbours() == 0);
        cell.set_neighbours(3);
        REQUIRE(cell.get_neighbours() == 3);
    }
}