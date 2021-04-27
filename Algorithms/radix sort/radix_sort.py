


def index(i: int, exp: int) -> int:
    return int((i/exp) % 10)






def counting_sort(array: list, n: int, exp: int) -> list:

    count = [0] * (10+1)

    for j in range(n):
        count[index(array[j], exp)] += 1

    for i in range(1, 10+1):
        count[i] += count[i-1]

    out = [None] * n
    for j in range(n-1, -1, -1):
        out[count[index(array[j], exp)]-1] = array[j]
        count[index(array[j], exp)] -= 1


    return out






def radix_sort(array: list) -> None:

    maximum_num = max(array)

    exp = 1
    while maximum_num/exp > 0:
        res = counting_sort(array, len(array), exp)
        for i in range(len(array)):
            array[i] = res[i]
        exp *= 10







if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2, 10, 44, 0, 1, 23, 11, 77, 50, 100, 7, 16, 2, 11]
    print(f"before sort: {array}")

    radix_sort(array)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")