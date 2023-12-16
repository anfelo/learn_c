#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchNode {
  int data;
  struct BinarySearchNode *left;
  struct BinarySearchNode *right;
} BinarySearchNode;

BinarySearchNode* createBSNode(int value) {
    BinarySearchNode *bsnode = (BinarySearchNode*)malloc(sizeof(struct BinarySearchNode));
    if (bsnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    bsnode->data  = value;
    bsnode->left = NULL;
    bsnode->right = NULL;

    return bsnode;
}

void freeBST(BinarySearchNode *bsnode) {
    if (bsnode == NULL) {
        return;
    }

    freeBST(bsnode->left);
    freeBST(bsnode->right);

    free(bsnode);
}

void insert(BinarySearchNode *bsnode, int value) {
    if (bsnode == NULL) {
        return;
    }

    if (bsnode->data > value && bsnode->left == NULL) {
        bsnode->left = createBSNode(value);
        return;
    }

    if (bsnode->data < value && bsnode->right == NULL) {
        bsnode->right = createBSNode(value);
        return;
    }

    if (bsnode->data > value && bsnode->left != NULL) {
        return insert(bsnode->left, value);
    }

    if (bsnode->data < value && bsnode->right != NULL) {
        return insert(bsnode->right, value);
    }
}

int search(BinarySearchNode *bsnode, int value) {
    if (bsnode == NULL) {
        return -1;
    }

    if (bsnode->data == value) {
        return bsnode->data;
    }

    if (bsnode->data > value) {
        return search(bsnode->left, value);
    } else {
        return search(bsnode->right, value);
    }
}

BinarySearchNode *lift(BinarySearchNode *bsnode, BinarySearchNode *nodeToDelete) {
    if (bsnode->left == NULL) {
        nodeToDelete->data = bsnode->data;
        return bsnode->right;
    } else {
        bsnode->left = lift(bsnode->left, nodeToDelete);
        return bsnode;
    }
}

BinarySearchNode *delete(BinarySearchNode *bsnode, int value) {
    if (bsnode == NULL) {
        return NULL;
    }

    if (bsnode->data == value) {
        if (bsnode->left == NULL && bsnode->right == NULL) {
            return NULL;
        }

        if (bsnode->left == NULL) {
            return bsnode->right;
        } else if (bsnode->right == NULL) {
            return bsnode->left;
        }

        if (bsnode->left != NULL && bsnode->right != NULL) {
            bsnode->right = lift(bsnode->right, bsnode);
            return bsnode;
        }
    }

    if (bsnode->data > value) {
        bsnode->left = delete(bsnode->left, value);
        return bsnode;
    } else {
        bsnode->right = delete(bsnode->right, value);
        return bsnode;
    }
}

void printDepthFirst(BinarySearchNode *bsnode) {
    if (bsnode == NULL) {
        return;
    }

    printf("( %d )", bsnode->data);
    printDepthFirst(bsnode->left);
    printDepthFirst(bsnode->right);
}

void printBreathFirst(BinarySearchNode *bsnode) {
    BinarySearchNode *nodes[10];
    nodes[0] = bsnode;
    int nodes_len = 1;

    while (nodes_len > 0) {
        BinarySearchNode *curr = nodes[0];
        nodes_len--;

        printf("(%d)", curr->data);

        if (curr->left != NULL) {
            nodes[nodes_len] = curr->left;
            nodes_len++;
        }

        if (curr->right != NULL) {
            nodes[nodes_len] = curr->right;
            nodes_len++;
        }
    }
}

int main(int argc, char *argv[]) {
    BinarySearchNode *bsroot= createBSNode(51);

    printBreathFirst(bsroot);
    printf("\n");

    printf("first level:\n");
    insert(bsroot, 40);
    insert(bsroot, 60);

    printBreathFirst(bsroot);
    printf("\n");

    printf("second level:\n");
    insert(bsroot, 20);
    insert(bsroot, 45);
    insert(bsroot, 100);
    insert(bsroot, 59);

    printBreathFirst(bsroot);
    printf("\n");

    int found = search(bsroot, 100);
    printf("Expected: %d Found: %d\n", 100, found);

    found = search(bsroot, 33);
    printf("Expected %d Found: %d\n", -1, found);


    printf("time to delete\n");

    delete(bsroot, 20);
    printBreathFirst(bsroot);
    printf("\n");

    freeBST(bsroot);

    return 0;
}
