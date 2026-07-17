#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoll(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoll(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoll(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

// ================= STUDENT FUNCTION =================
vector<long long> levelOrder(TreeNode* root) {
    vector<long long>output;
    if(root==NULL)return output;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        output.push_back(node->val);
        if(node->left!=NULL)q.push(node->left);
        if(node->right!=NULL)q.push(node->right);
    }
    return output;
}
// ====================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<long long> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}