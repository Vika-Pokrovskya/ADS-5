// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

 
int prior(char s) {
  switch (s) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '-':
      return 2;
    case '+':
      return 2;
    case '/':
      return 3;
    case '*':
      return 3;
    
  }
  return -1;
}


std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stck1;
  std::string itog;
  int res = 0;
  for (char a : inf) {
    bool iter = true;
    if (prior(a) == -1) {
      itog += a;
      itog += ' ';
      iter = false;
    }
    if (prior(a) == 0) {
      stck1.push(a);
      iter = false;
    }
    if (prior(a) > prior(stck1.pol())) {
      stck1.push(a);
      iter = false;
    }
    if (stck1.empty() && prior(a) != -1) {
      stck1.push(a);
      iter = false;
    }
    if (iter && a != ')') {
      while (prior(stck1.pol()) >= prior(a)) {
        itog += stck1.pop();
        itog += ' ';
      }
      stck1.push(a);
    }
    if (a == ')') {
      while (stck1.pol() != '(') {
        itog += stck1.pop();
        itog += ' ';
      }
      stck1.pop();
    }
    if (res == inf.size() - 1) {
      while (!stck1.empty()) {
        itog += stck1.pop();
        if (stck1.pri() != -1) itog += ' ';
      }
    }
    ++res;
  }
  return itog;
  }

int eval(std::string pref) {
 TStack<int, 100> stck2;
  
  
   
  for (char k : pref) {
     
    if (k == '+') {
      int i = stck2.pop();
      i = i + stck2.pop();
      stck2.push(i);
    }
    if (k == '-') {
      int i = stck2.pop();
      i = stck2.pop() - i;
      stck2.push(i);
    }
    if (k == '/') {
      int i = stck2.pop();
      i = stck2.pop() / i;
      stck2.push(i);
    }
    if (k == '*') {
      int i = stck2.pop();
      i = i * stck2.pop();
      stck2.push(i);
    }
    if (k == ' ') {
      continue;
    }
    if ((k - '0') > 0) {
      int i =k - '0';
      stck2.push(i);
    }
  }
  return stck2.pol();
}
