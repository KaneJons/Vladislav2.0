#include <iostream>
#include <cmath>
using namespace std;

// Проверка, является ли число простым
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= static_cast<int>(std::sqrt(num)); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Поиск индекса максимального элемента
int findMaxIndex(const int* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Удаление элемента из динамического массива
void removeElement(int*& arr, int& size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
        int* newArr = new int[size];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
}

// Вычисление среднего арифметического
double calculateAverage(const int* arr, int size) {
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// Удаление простых чисел после максимального элемента
void removePrimesAfterMax(int*& arr, int& size) {
    int maxIndex = findMaxIndex(arr, size);
    for (int i = size - 1; i > maxIndex; --i) {
        if (isPrime(arr[i])) {
            removeElement(arr, size, i);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int k;

    // Ввод размера массива
    cout << "Введите размер массива: ";
    cin >> k;

    // Выделение памяти для массива
    int* X = new int[k];

    // Ввод элементов массива
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < k; ++i) {
        cin >> X[i];
    }

    // Вычисление среднего арифметического до удаления
    double averageBefore = calculateAverage(X, k);
    cout << "Среднее арифметическое до удаления: " << averageBefore << "\n";

    // Удаление простых чисел после максимального элемента
    removePrimesAfterMax(X, k);

    // Вычисление среднего арифметического после удаления
    double averageAfter = calculateAverage(X, k);
    cout << "Среднее арифметическое после удаления: " << averageAfter << "\n";

    // Вывод итогового массива
    cout << "Массив после удаления: ";
    for (int i = 0; i < k; ++i) {
        cout << X[i] << " ";
    }
    cout << "\n";

    // Очистка памяти
    delete[] X;

    return 0;
}
