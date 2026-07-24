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
    Return the anti-clockwise boundary traversal of the binary tree
    (root, left boundary, leaves left-to-right, right boundary).
*/

void leftTraversal(TreeNode* root,vector<int>&leftBoundary){
    if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)return;
	leftBoundary.push_back(root->val);
    if(root->left!=NULL)leftTraversal(root->left,leftBoundary);
    else leftTraversal(root->right,leftBoundary);
}
void rightTraversal(TreeNode* root,vector<int>&rightBoundary){
    if(root==NULL)return;
	if(root->left==NULL && root->right==NULL)return;
    if(root->right!=NULL)rightTraversal(root->right,rightBoundary);
    else rightTraversal(root->left,rightBoundary);
	rightBoundary.push_back(root->val);
}

void leafNodeTraversal(TreeNode* root,vector<int>&leafNodes){
	if(root==NULL)return;
	if(root->left==NULL && root->right==NULL){
		leafNodes.push_back(root->val);
		return;
	}
	leafNodeTraversal(root->left,leafNodes);
	leafNodeTraversal(root->right,leafNodes);
}

vector<int> boundary(TreeNode* root) {
	vector<int>output;
	if(root==NULL)return output;
	output.push_back(root->val);
	if(root->left==NULL && root->right==NULL)return output;
	leftTraversal(root->left , output);
	leafNodeTraversal(root,output);
	rightTraversal(root->right,output);

	return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<int> ans = boundary(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}