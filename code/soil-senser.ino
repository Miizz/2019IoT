/* This file is about only testing the soil moisture sensor.
 */

int inpin = 2;    // define pin 2 as the input pin for the soil sensor
int val_digital;    // define a variable for digital read
long val_analog;    // define a variable for analog read
float voltage;    // define a variable for the voltage that pass the soil sensor

void setup()
{
  pinMode(inpin,INPUT);    // define pin 2 as the input pin for soil snesor
  Serial.begin(115200);    // define the baud rate as 115200, this should be consistent with the software setting. When connecting to other devices, like bluetooth, or wifi module, we should keep the baud rate consistent with them.
}
void loop()
{
    val_digital = digitalRead(inpin);    // read pin 2 and pass the value
    val_analog = analogRead(A0);    // collect the analog signal and pass the value
    Serial.println(val_analog);    // print the analog value
    voltage = (val_analog * 0.0048828125);    // convert to the voltage value
    Serial.print(voltage);    // print the voltage that passes the soil sensor
    Serial.println("V");    // print the "V" as the measure word for voltage
}
