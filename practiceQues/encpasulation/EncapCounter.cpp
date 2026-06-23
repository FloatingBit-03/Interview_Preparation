#include<iostream>
#include<atomic>

class CounterClass{
    private:
        static std::atomic<int> count;
    public:
        CounterClass(){
            std::cout<<"counter initialization using Ctor"<<"\n";
            ++count;
        }

        static int getCount(){
            return count.load();
        }

        ~CounterClass(){
            --count;
            std::cout<<"object deleted using Dtor"<<"\n";
        }
};

std::atomic<int> CounterClass::count = 0;

int main(){
    CounterClass obj1;
    CounterClass obj2;
    {
        CounterClass obj3;
        std::cout<<"total number of counter is: "<< CounterClass::getCount()<<"\n";
    }

    std::cout<<"Now total number of counter is: "<< CounterClass::getCount()<<"\n";
    return 0;
}