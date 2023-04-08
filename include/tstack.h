// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
    private:
  T mass[size] = {0};
  ;
  int a;

 public:
  TStack() {a = -1; }
  void Push(const T& value) {
    if (full()) {
      throw std::string(" full ");
    }else{
    mass[++a] = value;
    }
  }
  T pol() const { return mass[a]; }
  T pop() {
    if (empty()) {
    throw std::string(" empty ");
    }
  else {
    return mass[a--];
  }
  return mass[a--];
}
  int  pri() const { return a; }
  bool  empty() const { return a == -1; }
  bool full() const { return a == size; }
};

#endif  // INCLUDE_TSTACK_H_
