


class BinarySearchTree(object):
    
    class Node(object):
        def __init__(self, value: int) -> None:
            self.value = value
            self.p = None
            self.right = None
            self.left = None
            
            
            
    def __init__(self) -> None:
        self.__root__ = None
        self.__size__ = 0
        
    
    def insert(self, value: int) -> None:
        new_node = self.Node(value)
        current = self.__root__
        hold = None
        
        while current != None:
            hold = current
            
            if new_node.value < current.value:
                current = current.left
            else:
                current = current.right
            
                
        new_node.p = hold
        
        if hold == None:
            self.__root__ = new_node
        
        elif new_node.value < hold.value:
            hold.left = new_node
        
        else:
            hold.right = new_node
            
            
        self.__size__ += 1
    
    
    
    
    
    
    
    
    
    
if __name__ == "__main__":
    pass


