//Given the root of a binary tree, return the sum of values of its deepest leaves.
//Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
//Output: 15

#include <queue>
#include <iostream>
#include <vector>
#include <string>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int deepestLeavesSum(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty()) {
        sum = 0;  
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return sum;
}

TreeNode* createTreeFromBFS(std::vector<std::string> nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(std::stoi(nodes[0]));
    std::queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < nodes.size(); i++) {
        TreeNode* parent = q.front();
        q.pop();

        if (nodes[i] != "null") {
            TreeNode* leftChild = new TreeNode(std::stoi(nodes[i]));
            parent->left = leftChild;
            q.push(leftChild);
        }

        if (++i < nodes.size() && nodes[i] != "null") {
            TreeNode* rightChild = new TreeNode(std::stoi(nodes[i]));
            parent->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

int main() {
    std::vector<std::string> nodes = {"1", "2", "3", "4", "5", "null", "6", "7", "null", "null", "null", "null", "8"};
    TreeNode* root = createTreeFromBFS(nodes);

    std::cout << "Sum:" << deepestLeavesSum(root) << std::endl;

    return 0;
}
