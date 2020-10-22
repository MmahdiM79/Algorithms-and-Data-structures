

class Stack(object):

   
    def __init__(self, n: int):
        self.__size__ = n 
        self.__arr__ = [0 for _ in range(n)]
        self.__top__ = -1
        
        
    def is_empty(self) -> bool:
        return (self.__top__ == -1)
    
    
    def push(self, value: int) -> bool:
        
        if self.__top__ == self.__size__-1:
            return False
        
        self.__top__ += 1
        self.__arr__[self.__top__] = value
        return True
    
    
    def pop(self) -> int:
        
        if self.__top__ == -1:
            raise Exception("underflow")
        
        
        self.__size__ -= 1
        self.__top__ -= 1
        
        return self.__arr__[self.__top__+1]
        
        
        
    def values(self) -> list:
        return self.__arr__[:self.__top__+1]
        
        
    
    def __len__(self) -> int:
        return self.__size__
    
    
        
        
        
        
        
    
    
    




if __name__ == "__main__":
    
    print("\n\n ---------------- \n")
    print("a simple test:\n\n\n")
    
    
    # initialize a new stack
    s = Stack(1000)
    
    # add some values
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    s.push(5)
    s.push(6)
    s.push(7)
    s.push(8)
    s.push(9)
    s.push(10)
    s.push(11)
    
    
    print("stack: ", *(s.values()), '\n\n')
    
    
    s.push(12)
    print("after push value 12: ", *(s.values()), '\n')


    print("call pop function: ", s.pop(), '\n')

    print("after pop value 12: ", *(s.values()), '\n')
    
    
    
    
    
    
  
    print("\n\n ---------------- \n\n")
     
     
    