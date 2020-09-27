import java.util.Arrays;




/**
 * Use {@link InsertionSort#insertionSort(int...)} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class InsertionSort
{
    /**
     * This method sorts your int array with insertion sort algorithms
     * 
     * @param array : array to sort
     */
    public static void insertionSort(int...array)
    {
        // required variables
        int hold = 0, j = 0;


        for (int i = 2; i < array.length; i++)
        {
            // hold to compare with others
            hold = array[i];

            // divide list to two parts (array[0] to array[j] and array[j+1] to array[size-1])
            j = i-1;


            // compare 'hold' with other variables in array[0] to array[j] part
            while (j >= 0 && array[j] > hold)
            {
                // shift variable
                array[j+1] = array[j];

                j--;
            }

            array[j+1] = hold;
        }
    }



    /**
     * A simple example for {@link InsertionSort#insertionSort(int...)}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, -34, 23, -11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        insertionSort(array);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}