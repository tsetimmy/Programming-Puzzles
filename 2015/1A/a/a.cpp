// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int N;

int first () {
  int total = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i - 1] > v[i]) {
      total += v[i - 1] - v[i];
    }
  }
  return total;
}

int second () {
  int m = 0;
  for (int i = 1; i < v.size(); i++) {
    m = max(m, v[i - 1] - v[i]);
  }
  int total = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    if (m > v[i]) {
      total += v[i];
    } else {
      total += m;
    }
  }
  return total;
}

void doit (int cas) {
  v.clear();
  cin >> N;
  v = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  cout << "Case #" << cas << ": " << first() << " " << second() << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
