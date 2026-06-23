#include<iostream>
#include<mutex>

class MyClass{
    private:
        static int count;
        static std::mutex m;
    public:
        MyClass(){
            std::cout<<"Ctor called "<<"\n";
            std::lock_guard< std::mutex > lock(m);
            ++count;
        }

        static int getCount() {
            std::lock_guard<std::mutex> lock(m);
            return count;    
        }

        ~MyClass(){
            std::lock_guard<std::mutex> lock(m);
            --count;
            std::cout<<"Dtor called, object remains: "<< count <<"\n";
        }

};

int MyClass::count =0;
std::mutex MyClass::m=0;

int main(){
    MyClass obj1;
    MyClass obj2;
    {
        MyClass obj3;
        std::cout<<"Number of objects created till now is: "<< MyClass::getCount()<<"\n";
    }

     std::cout<<"now total numbers of objects created is: "<< MyClass::getCount()<<"\n";

    return 0;
}