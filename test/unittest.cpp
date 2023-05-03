#include "../src/special_id.hpp"
#include <catch2/catch.hpp>

TEST_CASE("uni::SpecialId")
{
    uni::SpecialId id;

    CHECK(id.to_string() == "A1");
    ++id;
    CHECK(id.to_string() == "A2");
    id++;
    CHECK(id.to_string() == "A3");

    id = "A9";
    CHECK(id.to_string() == "A9");
    ++id;
    CHECK(id.to_string() == "B1");


    id = "Z9";
    CHECK(id.to_string() == "Z9");
    ++id;
    CHECK(id.to_string() == "A1-A1");
    ++id;
    CHECK(id.to_string() == "A1-A2");

    id = "A1-Z9";
    CHECK(id.to_string() == "A1-Z9");
    ++id;
    CHECK(id.to_string() == "A2-A1");

    id = "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9";
    CHECK(id.to_string() == "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9");
    ++id;
    CHECK(id.to_string() == "A1");

    id = "C9";
    CHECK(id.to_string() == "C9");
    ++id;
    CHECK(id.to_string() == "E1");

    id = "E9";
    CHECK(id.to_string() == "E9");
    ++id;
    CHECK(id.to_string() == "H1");

    id = "I9";
    CHECK(id.to_string() == "I9");
    ++id;
    CHECK(id.to_string() == "K1");

    id = "L9";
    CHECK(id.to_string() == "L9");
    ++id;
    CHECK(id.to_string() == "N1");

    id = "P9";
    CHECK(id.to_string() == "P9");
    ++id;
    CHECK(id.to_string() == "R1");

    id = "U9";
    CHECK(id.to_string() == "U9");
    ++id;
    CHECK(id.to_string() == "W1");
}
