#include<iostream>

class Account{
private:
    double balance;
public:
// called parameterized ctor    
    Account(double initialBalance): balance(initialBalance){
            std::cout<<"Ctor called to initialized the balance"<<"\n";
        }
// setter function to set balance
    void deposit(double amount){
        balance += amount;
    } 
// getter function to get updated latest balance
    double getBalance() const{
        return balance;
    }
// withdraw function to withdraw amount from balance
    void withdraw(double amount){
        // check the amount to be withdrawn
        if(amount > balance){
            std::cout<<"insufficient Account balance"<<"\n";
            return;
        }
        else{
            balance -= amount;
            std::cout<<"Amount withdrawn successfully"<<"\n";
        }
    }

};

int main(){
    Account acc(1000.0);
    std::cout<<"Initial Balance: "<<acc.getBalance()<<"\n";
    acc.deposit(500.0);
    std::cout<<"Balance after deposit: "<<acc.getBalance()<<"\n";
    acc.withdraw(200.0);    
    return 0;
}