#include <iostream>
using namespace std;
 
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    cout<<"\nPrinting the elements of this linked list";
    while (ptr != NULL)
    {
        cout<<"\nElement: ", ptr->data;
        ptr = ptr->next;
    }
}
 
void enqueue(int val)
{
    struct Node *n = new struct Node;
    if(n==NULL){
        cout<<"\nQueue is Full";
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        cout<<"\nQueue is Empty";
    }
    else{
        f = f->next;
        val = ptr->data;
        delete(ptr);
    }
    return val;
}
 
int main()
{
    linkedListTraversal(f);
    cout<<"\nDequeuing element ", dequeue();
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    cout<<"\nDequeuing element ", dequeue();
    cout<<"\nDequeuing element ", dequeue();
    cout<<"\nDequeuing element ", dequeue();
    cout<<"\nDequeuing element ", dequeue();
    linkedListTraversal(f);
    return 0;
}
