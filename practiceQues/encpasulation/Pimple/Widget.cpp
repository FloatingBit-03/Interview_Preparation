#include"Widget.h"
#include<iostream>
#include<string>

// full impleemtation is hidden from Midget

class Widget::Impl {
    public:
    std::string name;
    int counter;

    Impl() : name("Internal Widget"), counter(0)
    {

    }

    void performWork(){
        ++counter;
        std::cout<< "working on "<< name
                 << ", count = "
                 << counter << "\n";
    }
};

Widget::Widget()
    : pImpl(std::make_unique<Impl>())
    {

    }

    Widget::~Widget() = default;

    void Widget::doWork()
    {
        pImpl->performWork();
    }