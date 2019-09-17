/* This program prints all possible solutioins of N-Queen problem for 
   given value of N. This program uses backtracking algorithm and is a
   brute force approach to print all possibilites without considering the
   rotation of board. Although algorithm would work fo all N, it is better 
   to keep N less than 10 beacuse for N=10 there are more than 1000 possiblities
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<int> res;

void initialize(int n) {
  board.resize(n);
  for (int i = 0; i < n; i++) {
    board[i].resize(n);
  }
  res.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }
}

void mark(int safe, int r, int c, int n) {
  for (int i = 0; i < n; i++) {
    if (i != r) board[i][c] += safe;
  }
  for (int i = 0; i < n; i++) {
    if (i != c) board[r][i] += safe;
  }
  for (int i = r + 1, j = c + 1; i < n && j < n; i++, j++) {
    board[i][j] += safe;
  }
  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
    board[i][j] += safe;
  }
  for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
    board[i][j] += safe;
  }
  for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
    board[i][j] += safe;
  }
}

void printresult(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == res[i]) {
        cout << "q ";
      } else {
        cout << "* ";
      }
    }
    cout << endl;
  }
}

void n_queen(int n, int r) {
  for (int i = 0; i < n; i++) {
    if (board[r][i] == 0) {
      mark(1, r, i, n);
      res[r] = i;
      if (r == n - 1) {
        printresult(n);
        cout << endl;
      } else {
        n_queen(n, r + 1);
      }
      mark(-1, r, i, n);
    }
  }
}

void queen(int n) {
  initialize(n);
  n_queen(n, 0);
}

int main() {
  int n;
  cout << "Enter Value Of N: ";
  cin >> n;
  if (n > 10 && n < 1) {
    return 0;
  } else {
    queen(n);
  }
}