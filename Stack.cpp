#include "Stack.h"
#include "Node.h"
#include <iostream>

Stack::Stack()
{
	_head = new Node();
	_current = _head;	
}

void Stack::Push(int newValue)
{
	// Переносим все элементы вправо на 1 и потом добавляем новый в начало
	while (_current->Next() != nullptr) // Переносим указатель в конец списка
	{
		_current = _current->Next();
	}
	_current->Add(_current->GetValue()); // Создаём новый элемент
	_current = _current->Next(); // Переходим в элемент, который только что создали
	while (_current != _head) // С последнего элемента и до головы записываем для каждого элемента значение элемента перед ним
	{
		_current->SetValue(_current->Previous()->GetValue()); // Записываем в текущий элемент значение элемента перед ним
		_current = _current->Previous();
	}
	_current->SetValue(newValue);
}

int Stack::Pop()
{
	int value = _head->GetValue(); // Сохраняем значение элемента, который будем сохранять	
	_current = _head->Next();
	while (_current->Next() != nullptr) // Переносим указатель в конец списка, меняя значение текущего элемента на значение следующего элемента
	{
		_current->Previous()->SetValue(_current->GetValue());
		_current = _current->Next();
	}
	_current->~Node(); // Удаляем последний элемент
	_current = _head; // Переносим указатель на голову
	return value; // Возвращаем значение элемента, которое мы сохранили
}

int Stack::Back()
{
	return _head->GetValue();
}

int Stack::Size()
{
	int size = 0;

	_current = _head;	
	while (_current->Next() != nullptr)
	{
		++size;
		_current = _current->Next();
	}
	return size;
}

void Stack::PrintStack()
{	
	int size = Size();	
	_current = _head;
	for (int i = 0; i < size; ++i)
	{
		std::cout << _current->GetValue() << '\t';
		_current = _current->Next();		
	}	
}