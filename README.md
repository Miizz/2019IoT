# Automatic Watering System

## About the artefact
> Have you ever left home for some days and been worried that no one can help you take care of your plants? Or have you ever found that the plants look so dry and withered due to long time of lacking water? This project focuses on helping you with such problems by building a communication between you and your plants!

To briefly talk about the project, it is a system that puts sensors in the soil of the plants, enables plants to **"talk"** to humans by sending data through wifi to smart phones, to notify people that they need some care. 

The **working process** is: 
1. Sensors sense the moisture in the soil and send the data to ESP32(the micro-controller).
2. ESP32(wifi client) processes the data and send messages to the smart phone(wifi server).
3. Smart phone can send commands to turn on/off the water pump to water the plants.

**Applications**: This is a simple system that uses sensors to detect the condition of items. For example, if we put sensors in the roads that can sense the rubbish or dirt on the road, it will be easier for cleaners to design the route of cleaning them. They might just need to choose some of the roads to clean and use the appropriate amount of water to clean them according to the road conditions. Another such example can be setting up sensors in the garbage bins so that the trash collectors can get this information of how full the trash bins are and only collect some of the trash bins rather than checking every single one in the town. These applications assist people in their respective occupations by disconnecting people from physically checking the conditions of items. They just need to react to the system when the condition needs to be improved or changed. 

## Hardware 
![things](https://github.com/Miizz/2019IoT/blob/master/pictures/things.jpg)
The above picture shows the hardware that I use for the project. Includes:
- an ESP32 micro-controller
- a soil moisture sensor
- a relay 
- a water pump
- a smart phone

All the items can be purchased online.

## Software
- [Arduino IDE](https://www.arduino.cc/en/Main/Software) is an open-source IDE that can be run on Windows, Mac OS X, and Linux. The environment is written in Java and based on Processing and other open-source software. This software can be used with any Arduino board. You can find more [instructions](https://www.arduino.cc/en/Guide/HomePage) here. 
- [mind+](http://www.mindplus.cc/) is a programming software designed for teenagers based on Scratch3.0. It allows people who do not have any programming experience to use advanced programming languages like python, C, and C++. [Full instructions](http://docs.dfrobot.com.cn/mindplus/) can be found here.

## More related blogs
To design this project, I have some [blogs](https://cs.anu.edu.au/courses/china-study-tour/news/#michelle-zhou) recording the progress, and a [design rationale](https://cs.anu.edu.au/courses/china-study-tour/news/2019/02/18/michelle-design-rationale/) to summarize my ideas. You are welcomed to read them.

## Future Development & Contact
Since this is just a simple system for people to take care of their single plant, I am hoping to extend this system to multiple plants, as well as include more sensors to detect the other aspects of health for the plants, which can be related to in horticultural technologies and greenhouse cultivation. 

If you have similar ideas or any kind of suggestions, you are very welcomed to contact me through email: *u6349815@anu.edu.au*.


## License
[MIT license](LICENSE.txt)