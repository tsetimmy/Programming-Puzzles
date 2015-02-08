#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

#define dim 300
typedef long long ll;

vector<string> v;
vector<string> ans;
ll hash[dim];

bool anagram (string a, string b) {
  for (ll i = 0; i < dim; i++) {
    hash[i] = 0;
  }

  for (ll i = 0; i < a.size(); i++) {
    a[i] = tolower(a[i]);
  }
  for (ll i = 0; i < b.size(); i++) {
    b[i] = tolower(b[i]);
  }

  for (ll i = 0; i < a.size(); i++) {
    hash[(ll)a[i]]++;
  }
  for (ll i = 0; i < b.size(); i++) {
    hash[(ll)b[i]]--;
  }

  for (ll i = 0; i < dim; i++) {
    if (hash[i] != 0) {
      return false;
    }
  }
  return true;
}

void doit () {
  ans.clear();

  bool anana;
  for (ll i = 0; i < v.size(); i++) {
    anana = true;
    for (ll j = 0; j < v.size(); j++) {
      if (i != j && anagram(v[i], v[j])) {
        anana = false;
        break;
      }
    }
    if (anana) {
      ans.push_back(v[i]);
    }

  }

  sort(ans.begin(), ans.end());
  for (ll i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}

int main () {
  string s;
  while (true) {
    cin >> s;
    if (s == "#") break;
    v.push_back(s);
  }
  doit();
  return 0;
}
