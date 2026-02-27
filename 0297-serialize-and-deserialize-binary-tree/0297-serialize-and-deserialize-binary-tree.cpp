/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    TreeNode* build(string &s, int &i) {
        if (s[i] == '#') {
            i += 2;
            return nullptr;
        }

        int j = i;
        while (s[j] != ',') j++;
        int val = stoi(s.substr(i, j - i));
        i = j + 1;

        TreeNode* node = new TreeNode(val);
        node->left = build(s, i);
        node->right = build(s, i);
        return node;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));