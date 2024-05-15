#ifndef __DICE_H_INCLUDED__
#define __DICE_H_INCLUDED__

//  for the NULL Pointer
#include <cstddef>

class Singleton {
    private:
        // static Ptr to the class instance
        static Singleton* instancePtr;
        // private default constructor
        Singleton() {}

    public:
        // deleting copy constructor
        Singleton(const Singleton& dice) = delete;

        // static method 
        static Singleton* getInstance() {
            // if Singleton 
            if (instancePtr == NULL) {
                instancePtr = new Singleton();
                return instancePtr;
            }
            else {
                return instancePtr;
            }
        }
};

class Dice : Singleton
{
private:
    // member variables
public:
};



#endif
