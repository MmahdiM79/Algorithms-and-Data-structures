


def merge(arr1 :list, arr2: list):
    
    output = []
    
    
    arr1.append(10**(10))
    arr2.append(10**(10))
    
        
      
    i, j = 0, 0
    for _ in range(0, len(arr1)+len(arr2)-2):
        if (arr1[i] < arr2[j]):
            output.append(arr1[i])
            i += 1
        else:
            output.append(arr2[j])
            j += 1
    
        
       
    return output




def merge_sort(array :list):
    
    if len(array) == 1:
        return array
    
    
    mid = int(len(array)/2)
    
    rigthArr = merge_sort(array[:mid])
    arr2 =  merge_sort(array[mid:])
    
    
    return merge(rigthArr, arr2)
        





if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2.7, 21, 43, 0.5, -1, 2.5, -11, 77, 50, 101, 72, 16]
    print(f"before sort: {array}")

    array = merge_sort(array)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")