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
 TStack<char, 100> stt;
  std::string res;
  int k = 0;
  for (char a : inf) {
    bool flag = 1;
    if (prior(a) == -1) {
      res += a;
      res += ' ';
      flag = 0;
    }
    if (prior(a) == 0) {
      stt.Push(a);
      flag = 0;
    }
    if (prior(a) > prior(stt.get())) {
      stt .Push(a);
      flag = 0;
    }
    if (stt.isEmpty() && prior(a) != -1) {
      stt.Push(a);
      flag = 0;
    }
    if (flag && a != ')') {
      while (prior(stt.get()) >= prior(a)) {
        res += stt.pop();
        res += ' ';
      }
      stt.Push(a);
    }
    if (a == ')') {
      while (stt.get() != '(') {
        res += stt.pop();
        res += ' ';
      }
      stt.pop();
    }
    if (k == inf.size() - 1) {
      while (!stt.isEmpty()) {
        res += stt.pop();
        if (stt.GetTop() != -1) res += ' ';
      }
    }
    ++k;
  }
  return res;
  }

int eval(std::string pref) {
  TStack<int, 100> st2;
  for (char a : pref) {
    if (a == ' ') {
      continue;
    }
    if (a == '+') {
      int p = st2.pop();
      p += st2.pop();
      st2.Push(p);
    }
    if (a == '-') {
      int p = st2.pop();
      p = st2.pop() - p;
      st2.Push(p);
    }
    if (a == '*') {
      int p = st2.pop();
      p *= st2.pop();
      st2.Push(p);
    }
    if (a == '/') {
      int p = st2.pop();
      p = st2.pop() / p;
      st2.Push(p);
    }
    if ((a - '0') > 0) {
      int o = a - '0';
      st2.Push(o);
    }
  }
  return st2.get();
 
}
