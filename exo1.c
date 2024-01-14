#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* create_tree(int value, struct TreeNode* left_subtree, struct TreeNode* right_subtree) {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    
    root->value = value;
    root->left = left_subtree;
    root->right = right_subtree;
    
    return root;
}

void destroy_tree(struct TreeNode* root) {
    if (root != NULL) {
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }
}

int node_count(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + node_count(root->left) + node_count(root->right);
}

int main() {
    // Creating a binary tree:  10
    //                          / \
    //                         5   15
    struct TreeNode* root = create_tree(10, create_tree(5, NULL, NULL), create_tree(15, NULL, NULL));

    // Testing node_count function
    int count = node_count(root);
    printf("Number of nodes in the tree: %d\n", count);

    // Destroying the tree
    destroy_tree(root);

    return 0;
}

