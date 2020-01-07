import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class StringProblemsTest {

    @Test
    void compressString() {
        StringProblems problems = new StringProblems();
        assertEquals(problems.compressString("AAAAABBBBBCCCCCC"), "A5B5C6");
        assertEquals(problems.compressString("aaabbbcccddddeeeeccc"), "a3b3c6d4e4");
        assertEquals(problems.compressString("AAAaaaaAAAaaaaAAAAaaa"), "A10a11");
        assertEquals(problems.compressString("aabb"), "aabb");
    }

    @Test
    void testRotateSquareMatrix() {
        StringProblems problems = new StringProblems();
        int[][] matrix_a = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };
        int[][] matrix_a_sol = {
                {3, 6, 9},
                {2, 5, 8},
                {1, 4, 7}
        };
        int[][] matrix_b = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
        };
        int[][] matrix_b_sol = {
                {4, 8, 12, 16},
                {3, 7, 11, 15},
                {2, 6, 10, 14},
                {1, 5, 9, 13}
        };
        assertTrue(Arrays.deepEquals(problems.rotateSquareMatrix(matrix_a), matrix_a_sol));
        assertTrue(Arrays.deepEquals(problems.rotateSquareMatrix(matrix_b), matrix_b_sol));
    }

    @Test
    void testZeroOutMatrix() {
        StringProblems problems = new StringProblems();
        int[][] matrix_c = {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        int[][] matrix_c_sol = {
                {1, 0, 1},
                {0, 0, 0},
                {1, 0, 1}
        };
        int[][] matrix_d = {
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 0}
        };
        int[][] matrix_d_sol = {
                {1, 1, 0},
                {1, 1, 0},
                {1, 1, 0},
                {1, 1, 0},
                {0, 0, 0}
        };
        assertTrue(Arrays.deepEquals(problems.zeroOutMatrix(matrix_c), matrix_c_sol));
        assertTrue(Arrays.deepEquals(problems.zeroOutMatrix(matrix_d), matrix_d_sol));
    }

}