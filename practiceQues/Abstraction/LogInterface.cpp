#include<iostream>

class ILogger{
    public:
        virtual void log(const std::string& msg) = 0; //pure virtual function no body
        virtual ~ILogger() = default;
};

class ConsoleLogger:public ILogger{
    public:
        void log(const std::string& msg) override
        {
            std::cout<< msg <<"\n";
        }
};

int main(){
    // ConsoleLogger obj;
    // obj.log("Starting of Console logger");  interface doesn not reaaly used
    ILogger* logger =new ConsoleLogger();
    logger->log("Console Logger Starting");
    delete logger;

    return 0;
}