#include <iostream>
using namespace std;
//узел стека
struct Node {
	int data;
	Node* prev;
	//конструктор узла стека
	Node(int value) : data(value), prev(nullptr) {};
};
struct Stack {
	Node* root;
	Node* tail;
	Stack() : root(nullptr), tail(nullptr) {
		cout << "стек создан" << endl;
	}
	//метод проверка пуст ли стек
	bool Empty() {
		return tail == nullptr;
	}
	//метод добавления узла
	void Push(int value) {
		Node* elem = new Node(value);
		if (Empty()) {
			root = elem;
			tail = elem;
		}
		else {			
			elem->prev = tail;
			tail = elem;
		}
	}
	//в обратном порядке
	void PrintStackReverse() {	
		Node* p = tail;
		while (p != nullptr) {
			cout << p->data << endl;
			p = p->prev;
		}
	}
	//в порядке добавления
	void PrintStack() {
		f(tail);
		cout << endl;
	}
	void f(Node* p) {
		if (p != root) {
			f(p->prev);
		}
		cout << p->data << "\n";
		if (p == root) {
			return;
		}	
	}
	//извлечение верхнего элемента (удаление)
	int pop() {
		try
		{
			if (Empty()) throw exception("стек пуст");
			int tmp_data = tail->data;
			Node* tmp_ptr = tail;
			tail = tail->prev;
			delete tmp_ptr;
			return tmp_data;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
		return -1;
	}
	//обращение к верхнему элементу 
	int pop() {
		try
		{
			if (Empty()) throw exception("стек пуст");
			return tail->data;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
		return -1;
	}
	peek() {

	 }
};

int main()
{
	setlocale(LC_ALL, "rus");
	Stack mystack;
	mystack.pop();
	mystack.Push(5);
	mystack.Push(15);
	mystack.Push(3);
	mystack.Push(8);
	mystack.Push(76);
	mystack.Push(1);
	mystack.Push(-9);
	mystack.Push(9);
	mystack.PrintStackReverse();
	cout << "в порядке добавления:" << endl;
	mystack.PrintStack();
	
	cout << "удаляем число " << mystack.pop() << endl;
	cout << "удаляем число " << mystack.pop() << endl;
	mystack.PrintStackReverse();
	return 0;
}