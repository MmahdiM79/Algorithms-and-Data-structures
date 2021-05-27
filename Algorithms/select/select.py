from math import ceil










def select(arr: list, i: int) -> int:

    hold = []
    current = 0
    for _ in range(ceil(len(arr)/5)):
        hold.append(arr[current:min((current+5, len(arr)))])
        current += 5

    print(hold)












if __name__ == "__main__":
    select([2, 3, 4, 1, 5, 6, 7, 8, 9, 0, 2], 4)