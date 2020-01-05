#include <iostream>
#include <string>

using namespace std;

/**
 * Determines if the given string as all unique characters.
 * Time complexity: O(N^2)
 * @param str - The input argument, given as a string.
 * @return
 *  true: the string contains all unique characters.
 *  false: the string has one or more duplicate characters.
 */
bool isUnique(string str) {
    if (str.empty()) {
        return false;
    } else {
        for (int i = 0; i < str.size(); ++i) {
            for (int j = i + 1; j < str.size(); ++j) {
                if (str[i] == str[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}

/**
 * Determines if one string can be a permutation of the other.
 * Time complexity: O(N)
 * @param a - The first string
 * @param b - The second string
 * @return
 *  True: Is a permutation
 *  False: Is not a permutation
 */
bool checkPermutation(string a, string b) {
    if ((a.empty() || b.empty()) && (a.size() != b.size())) {
        return false;
    } else {
        int a_ascii = 0;
        int b_ascii = 0;
        // They could now be a permutation of each other.
        for (int i = 0; i < a.size(); ++i) {
            a_ascii += int(tolower(a[i]));
            b_ascii += int(tolower(b[i]));
        }
        return a_ascii == b_ascii;
    }
}

int main() {
    // True
    string unique_test_1 = "abcdefghijklmnopqrstuvwxyz";
    // False
    string unique_test_2 = "UNIQUE";

    cout << isUnique(unique_test_1) << endl;
    cout << isUnique(unique_test_2) << endl;

    // True
    string permutation_test_1_a = "abc";
    string permutation_test_1_b = "CBA";

    // False
    string permutation_test_2_a = "mama";
    string permutation_test_2_b = "papa";

    cout << checkPermutation(permutation_test_1_a, permutation_test_1_b) << endl;
    cout << checkPermutation(permutation_test_2_a, permutation_test_2_b) << endl;

    return 0;
}


