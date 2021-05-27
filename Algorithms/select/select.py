from math import ceil





def find_mid(arr: list) -> int:

    if len(arr) == 1:
        return arr[0]


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

    












if __name__ == "__main__":
    select([2, 3, 4, 1, 5, 6, 7, 8, 9, 0, 2], 4)