



def RIGHT(x :int) -> int:
    return 2*x + 2

def LEFT(x :int) -> int:
    return RIGHT(x)-1





def max_heapify(array :list, i :int) -> None:

    l = LEFT(i)
    r = RIGHT(r)


    if l < len(array) and array[l] > array[i]:
        largest = l
    else:
        largest = i

    if r < len(array) and array[r] > array[largest]:
        largest = r


    if largest != i:
        array[i], array[largest] = array[largest], array[i]
        max_heapify(array, largest)
    







if __name__ == "__main__":
    