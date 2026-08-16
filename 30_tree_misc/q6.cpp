#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Serialize a tree to its level-order (BFS) form: values separated by single
// spaces, "null" for a missing child, trailing "null"s trimmed. Empty -> "".
string serialize(TreeNode* root) {
    if (!root) return "";
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* nd = q.front();
        q.pop();
        if (!nd) { out.push_back("null"); continue; }
        out.push_back(to_string(nd->val));
        q.push(nd->left);
        q.push(nd->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    string res;
    for (size_t i = 0; i < out.size(); i++) {
        if (i) res += ' ';
        res += out[i];
    }
    return res;
}

/*
    Implement only the function below.
    `inorder` and `postorder` are the inorder and postorder traversals of the same
    binary tree (all values distinct). Construct that tree and return its root.
*/
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0)return NULL;
        
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);

        int idx = -1;
        for(int i = 0 ; i < inorder.size() ;i++){
            if(inorder[i]==postorder[postorder.size()-1]){
                idx = i;
                break;
            }
        }

        vector<int>p_order1;//[0,idx-1] // left
        vector<int>p_order2;//[idx,n-2]; // right
        vector<int>i_order1;//[0,idx-1] // left
        vector<int>i_order2;//[idx+1,n-1]; // right

        for(int i = 0 ; i<idx;i++)p_order1.push_back(postorder[i]);
        for(int i = idx;i<postorder.size()-1;i++)p_order2.push_back(postorder[i]);
        for(int i = 0 ; i< idx;i++)i_order1.push_back(inorder[i]);
        for(int i = idx+1 ; i< inorder.size();i++)i_order2.push_back(inorder[i]);

        TreeNode* left_tree = buildTree(i_order1,p_order1);
        TreeNode* right_tree = buildTree(i_order2,p_order2);

        root->left=left_tree;
        root->right=right_tree;

        return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    TreeNode* root = buildTree(inorder, postorder);

    cout << serialize(root) << '\n';
    return 0;
}