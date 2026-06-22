#include<string>
#include<iostream>
#include<memory>

// encapsulation using private and public access specifiers
class Employee{
    private:
        std::string name;
        int empId;
    public:
        Employee(const std::string& n, int id): name(n),empId(id){
        }

        int getEmpId() const{
            return empId;
        }

        const std::string& getName() const{
            return name;
        }
        // using pure virtual function to creates abstraction (abstract class)
        virtual void calculateSalary() const =0; // pure virtual function

       virtual ~ Employee()= default; // default destructor for better compiler optimization
};

// inhetance
class Developer: public Employee{
    private:
        int salary;
        int bonus;
    public:
        Developer(const std::string& n, int id, int s, int b): Employee(n,id), salary(s), bonus(b){
        }
    // runtime polymorphism achieved by overriding the base class method
        void calculateSalary() const override{
            std::cout<<"Total Salary of Developer: "<<salary+bonus<<std::endl;      
        }
};

class Manager: public Employee{
    private:
        int salary;
        int bonus;
        int perk;
    public:
        Manager(const std::string& n, int id, int s, int b, int p): Employee(n,id), salary(s), bonus(b), perk(p){
            }
        void calculateSalary() const override{
            std::cout<<"Total Salary of Manager: "<<salary+bonus+perk<<std::endl;
        }   
};

int main(){
    // Employee* Emp1= new Developer("mohan",123,10000,2000);
    // Employee* Emp2= new Manager("ravi",456,20000,5000,1000);

    // std::cout<<"Employee name:: "<<Emp1->getName()
    //          <<"Employee ID:: "<<Emp1->getEmpId()<<std::endl;
    
    // std::cout<<"Employee name:: "<<Emp2->getName()
    //          <<"Employee ID:: "<<Emp2->getEmpId()<<std::endl;
    
    // Emp1->calculateSalary();
    // Emp2->calculateSalary();
 
    // // free resources allocating using new
    // delete Emp1;
    // delete Emp2;

    // use of smart pointer to masnage dynamic memory and avoid memory leaks
    std::unique_ptr<Employee> Emp1 = std::make_unique<Developer>("Mohan", 123, 20000,5000);
    std::unique_ptr<Employee> Emp2 = std::make_unique<Manager>("Ravi",456,30000,10000,5000);

    std::cout<<"Employee name:: "<<Emp1->getName()
             <<"Employee ID:: "<<Emp1->getEmpId()<<std::endl;
    
    std::cout<<"Employee name:: "<<Emp2->getName()
             <<"Employee ID:: "<<Emp2->getEmpId()<<std::endl;
    
    Emp1->calculateSalary();
    Emp2->calculateSalary();
 
    return 0;
}