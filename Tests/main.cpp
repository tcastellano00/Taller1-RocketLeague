#include "gtest/gtest.h"

int main(int argc, char **argv) {
	char w1[] = "";
    char w2[] = "";
    char* args[] = {w1, w2};

    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}