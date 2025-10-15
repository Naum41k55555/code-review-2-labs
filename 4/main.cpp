/*
    Задачние №4
    Дан двусвязный линейный список и указатель первый элемент этого 
    списка. Все элементы списка хранят различные между собой значения. Необходимо 
    вывести значения элементов списка, которые находятся между наименьшим и 
    наибольшим элементами списка, в том порядке, в каком они находятся в исходном 
    списке. Использовать процедуры. 

    Все динамические структуры данных реализовывать через классы. Не использовать STL.  
    Для каждой динамической структуры должен быть предусмотрен
    стандартный набор методов - добавления/удаления/вывода элементов. 
    Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "doubly_linked_list.h"

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Запрашивает у пользователя и валидирует ввод целого числа.
 * @param prompt Сообщение для пользователя.
 * @return Введенное пользователем целочисленное значение.
 */
int GetInteger(const string& prompt) {
	int value = 0;
	while (true) {
		cout << prompt;
		cin >> value;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка! Введите целое число.\n";
		} else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

/**
 * @brief Запрашивает у пользователя и валидирует ввод положительного целого числа.
 * @param prompt Сообщение для пользователя.
 * @return Введенное пользователем положительное целое число.
 */
int GetPositiveInteger(const string& prompt) {
	int value = 0;
	while (true) {
		value = GetInteger(prompt);
		if (value > 0) {
			return value;
		}
		cout << "Ошибка! Число должно быть положительным.\n";
	}
}

/**
 * @brief Находит и выводит элементы списка между минимальным и максимальным значениями.
 * @param list Константная ссылка на двусвязный список для обработки.
 */
void ProcessAndPrintBetweenExtremes(const DoublyLinkedList& list) {
	if (list.IsEmpty() || list.GetHead()->next == nullptr) {
		cout << "В списке недостаточно элементов для поиска." << endl;
		return;
	}

	const Node* min_node = list.GetHead();
	const Node* max_node = list.GetHead();

	for (const Node* current = list.GetHead()->next; current != nullptr; current = current->next) {
		if (current->data < min_node->data) {
			min_node = current;
		}
		if (current->data > max_node->data) {
			max_node = current;
		}
	}

	const Node* start_node = nullptr;
	const Node* end_node = nullptr;
	for (const Node* current = list.GetHead(); current != nullptr; current = current->next) {
		if (current == min_node) {
			start_node = min_node;
			end_node = max_node;
			break;
		}
		if (current == max_node) {
			start_node = max_node;
			end_node = min_node;
			break;
		}
	}

	cout << "\nЭлементы между " << min_node->data << " и " << max_node->data << ": ";
	if (start_node->next == end_node || start_node == end_node) {
		cout << "отсутствуют." << endl;
	} else {
		for (const Node* current = start_node->next; current != end_node; current = current->next) {
			cout << current->data << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	DoublyLinkedList data_list;

	int count = GetPositiveInteger("Введите количество элементов: ");

	cout << "Введите " << count << " целых чисел:" << endl;
	for (int i = 0; i < count; ++i) {
		string prompt = to_string(i + 1) + "-й элемент: ";
		int value = GetInteger(prompt);
		data_list.Append(value);
	}

	cout << "\nИсходный список: ";
	data_list.Display();

	ProcessAndPrintBetweenExtremes(data_list);

	return 0;
}

