#include "Node.h"
#include <iostream>

Node::~Node()
{
	// ������� �� ��������� ������ �� ���� ������� � �� ����� �������� �� ���������
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
	return _next; // ���������� ��������� �������
}

Node* Node::Previous()
{
	return _prev; // ���������� �������� ����������� ��������
}

void Node::Add(int newValue)
{	
	_next = new Node(); // �������� ������ ��� ����� ������
	_next->_value = newValue; // ���������� �������� ��������� ����� � ��������� �������
	_next->_prev = this; // ������ ������� ������� ����� ���������		
}

void Node::Add()
{
	_next = new Node(); // �������� ������ ��� ����� ������
	_next->_prev = this; // ������ ������� ������� ����� ���������		 
}

int Node::GetValue()
{
	return _value; // ���������� �������� �����
}

void Node::SetValue(int newValue)
{
	_value = newValue; // ����� �������� �����
}