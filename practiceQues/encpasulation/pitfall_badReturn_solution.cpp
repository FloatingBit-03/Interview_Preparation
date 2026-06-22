
/*
Preferred approaches:

Return primitive types by value.
Return large objects as const&.
Copying a std::string may allocate memory, so returning a const reference avoids that cost.
Avoid returning non-const references to private members unless modification is intentionally allowed.

*/
#include<iostream>

class Employee {
    private:
        std::string name;
        size_t salary;
    public:
        Employee(std::string str, size_t sal) : name(str), salary(sal) {
            std::cout<<"ctor to creates employee entry \n";
        } 
    // setter function to set employee's salary
        void setSalary(size_t sal){
            salary =sal;
        }
    //getter function to get employee's salary
        const size_t& getSalary() const{
            return salary;
        }
    // getter for employee's name
        const std::string& getName() const{
            return name;
        }
};

int main(){
    Employee emp1("mohan", 1000000);
    std::cout<<"Employee's name is: "<<emp1.getName()<<"\n";
    std::cout<<"Employee's salary is: "<<emp1.getSalary()<<"\n";
    //emp1.getSalary() = 1200000; // This line will cause a compilation error because getSalary() returns a const reference
    emp1.setSalary(1200000);
    std::cout<<"Employee's salary after increment is: "<<emp1.getSalary()<<"\n";
    return 0;
}