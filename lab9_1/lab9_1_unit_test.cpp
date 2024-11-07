
#include <gtest/gtest.h>
#include "sum.h"
#include "var.h"

using namespace nsVar;
using namespace nsSum;

TEST(SumTest, CalculatesCorrectSumAndIterations)
{

    x = 1.0;
    e = 0.0001;

    sum();

    double expected_s = exp(x);
    int expected_n = n;

    EXPECT_NEAR(s, expected_s, e);

    EXPECT_GT(n, 0);
}
