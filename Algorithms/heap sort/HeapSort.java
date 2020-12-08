


/**
 * Use {@link BubbleSort#heapSort(int...)} to sort your {@code int} Array
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class HeapSort 
{
    private int right(int x)
    {
        return 2*x + 2;
    }

    private int left(int x)
    {
        return right(x) - 1;
    }
}
