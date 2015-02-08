#include <iostream>
#include <fstream>
#include <limits>
#include <climits>
using namespace std;

char hash[500];
string s[6];

int main () {
  std::ifstream infile("/cygdrive/c/Users/ttse/Desktop/qual/in.txt");

  string temp;
  int idx = 0;
  while (getline(infile,temp)) {
    s[idx] = temp;
    idx++;
  }

  hash[(int)'z'] = 'q';
  hash[(int)'q'] = 'z';

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < s[i].length(); j++) {
      hash[(int)s[i][j]] = s[i+3][j];
    }
  }

  int T; cin >> T;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');




  for (int t = 1; t <= T; t++) {
    getline(cin, temp);
    cout << "Case #" << t << ": ";

    for (int j = 0; j < temp.length(); j++) {
      if (temp[j] != ' ') {
        cout << hash[(int)temp[j]];
      } else {
        cout << ' ';
      }
    }
    cout << endl;
  }


  return 0;
}
