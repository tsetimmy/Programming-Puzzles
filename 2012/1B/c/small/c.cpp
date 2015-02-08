#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define asize 20
#define power 1048576

struct my {
  vector<int> vec;
  int sum;
};

int N;
int a[asize];
int bin[asize];
my ans[power];
//vector<int> global_sum;
int idx;

bool foo (my left, my right) {
  return left.sum < right.sum;
}

void doit (int i, bool &done) {
  if (i == asize) {
    for (int j = 0; j < asize; j++) {
      if (bin[j] == 1) {
        ans[idx].vec.push_back(a[j]);
      }
    }
    for (int j = 0; j < ans[idx].vec.size(); j++) {
      ans[idx].sum += ans[idx].vec[j];
    }

    for (int j = 0; j < idx; j++) {
      if (ans[j].sum == ans[idx].sum) {

        for (int k = 0; k < ans[j].vec.size(); k++) {
          cout << ans[j].vec[k];
          if (k == ans[j].vec.size()-1) {
            cout << endl;
          } else {
            cout << " ";
          }
        }

        for (int k = 0; k < ans[idx].vec.size(); k++) {
          cout << ans[idx].vec[k];
          if (k == ans[idx].vec.size()-1) {
            cout << endl;
          } else {
            cout << " ";
          }
        }


        done = true;
        return;
      }
    }

    idx++;
    return;
  }

  for (int j = 0; j < 2; j++) {
    bin[i] = j;
    doit(i+1,done);
    if (done) return;
  }
}

void solve (int tcase) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < power; i++) {
    ans[i].vec.clear();
    ans[i].sum = 0;
  }
//  global_sum.clear();
  idx = 0;
  cout << "Case #" << tcase << ": " << endl;
  bool done = false;
  doit(0,done);

  if (done) return;

//  assert(idx == power);
//
//  sort(&ans[0], &ans[0]+power, foo);
//  
//  cout << "Case #" << tcase << ": " << endl;
//  for (int j = 0; j < power; j++) {
//    if (j != power-1 && ans[j].sum == ans[j+1].sum) {
//      for (int k = 0; k < ans[j].vec.size(); k++) {
//        cout << ans[j].vec[k];
//        if (k == ans[j].vec.size()-1) cout << endl;
//        else cout << " ";
//      }
//
//      for (int k = 0; k < ans[j+1].vec.size(); k++) {
//        cout << ans[j+1].vec[k];
//        if (k == ans[j+1].vec.size()-1) cout << endl;
//        else cout << " ";
//      }
//      return;
//
//
//    }
//  }

  cout << "Impossible" << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
}
