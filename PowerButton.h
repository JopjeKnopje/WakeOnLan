#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include "Arduino.h"




class PowerButton
{
    protected:
        unsigned int pin;

    public:
        PowerButton(unsigned int pin);
        void turnOn();
        void turnOff();
        // TODO Maybe add turnoff-forced

    private:
        static const int TURN_ON_TIME = 500;
        static const int TURN_OFF_TIME = 1500;

};


#endif