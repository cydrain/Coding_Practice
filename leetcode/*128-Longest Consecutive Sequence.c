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

/* C solution */
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        map<int,bool> m;
        int i, l, r, curr;
        int len, maxlen = 0;
        
        for (i = 0; i < n; i++) {
            m[num[i]] = false;
        }
        for (i = 0; i < n; i++) {
            curr = num[i];
            if (m[curr]) continue;
            m[curr] = true;
            len = 1;
            
            for (l = curr-1; m.find(l) != m.end() && !m[l]; l--) {
                m[l] = true;
                len++;
            }
            for (r = curr+1; m.find(r) != m.end() && !m[r]; r++) {
                m[r] = true;
                len++;
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};


/* Java solution */
public class Solution {
    public int longestConsecutive(int[] num) {
        Map<Integer,Boolean> m = new HashMap<>();
        int n = num.length;
        int i, l, r;
        int curr, len, maxlen = 0;
        
        for (i = 0; i < n; i++) {
            m.put(num[i], false);
        }
        for (i = 0; i < n; i++) {
            curr = num[i];
            if (m.get(num[i])) continue;
            m.replace(num[i], true);
            len = 1;
            
            for (l = curr-1; m.containsKey(l) && !m.get(l); l--) {
                m.replace(l, true);
                len++;
            }
            for (r = curr+1; m.containsKey(r) && !m.get(r); r++) {
                m.replace(r, true);
                len++;
            }
            maxlen = Math.max(maxlen, len);
        }
        return maxlen;
    }
}

