



def RIGHT(x :int) -> int:
    return 2*x + 2

def LEFT(x :int) -> int:
    return RIGHT(x)-1





def max_heapify(array :list, heap_size :int, i :int) -> None:

    l = LEFT(i)
    r = RIGHT(i)


    if l < heap_size and array[l] > array[i]:
        largest = l
    else:
        largest = i

    if r < heap_size and array[r] > array[largest]:
        largest = r


    if largest != i:
        array[i], array[largest] = array[largest], array[i]
        max_heapify(array, heap_size, largest)
    



def heap_sort(array :list) -> None:

    for i in range((len(array)//2 -1), -1, -1):
        max_heapify(array, i)

    for i in range((len(array)-1), 0, -1):
        array[0], array[i] = array[i], array[0]
        max_heapify(array, i)






if __name__ == "__main__":
    