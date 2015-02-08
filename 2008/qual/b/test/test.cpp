#include <iostream>
using namespace std;

int get_time (char h1, char h2, char m1, char m2) {
  int a = h1-'0';
  int b = h2-'0';
  int c = m1-'0';
  int d = m2-'0';
  return (a*10+b)*60+(c*10+d);
}

string line;
int main () {
  getline(cin, line);
  cout << "first time is: " << get_time(line[0],line[1],line[3],line[4]) << endl;
  cout << "second time is: " << get_time(line[6],line[7],line[9],line[10]) << endl;
  return 0;
}
