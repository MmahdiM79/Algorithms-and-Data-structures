




def bubble_sort(*args):
    
    # check type of the args (because type of args is tuple and it is immutable)
    if type(args) is tuple:
        array = list(args)
    else:
        array = args
        
    
    
    
    
    
    for i in range(0, len(array)):
        for j in range(i+1, len(array)):
            if array[i] > array[j]:
                array[i], array[j] = array[j], array[i]
        
       
       
    # return sorted array 
    return array
        
        






if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2.7, 21, 43, 0.5, -1, 2.5, -11, 77, 50, 101, 72, 16]
    print(f"before sort: {array}")

    array = bubble_sort(*array)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")