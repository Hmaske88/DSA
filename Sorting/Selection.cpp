#include<iostream>
using namespace std;

void printArray(int* A, int n){
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    cout<<"\nRunning Selection sort...";
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[i])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}
