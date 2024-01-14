#include <stdbool.h>
#include <stdlib.h>

struct MAryTreeNode {
    int value;
    struct MAryTreeNode** children;
    int num_children;
};

bool search_in_mary_tree(struct MAryTreeNode* node, int target) {
    if (node == NULL) {
        return false;
    }
    
    if (node->value == target) {
        return true;
    }
    
    for (int i = 0; i < node->num_children; i++) {
        if (search_in_mary_tree(node->children[i], target)) {
            return true;
        }
    }
    
    return false;
}

void insert_in_mary_tree(struct MAryTreeNode* node, int new_value) {
    // Assuming the node structure allows for modification and insertion
    node->num_children++;
    node->children = realloc(node->children, node->num_children * sizeof(struct MAryTreeNode*));
    
    if (node->children == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    
    node->children[node->num_children - 1] = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
    
    if (node->children[node->num_children - 1] == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    
    node->children[node->num_children - 1]->value = new_value;
    node->children[node->num_children - 1]->num_children = 0;
    node->children[node->num_children - 1]->children = NULL;
}

// Example usage:
// struct MAryTreeNode* root = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
// root->value = 10;
// root->num_children = 2;
// root->children = (struct MAryTreeNode**)malloc(2 * sizeof(struct MAryTreeNode*));
// root->children[0] = create_mary_tree_node(5);
// root->children[1] = create_mary_tree_node(15);
// search_result = search_in_mary_tree(root, 5);
// insert_in_mary_tree(root, 20);


#include <stdio.h>

int main() {
    // Creating an m-way tree:   10
    //                           / | \
    //                          5  15  20
    struct MAryTreeNode* root = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
    root->value = 10;
    root->num_children = 3;
    root->children = (struct MAryTreeNode**)malloc(3 * sizeof(struct MAryTreeNode*));
    root->children[0] = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
    root->children[0]->value = 5;
    root->children[0]->num_children = 0;
    root->children[0]->children = NULL;
    root->children[1] = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
    root->children[1]->value = 15;
    root->children[1]->num_children = 0;
    root->children[1]->children = NULL;
    root->children[2] = (struct MAryTreeNode*)malloc(sizeof(struct MAryTreeNode));
    root->children[2]->value = 20;
    root->children[2]->num_children = 0;
    root->children[2]->children = NULL;

    // Testing search_in_mary_tree function
    int target_value = 15;
    if (search_in_mary_tree(root, target_value)) {
        printf("Value %d found in the m-way tree.\n", target_value);
    } else {
        printf("Value %d not found in the m-way tree.\n", target_value);
    }

    // Testing insert_in_mary_tree function
    int new_value = 25;
    insert_in_mary_tree(root, new_value);
    printf("Inserted new value %d into the m-way tree.\n", new_value);

    // Cleanup
    // Assuming you have a separate cleanup function
    // to free memory for the m-way tree nodes

    return 0;
}
