#include<iostream>
#include<cstdint>
#include<memory>
#include<string>

class Message{
    private:
        uint32_t messageid;
        uint64_t length;
    public:
        Message(): messageid(0), length(0)
        {
        }

        void setMessage(uint32_t mid, uint64_t len){
            messageid = mid;
            length = len;
            std::cout<<"message id and length is setting"<<"\n";
        }

        uint32_t getMessgaeId() const
        {
            return messageid;
        }

        uint64_t getMessageLength() const
        {
            return length;
        }

        virtual void displayMessage() = 0; // pure virtual function tpo display message 
        virtual ~Message() = default;

};

class RadiusMessage:public Message{
    private:
        std::string messageType;
    public:
        RadiusMessage(const std::string& mtype): messageType(mtype)
        {

        }

        void displayMessage() override 
        {
            std::cout << "Message Type: " << messageType << "\n"
                      << "Message ID: " << getMessgaeId() << "\n"
                      << "Message Length: " << getMessageLength() << "\n";                  
        }

};

class DiameterMessage: public Message{
    private:
        std::string messageType;
    public:
        DiameterMessage(const std::string& mtype): messageType(mtype)
            {

            }

        void displayMessage() override 
            {
                std::cout << "Message Type: " << messageType << "\n"
                        << "Message ID: " << getMessgaeId() << "\n"
                        << "Message Length: " << getMessageLength() << "\n";                  
            }
};


int main(){
    // Radius message
    Message* mptr1 = new RadiusMessage("RadiusMessage");
    mptr1->setMessage(100,32);
    std::cout<<"Radius Message"<<"\n";
    mptr1->displayMessage();
    
    // diameter message
     Message* mptr2 = new DiameterMessage("DiameterMessage");
    mptr2->setMessage(200,128);
    std::cout<<"diameter Message"<<"\n";
    mptr2->displayMessage();

    // deleting all the dynamic resources
    delete mptr1;
    delete mptr2;
    
    return 0;
}