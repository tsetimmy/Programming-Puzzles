// C++
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

#define num 10000000
ll a[num+1];

void solve (int t) {
  ll A,B;
  cin >> A >> B;
  ll aidx = (ll)sqrt(A);
  if (aidx*aidx != A) aidx++;

  ll bidx = (ll)sqrt(B);
  //if (bidx*bidx != B) bidx--;

  int count = 0;
  for (int i = aidx; i <= bidx; i++) {
    if (a[i] != -1) {
      count++;
      //cout << i << " " << a[i] << endl;
    }
  }
  cout << "Case #" << t << ": " << count << endl;

  //if (t == 3) {
    //cout << aidx << endl;
    //cout << bidx << endl;
      //for (int i = 1; i <= 5; i++)
        //cout << a[i] << " ";
    //cout << endl;
  //}

}

bool ispal (ll c) {
  stringstream ss;
  ss << c;
  string aa = ss.str();
  string bb = "";

//  for (int i = aa.length()-1; i >= 0; i--) {
//    bb.push_back(aa[i]);
//  }
//
//  return (aa == bb);

  int i = 0;
  int j = aa.length()-1;

  while (i < j) {
    if (aa[i] != aa[j]) return false;
    i++;
    j--;
  }
  return true;

}

ll compute (ll b) {
  if (ispal(b) && ispal(b*b)) return b*b;
  return -1;
}

int main () {
  for (ll i = 0; i < num+1; i++) a[i] = -1;

  for (ll i = 1; i <= num; i++) {
    a[i] = compute(i);
  }



  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}







































































































string tokenize (string &target, string delimiter) {
  if (target == "")
    return target;

    string ret = "";
    size_t found = target.find(delimiter);
    if (found == std::string::npos && target != "") {
      ret = target;
      target = "";
    } else {
      ret = target.substr(0, found);
      target = target.substr(found+1,target.length());
    }
    return ret;
}
