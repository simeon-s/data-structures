#include <iostream>


struct TreeNode
{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} *root = NULL;

struct QueueNode
{
    struct TreeNode* data;
    struct QueueNode* next;
} *first = NULL, *rear = NULL;

using namespace std;

void enqueue(struct TreeNode* x)
{
    if(first == NULL)
    {
        first = new QueueNode;
        first->data = x;
        first->next = NULL;
        rear = first;
    }
    else
    {
        QueueNode *t = new QueueNode;
        t->data = x;
        t->next = NULL;
        rear->next = t;
        rear = t;
    }
}



struct TreeNode* dequeue()
{
    QueueNode *t = first;
    first = first->next;
    struct TreeNode *tempData;
    tempData = t->data;
    delete t;
    return tempData;

}

int isEmpty()
{
    if(first == NULL)
        return 1;
    else
        return 0;
}

void treeCreate()
{
    int x;
    cout << "Enter root value " << endl;
    cin >> x;
    root = new TreeNode;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    enqueue(root);
    while(!isEmpty())
    {
        struct TreeNode* p = dequeue();
        cout << "Enter the value of lchild of " << p->data <<  endl;
        cin >> x;
        if(x != -1)
        {
            TreeNode* t;
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        cout << "Enter the value of rchild of " << p->data <<  endl;
        cin >> x;
        if(x != -1)
        {
            TreeNode* t;
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }

    }
}

void traverseTree(struct TreeNode *p)
{
    if(p)
    {
        traverseTree(p->lchild);
        cout << p->data << " ";
        traverseTree(p->rchild);
    }
}



int main()
{
    treeCreate();
    traverseTree(root);
}
