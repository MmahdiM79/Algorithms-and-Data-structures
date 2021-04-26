




def partition(array: list, p: int, r: int) -> int:
    
    x = array[r]
    i = p-1
    
    for j in range(p, r):
        if array[j] <= x:
            i += 1
            array[i], array[j] = array[j], array[i]

    array[i+1], array[r] = array[r], array[i+1]

    return i+1









if __name__ == "__main__":


