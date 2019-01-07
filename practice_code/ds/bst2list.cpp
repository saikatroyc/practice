// Example program
#include <iostream>
#include <string>
using namespace std;

typedef struct node {
    struct node* left;
    struct node* right;
    int val;

    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
} Node;

void printtree(Node* root) {
    if (root) {
        printtree(root->left);
        cout << root->val << " ";
        printtree(root->right);
    }
}


void Tree2List(Node* root, Node** head) {
    if (!root) return;

    Tree2List(root->right, head);

    root->right = *head;
    if (*head) {
        (*head)->left = root;
    }
    *head = root;

    Tree2List(root->left, head);
}

void printlist(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    printtree(root);
    cout << "\n";

    Node *head = NULL;
    Tree2List(root, &head);
    printlist(head);
    return 0;
}
