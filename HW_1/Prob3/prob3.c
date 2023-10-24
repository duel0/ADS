#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* parent;
    struct node* left;
    struct node* right;
    int key;
    int priority;
} node;

void BSTInsert(node** root, node* n) {
    if (*root == NULL) {
        *root = n;
        n->parent = n->left = n->right = NULL;
    } else if (n->key < (*root)->key) {
        BSTInsert(&((*root)->left), n);
        (*root)->left->parent = *root;
    } else if (n->key > (*root)->key) {
        BSTInsert(&((*root)->right), n);
        (*root)->right->parent = *root;
    }
}

void TreapInsert(node** root, node* n) {
    BSTInsert(root, n);

    // Esegui la rotazione per mantenere la proprietà del treap
    while (*root != NULL && (*root)->priority > n->priority) {
        if (n->key < (*root)->key) {
            // Rotazione a destra
            node* newRoot = (*root)->left;
            (*root)->left = newRoot->right;
            newRoot->right = *root;
            newRoot->parent = (*root)->parent;
            (*root)->parent = newRoot;
            *root = newRoot;
        } else {
            // Rotazione a sinistra
            node* newRoot = (*root)->right;
            (*root)->right = newRoot->left;
            newRoot->left = *root;
            newRoot->parent = (*root)->parent;
            (*root)->parent = newRoot;
            *root = newRoot;
        }
    }
}

int main() {
    // Esempio di utilizzo
    node* root = NULL;
    node n;
    n.key = 5;
    n.priority = 10;
    TreapInsert(&root, &n);
    // Altre operazioni di inserimento o manipolazione dell'albero
    return 0;
}