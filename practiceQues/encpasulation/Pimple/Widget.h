#ifndef WIDGET_H
#define WIDGET_H

#include<memory>

class Widget {
    private:
        class Impl; // forward decleration
        std::unique_ptr<Impl> pImpl; //pointer to implementation
    public:
        Widget();
        ~Widget();   // this must be difine in .cpp file

        void doWork();
};

#endif