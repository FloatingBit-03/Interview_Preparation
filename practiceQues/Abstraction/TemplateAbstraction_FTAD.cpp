/*
Here:
        Abstraction is not a template class.
        add() is a template member function.
                                            When the compiler sees

obj.add(10,20);
it deduces; T = intm, and generates

int add(int a, int b)
{
    return a + b;
}

When it sees: obj.add(10.2,20.3);

it generates

double add(double a, double b)
{
    return a + b;
}

This is called function template argument deduction.
*/

#include<iostream>

class Abstraction{
    public:
        template<typename T>

        T add(T a, T b){
            return a + b;
        }
};

int main(){
    Abstraction obj;

    std::cout<<"sum two integers 10 and 20 is: "<<obj.add(10,20)<<"\n";
    std::cout<<"sum two double 10.2 and 20.3 is: "<<obj.add(10.2,20.3)<<"\n";


    return 0;
}