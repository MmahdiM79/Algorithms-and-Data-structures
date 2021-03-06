from math import ceil





def find_mid(arr: list) -> int:

    if len(arr) <= 5:
        arr.sort()
        return arr[len(arr)//2] if len(arr)%2 == 1 else arr[(len(arr)//2)-1]
        


    hold = []
    current = 0
    for _ in range(ceil(len(arr)/5)):
        hold.append(arr[current:min((current+5, len(arr)))])
        current += 5
    

    mids = []
    for sub in hold:
        sub.sort()
        mids.append(sub[len(sub)//2]) if len(arr)%2 == 1 else mids.append(sub[(len(sub)//2)-1])

    return find_mid(mids)






def partition(arr: list, pivot: int) -> tuple:
   
    less_than_pivot = []
    more_than_pivot = []

    for num in arr:
        if num < pivot:
            less_than_pivot.append(num)
        elif num > pivot:
            more_than_pivot.append(num)


    return (len(less_than_pivot)+1, less_than_pivot, more_than_pivot)





def select(arr: list, i: int) -> int:
    
    x = find_mid(arr)

    k, less_than_x, more_than_x = partition(arr, x)


    if k == i:
        return x
    elif i < k:
        return select(less_than_x, i)
    else:
        return select(more_than_x, i-k)












if __name__ == "__main__":
    array = [1, 5, 6, 8, 3, 4, 9, 7, 10, 11, -1, -4, 20, 0, 2]
    print(sorted(array))
    print(select(array, 5))