

def insertion_sort(*args):
    
    # check type of the args (because type of args is tuple and it is immutable)
    if type(args) is tuple:
        array = list(args)
    else:
        array = args


    for i in range(2, len(array)):

        # hold to compare with others
        hold = array[i]

        # divide list to two parts ( [0:j] and [j:end])
        j = i-1


        # compare 'hold' with other variables in [0:j] part
        while j >= 0 and array[j] > hold:
        
            # shift variable
            array[j+1] = array[j]

            j -= 1


        array[j+1] = hold

    

    # return the sorted array
    return array









if __name__ == "__main__":

    print("\n\n ---------------- \n")
    print("a simple test:\n")
    

    array = [2, 10, 44, 0, -1, 23, -11, 77, 50, 100, 7, 16]
    print(f"before sort: {array}")

    array = insertion_sort(*array)
    print(f"after sort: {array}")


    print("\n ---------------- \n\n")