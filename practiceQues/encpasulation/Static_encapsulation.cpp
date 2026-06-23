/*
Private static members are used when data must be shared across all objects of a class but should not be directly accessible. 
Encapsulation is maintained by keeping the static member private and providing controlled access through static getter/setter functions.
This allows validation, logging, synchronization, and invariant enforcement while protecting the shared state from accidental modification.
*/
#include<iostream>

class MyClass{
private:
    static int count;
public:
    void setCounter(){
        count++;
    }

    const static int getCount() {
        return count;
    }
};

int MyClass::count = 0;

int main(){
    MyClass obj1;
    obj1.setCounter();
    MyClass obj2;
    obj2.setCounter();
    MyClass obj3;
    obj3.setCounter();

    std::cout<<"total number of object creates is:: "<<obj3.getCount()<<"\n";

    return 0;
}