#include <iostream> 
using namespace std; 

class Father {
  public:
    virtual void Say() {
      cout << "Father say hello" << endl;
    }
};

class Son:public Father {
  public:
    void Say() {
      cout << "Son say hello" << endl;
    }
};

class A {
  private:
    int x;
    void set(int value) { x = value; }
  public:
    void setx(int value) { set(value); }
    void printx() { cout << x << endl; }
    void check() {
        A b;
        b.set(10);
        b.printx();
    }
};

int main() {
  Son son;
  Father *pFather = &son;
  Father& father = son;
  pFather->Say();
  father.Say();

  A a;
  a.printx();
  a.setx(10);
  // a.set(20);
  a.printx();
  a.check();
}

