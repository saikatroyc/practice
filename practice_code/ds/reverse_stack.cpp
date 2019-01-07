#include <iostream>
#include <stack>

using namespace std;
class MyStack {
    stack<int> st_;
    sorted_insert();
    public:
        MyStack(stack<int> s): st_(s);
        print_stack();
        insert_bottom();
        reverse_stack();
        sort_stack();
};

void print_stack(stack<int>& st);
void insert_bottom(stack<int>& st, const int& i);
void reverse_stack(stack<int>& st);
void sort_stack(stack<int>& st);
void sorted_insert(stack<int>& st, const int& i);

void print_stack(stack<int>& st) {
    if (st.size() > 0) {
        auto i = st.top();
        cout << i << "\n";
        st.pop();
        print_stack(st);
        st.push(i);
    }
}

void insert_bottom(stack<int>& st, const int& i) {
    if (!st.size()) {
        st.push(i);
    } else {
        const auto x = st.top();
        st.pop();
        insert_bottom(st, i);
        st.push(x);
    }
}

void reverse_stack(stack<int>& st) {
    if (st.size() > 0) {
        const auto i = st.top();
        st.pop();
        reverse_stack(st);
        insert_bottom(st, i);
    }
}

void sorted_insert(stack<int>& st, const int& i) {
    if (!st.size() || i > st.top()) {
        st.push(i);
    } else {
        const auto x = st.top();
        st.pop();
        sorted_insert(st, i);
        st.push(x);
    }
}

void sort_stack(stack<int>& st) {
    if (st.size()) {
        const auto x = st.top();
        st.pop();
        sort_stack(st);
        sorted_insert(st, x);
    }
}

int main() {
    {
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        print_stack(st);
        cout << "insert 0 at bottom\n";
        insert_bottom(st, 0);
        print_stack(st);
        cout << "reverse stack\n";
        reverse_stack(st);
        print_stack(st);*/
    }
    {
        stack<int> st;
        st.push(1);
        st.push(3);
        st.push(4);
        print_stack(st);
        sorted_insert(st, 2);
        print_stack(st);
    }
    {
        stack<int> st;
        st.push(4);
        st.push(1);
        st.push(3);
        st.push(2);
        print_stack(st);
        cout << "sorting stack\n";
        sort_stack(st);
        print_stack(st);
    }
    return 0;
}
