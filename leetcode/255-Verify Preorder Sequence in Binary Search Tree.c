/*
 * Verify Preorder Sequence in Binary Search Tree
 *
 * Given an array of numbers, verify whether it is the correct preorder traversal
 * sequence of a binary search tree.
 *
 * You may assume each number in the sequence is unique.
 */
// 1848ms
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder, int start, int end, long long lb, long long rb) {
        if (start >= end) return true;
        int i;
        for (i = start; i <= end; i++) {
            if (preorder[i] <= lb || preorder[i] >= rb) return false;
        }
        for (i = start+1; i <= end; i++) {
            if (preorder[i] > preorder[start]) break;
        }
        return (verifyPreorder(preorder, start+1, i-1, lb, preorder[start]) && 
                verifyPreorder(preorder, i, end, preorder[start], rb));
    }
    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorder(preorder, 0, preorder.size()-1, (long long)INT_MIN-1, (long long)INT_MAX+1);
    }
};


// 51ms
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int low = INT_MIN;
        for (int val : preorder) {
            if (val < low) return false;
            while (!s.empty() && val > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(val);
        }
        return true;
    }
};
