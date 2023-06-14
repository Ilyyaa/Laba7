// Laba7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& v, int l, int r);
int findOrderStatistic(vector<int>& array, int k);
void swap(vector<int>& v, int i, int j);
int main()
{
    vector<int> a = { 5,4,2,3,1 }; int k = 2;
    std::cout << k << " element = " << findOrderStatistic(a, k) << std::endl;
}

int findOrderStatistic(vector<int>& array, int k) {
    int left = 0, right = array.size(); k -= 1;
    while (true) {
        int mid = partition(array, left, right);
        if (mid == k) {
            return array[mid];
        }
        else if (k < mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
}

void swap(vector<int>& v, int i, int j)
    {
        int temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

int partition(vector<int>& v, int l, int r)
{
    int i, last;
    swap(v, l, (l+r)/2);
    last = l;
    for (i = l+1; i < r-l; i++) {
        if (v[i] < v[l]) {
            swap(v, ++last, i);
        }

    }
    swap(v, l, last);
    return last;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Выбираем опорный элемент
    int i = low;  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;  // Увеличиваем индекс меньшего элемента
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

#include <iostream>
#include <algorithm>
using namespace std;

// Функция для обмена элементов
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция разбиения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Выбираем опорный элемент
    int i = low;  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;  // Увеличиваем индекс меньшего элемента
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Функция поиска порядковой статистики с использованием алгоритма QuickSelect
int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) {  // Базовый случай - массив из одного элемента
        return arr[low];
    }

    // Разбиение массива
    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {  // Порядковая статистика найдена
        return arr[pivotIndex];
    } else if (k < pivotIndex) {  // Искомый элемент находится в левой части
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {  // Искомый элемент находится в правой части
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

// Функция поиска порядковой статистики
int findOrderStatistic(int arr[], int n, int k) {
    if (k > 0 && k <= n) {
        return quickSelect(arr, 0, n - 1, k - 1);
    }
    return -1;  // Некорректное значение k
}

// Тестирование функции
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl
