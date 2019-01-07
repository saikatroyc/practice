// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct node {
    int val;
    int row;
    int col;

    node(int val, int r, int c) {
        this->val = val;
        this->row = r;
        this->col = c;
    }

    void tostring() {
        cout << "val " << val << ", row " << row << ", col " << col << endl;
    }
};

struct compare {
    bool operator() (const node& n1, const node& n2) {
        // min-heap.
        return n1.val > n2.val;
    }
};

typedef priority_queue<node, vector<node>, compare> pq;

int main()
{
    pq q1;
    int m[4][4] = {{7,8,9}, {1,2,3}, {4,5,6}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            node n1 = node(m[i][j], i, j);
            n1.tostring();
            q1.push(n1);
        }
    }

    int k = 5;
    for (int i = 0; i < k - 1; ++i) {
        q1.pop();
    }

    node n = q1.top();
    cout << "\nkth smallest = "; n.tostring();
    return 0;
}
