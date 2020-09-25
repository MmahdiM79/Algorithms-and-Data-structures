




def selection_sort(*args):
    
    # check type of the args (because type of args is tuple and it is immutable)
    if type(args) is tuple:
        array = list(args)
    else:
        array = args
        
    
    # hold the index of the minmum value
    min_value_index = 0
    
    for i in range(0, len(array)-1):
        min_value_index = i
        
        # find minmum value
        for j in range(i+1, len(array)):
            if array[j] < array[min_value_index]:
                min_value_index = j 
                
        
        # swap
        hold = array[i]
        array[i] = array[min_value_index]
        array[min_value_index] = hold
        
       
       
    # return sorted array 
    return array
        
        






if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2.7, 21, 43, 0.5, -1, 2.5, -11, 77, 50, 101, 72, 16]
    print(f"before sort: {array}")

    array = selection_sort(*array)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")