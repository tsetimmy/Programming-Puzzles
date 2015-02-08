#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cctype>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull fact (ull in) {
  ull ret = 1;
  while (in > 1) {
    ret *= in;
    in--;
  }
  return ret;
}

bool compare (char left, char right) {
  if (tolower(left) == tolower(right)) return left > right;
  else return tolower(left) > tolower(right);
}

void next (string& s, bool& last) {
  ll k = -1;
  for (ll i = s.size() - 1; i >= 1; i--) {
    if (compare(s[i], s[i-1])) {
      k = i - 1;
      break;
    }
  }
  if (k == -1) {
    last = true;
    return;
  }

  ll l = -1;
  for (ll i = s.size()-1; i >= 0; i--) {
    if (compare(s[i], s[k])) {
      l = i;
      break;
    }
  }
  assert(l != -1);

  char temp = s[k];
  s[k] = s[l];
  s[l] = temp;


  ll left = k + 1;
  ll right = s.size() - 1;
  while (left < right) {
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
  }
}

bool foo (char left, char right) {
  if (tolower(left) == tolower(right)) return left < right;
  else return tolower(left) < tolower(right);
}


int main () {
  ull t; cin >> t;
  string s;
  bool last;
  for (ull i = 0; i < t; i++) {
    cin >> s;
    sort(s.begin(), s.end(), foo);
    last = false;
    while (true) {
      cout << s << endl;
      next(s,last);
      if (last) break;
    }


  }
  return 0;
}
