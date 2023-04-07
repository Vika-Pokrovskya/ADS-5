// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
   private:
  T mass[100];
  int a;

 public:
  TStack() : a(-1) {}
   
  const T& pop() {
    if ( empty()) {
      throw std::string("empty!!!!!");
    } else {
      return mass[a--];
    }
  }
  void push(T value) {
    if (full()) {
      throw std::string("It is full(((");
    } else {
     mass[++a] = value;
    }
  }
  
  const T& poll() const { return mass[a]; }
  bool empty() const { return a == -1; }
  bool full() const { return a == size - 1; }
};

#endif  // INCLUDE_TSTACK_H_
