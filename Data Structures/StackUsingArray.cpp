#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

bool isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return true;
    }
    return false;
}

bool isFull(struct stack *s)
{
    if(s->top==s->size-1)
    {
        return true;
    }
    return false;
}

void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        cout<<"\nstack is full";//stack overflow
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

void pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"\nstack underflow";
    }
    else
    {
        cout<<"\nPoped element is : "<<ptr->arr[ptr->top];
        ptr->top--;
    }
}

void peek(struct stack* ptr, int i)
{
    int index=ptr->top -i +1;
    if(index<0)
    {
        cout<<"\nNot a valid posotion for stack";
    }
    else
    {
        cout<<"\n"<<ptr->arr[index];
    }
}

int main()
{
    // struct stack s;
    // s.size=10;
    // s.top=-1;
    // s.arr=new int;
    // OR use below code
    struct stack *s;
    s=new struct stack;
    s->size=10;
    s->top=-1;
    s->arr=new int;
    
    push(s,32);
    push(s,31);
    push(s,100);
    push(s,300);
    cout<<s->arr[0];
    
    pop(s);
    
    peek(s,1);                      //indexes:  0    1    2    3
                                    //peek:     4    3    2    1
    return 0;
}

