

/**
 * This class represent a simple binary search tree
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class BinarySearchTree
{
    private class Node
    {
        // fields
        int value;
        Node p;
        Node right;
        Node left;

        // constructor

        public Node(int value)
        {
            this.value = value;
            p = right = left = null;
        }
    }



            /*  Fields  */
    
    public Node root;
    public long size;


         /* Constructor */
    /**
     * Create a new binary search tree
     */
    public BinarySearchTree()
    {
        root = null;
        size = 0;
    }


            /*  Methods  */

    /**
     * insert a new node to the tree
     * 
     * @param value : value of new node
     * @return the added node object
     */
    public Node insert(int value)
    {
        Node newNode = new Node(value);
        
        Node current = root;
        Node hold = null;

        while (current != null)
        {
            hold = current;

            if (newNode.value < current.value)
                current = current.left;
            else
                current = current.right;
        }

        newNode.p = hold;

        if (hold == null)
            root = newNode;

        else if (newNode.value < hold.value)
            hold.left = newNode;

        else
            hold.right = newNode;


        size++;
        return newNode;
    }


    /**
     * This method delete the given node from this tree
     * 
     * @param node : node to remove
     * @throws Exception if this tree is empty
     */
    public void delete(Node node) throws Exception
    {
        if (this.size == 0)
            throw new Exception("this binary search tree is empty");

        
        if (node.left == null)
            transplant(node, node.right);

        else if (node.right == null)
            transplant(node, node.left);

        else
        {
            Node r = root;
            root = node.right;
            Node hold = minimumNode();
            root = r;

            if (hold.p != node)
            {
                transplant(hold, hold.right);
                hold.right = node.right;
                hold.right.p = hold;
            }

            transplant(node, hold);
            hold.left = node.left;
            hold.left.p = hold;
        }

        size--;
    }
    

    /**
     * @return the node that have the minimum value in this tree
     * @throws Exception if tree is empty
     */
    public Node minimumNode() throws Exception
    {
        if (root == null)
            throw new Exception("tree is empty");

        Node current = root;

        while (current.left != null)
            current = current.left;

        
        return current;
    }


    /**
     * @return the node that have the maximum value in this tree
     * @throws Exception if tree is empty
     */
    public Node maximumNode() throws Exception
    {
        if (root == null)
            throw new Exception("tree is empty");

        Node current = root;

        while (current.right != null)
            current = current.right;

        
        return current;
    }


    /**
     * This method search for a value in this tree
     * 
     * @param value : value to find
     * @return the Node that has the given value. otherwise returns null
     */
    public Node search_recursive(int value)
    {
        Node current = root;
        Node output = null;

        if (current == null || current.value = value)
            return current;

        if (value < current.value)
            root = current.left;
        else 
            root = current.right;

        
        output = search_recursive(value);
        root = current;
        return output;
    }


    /**
     * This function search for a value in this tree
     * 
     * @param value : value that you looking for
     * @return the node which has the given value. if your given value isn't available in this tree, returns null
     */
    public Node search(int value)
    {
        Node current = root;
        
        while (current != null)
        {
            if (current.value == value)
                return current;

            if (value < current.value)
                current = current.left;
            else
                current = current.right;
        }


        return null;
    }


    /**
     * @return the next node in order walk
     */
    public Node successor()
    {
        if (root == null)
            return null;


        Node current = root;
        if (current.right != null)
            try { return minimumNode(); }
            catch (Exception e) {return null; }


        Node hold = current.p;
        while (hold != null && current != hold.right)
        {
            current = hold;
            hold = hold.p;
        }


        return hold;
    }


    /**
     * @return the previous node in order walk
     */
    public Node predecessor()
    {
        if (root == null)
            return null;


        Node current = root;
        if (current.left != null)
            try { return minimumNode(); }
            catch (Exception e) {return null; }


        Node hold = current.p;
        while (hold != null && current != hold.left)
        {
            current = hold;
            hold = hold.p;
        }


        return hold;
    }


    /**
     * This method walk values inorder and print them in terminal
     */
    public void walkInorder()
    {
        if (root != null)
        {
            Node current = root;

            root = current.left;
            walkInorder();

            System.out.print(current.value + " ");

            root = current.left;
            walkInorder();


            root = current;
        }
    }


    /**
     * This method walk values preorder and print them in terminal
     */
    public void walkPreorder()
    {
        if (root != null)
        {
            Node current = root;

            System.out.print(current.value + " ");

            root = current.left;
            walkPreorder();

            root = current.left;
            walkPreorder();


            root = current;
        }
    }


    /**
     * This method walk values postorder and print them in terminal
     */
    public void walkPostorder()
    {
        if (root != null)
        {
            Node current = root;

            root = current.left;
            walkPostorder();
            
            root = current.left;
            walkPostorder();
            
            System.out.print(current.value + " ");


            root = current;
        }
    }

    


    private void transplant(Node node1, Node node2)
    {
        if (node1.p == null)
            root = node2;

        else if (node1 == node1.p.left)
            node1.p.left = node2;

        else
            node1.p.right = node2;


        if (node2 != null)
            node2.p = node1.p;
    }








    // a simple program to test this class
    public static void main(String[] args) throws Exception
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        // create a new binary tree
        BinarySearchTree t = new BinarySearchTree();

        // add some values
        t.insert(3);
        t.insert(5);
        t.insert(0);
        t.insert(6);
        t.insert(7);
        t.insert(9);
        t.insert(2);
        t.insert(11);
        t.insert(1);
        t.insert(10);
        t.insert(8);


        // tree walks
        System.out.println("tree walks:");
        System.out.print("\tpreorder walk : "); t.walkPreorder(); System.out.print("\n");
        System.out.print("\tinorder walk  : "); t.walkInorder(); System.out.print("\n");
        System.out.print("\tpostorder walk: "); t.walkPostorder(); System.out.print("\n");



        // add a new value
        System.out.print("\ninorder walk after add 12:  ");
        Node node = t.insert(12);
        t.walkInorder();
        System.out.print("\n");


        // remove a node
        System.out.print("\ninorder walk after remove 12:  ");
        t.delete(node);
        t.walkInorder();
        System.out.print("\n");


        // find minimum
        System.out.println("\nminimum value in this tree:  " + t.minimumNode().value);
        // find maximum
        System.out.println("\nmaximum value in this tree:  " + t.maximumNode().value);




        System.out.println("\n ---------------- \n\n");
    }
}