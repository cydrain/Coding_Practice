/*
 * Convert Sorted List to Binary Search Tree
 *
 * Given a singly linked list where elements are sorted in ascending
 * order, convert it to a height balanced BST.
 *
 */

/* C solution */
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


/* Java solution */
public class Solution {
    public TreeNode sortedListToBST(List<ListNode> head, int start, int end) {
        if (start > end) return null;
        int mid = start + (end-start)/2;
        TreeNode left = sortedListToBST(head, start, mid-1);
        TreeNode root = new TreeNode(head.get(0).val);
        head.set(0, head.get(0).next);
        root.left = left;
        root.right = sortedListToBST(head, mid+1, end);
        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        ListNode node = head;
        int n = 0;
        while (node != null) {
            n++;
            node = node.next;
        }
        List<ListNode> list = new ArrayList<>();
        list.add(head);
        return sortedListToBST(list, 1, n);
    }
}

