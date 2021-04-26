




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


