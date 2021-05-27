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
        mids.append(sub[len(sub)//2])

    return find_mid(mids)






def partition(arr: list, pivot: int) -> tuple:
   
    less_than_pivot = []
    more_than_pivot = []

    for num in arr:
        if num < pivot:
            less_than_pivot.append(num)
        else:
            more_than_pivot.append(num)


    return (len(less_than_pivot), less_than_pivot, more_than_pivot)





def select(arr: list, i: int) -> int:
    pass
    












if __name__ == "__main__":
    array = [4, 5, 6, 8, 9, 1, 2, 3, 4, 5, 9, 0, 6]
    x = find_mid(array)
    print(x)
    print(sorted(array))
    print(partition(array, x))
    print(array)