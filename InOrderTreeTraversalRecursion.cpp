#include <iostream>
#include <stack>
#include <vector>



 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    static std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        helper(root, res);
        return res;
    }
    static void helper(TreeNode* root, std::vector<int>& res) {
        if (root != NULL) {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
};

// Example Usage (Main function)
int main() {
    /* 10
         /  \
        5    15
       / \    \
      3   7    20
    */

    // Create the sample tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);

    std::cout << "In-Order Traversal (Iterative):" << std::endl;
    std::vector<int> res = Solution::inorderTraversal(root); // Expected Output: 3 5 7 10 15 20 

    for (auto values : res) {
        std::cout << "Node Value: " << values << std::endl;
    }


    std::cout << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
