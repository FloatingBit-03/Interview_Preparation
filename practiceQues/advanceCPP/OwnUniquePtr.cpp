#include<iostream>

template<typename T>
class UniquePtr{
    private:
        T* ptr;
    public:
        explicit UniquePtr(T* p = nullptr) : ptr(p)
        {
            std::cout<<" Ctor called to allocates Dynamic Resources"<<"\n";
        }   
        ~UniquePtr(){
            delete ptr;
            std::cout<<" Dtor called to free dynamic allocated resources"<<"\n";
        } 
};

int main(){
    UniquePtr p(new int(10));

    return 0;
}