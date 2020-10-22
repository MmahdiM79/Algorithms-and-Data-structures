



class Queue(object):
    
    
    def __init__(self, size: int):
        self.__size__ = size
        self.__arr__ = [None for _ in range(size)]
        self.__head__ = 0
        self.__tail__ = 0
        
        
    
    def enqueue(self, value: int):
        
        self.__arr__[self.__tail__] = value
        
        self.__tail__ += 1
        self.__tail__ %= self.__size__
    
    
    
    def dequeue(self) -> int:
        
        if self.__head__ == self.__tail__:
            raise Exception("Queue is empty")
        
        output = self.__arr__[self.__head__]
        
        self.__head__ += 1
        self.__head__ %= self.__size__
        
        return output
    
    
    
    def values(self) -> list:
        
        output = []
        
        h = self.__head__
        t = self.__tail__
        
        while h != t:
            output.append(self.__arr__[h])
            h = (h+1)%self.__size__
            
        return output
    
    
    
    def size(self) -> int:
        return self.__size__
    
    
    
    def __len__(self) -> int:
        
        h = self.__head__
        t = self.__tail__
        
        if h == t:
            return 0
        
        if h < t:
            return (t - h)
        
        else:
            return (self.__size__ - h + t)
        
        
    
    def empty_space(self) -> int:
        return self.size() - self.__len__()
    
    
    
    
    
    
    
    
    
    
    
if __name__ == "__main__":
    
    print("\n\n ---------------- \n")
    print("a simple test:\n\n\n")
    
    
    # initialize a new queue
    q = Queue(1000)
    
    # add some values
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.enqueue(6)
    q.enqueue(7)
    q.enqueue(8)
    q.enqueue(9)
    q.enqueue(10)
    q.enqueue(11)
    
    
    print("stack: ", *(q.values()), '\n\n')
    
    
    q.enqueue(12)
    print("after enqueue value 12: ", *(q.values()), '\n')


    print("call dequeue function: ", q.dequeue(), '\n')

    print("after dequeue value 12: ", *(q.values()), '\n')
    
    
    
    
    
    
  
    print("\n\n ---------------- \n\n")
     
     
