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
string dict [dictcount];

string in;
bool flag2;

int best (int b, int ret, int c) {
  if (b == intmax && ret == intmax) return intmax;
  if (ret == intmax && b!= intmax) return b;
  if (b == intmax && ret != intmax) return ret+c;






  ret += c;
  if (ret < b) return ret; return b;
}

int go (int start_idx, int last_idx) {
  if (start_idx > in.length()-1) return 0;

  if (hash[start_idx][last_idx] != -1 && last_idx >= 0) {
    return hash[start_idx][last_idx];
  }

  int c;
  int b = intmax;
  int ret;
  bool flag;
  int org_index = last_idx;

  for (int i = 0; i < dictcount; i++) {



    if (start_idx+dict[i].length() > in.length()) continue;
    flag = true;
    c = 0;
    last_idx = org_index;
    for (int j = 0; j < dict[i].length(); j++) {
      if (in[start_idx+j] != dict[i][j] && last_idx+5 <= start_idx+j) {
        c++;
        last_idx = start_idx+j;
      }
      else if(in[start_idx+j] != dict[i][j] && last_idx+5 > start_idx+j) {
        flag = false;
        break;
      }
    }
    if (flag) {
      //if (dict[i]=="code") {
        //cout << "Here is c: " << c << endl;
        //cout << "Here is start_idx+dict[i].length: " << start_idx+dict[i].length() << endl;
        //cout << "Here is last_idx: " << last_idx << endl;
        //flag2 = true;
      //}

      //if (dict[i] == "jam" && flag2) {
        //cout << "Here is c: " << c << endl;
        //cout << "Here is start_idx+dict[i].length: " << start_idx+dict[i].length() << endl;
        //cout << "Here is last_idx: " << last_idx << endl;
        //cout << "while(1)" << endl;
      //ret =go(start_idx+dict[i].length(), last_idx);
      //cout << "Here is ret: " << ret << endl;
      //cout << "Here is c: " << c << endl;
      //cout << "Here is b: " << b << endl;
      //b = best(b, ret, c);
      //cout << "here is b: " << b << endl;
      //}


      ret =go(start_idx+dict[i].length(), last_idx);
      b = best(b, ret, c);
    }
  }

  if (hash[start_idx][last_idx] == -1 && last_idx >= 0) hash[start_idx][last_idx] = b;
  return b;


}

void solve (int t) {
  cin >> in;

  for (int i = 0; i < 1+4000; i++)for (int j =0 ;j < 1+4000; j++) hash[i][j]=-1;
  int ans = go(0,-5);
  cout << "Case #" << t << ": " << ans << endl;
}

int main () {
  flag2 = false;
  std::ifstream infile("/cygdrive/c/Users/ttse/Desktop/c/a.txt");
  string temp;
  int index = 0;
  int longest = 0;
  while (infile >> temp) {
    if (temp.length() > longest)
      longest = temp.length();


    dict[index] = temp;
    index++;
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
