#include <gtest/gtest.h>
#include "../app/main.hpp"

TEST(MultiplicationTest, HandlesPositiveNumbers) {
    EXPECT_EQ(multiplication(2, 2), 4);
}

TEST(Multiplication, HandlesNegativeNumbers) {
    EXPECT_EQ(multiplication(-1, 1), -1);
}