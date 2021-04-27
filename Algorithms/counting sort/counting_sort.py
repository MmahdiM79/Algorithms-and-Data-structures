







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

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [27, 21, 43, 50, 0, 2, 11, 77, 50, 101, 72, 16]
    print(f"before sort: {array}")

    array = counting_sort(array, len(array), 101)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")
