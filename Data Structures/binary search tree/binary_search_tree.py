


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
        
    
    
    def insert(self, value: int) -> Node:
        
        new_node = self.Node(value)
        current = self.__root__
        hold = None
        
        while current is not None:
            hold = current
            
            if new_node.value < current.value:
                current = current.left
            else:
                current = current.right
            
                
        new_node.p = hold
        
        if hold is None:
            self.__root__ = new_node
        
        elif new_node.value < hold.value:
            hold.left = new_node
        
        else:
            hold.right = new_node
            
            
        self.__size__ += 1
        return new_node
    
    
    
    def delete(self, node: Node) -> None:
        
        if node.left is None:
            self.__transplant__(node, node.left)
            
        elif node.right is None:
            self.__transplant__(node, node.right)
            
        else:
            hold = self.minimum_node()
            
            if hold.p is not node:
                self.__transplant__(hold, hold.right)
                hold.right = node.right
                hold.right.p = hold
                
            self.__transplant__(node, hold)
            hold.left = node.left
            hold.left.p = hold
            
            
        self.__size__ -= 1
        
        
        
    def __transplant__(self, node1: Node, node2: Node) -> None:
        
        if node1.p is None:
            self.__root__ = node2
            
        elif node1 is node1.p.left:
            node1.p.left = node2
            
        else:
            node1.p.right = node2
            
        
        if node2.p is not None:
            node2.p = node1.p
            
    
    
    def minimum_node(self) -> Node:
        
        if self.__root__ is None:
            raise Exception("tree is empty")
        
        
        current = self.__root__
        
        while current.left is not None:
            current = current.left
            
        return current
    
    
    
    def maximum_node(self) -> Node:
        
        if self.__root__ is None:
            raise Exception("tree is empty")
        
        
        current = self.__root__
        
        while current.right is not None:
            current = current.right
            
        return current
        
    
    
    
    
    
    
    
    
    
    
if __name__ == "__main__":
    pass


