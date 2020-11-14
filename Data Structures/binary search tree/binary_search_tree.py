


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
            self.__transplant__(node, node.right)
            
        elif node.right is None:
            self.__transplant__(node, node.left)
            
        else:
            root = self.__root__
            self.__root__ = node.right
            hold = self.minimum_node()
            self.__root__ = root
            
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
            
        
        if node2 is not None:
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
    
    
    
    def search(self, value: int) -> Node:
        
        current = self.__root__
        
        
        while current is not None:
            
            if current.value == value:
                return current
            
            if value < current.value:
                current = current.left
            else:
                current = current.right
                
                
        return None
    
    
    
    def search_recursive(self, value: int) -> Node:
        
        current = self.__root__
        output  = None
        
        if current is None or current.value == value:
            return current
        
        
        if value < current.value:
            self.__root__ = current.left
        else:
            self.__root__ = current.right

        
        output = self.search_recursive(value)
        self.__root__ = current
        return output
    
    
    
    def successor(self) -> Node:
        
        if self.__root__ is None:
            return None
        
        
        current = self.__root__
        if current.right is not None:
            return self.minimum_node()
        
        
        hold = current.p
        while hold is not None and current is hold.right:
            current = hold
            hold = hold.p
            
        
        return hold 
    
    
    
    def predecessor(self) -> Node:
        
        if self.__root__ is None:
            return None
        
        
        current = self.__root__
        if current.left is not None:
            return self.minimum_node()
        
        
        hold = current.p
        while hold is not None and current is hold.left:
            current = hold
            hold = hold.p
            
        
        return hold 
    
    
    
    def walk_inorder(self) -> None:
        
        if self.__root__ is not None:
            current = self.__root__
            
            self.__root__ = current.left
            self.walk_inorder()
            
            print(f"{current.value} ", end='', sep='')
            
            self.__root__ = current.right
            self.walk_inorder()
            
            
            self.__root__ = current
            
            
            
    def walk_preorder(self) -> None:
        
        if self.__root__ is not None:
            current = self.__root__
            
            print(f"{current.value} ", end='', sep='')
            
            self.__root__ = current.left
            self.walk_preorder()
            
            self.__root__ = current.right
            self.walk_preorder()
            
            
            self.__root__ = current
            
          
            
    def walk_postorder(self) -> None:
        
        if self.__root__ is not None:
            current = self.__root__
            
            self.__root__ = current.left
            self.walk_postorder()
            
            self.__root__ = current.right
            self.walk_postorder()
            
            print(f"{current.value} ", end='', sep='')
            
            
            self.__root__ = current
            
            
            
        
    
    
    
    
    
    
    
    
    
    
if __name__ == "__main__":
    
    print("\n\n ---------------- \n")
    print("a simple test:\n\n\n")
    
    
    
    # create a new binary tree
    t = BinarySearchTree()
    
    # add some nodes
    t.insert(2)
    t.insert(4)
    t.insert(1)
    t.insert(5)
    t.insert(8)
    t.insert(6)
    t.insert(9)
    t.insert(0)
    t.insert(10)
    t.insert(3)
    t.insert(11)
    t.insert(7)
    

    # tree walks
    print("tree walks:")
    print("\tpreorder walk :  ", end=''); t.walk_preorder(); print()
    print("\tinorder walk  :  ", end=''); t.walk_inorder(); print()
    print("\tpostorder walk:  ", end=''); t.walk_postorder(); print()
     
    
    # add a new node
    print("\ninorder walk after add a new node with value 12:  ", end='')
    node = t.insert(12)
    t.walk_inorder()
    print()
    
    
    # remove a node
    print("\ninorder walk after remove the node with value 12:  ", end='')
    t.delete(node)
    t.walk_inorder()
    print()
    
    
    # find minimum
    print(f"\nminimum value in this tree:  {t.minimum_node().value}")
    # find maximum
    print(f"\nmaximum value in this tree:  {t.maximum_node().value}")
    
    
    
    print("\n\n ---------------- \n\n")








