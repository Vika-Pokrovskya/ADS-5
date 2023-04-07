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
TStack<char, 100> stk;
  std::string str = "";
  bool flag = false;

  for (int i = 0; i < inf.length(); i++) {
    if (inf[i] == '(') {
      flag = true;
      continue;
    }

    if (inf[i] == ')' && !stk.isEmpty()) {
      flag = false;
      str.push_back(stk.pop());
      str.push_back(' ');

      if (!stk.isEmpty() && (stk.GetTop() == '*' || stk. GetTop() == '/')) {
        str.push_back(stk.pop());
        str.push_back(' ');
      }

      continue;
    } else if (inf[i] == ')') {
      flag = false;
      continue;
    }

    if (!flag && (inf[i] == '+' || inf[i] == '-') && !stk.isEmpty() &&
        (stk.GetTop() == '*' || stk.GetTop() == '/')) {
      str.push_back(stk.pop());
      str.push_back(' ');
    }

    if (inf[i] == '*' || inf[i] == '/' || inf[i] == '+' || inf[i] == '-') {
      stk.Push(inf[i]);
      continue;
    }

    if (isdigit(inf[i])) {
      str.push_back(inf[i]);
      str.push_back(' ');
      continue;
    }
  }

  while (!stk.isEmpty()) {
    str.push_back(stk.pop());
    str.push_back(' ');
  }

  str.pop_back();

  return str;
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
