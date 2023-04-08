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
 TStack<char, 100> stck;
  int res = 0;
  std::string itog;
  
  for (char a : inf) {
    bool  mar = true;
    if (stck.empty() && prior(a) != -1) {
      mar = false;
      stck.Push(a);
    }
    if (prior(a) == -1) {
      mar = false;
      itog += a;
      itog += ' ';
       
    }
    if (prior(a) == 0) {
      mar = false;
      stck.Push(a);
      
    }
    if (prior(a) > prior(stck.pol())) {
      mar = false;
      stck.Push(a);
       
    }
    
    if (mar && a != ')') {
      while (prior(stck.pol()) >= prior(a)) {
        itog += stck.pop();
        itog += ' ';
      }
      stck.Push(a);
    }
    if (a == ')') {
      while (stck.pol() != '(') {
        itog =itog+ stck.pop();
        itog += ' ';
      }
      stck.pop();
    }
    if (res == inf.size() - 1) {
      while (!stck.empty()) {
        itog =itog+ stck.pop();
        if (stck.pri() != -1) {
          itog = itog +  ' ';
        }
      }
    }
    ++res;
  }
  return itog;
  }

int eval(std::string pref) {
  TStack<int, 100> stck2;
  
  
  for ( char i:pref) {
    if ((i - '0') > 0) {
      int o = i - '0';
      stck2.Push(o);
    }
    if (i == ' ') {
      continue;
    }
    if (i == '+') {
      int p = stck2.pop();
      p += stck2.pop();
      stck2.Push(p);
    }
    if (i == '-') {
      int p = stck2.pop();
      p = stck2.pop() - p;
      stck2.Push(p);
    }
    if (i == '/') {
      int p = stck2.pop();
      p = stck2.pop() / p;
      stck2.Push(p);
    }
    if (i == '*') {
      int p = stck2.pop();
      p *= stck2.pop();
      stck2.Push(p);
    }
    
    
  }
  return stck2.pol();
}
