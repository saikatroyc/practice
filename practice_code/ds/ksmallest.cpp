// Example program
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void printvec(vector<int> v) {
    cout << endl;
    for (const auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int findKSmallest(const vector<int>& v, unsigned int k) {
    if (k <= 0) return -1;
    if (k > v.size()) return -1;

    // vector of size k.
    vector<int> v1;
    for (unsigned int i = 0; i < k; i++) {
        v1.push_back(v[i]);
    }

    // build a max heap.
    make_heap(v1.begin(), v1.end());

    for (unsigned int i = k; i < v.size(); ++i) {
        if (v1[0] > v[i]) {
            pop_heap(v1.begin(), v1.end());
            v1.pop_back();
            v1.push_back(v[i]);
            push_heap(v1.begin(), v1.end());
        }
    }

    return v1[0];
}

int main()
{
    //vector<int> a = {100,99, 4,1, 3,5,6, 97, 98};
    vector<int> a = {100,99, 4,1, 3,5,6};
    // min heap
    // make_heap(a.begin(), a.end(), [](int a, int b) {return a > b;});
    printvec(a);
    unsigned int k = 7;
    int i = findKSmallest(a, k);
    cout << "k(" << k << ") smallest: " << i;
    return 0;
}
