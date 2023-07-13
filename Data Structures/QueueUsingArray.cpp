#include <iostream>
using namespace std;
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        cout<<"This Queue is full\n";
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        cout<<"Enqued element: "<< val<<"\n";
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"This Queue is empty\n";
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = new int;
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    cout<<"Dequeuing element :"<< dequeue(&q)<<"\n";
    cout<<"Dequeuing element :"<< dequeue(&q)<<"\n";
    cout<<"Dequeuing element :"<< dequeue(&q)<<"\n"; 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        cout<<"Queue is empty\n";
    }
    if(isFull(&q)){
        cout<<"Queue is full\n";
    }
 
    return 0;
}
