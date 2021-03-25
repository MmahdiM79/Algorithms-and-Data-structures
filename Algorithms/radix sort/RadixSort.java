import java.util.Arrays;



/**
 * This is a simple implementation of radix sort.
 * Use {@link RadixSort#radixSort(int[])} to sort an array of integers.
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */ 
public class RadixSort 
{

    /**
     * @param i : index
     * @param exp : exponent
     * 
     * @return (i/exp) % 10
     */
    private static int index(int i, int exp)
    {
        return (i/exp) % 10;
    }


    /**
     * @param array : an array of integers
     * @return maximum value in the array
     */ 
    private static int maxArray(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; i++)
            if (array[i] > max)
                max = array[i];
        
        return max;
    }


    /**
     * This method sorts an array of integers using counting sort 
     * Values sorted by their exponents.
     * 
     * @param array : an array of integers
     * @param exp : the exponent of the array
     */
    private static void countingSort(int[] array, int exp)
    {
        int n = array.length;
        int[] count = new int[10];

        for (int i = 0; i < n; i++)
            count[index(array[i], exp)]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i-1];

        
        int[] result = new int[n];
        for (int i = n-1; i >= 0; i--)
        {
            result[count[index(array[i], exp)]-1] = array[i];
            count[index(array[i], exp)]--;
        }

        
        // copy array 'result' into array 'array'
        System.arraycopy(result, 0, array, 0, result.length);
    }


    /**
     * This method sorts an array of integers using radix sort algorithm.
     * 
     * @param array : an array of integers that you want to sort
     */
    public static void radixSort(int[] array)
    {
        int max = maxArray(array);


        int exp = 1;
        while (max/exp > 0)
        {
            countingSort(array, exp);
            exp *= 10;
        }
    }

    

    /**
     * A simple example for {@link RadixSort#radixSort(int[])}
     * 
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, 34, 23, 11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        radixSort(array, array.length);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}
