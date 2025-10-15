/* 
    Продолжение задания №3 файл реализации
    Дан текстовый файл, в первой строке которого хранится число N, а во второй
    строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
    поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
    нарушалась его упорядоченность.

    Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
    добавления/удаления/вывода элементов. 
    Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "linked_list.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList() : head_ptr_(nullptr) {}

LinkedList::~LinkedList() {
	Clear();
}

void LinkedList::InsertSorted(int value) {
	Node* new_node = new Node(value);

	if (IsEmpty() || value > head_ptr_->data) {
		new_node->next = head_ptr_;
		head_ptr_ = new_node;
		return;
	}

	Node* current = head_ptr_;
	while (current->next != nullptr && current->next->data > value) {
		current = current->next;
	}

	new_node->next = current->next;
	current->next = new_node;
}

bool LinkedList::DeleteValue(int value) {
	if (IsEmpty()) {
		return false;
	}

	if (head_ptr_->data == value) {
		Node* temp = head_ptr_;
		head_ptr_ = head_ptr_->next;
		delete temp;
		return true;
	}

	Node* current = head_ptr_;
	while (current->next != nullptr && current->next->data != value) {
		current = current->next;
	}

	if (current->next == nullptr) {
		return false;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	return true;
}

bool LinkedList::IsEmpty() const {
	return head_ptr_ == nullptr;
}

void LinkedList::Clear() {
	while (head_ptr_ != nullptr) {
		Node* temp = head_ptr_;
		head_ptr_ = head_ptr_->next;
		delete temp;
	}
}

void LinkedList::Display() const {
	if (IsEmpty()) {
		cout << "Список пуст." << endl;
		return;
	}
	Node* current = head_ptr_;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

const Node* LinkedList::GetHead() const {
	return head_ptr_;
}
