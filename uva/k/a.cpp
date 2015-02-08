#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll correct[30];
ll student[30];
ll hash[30][30];
ll l;

//void print () {
//  cout << "This is correct" << endl;
//  for (ll i = 0; i < correct.size(); i++) {
//    cout << correct[i] << " ";
//  }
//  cout << endl;
//  cout << "This is correct end" << endl;
//  cout << "This is student" << endl;
//  for (ll i = 0; i < student.size(); i++) {
//    cout << student[i] << " ";
//  }
//  cout << endl;
//  cout << "This is student end" << endl;
//}

//void fix () {
//  for (ll i = 0; i < correct.size(); i++) {
//    for (ll j = 0; j < student.size(); j++) {
//    }
//  }
//}

void clear_hash () {
  for (ll i = 0; i < 30; i++)
    for (ll j = 0; j < 30; j++)
      hash[i][j] = -1;
}

ll doit (ll cidx, ll sidx) {
  if (cidx == l || sidx == l) {
    return 0;
  }

  ll& val = hash[cidx][sidx];
  if (val != -1) return val;

  if (correct[cidx] == student[sidx]) {
    val =  doit(cidx+1,sidx+1)+1;
  } else {
    val = max (doit(cidx,sidx+1), doit(cidx+1,sidx));
  }
  return val;

}

int main () {
  ll t;
  cin >> l;
  for (ll i = 0; i < l; i++) {
    cin >> t;
    correct[t-1] = i+1;
  }

//  for (ll i = 0; i < l; i++) {
//    cout << correct[i] << " ";
//  }
//  cout << endl;

  ll idx = 0;
  //student.clear();
  while (cin >> t) {
    idx++;
    student[t-1] = idx;

    if (idx == l) {
      //print();
      clear_hash();
      cout << doit(0,0) << endl;
      idx = 0;
    }
  }

  return 0;
}

