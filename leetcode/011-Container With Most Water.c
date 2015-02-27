/*
 * Container With Most Water
 *
 * Given n non-negative integers a1, a2, ..., an, where each
 * represents a point at coordinate (i, ai). n vertical lines
 * are drawn such that the two endpoints of line i is at (i, ai)
 * and (i, 0).
 * Find two lines, which together with x-axis forms a container,
 * such that the container contains the most water.
 *
 * Note: You may not slant the container. 
 *
 */

/* C solution */
    int maxArea(vector<int> &A) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, j = A.size()-1;
        int water = 0;
        
        while (i < j) {
            water = max(water, (j-i)*min(A[i], A[j]));
            if (A[i] < A[j]) {
                i++;
            } else {
                j--;
            }
        }
        return water;
    }


/* Java solution */
public class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int l = 0, r = n-1, h;
        int area = 0;
        while (l < r) {
            h = Math.min(height[l], height[r]);
            area = Math.max(area, h*(r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        } 
        return area;
    }
}

