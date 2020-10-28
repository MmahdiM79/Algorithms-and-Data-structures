




public class Queue
{
            /*  Fields  */

    // hold values
    private int[] arr;

    // number of the values
    private int size;

    // first value index
    private int head;

    // last value index
    private int tail;





         /* Constructor */

    /**
     * Create a new Queue with given capacity
     * 
     * @param capacity
     */
    public Queue(int capacity)
    {
        arr = new int[capacity];

        size = 0;
        head = 0;
        tail = 0;
    }





            /*  Methods  */


    /**
     * Add a new value to the queue
     * 
     * @param value : value to add
     * @throws exception if queue is full
     */
    public void enqueue(int value) throws Exception
    {
        if (isFull())
            throw new Exception("the object " + this.getClass() + " is full");

        
        arr[tail] = value;
        tail++;
        tail %= arr.length;
        size++;
    }


    /**
     * Remove the first value in this queue
     * 
     * @return the removed value
     * @throws exception if queue is empty
     */
    public int dequeue() throws Exception
    {
        if (isEmpty())
            throw new Exception("the object " + this.getClass() + " is empty");

        
        int output = arr[head];

        head++;
        head %= arr.length;
        size++;

        return output;
    }


    /**
     * @return a {@code String} of queue values
     */
    @Override
    public String toString() 
    {
        String output = "[";

        for (int i = head; i != tail; i++, i %= arr.length)
            output += arr[i] + ", ";

        return output + "\b\b]";
    }



    /**
     * @return the capacity of this queue
     */
    public int getCapacity() { return arr.length; }

    /**
     * @return the empty space of this queue
     */
    public int getEmptySpace() { return arr.length - size; }

    /**
     * @return the size of the queue
     */
    public int getSize() { return size; }

    /**
     * @return {@code true} if queue is empty
     */
    public boolean isEmpty() { return (size == 0); }

    /**
     * @return {@code true} if queue is full
     */
    public boolean isFull() { return (size == arr.length); }






    /**
     * a simple test for how to use queue
     * @param args
     */
    public static void main(String[] args) throws Exception
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        Queue queue = new Queue(100);
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.enqueue(5);
        queue.enqueue(6);
        queue.enqueue(7);
        queue.enqueue(8);
        queue.enqueue(9);
        queue.enqueue(10);
        queue.enqueue(11);
        queue.enqueue(12);
        queue.enqueue(13);
        queue.enqueue(14);

        System.out.println("queue:  " + queue.toString() + "\n");


        queue.enqueue(15);
        System.out.println("after enqueue value 15:  " + queue.toString() + "\n");

        System.out.println("call pop function:  " + queue.dequeue() + "\n");

        System.out.println("queue after pop value 15:  " + queue.toString() + "\n");


        System.out.println("\n\n ---------------- \n\n");
    }
}
