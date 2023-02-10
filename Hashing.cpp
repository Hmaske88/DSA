#include <iostream>
#include<string.h>
using namespace std;

struct data
{
    char name[30];
    long telephone_no;
};

class hash1
{
    private:
        int n,sym,x,c,i,j;
        char client_name[30];
        long no;
        data d[10];
    public:
        hash1()
        {
            for (int i = 0; i < 10; i++)
            {
                d[i].telephone_no=0;
                strcpy(d[i].name,"NIL");    //strcpy used to copy one string to another
            }
        }
        void linear_probing_insert();
        void quadratic_probing_insert();
        void linear_search();
        void quadratic_search();
        void display();
};

void hash1::linear_probing_insert()
{
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name: ";
        cin>>client_name;
        cout<<"Enter the number: ";
        cin>>no;
        int sum=0;
        for(int i = 0; i < strlen(client_name); i++)
        {
            sum=sum+client_name[i];
        }
        x=(sum/strlen(client_name))%10;
        c=x;
        while(1)
        {
            if(d[x].telephone_no==0)
            {
                strcpy(d[x].name,client_name);
                d[x].telephone_no=no;
                break;
            }
            x=(x+1)%10; // Linear Probing
            if(c==x)
            {
                cout<<"Hash table is full"<<endl;
                break;
            }
        }
    }
}

void hash1::quadratic_probing_insert()
{
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name: ";
        cin>>client_name;
        cout<<"Enter the number: ";
        cin>>no;
        int sum=0;
        for(int i = 0; i < strlen(client_name); i++)
        {
            sum=sum+client_name[i];
        }
        x=(sum/strlen(client_name))%10;
        c=x;
        for(int j=1;j<6;j++)
        {
            if(d[x].telephone_no==0)
            {
                strcpy(d[x].name,client_name);
                d[x].telephone_no=no;
                break;
            }
            x=(c + j*j)%10; // quadratic Probing
            if(c==x)
            {
                cout<<"Hash table is full"<<endl;
                break;
            }
        }
    }
}

void hash1::linear_search()
{
    cout<<"\n\nEnter the name to search :";
    cin>>client_name;
    int sum=0;
    for (int i = 0; i < strlen(client_name); i++)
    {
        sum=sum+(int)client_name[i];
    }
    x=(sum/strlen(client_name))%10;
    c=x;
    while (1)
    {
        if(!strcmp(d[x].name, client_name))
        {
            cout<<"Data found : Telephone No. : "<<d[x].telephone_no<<endl;
            break;
        }
        x=(x+1)%10;
        if(c==x)
        {
            cout<<"Data not found "<<endl;
            break;
        }
    }
}

void hash1::quadratic_search()
{
    cout<<"\n\nEnter the name to search :";
    cin>>client_name;
    int sum=0;
    for (int i = 0; i < strlen(client_name); i++)
    {
        sum=sum+(int)client_name[i];
    }
    x=(sum/strlen(client_name))%10;
    c=x;
    for(int j=1;j<6;j++)
    {
        if(!strcmp(d[x].name, client_name))
        {
            cout<<"Data found : Telephone No. : "<<d[x].telephone_no<<endl;
            break;
        }
        x=(c + j*j)%10;
        if(c==x)
        {
            cout<<"Data not found "<<endl;
            break;
        }
    }
}

void hash1::display()
{
    cout<<"\nRecords are : ";
    for (int i = 0; i < 10; i++)
    {
        cout<<endl<<d[i].name<<" "<<d[i].telephone_no;
    }
}

int main()
{
    hash1 h;
    int m=1,ch;
    while(m==1)
    {
        cout<<"\nMenu:\n1.Linear probing\n2.Quadratic Probing\n";
        cout<<"Please enter the choice :";
        cin>>ch;
        if(ch==1)
        {
            h.linear_probing_insert();
            h.display();
            h.linear_search(); 
        }
        else if(ch==2)
        {
            h.quadratic_probing_insert();
            h.display();
            h.quadratic_search();
        }
        else
        {
            cout<<"You have enterd wrong choice\n";
        }
        
        cout<<"\nEnter 1 to continue or any another number to exit ::";
        cin>>m;
    }
    return 0;
}
