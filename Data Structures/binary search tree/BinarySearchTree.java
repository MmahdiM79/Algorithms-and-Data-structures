

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
}