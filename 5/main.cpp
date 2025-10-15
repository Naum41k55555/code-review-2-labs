/*  
    Задание №5
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

#include <iostream>
#include <limits>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief Запрашивает у пользователя и валидирует ввод размера контейнера.
 * @return Корректный размер (четное число >= 2).
 */
size_t GetEvenSize() {
	size_t size = 0;
	while (true) {
		cout << "\nВведите размер контейнера (четное число >= 2): ";
		if (!(cin >> size) || size < 2 || size % 2 != 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "Ошибка! Размер должен быть четным числом, не меньше 2." << endl;
			continue;
		}
		return size;
	}
}

/**
 * @brief Отображает меню и запрашивает у пользователя метод ввода данных.
 * @return Выбранный метод ввода из перечисления InputMethod.
 */
ContainerUtils::InputMethod GetInputMethod() {
	int choice = 0;
	while (true) {
		cout << "\nВыберите способ ввода данных:\n"
			<< "1. С клавиатуры\n"
			<< "2. Случайными числами\n"
			<< "3. Из файла\n"
			<< "Ваш выбор: ";
		if (!(cin >> choice) || choice < 1 || choice > 3) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "Ошибка! Введите число от 1 до 3." << endl;
			continue;
		}
		return static_cast<ContainerUtils::InputMethod>(choice);
	}
}

/**
 * @brief Обобщенная функция для полной обработки одного типа контейнера.
 * @tparam Container Тип контейнера (vector, deque или list).
 * @param container_name Строковое имя контейнера для вывода в консоль.
 */
template<typename Container>
void ProcessContainer(const string& container_name) {
	cout << "\n--- Обработка " << container_name << " ---";

	size_t size = GetEvenSize();
	ContainerUtils::InputMethod method = GetInputMethod();

	Container container;
	if (!ContainerUtils::FillContainer(container, size, method)) {
		cerr << "Не удалось заполнить контейнер." << endl;
		return;
	}

	cout << "\nИсходное содержимое:\n";
	ContainerUtils::PrintContainer(container);

	cout << "Содержимое в обратном порядке:\n";
	ContainerUtils::PrintReversed(container);

	ContainerUtils::SwapMiddleElements(container);
	cout << "После обмена средних элементов:\n";
	ContainerUtils::PrintContainer(container);
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned>(time(nullptr)));

	ProcessContainer<vector<int>>("std::vector");
	ProcessContainer<deque<int>>("std::deque");
	ProcessContainer<list<int>>("std::list");

	cout << "\nПрограмма успешно завершена." << endl;
	return 0;
}
