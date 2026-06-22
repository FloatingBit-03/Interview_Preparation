#include<iostream>

class Demo{
private:
    std::string name;
    // mutable variable can be modified in const function
    mutable int count;
public:
    Demo(int c, std::string str): count(c), name(str){
        std::cout << "Constructor called with name = "<< name << "\n";
        std::cout << "Constructor called with count = " << count << "\n";
        
    }
     const std::string& getName() const{
        count++;
        return name;
     }
     int getCount() const{
        return count;
     }
};

int main(){
    Demo obj(0,"mohan");
    std::cout<< "name of object is "<< obj.getName()<<"\n";
    std::cout<< "count of object is "<< obj.getCount()<<"\n";

    return 0;
}