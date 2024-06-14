#include <algorithm>
#include "test/googletest/googletest/include/gtest/gtest.h"
#include "main.cpp"

// Тестовый случай для проверки быстрой сортировки
TEST(SortingTest, QuickSort) {
int arr[] = {8, 3, 1, 7, 4};
int n = sizeof(arr) / sizeof(arr[0]);
std::sort(arr, arr + n);  // Сначала сортируем массив
std::random_shuffle(arr, arr + n);  // Затем перемешиваем его
// Теперь проверяем, что после быстрой сортировки массив стал отсортированным
quickSort(arr, 0, n - 1);
ASSERT_TRUE(std::is_sorted(arr, arr + n));
}

// Тестовый случай для проверки поразрядовой сортировки
TEST(SortingTest, RadixSort) {
int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
int n = sizeof(arr) / sizeof(arr[0]);
std::sort(arr, arr + n);  // Сначала сортируем массив
std::random_shuffle(arr, arr + n);  // Затем перемешиваем его
// Теперь проверяем, что после поразрядовой сортировки массив стал отсортированным
radixSort(arr, n);
ASSERT_TRUE(std::is_sorted(arr, arr + n));
}

// Тестовый случай для проверки сортировки перемешиванием
TEST(SortingTest, ShakerSort) {
int arr[] = {64, 34, 25, 12, 22, 11, 90};
int n = sizeof(arr) / sizeof(arr[0]);
std::sort(arr, arr + n);  // Сначала сортируем массив
std::random_shuffle(arr, arr + n);  // Затем перемешиваем его
// Теперь проверяем, что после сортировки перемешиванием массив стал отсортированным
shakerSort(arr, n);
ASSERT_TRUE(std::is_sorted(arr, arr + n));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}