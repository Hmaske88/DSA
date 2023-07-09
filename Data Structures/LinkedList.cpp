#include <iostream>
using namespace std;


struct node
{
    int data;
    struct node *next;
};


void linkedListTraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data;
        cout<<"\n";
        ptr=ptr->next;
    }
    cout<<"\n";
}


struct node* insertAtBegin(struct node* head, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}


struct node* insertAtIndex(struct node* head, int data, int index)
{
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    struct node* p=head;
    
    int i= 0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    
    return head;
    
}


struct node* insertAtEnd(struct node* head, int data)
{
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    
    while(p->next!=NULL)
    {
        p=p->next;
    }
    
    ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;
    
    return head;
}


struct node* insertAfterNode(struct node* head, struct node* prevNode, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    
    return head;
}


struct node* deleteFirst(struct node* head)
{
    struct node* ptr = head;
    head=ptr->next;
    
    delete(ptr);
    // OR use below code for above
    // free(ptr);
    
    return head;
}


struct node* deleteAtIndex(struct node* head, int index)
{
    struct node* ptr=head;
    int i=0;
    while(i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    
    struct node* q=ptr->next;
    ptr->next=q->next;
    free(q);
    
    return head;
}


struct node* deleteAtEnd(struct node* head)
{
    struct node* p=head;
    struct node* q=head->next;
    
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    
    p->next=NULL;
    free(q);
    return head;
}


struct node* deleteValue(struct node* head, int value)
{
    struct node* ptr=head->next;
    struct node* prevNode=head;
    while(ptr->data!=value && ptr->next!=NULL)
    {
        ptr=ptr->next;
        prevNode=prevNode->next;
    }
    
    if(ptr->data==value)
    {
        prevNode->next=ptr->next;
        free(ptr);
    }
    
    return head;
}


int main()
{
    struct node *head;
    struct node *second;
    
    head=new struct node;
    second=new struct node;
    // OR use below code for above
    // head=(struct node *)malloc(sizeof(struct node));
    // second=(struct node *)malloc(sizeof(struct node));
    
    head->data=10;
    head->next=second;
    
    second->data=20;
    second->next=NULL;

    cout<<"Traversal :\n";
    linkedListTraversal(head);
    
    cout<<"Adding element at beginning :\n";
    head=insertAtBegin(head,30);
    linkedListTraversal(head);
    
    cout<<"Adding element at index :\n";
    head=insertAtIndex(head,40,2);
    linkedListTraversal(head);
    
    cout<<"Adding element at end :\n";
    head=insertAtEnd(head,50);
    linkedListTraversal(head);
    
    cout<<"Adding element after node :\n";
    head=insertAfterNode(head,second,65);
    linkedListTraversal(head);
    
    cout<<"Deleting first element :\n";
    head=deleteFirst(head);
    linkedListTraversal(head);
    
    cout<<"Deleting element at index:\n";
    head=deleteAtIndex(head,2);
    linkedListTraversal(head);
    
    cout<<"Deleting element at end:\n";
    head=deleteAtEnd(head);
    linkedListTraversal(head);
    
    cout<<"Deleting element with given value :\n";      //this will delete the first occurance of the value
    head=deleteValue(head,40);
    linkedListTraversal(head);
    
    return 0;
}
