#include <stack>
#include <vector>
using namespace std;

class CustomStack {
public:
  int sz;
  int capacity;
  stack<int> s;
  vector<int> incr;
  CustomStack(int maxSize) {
    sz = 0;
    capacity = maxSize;
    incr = vector<int>(maxSize, 0);
  }

  void push(int x) {
    if (sz < capacity) {
      s.push(x);
      sz++;
    }
  }

  int pop() {
    if (s.empty()) {
      return -1;
    }
    int top = s.top();
    top += incr[sz - 1];
    if (sz > 1) {
      incr[sz - 2] += incr[sz - 1];
    }
    incr[sz - 1] = 0;
    s.pop();
    sz--;
    return top;
  }

  void increment(int k, int val) {
    if (min(sz, k)) {
      incr[min(sz, k) - 1] += val;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */