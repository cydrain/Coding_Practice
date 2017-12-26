/*
 * Repeated String Match
 *
 * Given two strings A and B, find the minimum number of times A has to be repeated
 * such that B is a substring of it. If no such solution, return -1.
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring
 * of it; and B is not a substring of A repeated two times ("abcdabcd"). 
 */
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lena = A.length();
        int lenb = B.length();
        string AA;
        while (AA.length() < lenb) {
            AA.append(A);
        }
        while (AA.length() <= (lenb/lena+2)*lena) {
            if (AA.find(B) != string::npos) return (AA.length() / lena);
            AA.append(A);
        }
        return -1;
    }
};
