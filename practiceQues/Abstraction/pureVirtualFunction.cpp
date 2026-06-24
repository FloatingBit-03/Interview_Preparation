#include<iostream>
#include<cstdint>

class Message{
    protected:
        uint32_t messageid;
        uint64_t length;
    public:
        Message(uint32_t mid, uint64_t len) : messageid(mid), length(len){
            std::cout<<"message class Ctor called to initialized variables"<<"\n";
        }
        void setMessage(uint32_t mid,uint64_t len){
            messageid=mid;
             length=len;
            return;
        }

        uint32_t getMessageId() const{
                 return messageid;
        }
        // display function is virtual that means radius and diameter class can define their own diplay function with their specifications 
        virtual void  displayMessage() = 0;

        virtual ~Message()=default;

};

class RadiusMessage:public Message{
    public:
    RadiusMessage(uint32_t mid, uint64_t len): Message(mid, len)
    {

    }
    void displayMessage() override{
        std::cout<<"display the Radius Message" << "\n";
        std::cout<<"message type: "<<"radius"
                 <<"message id: "<< messageid
                 <<"message Length: "<<length
                 <<"\n";
    }

};

class DiameterMessage:public Message{
    public:
    DiameterMessage(uint32_t mid, uint64_t len) : Message(mid, len)
    {

    }

    void displayMessage() override{
        std::cout<<"display the Diameter Message" << "\n";
        std::cout<<"message type: "<<"diameter"
                 <<"message id: "<< messageid
                 <<"message Length: "<<length
                 <<"\n";
    }
};

int main(){
    Message* mptr1= new RadiusMessage(100,32);
    mptr1->displayMessage();
    
    Message* mptr2= new DiameterMessage(200,128);
    mptr2->displayMessage();

    // deletes allocated resources
    delete mptr1;
    delete mptr2;

    return 0;
}