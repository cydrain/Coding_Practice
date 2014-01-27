/*
 * 3Sum
 *
 * Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *
 * For example, given array S = {-1 0 1 2 -1 -4},
 * 
 * A solution set is:
 *  (-1, 0, 1)
 *  (-1, -1, 2)
 *
 */
 
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        int n = num.size();
        if (n < 3) return r;
        int i, left, right;
        int sum;
        vector<int> p(3);
        sort(num.begin(), num.end());
        for (i = 0; i < n-2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            left = i+1;
            right = n-1;
            while (left < right) {
                sum = num[i] + num[left] + num[right];
                if (sum == 0) {
                    p[0] = num[i];
                    p[1] = num[left];
                    p[2] = num[right];
                    r.push_back(p);
                    do {
                        left++;
                    } while(left < right && num[left] == num[left-1]);
                    do {
                        right--;
                    } while (left < right && num[right] == num[right+1]);
                }
                else if (sum > 0) {
                    do {
                        right--;
                    } while (left < right && num[right] == num[right+1]);
                }
                else {
                    do {
                        left++;
                    } while (left < right && num[left] == num[left-1]);
                }
            }
        }
        return r;
    }
