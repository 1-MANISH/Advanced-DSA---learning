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
    Return the top view of the binary tree (left to right).
*/
vector<int> topView(TreeNode* root) {
		vector<int>output;
		if(root==NULL)return output;
		queue<pair<TreeNode*,int>>q;
		unordered_map<int,vector<int>>mp;
		q.push({root,0});
		int start = INT_MAX , end = INT_MIN;
		while(!q.empty()){

			auto[node,dist] = q.front();
			q.pop();
			start = min(start,dist);
			end = max(end,dist);
			mp[dist].push_back(node->val);

			if(node->left!=NULL)q.push({node->left,dist-1});
			if(node->right!=NULL)q.push({node->right,dist+1});
		}
		for(int dist=start;dist<=end;dist++){
			output.push_back(mp[dist][0]);
		}
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

    vector<int> ans = topView(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}