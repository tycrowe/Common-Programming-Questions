/**
 * @author Tyler Crowe
 * @version v1.0.0 - January 5th, 2020
 */
#include <iostream>
#include <string>

using namespace std;

// Helper Methods
string to_lower_case(string input) {
    for (char &i : input) {
        i = tolower(i);
    }
    return input;
}

string strip_spaces(string input) {
    string restr;
    for (char & i : input) {
        if(i != ' ') {
            restr.append(&i, 1);
        }
    }
    return restr;
}

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
 * Time complexity: O(N)
 * @param a - The given input string to convert into a url.
 * @param length - The "true" length of string. Which is determined by the size minus inappropriate whitespace capacity.
 * @return A new string, of the given string, now represented as a URL.
 */
string make_url(string a, int length) {
    string url;

    for (int i = 0; i < length; ++i) {
        if (a[i] == ' ') {
            url.append("%20");
        } else {
            url.append(1, a[i]);
        }
    }

    return url;
}

/**
 * Given a string, check if it's a permutation of a palindrome.
 * Time complexity: O(N)
 * @param a - The given string that may or may not be a permutation of a palindrome
 * @retun
 *  True: The given string is a permutation of a palindrome.
 *  False: The given string is not a permutation of a palindrome
 */
bool palindrome_permutation(string a) {
    if (!a.empty()) {
        // Attempt to form the given string into a palindrome. If we can, then we know it's true.
        // Start by stripping the spaces and lowering the caps.
        a = to_lower_case(strip_spaces(a));
        // Now, lets try and build a palindrome out of the input 'a'. We can do this by ensuring no more than one
        // character in a string has an odd amount of occurrences.
        int count[256] = {0}; // The size may not be defined, 256 should cover it. a-z, 0-9, A-Z, EN symbols. [ASCII]

        for (char & i : a) count[int(i)]++;
        int odd = 0;
        for (int j : count) {
            if((j & 1) == 1) odd++;
            if(odd > 1) return false;
        }
        return true;
    }
    return false;
}

/**
 * Given two strings, determine how many edits are required for string a to equal string b.
 * Time complexity: O(ab), size of strings a and b are unknown until runtime. Therefor, the execution time is a*b.
 * @param a - The first string to evaluate
 * @param b - The second string to evaluate
 * @return
 *  True: If only one edit is required.
 *  False: If more than one edit is required.
 */
bool one_away(string a, string b) {
    // Ways to edit: replace, append, remove
    // Start by checking the length. If the difference is greater than two, we can assume that at least two characters
    //  must be appended to make a == b. This covers the remove and append cases.
    if ((a.size() - b.size()) > 1) return false;
    int replacements = 0;
    for (char i : a) if(b.find(i) == string::npos) replacements++;
    return replacements == 1;
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

    // Problem 4 - Palindrome Permutation
    string palindrome_permutation_test_1 = "Tact Coa";
    string palindrome_permutation_test_2 = "cRR aac";
    string palindrome_permutation_test_3 = "aaants nogdASAldivesa edaliv agtod";
    cout << palindrome_permutation(palindrome_permutation_test_1) << endl;
    cout << palindrome_permutation(palindrome_permutation_test_2) << endl;
    cout << palindrome_permutation(palindrome_permutation_test_3) << endl;

    // Problem 5 - One Away
    string one_away_test_1a = "pale";
    string one_away_test_1b = "ple";
    string one_away_test_2a = "bale";
    string one_away_test_2b = "pale";
    string one_away_test_3a = "bake";
    string one_away_test_3b = "pale";
    cout << one_away(one_away_test_1a, one_away_test_1b) << endl;
    cout << one_away(one_away_test_2a, one_away_test_2b) << endl;
    cout << one_away(one_away_test_3a, one_away_test_3b) << endl;

    return 0;
}