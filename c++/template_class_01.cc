#include <iostream>

using namespace std;

/*
  Define a template class
  "template <class T>" equals to "template <typename T>"
*/
template <class T1, class T2>
class MyClass {
  private:
    T1 I;
    T2 J;
  public:
    // Constructor
    MyClass(T1 a, T2 b);
    void show();
};

template <class T1, class T2>
MyClass<T1, T2>::MyClass(T1 a, T2 b):I(a), J(b){}

/*
  Define a template function
*/
template <class T1, class T2>
void MyClass<T1, T2>::show() {
  cout<<"I="<<I<<", J="<<J<<endl;
}

int main() {
  MyClass<int, int> class1(3, 5);
  class1.show();

  MyClass<int, char> class2(3, 'a');
  class2.show();

  MyClass<double, int> class3(2.9, 10);
  class3.show();

  return 0;
}

