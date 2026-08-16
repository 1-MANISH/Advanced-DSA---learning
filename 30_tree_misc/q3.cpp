#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    vector<TreeNode*> st;
    st.push_back(root);
    while (!st.empty()) {
        TreeNode* nd = st.back();
        st.pop_back();
        if (nd->val == val) return nd;
        if (nd->left)  st.push_back(nd->left);
        if (nd->right) st.push_back(nd->right);
    }
    return nullptr;
}

/*
    Implement only the function below.
    Return the lowest common ancestor of the nodes p and q: the lowest node in
    the tree that has both p and q as descendants (a node may be a descendant
    of itself).
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;

        if(root==p or root==q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // at this node (p and q find)
        if(left!=NULL && right!=NULL)return root;

        // p found
        if(left!=NULL && right==NULL)return left;

        // q found
        if(left==NULL && right!=NULL)return right;

        // nothing found
        return NULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int pv, qv;
    cin >> pv >> qv;

    TreeNode* root = buildTree(nodes);
    TreeNode* p = findNode(root, pv);
    TreeNode* q = findNode(root, qv);

    cout << lowestCommonAncestor(root, p, q)->val << '\n';

    return 0;
}