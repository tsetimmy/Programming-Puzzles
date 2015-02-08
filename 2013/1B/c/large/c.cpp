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
#include <fstream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

int hash[1+4000][1+4000];

#define dictcount 521196
vector<string> dict[10];

string in;

bool binary_search (string val, int left, int right) {
  int idx = val.length() - 1;
  int piv = (left + right)/2;

  if ((left  > right) || (left == right && dict[idx][left] != val)) {
    return false;
  }

  if (val < dict[idx][piv]) {
    return binary_search(val, left, piv-1);
  } else if (val > dict[idx][piv]) {
    return binary_search(val, piv+1, right);
  } else {
    return true;
  }

}

bool exists (string val) {
  return binary_search(val, 0, dict[val.length() - 1].size());
}

int doit (int start_i, int last_i) {
  if (start_i > in.length() - 1) {
    return 0;
  }

  if (last_i != -5 && hash[start_i][last_i] != -1)
    return hash[start_i][last_i];



  string sub;
  int next_i;
  int b;
  int remain;

  b = intmax - 1000;
  next_i = last_i + 5;
  next_i = next_i - start_i;
  remain = in.length() - start_i;

  remain = min(remain, 10);

  if (next_i < 0) {
    next_i = 0;
  }


  for (int i = 1; i <= remain; i++) { // iterate through every size.
    sub = in.substr(start_i, i);

    if (exists(sub)) {
      b = min(b, doit(start_i + sub.length(), last_i));
    }

    if (next_i < sub.length()) {
      char t1;
      for (int j = next_i; j < sub.length(); j++) {
        t1 = sub[j];
        sub[j] = '*';
        // check
        if (exists(sub)) {
          b = min(b, 1 + doit(start_i + sub.length(), start_i + j));
        }
        sub[j] = t1;

      }
    }

    if (next_i + 5 < sub.length()) {
      char t1;
      char t2;
      for (int j = next_i + 5; j < sub.length(); j++) {
        t2 = sub[j - 5];
        t1 = sub[j];
        sub[j - 5] = '*';
        sub[j] = '*';
        // check
        if (exists(sub)) {
          b = min(b, 2 + doit(start_i + sub.length(), start_i + j));
        }
        sub[j - 5] = t2;
        sub[j] = t1;
      }
    }
  }


  if (last_i != -5)
    hash[start_i][last_i] = b;
  return b;


}

void solve (int t) {
  cin >> in;

  for (int i = 0; i < 4000+1; i++) {
    for (int j = 0; j < 4000+1; j++) {
      hash[i][j] = -1;
    }
  }

  int ans = doit(0, -5);

  cout << "Case #" << t << ": " << ans << endl;

}

void process (string temp) {
  int idx = temp.length()-1;
  dict[idx].push_back(temp);

  char t;
  for (int i = 0; i < temp.length(); i++) {
    t = temp[i];
    temp[i] = '*';
    dict[idx].push_back(temp);
    temp[i] = t;
  }

  if (temp.length() > 5) {
    char t2;
    for (int i = 5; i < temp.length(); i++) {
      t = temp[i-5];
      t2 = temp[i];
      temp[i-5] = '*';
      temp[i] = '*';
      dict[idx].push_back(temp);
      temp[i-5] = t;
       temp[i] = t2;
    }
  }


}

int main () {
  std::ifstream infile("/cygdrive/c/Users/Tim/Desktop/program/2013/1B/c/large/a.txt");
  string temp;
  int index = 0;
  while (infile >> temp) {
    process(temp);

  }

//  for (int i = 0; i < 10; i++) {
//    for (int j = 0; j < dict[i].size(); j++) {
//      for (int k = j+1; k < dict[i].size(); k++) {
//        if (dict[i][j] == dict[i][k]) {
//          dict[i].erase(dict[i].begin() + k);
//        }
//      }
//
//    }
//  }

  for (int i = 0; i < 10; i++) {
    sort(dict[i].begin(), dict[i].end());
    dict[i].erase(unique(dict[i].begin(), dict[i].end()),dict[i].end());
  }

  int count = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < dict[i].size(); j++) {
      count++;
    }
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
