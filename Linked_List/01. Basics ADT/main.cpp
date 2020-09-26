#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node* next;
} *first = NULL;


void create(int* arr, int sizeOfArray)
{
    Node *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < sizeOfArray; i++)
    {
        Node *t = (struct Node*)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node*p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void reverse_display_linked_list(struct Node*p)
{
    if(p!=NULL)
    {
        reverse_display_linked_list(p->next);
        cout << p->data << " ";
    }
}

int linked_list_count(struct Node*p)
{
    int counter = 0;
    if(p==NULL)
    {
        cout << "The linked list is empty. " << endl;

    }
    else
    {
        while(p!=NULL)
        {
            p = p->next;
            counter++;
        }
        cout << "The number of elements in the linked list is: " << counter << endl;
    }

    return counter;
}


int main()
{
    int A[] = {1,2,3,4,5};
    int arraySize = sizeof(A)/sizeof(A[0]);
    create(A,arraySize);
    display(first);
    cout << endl;
    reverse_display_linked_list(first);
    cout << endl;
    linked_list_count(first);
}
