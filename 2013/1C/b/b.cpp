#include <iostream>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int x,y;
string ans;

int get () {
  int xy = abs(x)+abs(y);
  int result = (int)((sqrt(1+8*xy)-1)/2);

  if (xy == result*(result+1)/2) {
    return result;
  }

  result++;
  while ((result*(result+1)/2)%2 != xy%2) {
    result++;
  }

  return result;
}

void solve (int tcase) {
  cin >> x >> y;
  ans = "";

  int s = get();

  while (s > 0) {
    if (abs(x) > abs(y)) {
      if (x < 0) {
        x += s;
        ans.push_back('W');
      } else {
        x -= s;
        ans.push_back('E');
      }
    } else {
      if (y < 0) {
        y += s;
        ans.push_back('S');
      } else {
        y -= s;
        ans.push_back('N');
      }
    } 
    s--;
  }


  //assert(x == 0 && x == y);
  cout << "Case #" << tcase << ": ";
  for (int i = ans.length()-1; i >= 0; i--)
    cout << ans[i];
  cout << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}

