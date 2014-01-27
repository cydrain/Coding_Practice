/*
 * Largest Rectangle in Histogram
 *
 * Given n non-negative integers representing the histogram's bar height
 * where the width of each bar is 1, find the area of largest rectangle 
 * in the histogram. 
 *
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10. 
 *
 */

    int largestRectangleArea(vector<int> &h) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        int i = 0, t;
        int m = 0;
        
        h.push_back(0);
        while (i < h.size()) {
            if (s.empty() || h[i] >= h[s.top()]) {
                s.push(i++);
            }
            else {
                t = s.top();
                s.pop();
                m = max(m, h[t] * (s.empty() ? i : (i-s.top()-1)));
            }
        }
        return m;
    }
