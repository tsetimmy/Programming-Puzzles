#include <iostream>
#include <limits>
#include <vector>
using namespace std;

string S, s;
vector<int> v;

void doit (int cas) {
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin >> S;
  cin >> s;

  v.clear();
  for (int i = 0; i < s.size(); i++) {
    v.push_back((int) (s[i] - '0'));
  }

  int stoodup = 0;
  int addition = 0;
  for (int i = 0; i < v.size(); i++) {
    if (stoodup >= i) {
      stoodup += v[i];
    } else {
      addition += i - stoodup;
      stoodup = i + v[i];
    }
  }
  cout << "Case #" << cas << ": " << addition << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++) {
    doit(cas + 1);
  }
  return 0;
}
