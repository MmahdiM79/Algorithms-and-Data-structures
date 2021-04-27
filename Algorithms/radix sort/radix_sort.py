


def index(i: int, exp: int) -> int:
    return (i/exp) % 10






def counting_sort(array: list, n: int, exp: int) -> list:

    count = [0] * (10+1)

    for j in range(n):
        count[index(array[j], exp)] += 1

    for i in range(1, 10+1):
        count[i] += count[i-1]

    out = [None] * n
    for j in range(n-1, -1, -1):
        out[count[index(array[j], exp)]] = array[j]
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