#include <stdio.h>

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *new_node() {
    TreeNode *temp = malloc(sizeof(TreeNode));
    if (temp != NULL) {
        temp->left = temp->right = NULL;
    }
    return temp;
}

// Check if root is NULL before calling
// Helper function for BST_Delete
TreeNode *min(TreeNode *root) {
    if (root->left == NULL) {
        return root;
    }
    else {
        return min(root->left);
    }
}

TreeNode *BST_Delete(TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->val) {
        root->left = BST_Delete(root->left, key);
    }
    else if (key > root->val) {
        root->right = BST_Delete(root->right, key);

    }
    else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = min(root->right);
        root->val = temp->val;
        root->right = BST_Delete(root->right, temp->val);
    }

    return root;
}

TreeNode *BST_Insert(TreeNode *root, int key) {
    if (root == NULL) {
        TreeNode *temp = new_node();
        if (temp != NULL) {
            temp->val = key;
        }
        else {
            return NULL;
        }

        return temp;
    }

    if (key < root->val) {
        root->left = BST_Insert(root->left, key);
    }
    else if (key >= root->val) {
        root->right = BST_Insert(root->right, key);
    }

    return root;
}

TreeNode *BST_Search(TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->val) {
        return BST_Search(root->left, key);
    }
    else if (key > root->val) {
        return BST_Search(root->right, key);
    }
    else {
        return root;
    }
}

int main(void) {}
