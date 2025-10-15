/* 
    Продолжение задания №2
    Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из
    исходного набора с нечетными номерами (1, 3, …, 9), а вторая — с четными (2, 4, …, 10);
    порядок чисел в каждой очереди должен совпадать с порядком чисел в исходном наборе.
    Вывести указатели на начало и конец первой, а затем второй очереди.

    Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
    добавления/удаления/вывода элементов. 
    Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

    В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
    узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
    очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
    последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
    удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
    пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
    значением элемента очереди считается значение его поля Data.
*/

#include "queue.h"

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

int main() {
	setlocale(LC_ALL, "Russian");

	Queue odd_queue = Queue();
	Queue even_queue = Queue();
	const int kTotalNumbers = 10;

	cout << "Введите " << kTotalNumbers << " чисел:\n";
	for (int i = 1; i <= kTotalNumbers; ++i) {
		string prompt = "Число " + to_string(i) + ": ";
		int number = GetInteger(prompt);

		if (i % 2 != 0) {
			odd_queue.Enqueue(number);
		} else {
			even_queue.Enqueue(number);
		}
	}

	cout << "\n--- Очередь с нечетными номерами ---\n";
	cout << "Содержимое: ";
	odd_queue.Display();
	cout << "Указатель на начало (head): " << odd_queue.GetHeadAddress() << endl;
	cout << "Указатель на конец (tail):   " << odd_queue.GetTailAddress() << endl;

	cout << "\n--- Очередь с четными номерами ---\n";
	cout << "Содержимое: ";
	even_queue.Display();
	cout << "Указатель на начало (head): " << even_queue.GetHeadAddress() << endl;
	cout << "Указатель на конец (tail):   " << even_queue.GetTailAddress() << endl;

	return 0;
}
