#include<iostream>
using namespace std;
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        cout<<"\nThis Queue is full";
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        cout<<"\nEnqued element: "<< val;
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"\nThis Queue is empty";
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
 
 
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = new int;
    
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    cout<<"\nDequeuing element :"<< dequeue(&q);
    cout<<"\nDequeuing element :"<< dequeue(&q);
    cout<<"\nDequeuing element :"<< dequeue(&q); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        cout<<"\nQueue is empty";
    }
    if(isFull(&q)){
        cout<<"\nQueue is full";
    }
 
    return 0;
}
