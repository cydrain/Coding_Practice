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
 
/* C solution */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = num.size();
        vector<vector<int>> result;
        vector<int> triplet(3, 0);
        int sum;
        int i, l, r;
        
        sort(num.begin(), num.end());
        for (i = 0; i < n; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            l = i+1;
            r = n-1;
            while (l < r) {
                sum = num[i] + num[l] + num[r];
                if (sum == 0) {
                    triplet[0] = num[i];
                    triplet[1] = num[l];
                    triplet[2] = num[r];
                    result.push_back(triplet);
                    do {
                        l++;
                    } while (l < r && num[l] == num[l-1]);
                    do {
                        r--;
                    } while (l < r && num[r] == num[r+1]);
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};


/* Java solution */
public class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> r = new ArrayList<List<Integer>>();
        int n = num.length;
        int i, j, k, sum;
        
        Arrays.sort(num);
        for (i = 0; i < n; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            j = i + 1;
            k = n - 1;
            while (j < k) {
                sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    List<Integer> l = new ArrayList<Integer>();
                    l.add(num[i]);
                    l.add(num[j]);
                    l.add(num[k]);
                    r.add(l);
                    do {
                        j++;
                    } while (j < k && num[j] == num[j-1]);
                    do {
                        k--;
                    } while (j < k && num[k] == num[k+1]);
                } else if (sum < 0) {
                    do {
                        j++;
                    } while (j < k && num[j] == num[j-1]);
                } else {
                    do {
                        k--;
                    } while (j < k && num[k] == num[k+1]);
                }
            }
        }
        return r;
    }
}

