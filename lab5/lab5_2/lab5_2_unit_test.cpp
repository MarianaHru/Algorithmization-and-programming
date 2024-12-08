#include <gtest/gtest.h>
#include "./lab5_2.h"

TEST(SeriesTest, TestA)
{
    double x = 2.0;
    int n = 1;
    double a = 1;

    double result = A(x, n, a);
    EXPECT_NEAR(result, 2.0, 1e-5);
}

// Тест для функції S
TEST(SeriesTest, TestS)
{
    double x = 0.5;
    double eps = 1e-5;
    int n = 0;
    double s = 0;

    double result = S(x, eps, n, s);

    EXPECT_NEAR(result, exp(x), eps);
    EXPECT_GT(n, 0);
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
