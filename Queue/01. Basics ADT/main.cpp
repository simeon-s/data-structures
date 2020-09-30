#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}
*front = NULL,
*rear = NULL,
*last = NULL;

void enqueue(int x)
{
    Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(!t)
    {
        cout << "The heap is full." << endl;
        return;
    }
    if(front == NULL)
    {
        front = new Node;
        front-> data = t->data;
        front-> next = NULL;
        last = front;

    }
    else
    {
        last -> next = t;
        last = t;
    }

}

void display(struct Node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void dequeue(int n)
{
    for(int i =0;i<n; i++)
    {
        Node *t = (struct Node*)malloc(sizeof(struct Node));
        t = front;
        front = front->next;
        delete t;
    }
}

void replace_x(int key, int newVal, struct Node *p)
{
    if(p->data == key)
        p->data = newVal;
    else
    {
        while(p->data != key)
        {
            p = p->next;
        }
        if(p->data == key)
            p->data = newVal;
        else
            cout << "The key is not found" << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    replace_x(10,8,front);
    display(front);
    dequeue(1);
    display(front);
}
