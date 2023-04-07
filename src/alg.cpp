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
std::string a = "";
  bool flag = true;
  TStack<char, 100> stack1;
  for (int i = 0; i < inf.length(); i++) {
    if (prior(inf[i]) == inf[i]) {
      a = a + inf[i] + ' ';
      continue;
    } else {
      if (prior(inf[i]) == 0) {
        stack1.Push(inf[i]);
        continue;
      }
      if (stack1.isEmpty()) {
        stack1.Push(inf[i]);
        continue;
      }
      if (prior(inf[i]) > prior(stack1.get())) {
        stack1.Push(inf[i]);
        continue;
      }
      if (prior(inf[i]) <= prior(stack1.get()) && prior(inf[i]) != 0) {
       a = a + stack1.get() + ' ';
        stack1.pop();
      }
      if (prior(inf[i]) == 1) {
        stack1.pop();
      } else {
        stack1.Push(inf[i]);
      }
    }
  }
  while (!stack1.isEmpty()) {
   a = a + stack1.get();
    stack1.pop();
    if (!stack1.isEmpty()) {
      a = a + ' ';
    }
  }
  return a;
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
