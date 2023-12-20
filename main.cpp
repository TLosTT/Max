#include <iostream>
using namespace std;

// Структура для хранения числа и его индекса
struct INumber {
    float value;
    int index;
};

// Функция для сравнения двух элементов типа INumber
int compare(const void *a, const void *b) {
    const INumber *numA = (const INumber *)a;
    const INumber *numB = (const INumber *)b;
    
    if (numA->value > numB->value) {
        return -1;
    } else if (numA->value < numB->value) {
        return 1;
    } else {
        // Если значения равны, сравниваем индексы
        if (numA->index < numB->index) {
            return -1;
        } else if (numA->index > numB->index) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main()
{   
    int n;
    cout << "Введите длину массива:";
    cin >> n;
    INumber numbers[n];
    cout << "Введите последовательность чисел:";
    for(int i=0; i < n; i++)
    {
        cin >> numbers[i].value; // Считываем значение числа
        numbers[i].index = i; // Присваиваем индекс числу
    }
    qsort(numbers, n, sizeof(INumber), compare); // Сортируем массив чисел с помощью функции qsort
    cout << "Максимальное значение массива №1: " << numbers[0].value << "  Индекс: " << numbers[0].index << "\n";
    cout << "Максимальное значение массива №2: " << numbers[1].value << "  Индекс: " << numbers[1].index << "\n";
}