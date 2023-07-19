l=[1,2,3,4,5]

# Algorithm with time complexity O(n**2) for already sorted array
def bubble_sort(arr):
    for i in range(len(arr)-1):
        print("Pass no. :",i+1)
        for j in range(1,len(arr)):
            if arr[j-1]>arr[j]:
                arr[j-1],arr[j]=arr[j],arr[j-1]
    print(arr)
bubble_sort(l)


# Algorithm with time complexity O(n) for already sorted array  i.e.adaptive
def bubble_sort(arr):
    for i in range(len(arr)-1):
        isSorted=1
        print("Pass no. :",i+1)
        for j in range(1,len(arr)):
            if arr[j-1]>arr[j]:
                arr[j-1],arr[j]=arr[j],arr[j-1]
                isSorted=0
        if(isSorted==1):
            break
    print(arr)
bubble_sort(l)
