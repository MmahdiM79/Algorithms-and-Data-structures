import java.util.Arrays;

/**
 * Use {@link BubbleSort#heapSort(int[])} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class HeapSort 
{
    // return the index of the right child of the given index
    private static int right(int x)
    {
        return 2*x + 2;
    }

    // return the index of the left child of the given index
    private static int left(int x)
    {
        return right(x) - 1;
    }


    // max heap your array from the given index until the end
    private static void maxHeapify(int[] array, int heapSize, int i)
    {
        int r = right(i);
        int l = left(i);


        int largest;
        if (l < heapSize && array[l] > array[i])
            largest = l;
        else
            largest = i;

        if (r < heapSize && array[r] > array[largest])
            largest = r;


        if (largest != i)
        {
            int hold = array[i];
            array[i] = array[largest];
            array[largest] = hold;

            maxHeapify(array, heapSize, largest);
        }
    }


    /**
     * This method sort your array with heap sort algorithm
     * 
     * @param array : array to sort
     */
    public static void heapSort(int[] array)
    {
        for (int i = 0; i < (array.length/2 - 1); i++)
            maxHeapify(array, array.length, i);
            
        for (int i = array.length-1; i > 0; i--)
        {
            int hold = array[0];
            array[0] = array[i];
            array[i] = hold;

            maxHeapify(array, i, 0);
        }
    }



    /**
     * A simple example for {@link BubbleSort#heapSort(int[])}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, -34, 23, -11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        heapSort(array);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}
