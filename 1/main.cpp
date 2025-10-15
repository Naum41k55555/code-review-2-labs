/*
    Задача 1. Стек (stack)
    Дано число D и указатель P1 на вершину непустого стека. 
    Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

    Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
    добавления/удаления/вывода элементов. 
    Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

    В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
    узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
    стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
    его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
    элемента стека считается значение его поля Data
*/

#include "stack.h"

#include <iostream>

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
 * @brief Обрабатывает логику добавления нового элемента в стек.
 * @details Запрашивает у пользователя число, добавляет его в стек и выводит
 *          адрес новой вершины.
 * @param data_stack Ссылка на стек для модификации.
 */
void HandleAddElement(Stack& data_stack) {
	int value = GetInteger("Введите число для добавления в стек: ");
	data_stack.Push(value);
	cout << "Элемент " << value << " добавлен." << endl;
	const Node* p2 = data_stack.GetTopAddress();
	cout << "Адрес новой вершины стека (P2): " << p2 << endl;
}

/**
 * @brief Обрабатывает логику удаления элемента с вершины стека.
 * @details Перед удалением сообщает, какой элемент будет удален, если стек не пуст.
 * @param data_stack Ссылка на стек для модификации.
 */
void HandleRemoveElement(Stack& data_stack) {
	if (!data_stack.IsEmpty()) {
		cout << "Элемент " << data_stack.Top() << " удален." << endl;
		data_stack.Pop();
	} else {
		// Вызываем Pop на пустом стеке, чтобы он вывел свое сообщение об ошибке
		data_stack.Pop();
	}
}


/**
 * @brief Отображает главное меню программы.
 */
void ShowMenu() {
	cout << "\nМеню:\n"
		<< "1. Добавить элемент в стек\n"
		<< "2. Удалить элемент из стека\n"
		<< "3. Показать содержимое стека\n"
		<< "4. Выйти\n"
		<< "Введите ваш выбор: ";
}

int main() {
	setlocale(LC_ALL, "Russian");

	Stack data_stack = Stack();
	int choice = 0;

	while (true) {
		ShowMenu();
		choice = GetInteger("");

		switch (choice) {
			case 1: {
				HandleAddElement(data_stack);
				break;
			}
			case 2: {
				HandleRemoveElement(data_stack);
				break;
			}
			case 3: {
				data_stack.Display();
				break;
			}
			case 4: {
				cout << "Выход из программы." << endl;
				return 0;
			}
			default: {
				cout << "Неверный выбор! Пожалуйста, попробуйте снова." << endl;
				break;
			}
		}
	}

	return 0;
}
