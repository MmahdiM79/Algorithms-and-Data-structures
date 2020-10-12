import java.util.ArrayList;
import java.util.List;





/**
 * Use {@link BinarySearch#binarySearch(List<Integer>, int)} to 
 *  search for a value in your sorted list
 * 
 * 
 * @author Mohammad Mahdi Malmasi
 * @version 0.1.0
 */
public class BinarySearch
{
    /**
     * This method search for a value in your {@code List<Integer>} with binary search algorithm
     * 
     * @param array : a sorted {@code List<Integer>}
     * @param target : value that you search for it
     */
    public static void binarySearch(List<Integer> array, int target)
    {
        if (array.isEmpty())
        {
            System.out.println("the given array not included the given target");
            return;
        }


        if (array.size() < 2)
        {
            if (array.get(0) == target)
                System.out.println("the given array included the given target");
            else
                System.out.println("the given array not included the given target");


            return;
        }



        int midIndex = 0, start = 0, end = array.size()-1;

        while(true)
        {
            if (start == end)
            {
                System.out.println("the given array not included the given target");
                return;
            }

            midIndex = (start + end)/2;

            if (array.get(midIndex) == target)
            {
                System.out.println("the given array included the given target");
                return;
            }

            if (target > array.get(midIndex))
                start = midIndex+1;
            else
                end = midIndex;
        }
    }



    /**
     * A simple example for {@link BinarySearch#binarySearch(list<Integer, int)}
     *  
     * @param args
     */
    public static void main(String[] args) 
    {
        ArrayList<Integer> array = new ArrayList<>();
        array.add(-45); array.add(-12); array.add(-2); array.add(0); array.add(3); array.add(23); array.add(78);
        array.add(123); array.add(222); array.add(345); array.add(444); array.add(654); array.add(765);
        

        System.out.println("\n\n ---------------- \n");
        System.out.println("a simple test:\n");
        

        System.out.println("array: " + array.toString() + "\n");


        System.out.print("search for -12 in array: ");
        binarySearch(array, -12);
        System.out.print("search for 111 in array: ");
        binarySearch(array, 111);


        System.out.println("\n\n ---------------- \n\n");
    }
}
