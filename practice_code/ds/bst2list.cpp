// Example program
#include <iostream>
#include <string>
#include <queue>

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

void list2tree(Node* head, Node* &root) {

    if (!head) {
        root = NULL;
        return;
    }


    root = head;
    head = head->right;
    root->right = NULL;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *parent = q.front();
        q.pop();
        if (head) {
            Node *leftChild = head;
            head = head->right;
            leftChild->right = NULL;
            leftChild->left = NULL;
            parent->left = leftChild;
            q.push(leftChild);

            if (head) {
                Node *rtChild = head;
                head = head->right;
                rtChild->right = NULL;
                rtChild->left = NULL;
                parent->right = rtChild;
                q.push(rtChild);
            }
        }
    }
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

    cout << "\n";
    Node *root1;
    list2tree(head, root1);
    printtree(root1);
    return 0;
}
