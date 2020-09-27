import java.util.Arrays;






/**
 * Use {@link BubbleSort#BubbleSort(int...)} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class BubbleSort
{
    /**
     * This method sorts your int array with bubble sort algorithms
     * 
     * @param array : array to sort
     */
    public static void bubbleSort(int...array)
    {
        // hold values for swaping
        int hold = 0;


        for (int i = 0; i < array.length; i++)
            for (int j = i+1; j < array.length; j++)
                if (array[i] > array[j])
                {
                    hold = array[i];
                    array[i] = array[j];
                    array[j] = hold;
                }
    }



    /**
     * A simple example for {@link BubbleSort#bubbleSort(int...)}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, -34, 23, -11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        bubbleSort(array);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}