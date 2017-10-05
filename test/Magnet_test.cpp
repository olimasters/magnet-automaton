#include "catch.hpp"
#include "Magnet.h"

TEST_CASE("Magnets initialise to the correct size when done randomly")
{
    Magnet magnet(10,20);
    REQUIRE(magnet.getHeight() == 10);
    REQUIRE(magnet.getWidth() == 20);
}

TEST_CASE("Magnet constructor taking spins works")
{
    Magnet magnet({{1,-1,1},{-1,1,-1}});
    std::vector<std::vector<int>> expected = {{1,-1,1},{-1,1,-1}};
    REQUIRE(magnet.getSpins() == expected);
}

TEST_CASE("Magnet's update function leaves spins alone when necessary")
{
    std::vector<std::vector<int>> initialSpins{
            { 1,-1, 1, 1},
            { 1, 1, 1,-1},
            {-1, 1,-1,-1},
            {-1, 1, 1, 1}
    };
    Magnet magnet(initialSpins);

    SECTION("Top-left corner")
    {
        REQUIRE(!magnet.update(0,0));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Top-right corner")
    {
        REQUIRE(!magnet.update(0,magnet.getWidth()-1));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Bottom-left corner")
    {
        REQUIRE(!magnet.update(magnet.getHeight()-1,0));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Bottom-right corner")
    {
        REQUIRE(!magnet.update(magnet.getHeight()-1,magnet.getWidth()-1));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Top edge")
    {
        REQUIRE(!magnet.update(0,2));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Right edge")
    {
        REQUIRE(!magnet.update(2,3));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Bottom edge")
    {
        REQUIRE(!magnet.update(3,2));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Left edge")
    {
        REQUIRE(!magnet.update(1,0));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
    SECTION("Interior element")
    {
        REQUIRE(!magnet.update(1,2));
        REQUIRE(magnet.getSpins() == initialSpins);
    }
}

TEST_CASE("Magnet's update function updates when necessary")
{
    std::vector<std::vector<int>> initialSpins{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
    };
    Magnet magnet(initialSpins);

    SECTION("Top-left corner")
    {
        REQUIRE(magnet.update(0,0));
        std::vector<std::vector<int>> expected{
            {-1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Top-right corner")
    {
        REQUIRE(magnet.update(0,magnet.getWidth()-1));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1,-1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Bottom-left corner")
    {
        REQUIRE(magnet.update(magnet.getHeight()-1,0));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            { 1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Bottom-right corner")
    {
        REQUIRE(magnet.update(magnet.getHeight()-1,magnet.getWidth()-1));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1, 1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Top edge")
    {
        REQUIRE(magnet.update(0,2));
        std::vector<std::vector<int>> expected{
            { 1,-1, 1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Right edge")
    {
        REQUIRE(magnet.update(2,3));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1,-1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Bottom edge")
    {
        REQUIRE(magnet.update(3,2));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1,-1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Left edge")
    {
        REQUIRE(magnet.update(1,0));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            { 1, 1, 1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Interior element (1,2)")
    {
        REQUIRE(magnet.update(1,2));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1,-1,-1},
            { 1,-1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
    SECTION("Interior element (2,1)")
    {
        REQUIRE(magnet.update(2,1));
        std::vector<std::vector<int>> expected{
            { 1,-1,-1, 1},
            {-1, 1, 1,-1},
            { 1, 1,-1, 1},
            {-1, 1, 1,-1}
        };
        REQUIRE(magnet.getSpins() == expected);
    }
}
