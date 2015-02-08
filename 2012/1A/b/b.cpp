#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
using namespace std;

#define lmax 2001
int N;
pair<int, int> levels[lmax];
pair<bool, bool> complete[lmax];
int stars;
int ans;

bool foo (pair<int, int> left, pair<int, int> right) {
  return left.second > right.second;
}

bool completed () {
  for (int i = 0; i < N; i++) {
    if (complete[i].second == false) {
      return false;
    }
  }
  return true;
}

bool complete1 () {
  for (int i = 0; i < N; i++) {
    if (complete[i].first == false && complete[i].second == false && levels[i].first <= stars) {
      stars++;
      ans++;
      complete[i].first = true;
      return true;
    }
  }

  return false;
}

bool complete2 () {
  int best_idx = -1;
  for (int i = 0; i < N; i++) {
    if (complete[i].first == false && complete[i].second == false && levels[i].second <= stars) {
      stars += 2;
      ans++;
      complete[i].second = true;
      return true;
    } else if (complete[i].first == true && complete[i].second == false && levels[i].second <= stars) {
      best_idx = i;
    }
  }
  if (best_idx != -1) {
    stars++;
    ans++;
    complete[best_idx].second = true;
    return true;
  } else {
    return false;
  }
}

void solve (int tcase) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> levels[i].first;
    cin >> levels[i].second;
  }
  for (int i = 0; i < lmax; i++) {
    complete[i].first = false;
    complete[i].second = false;
  }
  stars = 0;
  ans = 0;
  sort(&levels[0], &levels[0]+N, foo);
  //for (int i = 0; i < N; i++) {
    //cout << levels[i].second << " ";
  //}
  //cout << endl;

  bool two, one;
  while (true) {
    if (completed()) {
      break;
    }
    two = complete2();
    if (two) {
      //cout << "two: " << stars << endl;
      continue;
    }

    one = complete1();
    //if (one) cout << "one: " << stars << endl;

    if (!one && !two) {
      cout << "Case #" << tcase << ": Too Bad" << endl;
      return;
    }
  }
  assert(stars == 2*N);
  cout << "Case #" << tcase << ": " << ans << endl;


}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
