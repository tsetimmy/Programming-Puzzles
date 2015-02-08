#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<int> vec;

int gcdr (int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return gcdr(b%a, a);
  }
}

void solve (int tcase) {
  cin >> N;
  int t;
  vec.clear();
  for (int n = 0; n < N; n++) {
    cin >> t;
    vec.push_back(t);
  }

  sort(vec.begin(), vec.end());
  cout << "Case #" << tcase << ": ";
  int greatest;
  if (vec.size() == 2) {
    greatest = vec[1]-vec[0];
  } else {
    greatest = gcdr(vec[1]-vec[0], vec[2]-vec[1]);
  }
  if (greatest == 1) {
    greatest = 0;
  } else {
    int temp = greatest;
    greatest = vec[0]%greatest;
    if (greatest != 0) {
      greatest = temp - greatest;
    }
  }
  cout << greatest << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
