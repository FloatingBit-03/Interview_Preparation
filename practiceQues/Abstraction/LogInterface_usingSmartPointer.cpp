#include<iostream>
#include<string>
#include<memory>

class ILogger{
    public:
        virtual void log(const std::string& msg) = 0;
    // now making the dtor as virtual
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
    std::unique_ptr<ILogger> logger = std::make_unique<ConsoleLogger> ();
    logger->log("Console logger starting");

    return 0;
}