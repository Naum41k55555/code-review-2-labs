/* 
    Продолжение задания №2 файла реализации
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

using namespace std;

Queue::Queue() : head_ptr_(nullptr), tail_ptr_(nullptr) {}

Queue::~Queue() {
	while (!IsEmpty()) {
		Node* temp = head_ptr_;
		head_ptr_ = head_ptr_->next;
		delete temp;
	}
}

void Queue::Enqueue(int value) {
	Node* new_node = new Node(value);
	if (IsEmpty()) {
		head_ptr_ = new_node;
		tail_ptr_ = new_node;
	} else {
		tail_ptr_->next = new_node;
		tail_ptr_ = new_node;
	}
}

void Queue::Dequeue() {
	if (IsEmpty()) {
		cerr << "Ошибка: Попытка извлечь элемент из пустой очереди." << endl;
		return;
	}

	Node* temp = head_ptr_;
	head_ptr_ = head_ptr_->next;
	delete temp;

	if (head_ptr_ == nullptr) {
		tail_ptr_ = nullptr;
	}
}

bool Queue::IsEmpty() const {
	return head_ptr_ == nullptr;
}

const Node* Queue::GetHeadAddress() const {
	return head_ptr_;
}

const Node* Queue::GetTailAddress() const {
	return tail_ptr_;
}

void Queue::Display() const {
	if (IsEmpty()) {
		cout << "Очередь пуста.\n";
		return;
	}
	Node* current = head_ptr_;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
