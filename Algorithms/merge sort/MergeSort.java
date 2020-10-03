import java.util.Arrays;




/**
 * Use {@link MergeSort#mergeSort(int, int, int...)} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class MergeSort
{
    /**
     * a simple method that merge to parts of a array
     * 
     * 
     * @param array : the main array
     * @param startIndex : first index of first part
     * @param midIndex : last index of first part and first index of second part
     * @param lastIndex : last index of second part
     */
    public static void merge(int[] array, int startIndex, int midIndex, int lastIndex)
    {
        // calculate the size of the sub arrays
    int rightSubArraySize = midIndex - startIndex + 1;
    int leftSubArraySize = lastIndex - midIndex;



    // initialize first sub array
    int[] rightArray = new int[rightSubArraySize + 1];
    for (int i = 0; i < rightSubArraySize; i++)
        rightArray[i] = array[startIndex + i];


    // initialize second sub array
    int[] leftArray = new int[leftSubArraySize + 1];
    for (int j = 0; j < leftSubArraySize; j++)
        leftArray[j] = array[midIndex + j + 1];


    

    // set sentinels
    rightArray[rightSubArraySize] = Integer.MAX_VALUE;
    leftArray[leftSubArraySize] = Integer.MAX_VALUE;



    // merging
    int i = 0, j = 0;
    for (int k = startIndex; k <= lastIndex; k++)
        if (rightArray[i] <= leftArray[j])
            array[k] = rightArray[i++];
        else
            array[k] = leftArray[j++];
    }


    /**
     * This method sorts your int array with merge sort algorithm
     * 
     * 
     * @param startIndex : for start set it to 0
     * @param lastIndex : for start set it to array.lenght-1
     * @param array : array to sort
     */
    public static int[] mergeSort(int startIndex, int lastIndex, int...array)
    {
        if (startIndex < lastIndex)
        {
            int midIndex = (startIndex + lastIndex)/2;


            // sort first half
            mergeSort(startIndex, midIndex, array);

            // sort second half
            mergeSort(midIndex+1, lastIndex, array);

            // merge two halfs
            merge(array, startIndex, midIndex, lastIndex);


            return array;
        }

        return new int[0];
    }


    /**
     * A simple example for {@link MergeSort#mergeSort(int...)}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        int[] array = {8, 10, 252, 0, -34, 23, -11, 43, 50, 101, 7, 33, 12};
        System.out.println("before sort: " + Arrays.toString(array));


        mergeSort(0, array.length-1, array);
        System.out.println("after sort: " + Arrays.toString(array));


        System.out.println("\n ---------------- \n\n");
    }
}