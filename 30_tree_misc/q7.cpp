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

/*
    Implement only the function below.
    Return whether the binary tree is height-balanced, that is, whether the left
    and right subtrees of every node differ in height by no more than 1.
*/
pair<bool,int> isBal(TreeNode* root){
        if(root==NULL)return {true,0};
        auto [b1,h1] = isBal(root->left);
        auto [b2,h2] = isBal(root->right);
        if(b1 && b2 && abs(h1-h2)<=1 ){
            return {true,max(h1,h2)+1};
        }else{
            return {false,max(h1,h2)+1};
        }
    }
bool isBalanced(TreeNode* root) {
	return isBal(root).first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isBalanced(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}