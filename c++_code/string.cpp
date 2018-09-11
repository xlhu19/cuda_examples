#include <iostream>
#include <string.h>

using namespace std;

void swap(const int& a, int& b) {
    int temp = a;
    // a = b;
    b = temp;
}

int test() {
  int a = 10;
  return a;
}

int main() {
    char* c1 = (char*) "Today is a good day!";
    // cout<<strlen(strlen(c1))<<endl;
    // char*& c2 = c1;
    int a = 1;
    int& b = a;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<&a<<endl;
    cout<<&b<<endl;

    int c = 10;
    b = 20;

    swap(test(), c);
    cout<<a<<endl;
    cout<<c<<endl;

}

