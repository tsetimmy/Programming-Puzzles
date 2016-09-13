// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cassert>
using namespace std;

string s;
vector<int> ans;

bool exists (char a) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == a)
      return true;
  }
  return false;
}

void remove (string t) {
  for (int i = 0; i < t.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (t[i] == s[j]) {
        s[j] = '!';
        break;
      }
    }
  }
}

void doit () {
  ans.clear();
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin >> s;
  char chars[10] = {'Z', 'G', 'X', 'U', 'F', 'V', 'H', 'I', 'N', 'T'};
  string strings[10] = {"ZERO", "EIGHT", "SIX", "FOUR", "FIVE", "SEVEN", "THREE", "NINE", "ONE", "TWO"};
  int ints[10] = {0, 8, 6, 4, 5, 7, 3, 9, 1, 2};
  for (int i = 0; i < 10; i++) {
    while (exists(chars[i])) {
      remove(strings[i]);
      ans.push_back(ints[i]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << " ";
  for (int i = 0;  i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 1; cas <= tcases; cas++) {
    cout << "Case #" << cas << ":";
    doit();
  }
  return 0;
}
