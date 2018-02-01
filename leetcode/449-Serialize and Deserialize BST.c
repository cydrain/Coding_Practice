/*
 * Serialize and Deserialize BST
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible. 
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void serialize(TreeNode* root, string& token) {
        if (root == nullptr) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        for (int i = 0; i < 4; i++) token.push_back(buf[i]);
        serialize(root->left, token);
        serialize(root->right, token);
    }
    string serialize(TreeNode* root) {
        string token;
        serialize(root, token);
        return token;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserializeHelper(string& data, int& pos, int low, int high) {
        if (pos >= data.length()) return nullptr;
        int val;
        memcpy(&val, &data[pos], sizeof(int));
        if (val < low || val > high) return nullptr;
        TreeNode* node = new TreeNode(val);
        pos += sizeof(int);
        node->left = deserializeHelper(data, pos, low, val);
        node->right = deserializeHelper(data, pos, val, high);
        return node;
    }
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos, INT_MIN, INT_MAX);
    }
};
