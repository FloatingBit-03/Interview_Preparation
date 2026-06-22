  /*
    returning pointer to balance variable is a bad practice, 
    cause the encapsulation is broken and the balance variable can be modified outside the class, 
    which can lead to unexpected behavior and bugs in the code.
    */
#include<iostream>

class Employee{
    private:
        std::string name;
        size_t balance =0;
    public:
    // setter function for balance
        void setBalance(size_t inputBalance){
            balance += inputBalance;
        }
    // getter function for balance
  
   // returning the private member variable balance as a pointer, which can be modified outside the class
    //    size_t* getSalary(){
    //        return &balance;
     //   }
    // returninhg the private member balance as reference, leads to modification of private variable outside the class,

        size_t& getSalary(){
            return balance;
        }
};

int main(){
    Employee emp1;
    emp1.setBalance(1000);
    //std::cout << "Employee balance: " << emp1.getSalary() << std::endl;
   // *emp1.getSalary() =100;
   // std::cout << "modified employee salary: " << *emp1.getSalary()<< std::endl;

    // referencee 
    emp1.getSalary() = 100;
    std::cout << "modified employee salary: " << emp1.getSalary()<< std::endl;
    return 0;
}
