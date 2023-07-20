l=[5,2,7,4,6,3,2]

def selectionSort(arr):
    for i in range(len(arr)-1):
        for j in range(i+1,len(arr)):
            if arr[i]>arr[j]:
                arr[i],arr[j]=arr[j],arr[i] #swap
                # arr[i]=arr[j]
                # arr[j]=arr[i]
    print(arr)
    
selectionSort(l)
