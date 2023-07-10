#include <iostream>
using namespace std;
 
struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr,char val)
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
        ptr->top--;
    }
}
 
int parenthesisMatch(string exp){
    // Create and initialize the stack
    struct stack* sp = new stack;
    sp->size = exp.length();
    sp->top = -1;
    sp->arr = new char;
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main()
{
    string exp = "8)*(9)";
    if(parenthesisMatch(exp)){
        cout<<"The parenthesis is matching";
    }
    else{
        cout<<"The parenthesis is not matching";
    }
    return 0;
}
