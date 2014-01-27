/*
 * Convert Sorted List to Binary Search Tree
 *
 * Given a singly linked list where elements are sorted in ascending
 * order, convert it to a height balanced BST.
 *
 */

    TreeNode *sortedListToBST(ListNode* &head, int start, int end) {        
        if (start > end) return NULL;
        int m = (start + end) / 2;
        TreeNode *leftChild = sortedListToBST(head, start, m-1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = leftChild;
        root->right = sortedListToBST(head, m+1, end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *tmp = head;
        int n = 0;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        return sortedListToBST(head, 1, n);
    }
