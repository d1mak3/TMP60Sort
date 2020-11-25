#ifndef STACK
#define STACK

#include "Node.h"

// Класс, в котором реализуются фукнции стека
class Stack
{
private:
	// Голова очереди
	Node* _head;

	// Текущий элемент
	Node* _current;	
public:
	// В конструкторе выделяем память под _head & _current
	Stack();

	// Добавляем элемент в стек
	void Push(int newValue);

	// Убираем последний элемент из стека и возвращаем его значение
	int Pop();

	// Возвращаем значение последнего элемента
	int Back();

	// Возвращаем размер стека
	int Size();	

	// Вывод стека
	void PrintStack();
};

#endif
