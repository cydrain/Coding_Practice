/*
 * 4Sum
 *
 * Given an array S of n integers, are there elements a, b, c, and d
 * in S such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
 * (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *  A solution set is:
 *   (-1,  0, 0, 1)
 *   (-2, -1, 1, 2)
 *   (-2,  0, 0, 2)
 * 
 */

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        int i, j, s, t;
        int left;
        sort(num.begin(), num.end());
        for (i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (j = i+1; j < num.size(); j++) {
                if (j > i+1 && num[j] == num[j-1]) continue;
                left = target - num[i] - num[j];
                s = j + 1;
                t = num.size() - 1;
                while (s < t) {
                    if (num[s] + num[t] == left) {
                        vector<int> p;
                        p.push_back(num[i]);
                        p.push_back(num[j]);
                        p.push_back(num[s]);
                        p.push_back(num[t]);
                        r.push_back(p);
                        s++;
                        while (num[s] == num[s-1] && s < t) {
                            s++;
                        }
                        t--;
                        while (num[t] == num[t+1] && s < t) {
                            t--;
                        }
                    }
                    else if (num[s] + num[t] > left) {
                        t--;
                        while (num[t] == num[t+1] && s < t) {
                            t--;
                        }
                    }
                    else {
                        s++;
                        while (num[s] == num[s-1] && s < t) {
                            s++;
                        }
                    }
                }
            }
        }
        return r;
    }
