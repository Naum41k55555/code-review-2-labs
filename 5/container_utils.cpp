/*
    Продолжение задания №5 заголовочный файл
    Элементами контейнеров являются целые числа. Для
    заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
    для вывода элементов использовать итератор (для вывода элементов в обратном порядке
    использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
    Обязательно наличие дружественного интерфейса. Ввод данных организовать 
    разными способами (с клавиатуры, рандом, из файла)

    Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее
    двух элементов, количество элементов является четным. Поменять значения двух средних
    элементов каждого из исходных контейнеров. Использовать алгоритм swap (не путать его с
    одноименной функцией-членом контейнера).
*/

#include "container_utils.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>

using namespace std;

template<typename Container>
void ContainerUtils::FillFromKeyboard(Container& container, size_t size) {
	cout << "Введите " << size << " целых чисел:" << endl;
	for (size_t i = 0; i < size; ++i) {
		int value;
		while (!(cin >> value)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "Ошибка! Введите целое число: ";
		}
		container.push_back(value);
	}
}

template<typename Container>
void ContainerUtils::FillWithRandom(Container& container, size_t size) {
	generate_n(back_inserter(container), size, []() {
		return rand() % 100;
	});
	cout << "Сгенерировано " << size << " случайных элементов." << endl;
}

template<typename Container>
bool ContainerUtils::FillFromFile(Container& container, size_t size) {
	string filename = "";
	cout << "Введите имя файла: ";
	cin >> filename;

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
		return false;
	}

	size_t count = 0;
	int value = 0;
	while (file >> value && count < size) {
		container.push_back(value);
		count++;
	}

	if (count < size) {
		cerr << "Ошибка: Файл содержит только " << count << " из " << size << " необходимых элементов." << endl;
		return false;
	}
	return true;
}

template<typename Container>
bool ContainerUtils::FillContainer(Container& container, size_t size, InputMethod method) {
	container.clear();
	if (size < 2 || size % 2 != 0) {
		cerr << "Ошибка: Размер должен быть четным и >= 2." << endl;
		return false;
	}

	switch (method) {
		case InputMethod::kKeyboard:
			FillFromKeyboard(container, size);
			return true;
		case InputMethod::kRandom:
			FillWithRandom(container, size);
			return true;
		case InputMethod::kFile:
			return FillFromFile(container, size);
		default:
			cerr << "Ошибка: Неизвестный метод ввода." << endl;
			return false;
	}
}

template<typename Container>
void ContainerUtils::PrintContainer(const Container& container) {
	copy(container.begin(), container.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<typename Container>
void ContainerUtils::PrintReversed(const Container& container) {
	copy(container.rbegin(), container.rend(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

template<typename Container>
void ContainerUtils::SwapMiddleElements(Container& container) {
	if (container.size() < 2 || container.size() % 2 != 0) {
		return;
	}
	auto mid1 = container.begin();
	advance(mid1, container.size() / 2 - 1);
	auto mid2 = next(mid1);
	iter_swap(mid1, mid2);
}

template bool ContainerUtils::FillContainer<vector<int>>(vector<int>&, size_t, InputMethod);
template bool ContainerUtils::FillContainer<deque<int>>(deque<int>&, size_t, InputMethod);
template bool ContainerUtils::FillContainer<list<int>>(list<int>&, size_t, InputMethod);

template void ContainerUtils::PrintContainer<vector<int>>(const vector<int>&);
template void ContainerUtils::PrintContainer<deque<int>>(const deque<int>&);
template void ContainerUtils::PrintContainer<list<int>>(const list<int>&);

template void ContainerUtils::PrintReversed<vector<int>>(const vector<int>&);
template void ContainerUtils::PrintReversed<deque<int>>(const deque<int>&);
template void ContainerUtils::PrintReversed<list<int>>(const list<int>&);

template void ContainerUtils::SwapMiddleElements<vector<int>>(vector<int>&);
template void ContainerUtils::SwapMiddleElements<deque<int>>(deque<int>&);
template void ContainerUtils::SwapMiddleElements<list<int>>(list<int>&);
