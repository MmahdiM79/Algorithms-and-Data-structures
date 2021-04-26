




def partition(array: list, p: int, r: int) -> int:
    
    x = array[r]
    i = p-1
    
    for j in range(p, r):
        if array[j] <= x:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[r] = array[r], array[i+1]

    return i+1



def quick_sort(array: list, p: int, r: int) -> None:

    if p < r:
        q = partition(array, p, r)
        quick_sort(array, p, q-1)
        quick_sort(array, q+1, r)






if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2.7, -21, 43, 0, -1, 2.5, -11, 77, -50, 101, 72, 16, 33]
    print(f"before sort: {array}")

    quick_sort(array, 0, len(array)-1)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")
