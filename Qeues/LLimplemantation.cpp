#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

class qeue
{
public:
    Node *start = NULL;
    Node *end = NULL;
    int size = 0;

    // Methods
//! T.C O(1) S.C dynamic space
    void push(int x)
    {
        Node *temp = new Node(x);

        if (size == 0)
        {
            start = temp;
            end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        size++;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "qeue is empty";
            return;
        }
        Node *temp = start;
        if (size == 1)
        {
            start = NULL;
            end = NULL;
            delete temp;
        }
        else
        {
            start = start->next;
            delete temp;
        }
        size--;
        return;
    }

    int top()
    {
        if (size == 0)
        {
            cout << "queue is empty";
            return;
        }

        return start->data;
    }

    int size()
    {
        return size;
    }
};
