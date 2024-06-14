#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // для max_element

using namespace std;

// Функция для обмена двух элементов массива
void swap(int* a, int* b, int& swoop) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swoop = swoop + 3;
}

// Функция для разделения массива на две части
int partition(int arr[], int low, int high, int& swaps) {
    int pivot = arr[high]; // выбираем последний элемент в качестве опорного
    swaps++;
    int i = (low - 1);     // индекс меньшего элемента
    swaps++;
    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            swaps++;
            i++; // увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j], swaps);
            swaps++;
        }
    }
    swap(&arr[i + 1], &arr[high], swaps);
    return (i + 1);
}

// Основная функция, реализующая быструю сортировку
void quickSort(int arr[], int low, int high, int& swap) {
    if (low < high) {
        swap++;
        // pi - индекс, разделяющий массив на две части
        int pi = partition(arr, low, high, swap);

        // Рекурсивно сортируем элементы до и после разделяющего индекса
        quickSort(arr, low, pi - 1, swap);
        quickSort(arr, pi + 1, high, swap);
    }
    else{
        swap++;
    }
}


// Функция для получения максимального значения в массиве
int getMax(int arr[], int n, int& swap) {
    int max_val = arr[0];
    swap++;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            swap = swap + 2;
        }
        else{
            swap++;
        }
    }
    return max_val;
}

// Функция для выполнения сортировки подсчетом на основе значений разрядов
void countSort(int arr[], int n, int exp, int& swap) {
    int output[n]; // выходной массив
    int count[10] = {0}; // массив для подсчета цифр

    // Считаем количество появлений каждой цифры
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        swap = swap + 2;
    }

    // Изменяем count[i] так, чтобы он содержал позицию этой цифры в выходном массиве
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        swap++;
    }

    // Строим выходной массив
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        swap += 5;
    }

    // Копируем выходной массив обратно в arr, так что arr теперь содержит отсортированные числа по текущему разряду
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        swap++;
    }
}

// Основная функция для выполнения поразрядной сортировки
void radixSort(int arr[], int n, int& swap) {
    // Находим максимальное число, чтобы знать количество разрядов
    int m = getMax(arr, n, swap);
    swap++;
    // Выполняем сортировку для каждого разряда (единицы, десятки, сотни и т.д.)
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp, swap);
    }
}


// Функция для сортировки перемешиванием
void cocktailSort(int arr[], int n, int& swaps) {
    bool swapped = true;
    int start = 0;
    swaps++;
    int end = n - 1;
    swaps += 2;

    while (swapped) {
        // Сначала считаем, что обменов нет
        swapped = false;

        // Проходим слева направо как в сортировке пузырьком
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps += 3;
                swapped = true;
            }
            else{
                swaps++;
            }
        }

        // Если не было обменов, массив уже отсортирован
        if (!swapped) {
            break;
        }

        // Уменьшаем конец, потому что последний элемент уже на своем месте
        swapped = false;
        --end;
        swaps++;

        // Проходим справа налево, выполняя те же операции
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps += 3;
                swapped = true;
            }
        }

        // Увеличиваем начало, потому что первый элемент уже на своем месте
        ++start;
        swaps++;
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int* arr1;
    int* arr2;
    int* arr3;
    arr1 = new int[100];
    arr2 = new int[100];
    arr3 = new int[100];
    arr1[0] = 0;
    arr2[0] = 0;
    arr3[0] = 0;
    for (int x = 1; x < 100; x++) {
        int swaps1 = 0;
        int swaps2 = 0;
        int swaps3 = 0;
        int*array;
        array = new int[x];
        for (int y = 0; y < 100; y++) {
            srand(time(NULL));
            for (int i = 0; i < x; i++) {
                array[i] = rand();
            }
            int*array1;
            int*array2;
            array1 = new int[x];
            array2 = new int[x];
            for (int c = 0; c < x; c++){
                array1[c] = array[c];
                array2[c] = array[c];
            }
            quickSort(array, 0, x-1, swaps1);
            radixSort(array1, x, swaps2);
            cocktailSort(array2, x, swaps3);
            delete[] array1;
            delete[] array2;
        }
        arr1[x] = swaps1 / 100;
        arr2[x] = swaps2 / 100;
        arr3[x] = swaps3 / 100;
        delete[] array;
    }
    printArray(arr1, 100);
    printArray(arr2, 100);
    printArray(arr3, 100);
}