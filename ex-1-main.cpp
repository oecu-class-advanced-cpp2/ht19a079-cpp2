//HT19A079
//�����
#include <iostream>
#include <cmath>
#include<stdio.h>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

using namespace std;

bool is_prime(int num) {  // 2�����num�܂ł̑f���𔻒肷��֐�
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
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
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
  cout << "������ a = ";
  cin >> a;
  cout << "������ b = ";
  cin >> b;
  cout << "������ n = ";
  cin >> n;
  cout << nth_prime(a, b, n) << endl;
  // �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
  return 0;
}