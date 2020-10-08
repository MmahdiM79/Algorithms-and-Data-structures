





def binary_search(array: list, target: int):
    
    if len(array) == 0:
        
        print("the given array not included the given target")
        return
    
    
        
    if len(array) == 1:
        
        if array[0] == target:
            print("the given array included the given target")
        else:
            print("the given array not included the given target")
            
        return
    
    
    

    start, end = 0, len(array)-1
    
    while True:
        
        mid = (end + start)//2
        
        if start == end:
            print("the given array not included the given target")
            return
        
        if array[mid] == target:
            print("the given array included the given target")
            return
        
        if target > array[mid]:
            start = mid
        else:
            end = mid
            
        
            
            
            
            




if __name__ == "__main__":
    
    print("\n\n ---------------- \n")
    print("a simple test:\n\n\n")
    
    
    # create a sorted array
    array = sorted([-2, 0, 55, 6, -11, -56, 34, 7, 3, 8, 99, 12, 123, 4, 3, -2, 1.34, 34.8, 53, 7])
    print("array:  ", array, '\n')
    
    

    print("search for 4 in array:  ", end='')
    binary_search(array, 4)
    
    print("search for -343 in array:  ", end='')
    binary_search(array, -343)
    
    
    print("\n\n ---------------- \n\n")