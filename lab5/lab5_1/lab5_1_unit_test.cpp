#include <gtest/gtest.h>
#include <cmath>    // Для sin, cos, pow та abs
#include "./lab5_1.h" // Підключаємо заголовок з оголошенням функції k

// Тест для функції k
TEST(TestKFunction, HandlesSimpleInput)
{
    // Використовуємо функцію k з раніше оголошеним прототипом
    double result = k(1.0, 2.0);
    double expected = (sin(1.0) / (1.0 * 1.0) + (2.0 * 2.0)) + (cos(1.0) / 1.0 + abs(1.0 * 2.0));

    EXPECT_NEAR(result, expected, 0.0001); // Використовуємо EXPECT_NEAR для порівняння з точністю
}

// Тест для основної логіки програми
TEST(TestMainLogic, CalculatesC)
{
    double p = 2.0;
    double q = 1.0;
    // Використовуємо функцію k з раніше оголошеним прототипом
    double c = k(1 + (p * p), 1 - (q * q)) - pow(k(1, (p * q)), 2) / (1 + k(p * q, 1));
    double expectedC = k(1 + 4, 1 - 1) - pow(k(1, (2 * 1)), 2) / (1 + k(2 * 1, 1));

    EXPECT_NEAR(c, expectedC, 0.0001); // Тест для змінної c
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv); // Ініціалізація GoogleTest
    return RUN_ALL_TESTS();                 // Запуск всіх тестів
}
