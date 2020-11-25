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
	// ��������� ��� �������� ������ �� 1 � ����� ��������� ����� � ������
	while (_current->Next() != nullptr) // ��������� ��������� � ����� ������
	{
		_current = _current->Next();
	}
	_current->Add(_current->GetValue()); // ������ ����� �������
	_current = _current->Next(); // ��������� � �������, ������� ������ ��� �������
	while (_current != _head) // � ���������� �������� � �� ������ ���������� ��� ������� �������� �������� �������� ����� ���
	{
		_current->SetValue(_current->Previous()->GetValue()); // ���������� � ������� ������� �������� �������� ����� ���
		_current = _current->Previous();
	}
	_current->SetValue(newValue);
}

int Stack::Pop()
{
	int value = _head->GetValue(); // ��������� �������� ��������, ������� ����� ���������	
	_current = _head->Next();
	while (_current->Next() != nullptr) // ��������� ��������� � ����� ������, ����� �������� �������� �������� �� �������� ���������� ��������
	{
		_current->Previous()->SetValue(_current->GetValue());
		_current = _current->Next();
	}
	_current->~Node(); // ������� ��������� �������
	_current = _head; // ��������� ��������� �� ������
	return value; // ���������� �������� ��������, ������� �� ���������
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