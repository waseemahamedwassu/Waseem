#include <iostream>

using namespace std;

template <class T>
struct itf_T {
  virtual void doit() = 0;
};

struct obj_base {
  int nb;
  obj_base() : nb(42) {}
};

template <class T>
struct obj : public itf_T<T>, public obj_base {
  void doit() {cout << "hello" << endl;}
};


int main() {
  itf_T<int> * i = new obj<int>();
  i->doit();
  cout << (dynamic_cast<obj_base *>(i))->nb << endl;
  cout << ((obj_base *)(i))->nb << endl;
  return 0;
}
