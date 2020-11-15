


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

    public BinarySearchTree()
    {
        root = null;
        size = 0;
    }
}