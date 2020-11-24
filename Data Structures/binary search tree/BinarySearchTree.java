

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
}