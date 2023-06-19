#include <gtest/gtest.h>

#include "src/main.h"

TEST(MainTest, BasicMainTest)
{
    A a;
    EXPECT_EQ(a.f1(), 1);
}