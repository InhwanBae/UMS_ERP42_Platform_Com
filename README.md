## UMS_ERP42_Platform_Com
Test code for unmanned solution ERP-42 platform

[http://www.wegokorea.kr/02_pro03_10.html](http://www.wegokorea.kr/02_pro03_10.html)

[http://www.robotworld.or.kr/intro_info.php?sid=18](http://www.robotworld.or.kr/intro_info.php?sid=18)

![ERP42IMG](http://www.wegokorea.kr/images/p168.gif)

## Features
* Real-time user input process & control platform
* Multiple Input Control
* Emergency Stop(E-STOP) feature
* Using c++

## Environments
* Microsoft Windows
* Visual Studio 2015

## Running Examples
First launch, you need to input the serial port that connect to the platform.
```
COM Port: 4
```

If the connection failed, it will show message.
```
Connection Failed
```

If the connection Success, you can see the command example.
```
Commands: AorM, E-STOP, GEAR, SPEED, STEER, BREAK, QUIT
example: GEAR 1 SPEED 100
```
There are 6 platform control commands, 1 exit control. With platform's mannual, you can set individual values with commands.
```
GEAR 0 SPEED 200 BREAK 0 BREAK 0
GEAR 0 SPEED 50 STEER 200 
GEAR 1 SPEED 0 STEER 0 BREAK 10
```

If you make any typos, it will show the emergency-stop message, send platform `E-STOP 1`. You have to type `E-STOP 0` to exit from emergency-stop mode and control platform. You can use this method at any emergency situations
```
 "Enter correct code. Emergency Stopped" 
```
