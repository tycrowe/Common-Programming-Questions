import java.util.Arrays;

/**
 * @author Tyler Crowe
 * @version v1.0.0 - 1/7/2019
 */
public class StringProblems {

    public StringProblems() {
        System.out.println(compressString("AAAAAAAaaBBbbCCcc"));
    }

    /**
     * Method for compressing a string. For this algorithm, we're given a string as a parameter and
     * asked to "compress" it down to it's character and count representation. For example: The
     * string AAaaBBbbCCcc becomes A2a2B2b2C2c2. Note, these two strings are equal in length. When
     * this occurs, we return the given string. We only return the compressed string when the length
     * after compression is less than the given string's length.
     * @param a - The given string to compress.
     * @return - The compressed string.
     */
    private String compressString(String a) {
        // For our new string
        StringBuilder restr = new StringBuilder();
        // Make a count array.
        int[] count = new int[256];
        for (char c : a.toCharArray()) {
            count[(int) c] += 1;
        }
        for (int i = 0; i < count.length; i++) {
            if(count[i] != 0) {
                restr.append((char) i);
                restr.append(count[i]);
            }
        }
        return (restr.toString().length() >= a.length()) ? a : restr.toString();
    }

    public static void main(String[] args) {
        new StringProblems();
    }

}
