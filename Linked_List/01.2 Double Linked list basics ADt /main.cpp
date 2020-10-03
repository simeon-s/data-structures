#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* previous;
    struct Node* next;
} *first = NULL, *last = NULL;

void create(int *a, int arraySize)
{
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    first->previous = NULL;
    last = first;
    for(int i = 1; i<arraySize; i++)
    {
        Node *t = new Node;
        t->data = a[i];
        t->next = NULL;
        t->previous = last;
        last->next = t;
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
}

void remove(int key, struct Node*p)
{
    while(p->data!=key && p!=NULL)
    {
         p = p->next;
    }
   Node *t = p;
   Node*prev =  p->previous;
   prev->next = p->next;
   delete p;

}

int main()
{
 int A[] = {7,4,6,3};
 int key = 4;
 int arraySize = sizeof(A)/sizeof(A[0]);
 create(A, arraySize);
 display(first);
 cout << endl;
 remove(key,first);
 display(first);
}
