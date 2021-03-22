import java.util.Arrays;



/**
 * This is a simple implementation of counting sort.
 * Use {@link CountingSort#countingSort(int[], int)} to sort an array of integers.
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class CountingSort 
{
    /**
     * a simple method to sort an array of integers using counting sort algorithm.
     * 
     * 
     * @param array : an array of integers
     * @param k : maximum value of the array
     */ 
    public static void countingSort(int[] array, int k)
    {
        int[] count = new int[k+1];

        for (int i = 0; i < array.length; i++)
            count[array[i]]++;

        for (int i = 1; i < count.length; i++)
            count[i] += count[i-1];


        int[] result = new int[array.length];
        for (int i = array.length-1; i >= 0; i--)
        {
            result[count[array[i]]-1] = array[i];
            count[array[i]]--;
        }

        
        System.arraycopy(result, 0, array, 0, result.length);
    }




    /**
     *  A simple example for {@link CountingSort#countingSort(int[], int)}
     * 
     * @param args
     */ 
    public static void main(String[] args)
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, 34, 23, 11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        countingSort(array, 252);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}
