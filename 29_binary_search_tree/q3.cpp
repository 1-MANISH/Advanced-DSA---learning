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
    Delete the node whose value equals `key` from the BST and return the new
    root. To delete a node that has two children, replace its value with its
    in-order successor (the smallest value in its right subtree), then delete
    that successor from the right subtree. If `key` is not present, return the
    tree unchanged.
*/

int MIN(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        
        //left me chalo
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){// right me chalo
            root->right=deleteNode(root->right,key);
        }else{

            // leaf node need to delete
            if(root->left==NULL and root->right==NULL){
                return NULL;
            }
            // node with only left
            if(root->left!=NULL and root->right==NULL){
                return root->left;
            }
            //  node with only right
            if(root->left==NULL and root->right!=NULL){
                return root->right;
            }
            // node with both - left and right
            int mn = MIN(root->right);
            root->val = mn;
            // delete mx from root->left
            root->right=deleteNode(root->right,mn);
            
        }
        return root; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int key;
    cin >> key;

    TreeNode* root = buildTree(nodes);

    root = deleteNode(root, key);

    cout << serialize(root) << '\n';

    return 0;
}