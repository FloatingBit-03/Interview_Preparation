#include<iostream>
#include<string>
#include<memory>
#include<filesystem>
#include<fstream>

class ILogger{
    public:
        virtual void log(const std::string& msg) = 0;
        // creates virtual default dtor
        virtual ~ILogger() = default;
};

class ConsoleLogger:public ILogger{
    public:
        void log(const std::string& msg) override
        {
            std::cout<< msg <<"\n";
        }
};

class FileLogger:public ILogger{
    private:
        //std::ofstream file("/mnt/c/Users/Mohan Singh/Desktop/Interview_Prepration/practiceQues/Abstraction/app.log");
        std::ofstream file;
    public:
        FileLogger(const std::string& filename = "app.log") : file(filename, std::ios::app) //append mode
            {
                // check if file is open or not
                if(!file.is_open()){
                    throw std::runtime_error("failed to open log file");
                }
                    std::cout<<" filelogger writing to: "
                             << std::filesystem::absolute(filename)
                             <<"\n";
            }
        void log(const std::string& msg) override
            {
                file << msg <<"\n";
            }
};

int main(){
    // creates unique pointer to access Console Logger
    std::unique_ptr<ILogger> logger;
    
    logger = std::make_unique<ConsoleLogger> ();
    logger->log("Console Logger");

    logger = std::make_unique<FileLogger> ();
    logger->log("File Logger");

    return 0;
}