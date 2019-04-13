#include "Cell.h"
#include "catch.h"
#include <stdexcept>


TEST_CASE("Tests for Cell", "[Cell]") {

    SECTION("Testing Cell ADT created properly using default constructor") {
        Cell cell;
        REQUIRE(cell.get_life() == false);
        REQUIRE(cell.get_neighbours() == 0);
    }


}