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
    Return the number of nodes in the largest subtree of the given binary tree
    that is itself a valid Binary Search Tree.
*/

struct Data{
  bool isBst=true;
  int size = 0;
  int minimum = INT_MAX;
  int maximum = INT_MIN;
  int largerBstSize=0;
};
Data largerBST(TreeNode * root){
        if(root==NULL)return Data();
        
        Data left = largerBST(root->left);
        Data right = largerBST(root->right);
        
        Data ans;
        ans.minimum = min(root->val , min(left.minimum,right.minimum));
        ans.maximum = max(root->val , max(left.maximum,right.maximum));
        ans.isBst = left.maximum< root->val && right.minimum>root->val && left.isBst && right.isBst;
        ans.size = left.size+right.size+1;
        if(ans.isBst){
            ans.largerBstSize = ans.size;
        }else{
            ans.largerBstSize = max(left.largerBstSize,right.largerBstSize);
        }
        
        return ans;
}
int largestBst(TreeNode* root) {
    Data d = largerBST(root);
    return d.largerBstSize;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << largestBst(root) << '\n';

    return 0;
}