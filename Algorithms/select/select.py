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




def select(arr: list, i: int) -> int:
    pass
    












if __name__ == "__main__":
    array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    print(find_mid(array))
    print(sorted(array))