//ht19a079
//増井 光
#include <iostream>
#include <string>
#include<sstream>

namespace cpp2 {
  //mcxi
  //mcxi 記法を解析するクラスです。
  class mcxi {
  public:
    /* ----------------------------------------------------------------- */
    /*
       mcxi

       指定された文字列を解析して、オブジェクトを初期化します。
       以下の場合には例外が創出されます。

       1. [2-9,m,c,x,i] 以外の文字が出現した場合
       2. 2 文字続けて数字 (2-9) が出現した場合
       3. m, c, x, i がこの順序で出現しなかった場合
          ただし、例えば mx のように、特定の文字をスキップする事は許容
          されます。
     */
     /* ----------------------------------------------------------------- */
    mcxi(const std::string& s) : value_(0) {
      int num = 0;
      for (auto pos = s.begin(); pos != s.end(); ++pos) {
        if (*pos >= '2' && *pos <= '9') {
          num = *pos - '0';
        }
        else {
          int u = unit(*pos);
          value_ += std::max(num, 1) * u;
          num = 0;
        }
      }
    }



    //operator+
    //2 つのオブジェクトの加算結果を取得します。
    mcxi operator+(const mcxi& rhs) {
      mcxi rhsadd("");
      rhsadd.value_ = value_ + rhs.value_;
      return rhsadd;
    }

    //to_string
    //現在の値を mcxi 記法に変換します。
    std::string to_string() const {

      std::stringstream ss;

      int q = value_ / 1000;
      if (q == 1) {
        ss << 'm';
      }
      if (q > 1) {
        ss << q;
        ss << 'm';
      }

      int n = value_ / 100;
      if (q == 1) {
        ss << 'c';
      }
      if (q > 1) {
        ss << n;
        ss << 'c';
      }

      int r = value_ / 10;
      if (q == 1) {
        ss << 'x';
      }
      if (q > 1) {
        ss << r;
        ss << 'x';
      }

      int e = value_ / 1;
      if (q == 1) {
        ss << 'i';
      }
      if (q > 1) {
        ss << e;
        ss << 'i';
      }
      return "XXX";
    }

    void debug_mcxi() {
      std::cout << "value_: " << value_ << std::endl;
    }

  private:
    int unit(char c) {
      switch (c) {
      case 'm':return 1000;
      case 'c':return 100;
      case 'x':return 10;
      case 'i':return 1;
      }
    }

  private:
    int value_;
  };
}

int main() {
  cpp2::mcxi a0("xi");
  a0.debug_mcxi();
  cpp2::mcxi b0("x9i");
  b0.debug_mcxi();
  auto result0 = a0 + b0;
  std::cout << "3x" << " " << result0.to_string() << std::endl;

  cpp2::mcxi a1("i");
  a1.debug_mcxi();
  cpp2::mcxi b1("9i");
  b1.debug_mcxi();
  auto result1 = a1 + b1;
  std::cout << "x" << " " << result1.to_string() << std::endl;

  cpp2::mcxi a2("c2x2i");
  a2.debug_mcxi();
  cpp2::mcxi b2("4c8x8i");
  b2.debug_mcxi();
  auto result2 = a2 + b2;
  std::cout << "6cx" << " " << result2.to_string() << std::endl;

  cpp2::mcxi a3("m2ci");
  a3.debug_mcxi();
  cpp2::mcxi b3("4m7c9x8i");
  b3.debug_mcxi();
  auto result3 = a3 + b3;
  std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

  cpp2::mcxi a4("9c9x9i");
  a4.debug_mcxi();
  cpp2::mcxi b4("i");
  b4.debug_mcxi();
  auto result4 = a4 + b4;
  std::cout << "m" << " " << result4.to_string() << std::endl;

  cpp2::mcxi a5("i");
  a5.debug_mcxi();
  cpp2::mcxi b5("9m9c9x8i");
  b5.debug_mcxi();
  auto result5 = a5 + b5;
  std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

  cpp2::mcxi a6("m");
  a6.debug_mcxi();
  cpp2::mcxi b6("i");
  b6.debug_mcxi();
  auto result6 = a6 + b6;
  std::cout << "mi" << " " << result6.to_string() << std::endl;

  cpp2::mcxi a7("i");
  a7.debug_mcxi();
  cpp2::mcxi b7("m");
  b7.debug_mcxi();
  auto result7 = a7 + b7;
  std::cout << "mi" << " " << result7.to_string() << std::endl;

  cpp2::mcxi a8("m9i");
  a8.debug_mcxi();
  cpp2::mcxi b8("i");
  b8.debug_mcxi();
  auto result8 = a8 + b8;
  std::cout << "mx" << " " << result8.to_string() << std::endl;

  cpp2::mcxi a9("9m8c7xi");
  a9.debug_mcxi();
  cpp2::mcxi b9("c2x8i");
  b9.debug_mcxi();
  auto result9 = a9 + b9;
  std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}