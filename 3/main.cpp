/*
    Задача 3. Односвязный список (linked list)
    Дан текстовый файл, в первой строке которого хранится число N, а во второй
    строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
    поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
    нарушалась его упорядоченность.

    Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
    добавления/удаления/вывода элементов. 
    Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "linked_list.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Запрашивает у пользователя и валидирует непустую строку.
 * @param prompt Сообщение для пользователя.
 * @return Введенная пользователем непустая строка.
 */
string GetString(const string& prompt) {
	string value = "";
	while (true) {
		cout << prompt;
		getline(cin, value);
		if (!value.empty()) {
			return value;
		}
		cout << "Ошибка! Ввод не может быть пустым." << endl;
	}
}

/**
 * @brief Загружает данные из файла в упорядоченный список.
 * @param filename Имя файла для чтения.
 * @param list Ссылка на список, который будет заполнен.
 * @return `true` в случае успеха, `false` при любой ошибке.
 */
bool LoadListFromFile(const string& filename, LinkedList& list) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Ошибка: Не удалось открыть файл \"" << filename << "\"." << endl;
		return false;
	}

	int n = 0;
	file >> n;
	if (file.fail() || n < 0) {
		cerr << "Ошибка: Некорректное значение количества элементов в файле." << endl;
		return false;
	}

	list.Clear();
	for (int i = 0; i < n; ++i) {
		int value = 0;
		file >> value;
		if (file.fail()) {
			cerr << "Ошибка: Не удалось прочитать элемент №" << i + 1 << "." << endl;
			list.Clear();
			return false;
		}
		list.InsertSorted(value);
	}

	cout << "Данные из файла \"" << filename << "\" успешно загружены." << endl;
	return true;
}

/**
 * @brief Сохраняет данные из списка в файл.
 * @param filename Имя файла для записи.
 * @param list Константная ссылка на список для сохранения.
 * @return `true` в случае успеха, `false` при ошибке.
 */
bool SaveListToFile(const string& filename, const LinkedList& list) {
	ofstream file(filename);
	if (!file.is_open()) {
		cerr << "Ошибка: Не удалось создать или открыть файл \"" << filename << "\" для записи." << endl;
		return false;
	}

	int count = 0;
	const Node* current = list.GetHead();
	while (current != nullptr) {
		count++;
		current = current->next;
	}

	file << count << "\n";

	current = list.GetHead();
	while (current != nullptr) {
		file << current->data << " ";
		current = current->next;
	}

	cout << "Данные успешно сохранены в файл \"" << filename << "\"." << endl;
	return true;
}

int main() {
	setlocale(LC_ALL, "Russian");
	LinkedList sorted_list = LinkedList();

	string input_filename = GetString("Введите имя файла для чтения: ");
	if (!LoadListFromFile(input_filename, sorted_list)) {
		return 1;
	}

	cout << "\nИтоговый упорядоченный список:" << endl;
	sorted_list.Display();

	cout << "\n--- Сохранение списка в файл ---" << endl;
	string output_filename = GetString("Введите имя файла для сохранения: ");
	if (!SaveListToFile(output_filename, sorted_list)) {
		return 1;
	}

	return 0;
}
