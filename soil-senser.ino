int ledpin=13;//define pin 13
int inpin=2;//define pin 2
int val;//define a variable
long  val_1;//define a variable
float  voltage;//define a variable 

void setup()
{
  pinMode(ledpin,OUTPUT);//define the ledpin as the output pin
  pinMode(inpin,INPUT);//define pin 2 as the input pin
  Serial.begin(115200);//define the baud rate as 115200, this should be consistent with the software setting. when connceting to other devices, like bluetooth, we should keep the baud rate consistent with these devices.
}
void loop()
{
    val=digitalRead(inpin);//read pin 2 and pass the value
    val_1=analogRead(A0);//collect the analog signal and pass the value 
    Serial.println(val_1);//print the analog value
    voltage=(val_1*0.0048828125);//convert to the voltage value
    //Serial.println(val);
    Serial.print(voltage);//print the voltage
    Serial.println("V");//print the "V" as the measure word for voltage
//    if(val==HIGH)
//    {
//      digitalWrite(ledpin,LOW);
//    }
//    else
//    { 
//      digitalWrite(ledpin,HIGH);
//    }
//    delay(1000);
}
