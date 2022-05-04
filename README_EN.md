# Psychrometer
Library for determining humidity by dry and wet bulb for Arduino
- The library is not tied to a thermometer, it takes a pure temperature
- Cunning approximation of partial pressure tables
- Possibility to calibrate the psychrometer constant

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found by the name **Psychrometer** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download Library](https://github.com/GyverLibs/Psychrometer/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
Psychrometer psy;
```

<a id="usage"></a>
## Usage
```cpp
float getHumidity(float dry, float wet); // get humidity from (dry temp, wet temp)
float calibrate(float dry, float wet, float hum); // calibration A to (dry temp, wet temp, real wet)
void setP(long p); // set pressure (in pascals)
void setPmm(float p); // set pressure (in mmHg)
void setA(float a); // set psychrometer constant
float getA(); // get psychrometer constant
```

<a id="example"></a>
## Example
```cpp
#include <Psychrometer.h>
Psychrometer psy;

void setup() {
  Serial.begin(9600);
  
  //psy.setP(99085); // set pressure in Pa
  psy.setPmm(745); // set pressure in mm. rt. Art.
  
  // get humidity by (dry temp, wet temp)
  Serial.println(psy.getHumidity(15.0, 12.5));
  
  // calibrate the device constant
  //psy.calibrate(15.0, 12.5, 30); // (dry temp, wet temp, real wet)
  // get new A from psy.getA()
  //psy.setA(0.0007947); // set device constant (default 0007947)
}

void loop() {
}
```

<a id="versions"></a>
## Versions
- v1.0

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!