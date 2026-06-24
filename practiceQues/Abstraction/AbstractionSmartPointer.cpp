#include<iostream>
#include<cstdint>
#include<memory>
#include<string>

class Message{
    private:
        uint32_t messageid;
        uint64_t length;
    public:
        Message( uint32_t mid, uint64_t len): messageid(mid), length(len)
        {
        }

        // void setMessage(uint32_t mid, uint64_t len){
        //     messageid = mid;
        //     length = len;
        //     std::cout<<"message id and length is setting"<<"\n";
        // }

        uint32_t getMessgaeId() const
        {
            return messageid;
        }

        uint64_t getMessageLength() const
        {
            return length;
        }

        virtual void displayMessage() const = 0; // pure virtual function tpo display message 
        virtual ~Message() = default;

};

class RadiusMessage:public Message{
    public:
        RadiusMessage( uint32_t mid, uint64_t len) : Message(mid,len)
        {
        }

        void displayMessage() const override 
        {
            std::cout << "Message Type: Radius Message" << "\n"
                      << "Message ID: " << getMessgaeId() << "\n"
                      << "Message Length: " << getMessageLength() << "\n";                  
        }

};

class DiameterMessage: public Message{
    public:
        DiameterMessage( uint32_t mid, uint64_t len): Message(mid,len)
        {
        }

        void displayMessage() const override 
            {
                std::cout << "Message Type: Diameter Message" << "\n"
                        << "Message ID: " << getMessgaeId() << "\n"
                        << "Message Length: " << getMessageLength() << "\n";                  
            }
};


int main(){
    // Radius message
    //Message* mptr1 = new RadiusMessage("RadiusMessage");
    std::unique_ptr<Message> mptr1= std::make_unique<RadiusMessage>(100, 32);
    //mptr1->setMessage(100,32);
    std::cout<<"Radius Message"<<"\n";
    mptr1->displayMessage();
    
    // diameter message
    //Message* mptr2 = new DiameterMessage("DiameterMessage");
    std::unique_ptr<Message> mptr2 = std::make_unique<DiameterMessage>(200, 128);
    //mptr2->setMessage(200,128);
    std::cout<<"diameter Message"<<"\n";
    mptr2->displayMessage();

    return 0;
}