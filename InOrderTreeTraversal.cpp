#include <iostream>
#include <stack>

// 1. Node Structure Definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 2. Iterative In-Order Traversal Function
void iterativeInorder(TreeNode* root) {
    // A stack to store nodes (ancestors/unvisited right subtrees)
    std::stack<TreeNode*> s;

    // A pointer to traverse the tree
    TreeNode* current = root;

    // Loop continues until we've finished visiting all nodes
    // (current is null AND stack is empty)
    while (current != NULL || !s.empty()) {

        // Phase 1: Go left as far as possible, pushing all ancestors onto the stack
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        // Phase 2: The current node is null (reached the end of a left branch).
        // Pop the most recent ancestor (the "root" of this current subtree).
        current = s.top();
        s.pop();

        // Process (print) the popped node. This is the "Root" step in the L-R-R order.
        std::cout << current->val << " ";

        // Phase 3: Move to the right subtree of the processed node. 
        // The loop will then repeat Phase 1 on this new subtree.
        current = current->right;
    }
}

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
    iterativeInorder(root); // Expected Output: 3 5 7 10 15 20 
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
