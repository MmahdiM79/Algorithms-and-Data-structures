

/**
 * This class represent a simple stack 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class Stack
{
            /*  Fields  */

    // hold values
    int[] arr;

    // hold the index of last value
    int top;




         /* Constructor */

    /**
     * Create a new stack with given size
     * 
     * @param size : size of stack to create
     */
    public Stack(int size)
    {
        arr = new int[size];
        top = -1;
    }



            /*  Methods  */

    
    /**
     * add the given value to the end of the stack
     * 
     * @param value : value to add
     * @throws Exception if stack is full
     */
    public void push(int value) throws Exception
    {
        try
        {
            arr[++top] = value;
        }
        catch (IndexOutOfBoundsException e)
        {
            throw new Exception("stack overflow !");
        }
    }


    /**
     * remove the last value from stack and return it
     * 
     * @return the removed value
     * @throws Exception if stack is empty
     */
    public int pop() throws Exception
    {
        try
        {
            return arr[top--];
        }
        catch (IndexOutOfBoundsException e)
        {
            throw new Exception("stack underflow !");
        }
    }


    /**
     * @return the last value of stack
     * 
     * @throws Exception if stack is underflow
     */
    public int peek() throws Exception
    {
        try
        {
            return arr[top];
        }
        catch (IndexOutOfBoundsException e)
        {
            throw new Exception("stack underflow !");
        }
    }


    /**
     * @return {@code true} if stack is empty. otherwise returns {@code false}
     */
    public boolean isEmpty()
    {
        return (top == -1);
    }


    /**
     * @return a {@code String} of stack values
     */
    @Override
    public String toString()
    {
        String output = "[";

        for (int i = 0; i <= top; i++)
            output += arr[i] + ", ";

        return output + "\b\b]";
    }









    public static void main(String[] args) throws Exception
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        Stack stack = new Stack(100);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        stack.push(7);
        stack.push(8);
        stack.push(9);
        stack.push(10);
        stack.push(11);
        stack.push(12);
        stack.push(13);
        stack.push(14);

        System.out.println("stack:  " + stack.toString() + "\n");


        stack.push(15);
        System.out.println("after push value 15:  " + stack.toString() + "\n");

        System.out.println("call pop function:  " + stack.pop() + "\n");

        System.out.println("stack after pop value 15:  " + stack.toString() + "\n");


        System.out.println("\n\n ---------------- \n\n");
    }
}