/* A C++ program that converts integer in range(-999999999999 to 999999999999)
   int words and prints them.*/

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string word(int i) {
  switch (i) {
    case 0:
      return "zero";
    case 1:
      return "one";
    case 2:
      return "two";
    case 3:
      return "three";
    case 4:
      return "four";
    case 5:
      return "five";
    case 6:
      return "six";
    case 7:
      return "seven";
    case 8:
      return "eight";
    case 9:
      return "nine";
    case 10:
      return "10";
    case 11:
      return "eleven";
    case 12:
      return "twelve";
    case 13:
      return "thirteen";
    case 14:
      return "fourteen";
    case 15:
      return "fifteen";
    case 16:
      return "sixteen";
    case 17:
      return "seventeen";
    case 18:
      return "eighteen";
    case 19:
      return "nineteen";
    case 20:
      return "twenty";
    case 30:
      return "thirty";
    case 40:
      return "fourty";
    case 50:
      return "fifty";
    case 60:
      return "sixty";
    case 70:
      return "seventy";
    case 80:
      return "eighty";
    case 90:
      return "ninety";
    case 102:
      return "hundred";
    case 103:
      return "thousand";
    case 106:
      return "million";
    case 109:
      return "billion";
    default:
      return "";
  }
}

string hundreds(int n) {
  string result = "";
  int x = n / 100;
  n = n % 100;
  if (x > 0) {
    result += word(x) + " " + word(102);
  }
  if (n > 0) {
    if (x > 0) {
      result += " ";
    }
    if (n < 20) {
      result += word(n);
    } else {
      int y = n - n % 10;
      n = n % 10;
      result += word(y);
      if (n > 0) {
        result += " " + word(n);
      }
    }
  }
  return result;
}

int main() {
  long long int n;
  long long int max = 999999999999;
  cout << "Enter number in range (-999999999999 to 999999999999): ";
  cin >> n;
  if (abs(n) > max) {
    cout << "Can't print for this number";
  } else {
    cout << "Result:";
    string result = "";
    if (n < 0) {
      result += " minus";
    }
    n = abs(n);
    long long int b, m, t;
    b = n / 1000000000;
    n = n % 1000000000;
    m = n / 1000000;
    n = n % 1000000;
    t = n / 1000;
    n = n % 1000;
    if (b > 0) {
      result += " " + hundreds(b) + " " + word(109);
    }
    if (m > 0) {
      result += " " + hundreds(m) + " " + word(106);
    }
    if (t > 0) {
      result += " " + hundreds(t) + " " + word(103);
    }
    if (n > 0) {
      result += " " + hundreds(n);
    }
    if (result == "") {
      result = " " + word(0);
    }
    cout << result;
  }
  return 0;
}
