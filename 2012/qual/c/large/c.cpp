// C++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
#include <assert.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

#define twomil 2000000
bool hash [2000000+1];
int A, B;
int ans;
vector<int> temp;

int doit (int i) {
  if (hash[i]) {
    return 0;
  }

  stringstream ss;
  ss << i;
  string str = ss.str();

  temp.clear();
  temp.push_back(i);
  string t;
  for (int k = 1; k <= str.length()-1; k++) {
    if (str[k] != '0') {
      t = str.substr(k,str.length()-k)+str.substr(0,k);
      temp.push_back(atoi(t.c_str()));
    }
  }
 
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()),temp.end());

  while (true) {
    if (temp.back() <= B) {
      break;
    } else {
      temp.pop_back();
    }
  }

  while (true) {
    if (temp.front() < i) {
      temp.erase(temp.begin());
    } else {
      break;
    }
  }

  int ret = temp.size()-1;
  ret = ret*(ret+1)/2;

  for (int k = 0; k < temp.size(); k++) {
    hash[temp[k]] = true;
  }
  return ret;
}

void solve (int t) {
  cin >> A >> B;
  for (int i = A; i <= B; i++) {
    hash[i] = false;
  }

  ans = 0;
  for (int i = A; i <= B; i++) {
    ans += doit(i);
  }
  cout << "Case #" << t << ": " << ans << endl;

}

int main () {
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
