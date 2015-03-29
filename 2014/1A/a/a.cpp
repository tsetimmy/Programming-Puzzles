// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
using namespace std;

int N, L;
vector<string> changeable;
vector<string> target;
string xors[150][150];
bool taken[150];

int count (string a) {
  int ret = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '1') {
      ret++;
    }
  }
  return ret;
}

int minimum (int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

string XOR (string a, string b) {
  assert(a.size() == b.size());
  string ret = "";
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) {
      ret.push_back('0');
    } else {
      ret.push_back('1');
    }
  }
  return ret;
}

void doit (int cas) {
  cin >> N >> L;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  changeable.clear();
  target.clear();

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    changeable.push_back(s);
  }
  for (int i = 0; i < N; i++) {
    cin >> s;
    target.push_back(s);
  }

  for (int i = 0; i < changeable.size(); i++) {
    for (int j = 0; j < target.size(); j++) {
      xors[i][j] = XOR(changeable[i], target[j]);
    }
  }

  vector<string> ans;
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      taken[k] = false;
    }

    taken[i] = true;
    bool got;
    for (int j = 1; j < N; j++) {
      got = false;
      for (int k = 0; k < N; k++) {
        if (xors[j][k] == xors[0][i]) {
          assert(taken[k] == false);
          taken[k] = true;
          got = true;
          break;
        }
      }
      if (got == false) {
        goto next;
      }
    }

    for (int l = 0; l < N; l++) {
      assert(taken[l]);
    }
    ans.push_back(xors[0][i]);

    next:
    while(0);
  }
  cout << "Case #" << cas << ": ";
  if (ans.size() == 0) {
    cout << "NOT POSSIBLE" << endl;
    return;
  }
  int best = count(ans[0]);
  for (int i = 0; i < ans.size(); i++) {
    best = minimum(best, count(ans[i]));
  }
  cout << best << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int t = 0; t < tcases; t++) {
    doit(t + 1);
  }
  return 0;
}
