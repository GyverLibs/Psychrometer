This is an automatic translation, may be incorrect in some places. See sources and examples!

# PSYCHROMETER
Library for determining humidity by dry and wet thermometer for arduino
- The library is not tied to the thermometer, takes purely temperature
- cunning approximation of partial pressure tables
- the ability to calibrate a constant psychrometer

## compatibility
Compatible with all arduino platforms (used arduino functions)

## Content
- [installation] (# Install)
- [initialization] (#init)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found by the name ** psychrometer ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download library] (https://github.com/gyverlibs/psychrometer/archive/refs/heads/main.zip). Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="init"> </a>
## initialization
`` `CPP
PSYCHROMETER PSY;
`` `

<a id="usage"> </a>
## Usage
`` `CPP
Float Gethumidity (Float Dry, Float Wet);// Get moisture from (pace. Sukh., Tempe. Wolf.)
Float Calibrate (Float Dry, Float Wet, Float Hum);// Calibration A according to (pace. Sukh., Temp. Wolf., Real moisture.)
VOID Setp (Long P);// Set the pressure (in Pascal)
VOID setpm (float p);// Set the pressure (in mm. Rt. Art.)
VOID seta (float a);// Install a constant psychromometer
Float geta ();// Get a constant psychrometer
`` `

<a id="EXAMPLE"> </a>
## Example
`` `CPP
#include <psychrometer.h>
PSYCHROMETER PSY;

VOID setup () {
  Serial.Begin (9600);
  
  //psy.setp(99085);// Set the pressure in PA
  Psy.Setpm (745);// Set the pressure in mm.RT.Art.
  
  // Get moisture on (pace. Dry, pace. Wet)
  Serial.println (psy.gethumidity (15.0, 12.5));
  
  // Calibration of a permanent device
  //psy.calibrate(15.0, 12.5, 30);// (pace. Sukh., Temp. Wum., Real moist.)
  // Get new and you can from psy.geta ()
  //psy.seta(0.0007947);// Install a permanent device (by default 0007947)
}

vOID loop () {
}
`` `

<a id="versions"> </a>
## versions
- V1.0

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code