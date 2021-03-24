import java.util.Arrays;

public class RadixSort 
{
    private static int index(int i, int exp)
    {
        return (i/exp) % 10;
    }


    private static int maxArray(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; i++)
            if (array[i] > max)
                max = array[i];
        
        return max;
    }


    private static void countingSort(int[] array, int n, int exp)
    {
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



    public static void radixSort(int[] array, int n)
    {
        int max = maxArray(array);


        int exp = 1;
        while (max/exp > 0)
        {
            countingSort(array, n, exp);
            exp *= 10;
        }
    }

    


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
