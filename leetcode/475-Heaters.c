/*
 * Heaters

Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

    Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
    Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
    As long as a house is in the heaters' warm radius range, it can be warmed.
    All the heaters follow your radius standard and the warm radius will the same.

Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:

Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
 */
class Solution {
public:
    int findRadius(vector<int>& A, vector<int>& H) {
        sort(A.begin(), A.end());
        sort(H.begin(), H.end());
        vector<int> res(A.size(), INT_MAX); 
        
        // For each house, calculate distance to nearest RHS heater
        for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
            if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
            else { h++; }
        }
        
        // For each house, calculate distance to nearest LHS heater
        for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
            if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
            else { h--; }
        }
       
        return *max_element(res.begin(), res.end());
    }
};


class Solution {
public:
    int getClosestHeaterDistance(vector<int>& heaters, int pos) {
        int n = heaters.size();
        int l = 0, r = n-1, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (pos < heaters[mid]) {
                r = mid - 1;
            } else if (pos == heaters[mid]) {
                l = mid;
                break;
            } else {
                l = mid + 1;
            }
        }
        if (l == 0) {
            return heaters[0] - pos;
        } else if (l == n) {
            return pos - heaters[n-1];
        } else {
            return min(heaters[l]-pos, pos-heaters[l-1]);
        }
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int i, minRadius = 0;
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++) {
            minRadius = max(minRadius, getClosestHeaterDistance(heaters, houses[i]));
        }
        return minRadius;
    }
};
