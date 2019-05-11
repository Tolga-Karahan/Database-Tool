#include <stdlib.h>
using namespace std;


struct MyClass {
   MyClass(const char* s);
   void methodA();
};

void someMethod(MyClass* m);

void test() {

   unique_ptr<MyClass> ptr1(new MyClass("obj1"));

   ptr1->methodA(); 
   
   someMethod(ptr1.get()); 

   unique_ptr<MyClass> ptr2(std::move(ptr1));

   ptr1.reset(new MyClass("obj2"));

   ptr2.reset("obj3");

   ptr1.reset();

}