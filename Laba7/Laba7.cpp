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