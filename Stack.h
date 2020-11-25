#ifndef STACK
#define STACK

#include "Node.h"

// �����, � ������� ����������� ������� �����
class Stack
{
private:
	// ������ �������
	Node* _head;

	// ������� �������
	Node* _current;	
public:
	// � ������������ �������� ������ ��� _head & _current
	Stack();

	// ��������� ������� � ����
	void Push(int newValue);

	// ������� ��������� ������� �� ����� � ���������� ��� ��������
	int Pop();

	// ���������� �������� ���������� ��������
	int Back();

	// ���������� ������ �����
	int Size();	

	// ����� �����
	void PrintStack();
};

#endif
