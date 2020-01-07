import java.util.Arrays;

/**
 * @author Tyler Crowe
 * @version v1.0.0 - 1/7/2019
 */
public class StringProblems {

    /**
     * Method for compressing a string. For this algorithm, we're given a string as a parameter and
     * asked to "compress" it down to it's character and count representation. For example: The
     * string AAaaBBbbCCcc becomes A2a2B2b2C2c2. Note, these two strings are equal in length. When
     * this occurs, we return the given string. We only return the compressed string when the length
     * after compression is less than the given string's length.
     * @param a - The given string to compress.
     * @return - The compressed string.
     */
    public String compressString(String a) {
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

    /**
     * Rotates a given N*N matrix by 90 degrees.
     *
     * 0 1 0        ----->        0 1 0
     * 1 0 0        --90->        0 0 1
     * 0 0 1        ----->        1 0 0
     *
     * Note: We can improve this by considering how a matrix is rotated. Below is a brief discussion of the technique:
     * [1] 2 [3]                                                                    [3] 2 [9]
     *  4  5  6      ---> start by rotating these elements counter clockwise --->    4  5  6
     * [7] 8 [9]                                                                    [1] 8 [7]
     *
     *  3 [2] 9                                                                      3 [6] 9
     * [4] 5 [6]      ---> then rotate these elements counter clockwise       --->  [2] 5 [8]
     *  1 [8] 7                                                                      1 [4] 7
     *
     * This method will use considerably (depending of course the size of the given array) less space in memory because
     * it alters the given array instead of populating a new one of the same size. However, the complexity remains at
     * O(N^2).
     *
     * Time complexity: O(N^2)
     * @param a - The matrix to be rotated.
     * @return - The rotated matrix by 90 degrees.
     */
    public int[][] rotateSquareMatrix(int[][] a) {
        // Basic principle: read from incoming matrix a's nth column and write to b's nth row.
        int[][] b = new int[a.length][a.length]; // Always a square matrix.

        int track = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = a.length - 1; j >= 0; j--) {
                b[track][i] = a[i][j];
                track++;
            }
            track = 0;
        }
        return b;
    }

    /**
     * Given an M*N matrix, zero out the nth row and column if an element at the evaluating position is zero.
     * 0 1 1      0 0 0
     * 1 1 1  ->  0 1 1
     * 1 1 1      0 1 1
     * Time complexity: O(N)
     * @param a - The given M*N matrix. Where M can be >, <, or = to N
     * @return - The newly created array.
     */
    public int[][] zeroOutMatrix(int[][] a) {
        int[][] b = new int[a.length][a[0].length];
        // Thought process: Find where zeros are present in the given matrix. Then take note of the row number and
        //  column number when a zero is found.
        boolean[] rows = new boolean[a.length];
        boolean[] cols = new boolean[a[0].length];

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if (a[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                if(rows[i] || cols[j]) {
                    b[i][j] = 0;
                } else {
                    b[i][j] = a[i][j];
                }
            }
        }

        return b;
    }

    public static void main(String[] args) {
        new StringProblems();
    }

}
