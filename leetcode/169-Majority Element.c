/*
 * Majority Element
 *
 * Given an array of size n, find the majority element. The majority element
 * is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 */

/* C solution */
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        int ele, count = 0;
        int i;
        
        for (i = 0; i < n; i++) {
            if (count == 0) {
                ele = num[i];
                count = 1;
            } else {
                if (ele == num[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        
        return ele;
    }
};

