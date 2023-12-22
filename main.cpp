#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Структура для хранения числа и его индекса
struct INumber {
    double value;
    int index;
};

// Функция для сравнения двух элементов типа INumber
bool compare(const INumber &a, const INumber &b) {
    if (a.value != b.value) {
        return a.value > b.value; // Сортировка по убыванию значения
    } else {
        return a.index < b.index; // Если значения равны, то сортировка по возрастанию индекса
    }
}

int main() {
    int n;
    cout << "Введите длину массива:";
    cin >> n;

    if (n < 1) {
        cout << "Массив пуст." << endl;
        return 0;
    }

    vector<INumber> numbers(n); // Использован vector (вместо него могло быть создание динамического массива)

    cout << "Введите последовательность чисел:";
    for(int i=0; i < n; i++) {
        cin >> numbers[i].value;
        numbers[i].index = i;
    }

    sort(numbers.begin(), numbers.end(), compare); // Сортировка вектора по заданным критериям

    cout << "Максимальное значение массива №1: " << numbers[0].value << "  Индекс: " << numbers[0].index << "\n";

    if (n > 1) {
        cout << "Максимальное значение массива №2: " << numbers[1].value << "  Индекс: " << numbers[1].index << "\n";
    }

    // Нет необходимости освобождать память, так как это делается автоматически при уничтожении вектора
}