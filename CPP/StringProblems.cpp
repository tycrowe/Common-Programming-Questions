/**
 * @author Tyler Crowe
 * @version v1.0.0 - January 5th, 2020
 */
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
bool is_unique(string str) {
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
bool check_permutation(string a, string b) {
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

/**
 * Given a string of 'length', replace all appropriate whitespace with "%20". Appropriate whitespace is defined as a
 * space between two words. For example, "Tyler Crowe   ". The trailing whitespace at the end of the former string is
 * noted as "inappropriate" whitespace.
 * Time complexity:
 * @param a - The given input string to convert into a url.
 * @param length - The "true" length of string. Which is determined by the size minus inappropriate whitespace capacity.
 * @return A new string, of the given string, now represented as a URL.
 */
string make_url(string a, int length) {
    string url;

    for (int i = 0; i < length; ++i) {
        if(a[i] == ' ') {
            url.append("%20");
        } else {
            url.append(1, a[i]);
        }
    }

    return url;
}

int main() {
    // True
    string unique_test_1 = "abcdefghijklmnopqrstuvwxyz";
    // False
    string unique_test_2 = "UNIQUE";

    cout << is_unique(unique_test_1) << endl;
    cout << is_unique(unique_test_2) << endl;

    // True
    string permutation_test_1_a = "abc";
    string permutation_test_1_b = "CBA";

    // False
    string permutation_test_2_a = "mama";
    string permutation_test_2_b = "papa";

    cout << check_permutation(permutation_test_1_a, permutation_test_1_b) << endl;
    cout << check_permutation(permutation_test_2_a, permutation_test_2_b) << endl;

    string url_test_1 = "Mr John Smith";
    int true_length_1 = 13;

    string url_test_2 = "alluring cute kitten video";
    int true_length_2 = 26;

    cout << make_url(url_test_1, true_length_1) << endl;
    cout << make_url(url_test_2, true_length_2) << endl;

    return 0;
}


