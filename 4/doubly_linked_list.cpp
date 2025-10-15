/*
    Продолжение задания 4 файл реализации
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

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head_ptr_(nullptr), tail_ptr_(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
	Clear();
}

void DoublyLinkedList::Append(int value) {
	Node* new_node = new Node(value);
	if (IsEmpty()) {
		head_ptr_ = new_node;
		tail_ptr_ = new_node;
	} else {
		tail_ptr_->next = new_node;
		new_node->prev = tail_ptr_;
		tail_ptr_ = new_node;
	}
}

bool DoublyLinkedList::IsEmpty() const {
	return head_ptr_ == nullptr;
}

void DoublyLinkedList::Clear() {
	while (head_ptr_ != nullptr) {
		Node* temp = head_ptr_;
		head_ptr_ = head_ptr_->next;
		delete temp;
	}
	tail_ptr_ = nullptr;
}

const Node* DoublyLinkedList::GetHead() const {
	return head_ptr_;
}

void DoublyLinkedList::Display() const {
	if (IsEmpty()) {
		cout << "Список пуст." << endl;
		return;
	}
	const Node* current = head_ptr_;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
