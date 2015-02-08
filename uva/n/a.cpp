#include <iostream>
#include <cassert>
using namespace std;

void swap (string& s, int a, int b) {
  char t = s[a];
  s[a] = s[b];
  s[b] = t;
}

string next (string s) {
  int len = s.size();

  int k = -1;
  for (int i = len-1; i >= 1; i--) {
    if (s[i] > s[i-1]) {
      k = i - 1;
      break;
    }
  }
  if (k == -1) {
    return "No Successor";
  }

  int l = -1;
  for (int i = len-1; i >= 0; i--) {
    if (s[i] > s[k]) {
      l = i;
      break;
    }
  }
  assert(l != -1);

  swap(s, k, l);

  int left, right;
  left = k + 1;
  right = len - 1;

  while (left < right) {
    swap(s, left, right);
    left++;
    right--;
  }

  return s;

}

int main () {
  string s;
  while (true) {
    cin >> s;
    if (s == "#") break;
    cout << next(s) << endl;
  }
  return 0;
}
