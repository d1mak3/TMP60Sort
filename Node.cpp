#include "Node.h"
#include <iostream>

Node::~Node()
{
	// Убираем из элементов ссылки на этот элемент и из этого элемента на остальные
	if (this->_next == nullptr)
	{
		_prev->_next = nullptr;
	}
	else
	{
		_prev->_next = this->_next;
		this->_next->_prev = _prev;
		delete _prev;
		delete _next;
	}
}

Node* Node::Next()
{	
	return _next; // Возвращаем следующий элемент
}

Node* Node::Previous()
{
	return _prev; // Возвращаем значение предыдущего элемента
}

void Node::Add(int newValue)
{	
	_next = new Node(); // Выделяем память под новую ячейку
	_next->_value = newValue; // Записываем значение вводимого числа в следующий элемент
	_next->_prev = this; // Ставим текущий элемент перед следующим		
}

void Node::Add()
{
	_next = new Node(); // Выделяем память под новую ячейку
	_next->_prev = this; // Ставим текущий элемент перед следующим		 
}

int Node::GetValue()
{
	return _value; // Возвращаем значение числа
}

void Node::SetValue(int newValue)
{
	_value = newValue; // Задаём значение числа
}