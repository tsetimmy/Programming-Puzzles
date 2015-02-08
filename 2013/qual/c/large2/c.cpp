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

vector<string> all;
int digits[60];
int set[3] = {0, 1, 2};


string A, B;
bool cmp (string l, string r) {
  if (l.length() < r.length()) return true;
  if (l.length() > r.length()) return false;
  if (l < r) return true;
  if (l > r) return false;
  return true;
}

void solve (int t) {
  cin >> A >> B;


  int count = 0;
  for (int i = 0; i < all.size(); i++)
    if (cmp(A, all[i]) && cmp(all[i], B))
      count++;

  cout << "Case #" << t << ": " << count << endl;
}

void generate (int s, int e, int len, int c) {
  if (c > 9) return;
  if (s > e && c <= 9) {

    string temp = "";
    string temp2 = "";
    int val, val2;
    for (int i = 1; i <= len; i++) {
      val = 0;
      val2 = len;
      for (int j = i; j <= len; j++) {
        val += digits[j]*digits[val2];
        val2--;
      }
      temp.push_back(val+'0');
    }
    for (int i = temp.length()-1; i >= 1; i--)
      temp2.push_back(temp[i]);
    all.push_back(temp2+temp);


//    cout << "ori" << endl;
//    for (int i = 1; i <= len; i++)
//      cout << digits[i];
//    cout << endl;
//    cout << "mul" << endl;
//    cout << temp2+temp << endl;

    return;
  }
  if (s > e) return;

  int idx;
  if (s == 1) idx = 1;
  else idx = 0;

  for (int i = idx; i < 3; i++) {
    digits[s] = set[i];
    digits[e] = set[i];
    int in;
    if (s == e) in = c + set[i]*set[i];
    else in = c + 2*set[i]*set[i];
    generate(s+1, e-1, len, in);
  }

}

int main () {
  all.push_back("1");
  all.push_back("4");
  all.push_back("9");

  for (int i = 2; i <= 50; i++)
    generate(1,i,i,0);

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
