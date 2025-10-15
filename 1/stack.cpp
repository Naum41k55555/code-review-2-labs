/*
    Продолжение задачи №1 стека (stack) файл реализации
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

Stack::Stack() : top_ptr_(nullptr) {}

Stack::~Stack() {
	while (!IsEmpty()) {
		Node* temp = top_ptr_;
		top_ptr_ = top_ptr_->next;
		delete temp;
	}
}

void Stack::Push(int value) {
	Node* new_node = new Node(value);
	new_node->next = top_ptr_;
	top_ptr_ = new_node;
}

void Stack::Pop() {
	if (IsEmpty()) {
		cerr << "Ошибка: Попытка извлечь элемент из пустого стека." << endl;
		return;
	}

	Node* temp = top_ptr_;
	top_ptr_ = top_ptr_->next;
	delete temp;
}

int Stack::Top() const {
	if (IsEmpty()) {
		cerr << "Ошибка: Попытка прочитать элемент из пустого стека." << endl;
		return 0;
	}
	return top_ptr_->data;
}

bool Stack::IsEmpty() const {
	return top_ptr_ == nullptr;
}

const Node* Stack::GetTopAddress() const {
	return top_ptr_;
}

void Stack::Display() const {
	if (IsEmpty()) {
		cout << "Стек пуст.\n";
		return;
	}
	Node* current = top_ptr_;
	cout << "Элементы стека: ";
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
