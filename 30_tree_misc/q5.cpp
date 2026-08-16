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
    `preorder` and `inorder` are the preorder and inorder traversals of the same
    binary tree (all values distinct). Construct that tree and return its root.
*/
unordered_map<int,int>mapping;//ele->index
TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd ,  int inStart,int inEnd){

        if(preStart>preEnd)return NULL;
        // base case
        auto root = new TreeNode(preorder[preStart]);

        int idx = mapping[root->val];

        int leftSubTreeSize = idx-inStart;
        root->left = helper(preorder,inorder,preStart+1,preStart+leftSubTreeSize,inStart,idx-1);
        root->right = helper(preorder,inorder,preStart+leftSubTreeSize+1,preEnd,idx+1,inEnd);

        return root;

}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i  =0 ; i< n ; i++)mapping[inorder[i]]=i;
        return helper(preorder,inorder,0,n-1,0,n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    TreeNode* root = buildTree(preorder, inorder);

    cout << serialize(root) << '\n';
    return 0;
}