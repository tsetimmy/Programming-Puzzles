#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;

#define cmax 36
#define dmax 28

int C, D, N;

string combine [cmax];
string opposed [dmax];
vector<char> elements;


void check () {
  int end = elements.size()-1;
  for (int c = 0; c < C; c++) {
    if (elements.size() >= 2) {
      if ((combine[c][0] == elements[end] && combine[c][1] == elements[end-1])||
      (combine[c][1] == elements[end] && combine[c][0] == elements[end-1])) {
        elements.pop_back();
        elements.pop_back();
        elements.push_back(combine[c][2]);
      }
    }
  }

  char match;
  bool breakout;
  for (int i = elements.size()-1; i >= 0; i--) {
    match = ' ';
    breakout = false;
    for (int d = 0; d < D; d++) {
      if (elements[i] == opposed[d][0]) {
        match = opposed[d][1];
      } else if (elements[i] == opposed[d][1]) {
        match = opposed[d][0];
      }
      if (match != ' ') {
        for (int j = i-1; j >=0; j--) {
          if (elements[j] == match) {
            elements.clear();
            return;
            //for (int k = 0; k < abs(i-j)+1; k++) {

              //elements.erase(elements.begin()+j);
            //}
            //return;
            //breakout = true;
          }
          //if (breakout) break;
        }
      }

    }
    //if (breakout) {
      //break;
    //}
  }

}

void solve (int tcase) {
  cin >> C;
  for (int c = 0; c < C; c++) {
    cin >> combine[c];
  }
  cin >> D;
  for (int d = 0; d < D; d++) {
    cin >> opposed[d];
  }
  cin >> N;

  char in;
  elements.clear();
  for (int n = 0; n < N; n++) {
    cin >> in;
    elements.push_back(in);
    check();
  }

  cout << "Case #" << tcase << ": ";
  cout << "[";
  for (int i = 0; i < elements.size(); i++) {
    cout << elements[i];
    if (i != elements.size()-1) {
      cout << ", ";
    }
  }
  cout << "]";
  cout << endl;


}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
