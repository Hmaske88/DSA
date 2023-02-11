#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
}*root;

class GT
{
    public:
    void create_tree();
    void display(node*r1);
    GT()
    {
        root=NULL;
    }
};

void GT::create_tree()
{
    int tbook,tchapters,tsections,i,j,k;
    root=new node;
    cout<<"\nEnter name of book :";
    cin>>root->label;
    cout<<"\nEnter no. of chapter in book :";
    cin>>root->ch_count;
    tchapters=root->ch_count;
    for(i=0;i<root->ch_count;i++)
    {
        root->child[i]=new node;
        cout<<"Enter chapter "<<i+1<<" name : ";
        cin>>root->child[i]->label;
        
        cout<<"\nEnter no. of sections in chapter "<<root->child[i]->label<<" : ";
        cin>>root->child[i]->ch_count;
        tsections=root->child[i]->ch_count;
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"Enter section "<<j+1<<" name : ";
            cin>>root->child[i]->child[j]->label;
        }
    }
}

void GT::display(node*r1)
{
    int i,j,k,tchapters;
    if(r1 != NULL)
    {
        cout<<"\n-----Book Hierarchy-------";
        cout<<"\nBook title :"<<r1->label;
        tchapters=r1->ch_count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"\nChapter"<<i+1<<" :"<<r1->child[i]->label;
            
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                cout<<"\nSection "<<j+1<<" :"<<r1->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    int choice;
    GT gt;
    while(1)
    {
        cout<<"\n------------------------"<<endl;
        cout<<"Book Tree Creation"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                gt.create_tree();
                break;
            case 2:
                gt.display(root);
                cout<<"\n";
                break;
            case 3:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
}
