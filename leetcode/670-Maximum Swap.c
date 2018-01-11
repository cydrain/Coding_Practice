/*
 * Maximum Swap
 *
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 *
 * Example 1:
 *   Input: 2736
 *   Output: 7236
 *   Explanation: Swap the number 2 and the number 7.
 *
 * Example 2:
 *   Input: 9973
 *   Output: 9973
 *   Explanation: No swap.
 */
class Solution {
public:
    int maximumSwap(int num) {
        string numstr = std::to_string(num);

        int maxidx = -1, maxdigit = -1;
        int leftidx = -1, rightidx = -1;        

        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more 
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        std::swap(numstr[leftidx], numstr[rightidx]);

        return std::stoi(numstr);
    }
};


class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int len = s.length(), i, j;
        int maxidx;
        for (i = 0; i < len; i++) {
            maxidx = i;
            for (j = len-1; j > i; j--) {
                if (s[j] > s[maxidx]) {
                    maxidx = j;
                }
            }
            if (maxidx != i) {
                swap(s[maxidx], s[i]);
                break;
            }
            
        }
        return stoi(s);
    }
};
