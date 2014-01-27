/*
 * Longest Consecutive Sequence
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * For example,
 *  Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4].
 * Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity. 
 *
 */

    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int,int> s;
        int left, right;
        int len, maxlen = 0;
        int i;
        
        for (i = 0; i < num.size(); i++) {
            s[num[i]] = 1;
        }
        for (i = 0; i < num.size(); i++) {
            if (s[num[i]] == 1) {
                s[num[i]] = 0;
                len = 1;
                left = num[i]-1;
                right = num[i]+1;
                
                while (s.find(left) != s.end()) {
                    s[left--] = 0;
                    len++;
                }
                while (s.find(right) != s.end()) {
                    s[right++] = 0;
                    len++;
                }
                
                maxlen = max(maxlen, len);
            }
        }
        
        return maxlen;
    }
