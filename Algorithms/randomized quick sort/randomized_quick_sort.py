from random import randint





def partition(array: list, p: int, r: int) -> int:
    
    x = array[r]
    i = p-1
    
    for j in range(p, r):
        if array[j] <= x:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[r] = array[r], array[i+1]

    return i+1




def randomized_partition(array: list, p: int, r: int) -> int:

    i = randint(p, r)
    array[i], array[r] = array[r], array[i]

    return partition(array, p, r)





def randomized_quick_sort(array: list, p: int, r: int) -> None:

    if p < r:
        q = randomized_partition(array, p, r)
        randomized_quick_sort(array, p, q-1)
        randomized_quick_sort(array, q+1, r)








if __name__ == "__main__":

