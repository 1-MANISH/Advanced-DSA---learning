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
    Return the LENGTH of the diameter of the tree: the length of the longest
    path between any two nodes, measured in the NUMBER OF EDGES on that path.
    The path may or may not pass through the root.
*/
 // height diameter
pair<int,int> helper(TreeNode* root){
        if(root==NULL)return {0,0};
        auto[lh,ld] = helper(root->left);
        auto [rh,rd] = helper(root->right);
        // either take root or exclude root
        return {max(lh,rh)+1 , max(lh+rh,max(ld,rd))};
}
int diameterOfBinaryTree(TreeNode* root) {
     return helper(root).second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << diameterOfBinaryTree(root) << '\n';

    return 0;
}