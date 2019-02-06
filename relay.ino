// This is about controlling the water pump through relay. 
// In the loop, we can see that it turns on every 5 seconds.
int pinRelay=2;//define pin 2 as the relay pin

void setup()
{
  pinMode(pinRelay,OUTPUT);//define the relay pin as the output pin
}
void loop()
{
  digitalWrite(pinRelay,LOW);delay(5000);
  digitalWrite(pinRelay,HIGH);delay(5000);
 }
