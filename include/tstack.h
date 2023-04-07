// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
    private:
  T mass[size] = {0};
  int a;

 public:
  TStack() {a = -1; }
  void Push(const T& value) {
    if (!isFull()) {
      mass[++a] = value;
    }
  }
  T      get() const { return mass[a]; }
  T pop() { return mass[a--]; }
  int GetTop() const { return a; }
  bool isEmpty() const { return a == -1; }
  bool isFull() const { return a == size; }
};

#endif  // INCLUDE_TSTACK_H_
