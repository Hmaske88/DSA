#include <iostream>
using namespace std;
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}
 
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

char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"\nstack underflow";
        return -1;
    }
    else
    {
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}


int isOperator(char ch)
{
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}


char* infixToPostfix(string infix)
{
    struct stack * sp = new struct stack;
    sp->size = 10; 
    sp->top = -1;
    sp->arr = new char[sp->size];
    char * postfix = new char[sp->size];
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


int main()
{
    string infix = "x-y/z-k*d";
    cout<<"postfix is "<< infixToPostfix(infix);
    return 0;
}
