/*
 * Pascal's Triangle II
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1]. 
 *
 */

    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> s;
        
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i-1; j > 0; j--) {
                s[j] += s[j-1];
            }
            s.push_back(1);
        }
        
        return s;
    }
