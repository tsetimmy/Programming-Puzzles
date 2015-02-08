#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
  cout << std::fixed;
  cout << std::setprecision(0);


  double n, p;
//  n = 1e101;
//  cout << n << endl;
//  return 0;

  while (cin >> n >> p) {
    cout << exp(log(p)/n) << endl;
  }


  return 0;
}
