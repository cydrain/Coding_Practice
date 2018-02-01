/*
 * Serialize and Deserialize Binary Tree
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following tree
 *
 *    1
 *   / \
 *  2   3
 *     / \
 *    4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary
 * tree. You do not necessarily need to follow this format, so please be creative
 * and come up with different approaches yourself.
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        string token = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return token;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    
    TreeNode* mydeserialize(string& data) {
        if (data[0] == '#') {
            if (data.length() > 1) data = data.substr(2);
            return NULL;
        } else {
            int pos = data.find(',');
            TreeNode* node = new TreeNode(stoi(data.substr(0,pos)));
            data = data.substr(pos+1);
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
};



class Codec {
public:
    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root, string& token) {
        if (root == nullptr) {
            token += "#,";
            return;
        } else {
            token += to_string(root->val);
            token += ",";
            serializeHelper(root->left, token);
            serializeHelper(root->right, token);
        }
    }
    string serialize(TreeNode* root) {
        string token;
        serializeHelper(root, token);
        return token;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserializeHelper(string& data, int& pos) {
        if (data[pos] == '#') {
            pos += 2;
            return nullptr;
        } else {
            int comma = data.find_first_of(',', pos);
            int val = stoi(data.substr(pos, comma-pos));
            pos = comma + 1;
            TreeNode* node = new TreeNode(val);
            node->left = deserializeHelper(data, pos);
            node->right = deserializeHelper(data, pos);
            return node;
        }
    }
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }
};
