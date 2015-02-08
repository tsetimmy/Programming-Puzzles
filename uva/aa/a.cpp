#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> circle;
int n, k;

int get (int idx) {
  int c = 0;
  int ret = idx;
  while (true) {
    ret = ret % n;
    if (circle[ret] != -1) {
      c++;
    }
    if (c == k) break;
    ret++;
  }
  return ret;
}

void doit (int start, bool& done) {
  circle.clear();
  cout << "This is n: " << n  << endl;
  for (int i = 0; i < n; i++) {
    cout << "Here is i: " << i << endl;
    circle.push_back(i);
  }

  int idx = start - 1;
  int killed = 0;
  int t;
  while (killed != n - 1) {
    idx = get(idx + 1);
    cout << circle[idx] << endl;
    circle[idx] = -1;
    killed++;
    t = idx;
    idx = get(idx + 1);
    circle[t] = circle[idx];
    circle[idx] = -1;
    idx = t;
  }

  assert(n == circle.size());
  for (int i = 0; i < n; i++) {
    if (circle[i] == 0) {
      cout << start+1 << endl;
      done = true;
    }
  }
}

int main () {
  bool done;
  while (true) {
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    done = false;
    //for (int i = 0; i < n; i++) {
      doit(3,done);
      if (done) {
        break;
      }
    //}
  }
  return 0;
}
