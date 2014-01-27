/*
 * 3Sum Closest
 *
 * Given an array S of n integers, find three integers in S such
 * that the sum is closest to a given number, target.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 *
 */

    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int i, j, k;
        int sum, r = num[0] + num[1] + num[n-1];
        
        sort(num.begin(), num.end());
        for (i = 0; i < n; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                sum = num[i] + num[j] + num[k];
                if (sum == target) return sum;
                if (abs(sum-target) < abs(r-target)) {
                    r = sum;
                }
                if (sum > target) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }
        
        return r;
    }
