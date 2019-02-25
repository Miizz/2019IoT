/* This is about testing the relay, which controls the water pump.
   It will turn on and off the relay for a period of 5 seconds.
 */

int pinRelay = 2;    // define pin 2 as the relay pin

void setup()
{
  pinMode(pinRelay,OUTPUT);    // define the relay pin as the output pin
}

void loop()
{
  digitalWrite(pinRelay,LOW);delay(5000);    // turn the water pump off and last for 5 seconds.
  digitalWrite(pinRelay,HIGH);delay(5000);    // turn the water pump on and last for 5 seconds.
 }
