//HT19A079
//増井光
#include <iostream>
#include <cmath>
#include<stdio.h>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

using namespace std;

bool is_prime(int num) {  // 2から√numまでの素数を判定する関数
  if (num == 1) {
    return false;
  }
  for (int i = 2; i < sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
  int count = 0;
  while (a < CPP2_PRIME_UPPER_LIMIT) {
    if (is_prime(a)) {
      count++;
    }
    if (count == n) {
      break;
      cout << 0;
    }
    a += d;
  }
  return a;
}

int main() {
  int a, b, n;
  cout << "正整数 a = ";
  cin >> a;
  cout << "正整数 b = ";
  cin >> b;
  cout << "正整数 n = ";
  cin >> n;
  cout << nth_prime(a, b, n) << endl;
  // 以下、同様に、入出力例通りになるか確認せよ。
  return 0;
}