




def counting_sort(array: list, n: int, k: int) -> list:

    count = [0] * (k+1)

    for j in range(n):
        count[array[j]] += 1

    for i in range(1, k+1):
        count[i] += count[i-1]

    out = [None] * n
    for j in range(n-1, -1, -1):
        out[count[array[j]]-1] = array[j]
        count[array[j]] -= 1


    return out











if __name__ == "__main__":
