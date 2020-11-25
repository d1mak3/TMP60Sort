#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <ctime> // Для рандома

using namespace std;

Stack SortStack(Stack stackToSort)
{    
    Stack finalStack;
    Stack temp;
    int defaultstacksize = stackToSort.Size();
    finalStack.Push(stackToSort.Pop());
    for (int i = 1; i < defaultstacksize; ++i)
    {
        while (stackToSort.Back() > finalStack.Back() && finalStack.Size() != 0)
        {
            int num = finalStack.Pop();
            temp.Push(num);             
        }
        finalStack.Push(stackToSort.Pop());
        int tempsize = temp.Size();        
        for (int j = 0; j < tempsize; ++j)
        {
            finalStack.Push(temp.Pop());
        }
    }
    
    return finalStack;    
}

int main()
{        
    setlocale(0, "");
    Stack stackToSort;    
    cout << "Введите количество чисел\n";
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        stackToSort.Push(rand());
    }
    stackToSort = SortStack(stackToSort);
    stackToSort.PrintStack();
}