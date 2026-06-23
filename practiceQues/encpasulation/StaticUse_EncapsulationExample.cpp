/*
this demonstrates:

Encapsulation: activeSession is private.
Static data member: one copy shared by all objects.
Static member functions: access shared state without needing an object.
RAII: constructor acquires/increments the resource count, destructor releases/decrements it.
Scope-based lifetime management: objects are automatically cleaned up when they leave scope.
*/

#include<iostream>
#include<cstdint>
#include<atomic>

class SessionManager{
    private:
        static std::atomic <uint64_t> activeSession;
    public:
        SessionManager(){
            incrementSessionCount();
        }
    // getter function
        static uint64_t getActiveSession(){
            return activeSession.load();
        }
    // setter function
       static void incrementSessionCount(){
            ++activeSession;
       }
       
       static void decrementSessionCount(){
            if(activeSession>0)
                --activeSession;
        }

       ~SessionManager(){
            decrementSessionCount();
       }
};

std::atomic<uint64_t> SessionManager::activeSession{0};

int main(){
    // object creation
    
    SessionManager obj1;
    SessionManager obj2;

    {
    SessionManager obj3;
    std::cout<<"total Active Session is: "
             << SessionManager::getActiveSession()
             <<"\n";
    }
    // object1 deleted automatically when obj3 get out of scope
    std::cout<<"Now total Active Session is: "
             << SessionManager::getActiveSession()
             <<"\n";

    return 0;
}