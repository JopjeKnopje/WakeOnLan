#include "PowerButton.h"



PowerButton::PowerButton(unsigned int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    
}


void PowerButton::turnOff()
{
    digitalWrite(pin, HIGH);
    delay(TURN_OFF_TIME);
    digitalWrite(pin, LOW);
}


void PowerButton::turnOn()
{
    digitalWrite(pin, HIGH);
    delay(TURN_ON_TIME);
    digitalWrite(pin, LOW);
}

