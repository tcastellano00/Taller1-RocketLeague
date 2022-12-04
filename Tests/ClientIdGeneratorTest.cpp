#include "gtest/gtest.h"
#include "../Server/ClientIdGenerator.h"

TEST(ClientIdGeneratorTest, getId_shoudlReturnOneWhenTheGeneratorItsCreated) {
    ClientIdGenerator::reset();
    
    int id = ClientIdGenerator::getId();

    EXPECT_EQ (id, 1);
}

TEST(ClientIdGeneratorTest, getId_shoudlReturnDistinctIdNextTimeItsCalled) {
    ClientIdGenerator::reset();

    int id = ClientIdGenerator::getId();
    int id2 = ClientIdGenerator::getId();

    EXPECT_FALSE (id == id2);
}

TEST(ClientIdGeneratorTest, getId_shoudlReturnFourWhenItsCalledFourTimes) {
    ClientIdGenerator::reset();

    ClientIdGenerator::getId();
    ClientIdGenerator::getId();
    ClientIdGenerator::getId();
    int id = ClientIdGenerator::getId();

    EXPECT_EQ (id, 4);
}