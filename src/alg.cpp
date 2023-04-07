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
    case ' ':
      return -101;
  }
  return -1;
}

std::string infx2pstfx(std::string inf) {
TStack<char, 100> st;
    std::string l = "";
    int nom = 0;
    int p = -1;

    for (auto& it : inf) {
    nom =  prior(it);
      p  = prior(st.poll());
    if (nom == 1) { 
         while (prior(st.poll()) > 0) {
        l =l+ st.pop();
        l =l+ " ";
      }
      st.pop();

      l += it;
      l += " ";
    }   else if (nom == 1) {  
      l += it;
      l += " ";
    } else if (nom > p || st.empty()) {
      st.push(it);
    } else if (nom == 0) {  
      st.push(it);
    } else if (nom <= p && nom > 1) {
      while (prior(st.poll()) > 1) {
        l += st.pop();
        l = l + " ";
      }
      st.push(it);
    }
      if (it == '\n') {  
        while (prior(st.poll()) > 1) {
           l += st.pop();
         l += " ";
        }
        st.pop();
      }
     
    }
    std::string out = "";
    for (int i = 0; i < l.length() - 1; ++i) {
      out =out+ l[i];
    }
    return out;

    while (prior(st .poll()) > 1) {
      l=l+ st .pop();
     l =l+ " ";
    }
 }
int operation(int x, int y, char it) {
    switch (it) {
      case '+':
        return x + y;
      case '-':
        return x - y;
      case '*':
        return x * y;
      case '/':
        return x /y;
    }
    return 0;
  }

int eval(std::string pref) {
   TStack<int, 100> stk;

    int x = 0;
    int y = 0;
    int result = 0;
    int z = 0;

    for (int i = 0; i < pref.length(); i++) {
     if (    isdigit(pref[i])) {
        z += atoi(&pref[i]);
        
     } else if (pref[i] == ' ') {
        if (z == 0) continue;
        stk.push(z);
        z = 0;

      } else {
        x = stk.pop();
        y = stk.pop();
        switch (pref[i]) {
         case '+':
           result = x + y;
           break;
         case '-':
           result = x - y;
           break;
         case '/':
           result = x / y;
           break;
         case '*':
           result = x * y;
           break;
        }
      }
      return result;
    } 
   
}
