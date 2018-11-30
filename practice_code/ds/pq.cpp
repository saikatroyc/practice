// Example program
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class myobject {
    int val_;
    public:
        myobject(int val) : val_(val) {}
        int val() const {
            return val_;
        }
};
class MyCompare {
        bool is_less_than_comparator_;
        public:
            MyCompare (const bool& is_less_than_comparator=true) :  is_less_than_comparator_(is_less_than_comparator) {}
            bool operator() (const myobject& a, const myobject& b) {
                if (is_less_than_comparator_) {
                    return a.val() < b.val();
                } else {
                    return b.val() < a.val();
                }
        }
};
typedef std::priority_queue<myobject,std::vector<myobject>, MyCompare> mypq_type;
void popandprint(mypq_type* q);
int main()
{
    mypq_type q1;
    mypq_type q2(MyCompare(false));
    myobject mo1(1), mo2(2), mo3(3);
    q2.push(mo1);
    q2.push(mo2);
    q2.push(mo3);
    popandprint(&q2);
    q1.push(mo3);
    q1.push(mo2);
    q1.push(mo1);
    popandprint(&q1);
    cout << "end of program";

}

void popandprint(mypq_type* q) {
    while (!q->empty()) {
        cout << q->top().val() << endl;
        q->pop();
    }
}
