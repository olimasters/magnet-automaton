#include "catch.hpp"
#include "Magnet.h"

TEST_CASE("Magnets initialise to the correct size")
{
    Magnet magnet(10,20);
    
    REQUIRE(magnet.getHeight() == 10);
    REQUIRE(magnet.getWidth() == 20);
}
