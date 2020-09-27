import java.util.Arrays;





/**
 * Use {@link SelectionSort#selectionSort(int...)} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class SelectionSort
{


     /**
     * This method sorts your int array with selection sort algorithms
     * 
     * @param array : array to sort
     */
    public static void selectionSort(int...array)
    {
        // hold the index of the minimum value
        int minValueIndex = 0;


        for (int i = 0; i < array.length-1; i++)
        {
            minValueIndex = i;

            // find the minimum value
            for (int j = i+1; j < array.length; j++)
                if (array[j] < array[minValueIndex])
                    minValueIndex = j;


            // swap
            int hold = array[i];
            array[i] = array[minValueIndex];
            array[minValueIndex] = hold;
        }
    }




    /**
     * A simple example for {@link SelectionSort#selectionSort(int...)}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 25, 0, -34, 23, -11, 43, 50, 123, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        selectionSort(array);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}