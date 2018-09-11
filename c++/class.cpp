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

int main() {
  Son son;
  Father *pFather = &son;
  Father& father = son;
  pFather->Say();
  father.Say();
}

