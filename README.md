# EasyBlink Arduino Library

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

## Introduction

This library allows you to perform multiple blinking operations with LEDs and NeoPixels. 



## Dependencies

This library has two dependencies:

* [Adafruit_NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel) created by [Adafruit Industries](https://github.com/adafruit)
* [LinkedList](https://github.com/ivanseidel/LinkedList) created by [ivanseidel](https://github.com/ivanseidel)

You must have them installed in your environment in order for it to compile.



## Usage

### Create an instance of the EasyBlink class

You must first create an instance of the class **EasyBlink**. This is the main class of the library and it is in charge of wrapping the **LEDs** and **NeoPixels** together. **EasyBlink** class can take one mandatory parameter as argument, the pin number where the first **NeoPixel** of the strip is connected.

``` c++
// EasyBlink Object
EasyBlink easyBlink(NeoPixelPin);
```



### Create a pixel instance

This object represents **Pixel** itself with all its methods and properties. The order in which these objects are created must match their position in the **NeoPixelStrip**. The constructor of the **Pixel** class does not take any parameters as arguments.

``` c++
// Pixel Object
Pixel myPixel;
```



### Add the pixel to EasyBlink

``` c++
void setup(){
  easyblink.addPixel(&myPixel);
}
```



### Set the pixel color

The ``` setColor()``` method allow you to set the color of the Pixel. 

```c++
// Set the pixel color using a string with the HEX color code.
myPixel.setColor(String);
// Set the pixel color using the HEX color code.
myPixel.setColor(HEX);
// Set the pixel color using a custom color object.
Color customColor(R, G, B);
myPixel.setColor(customColor);
```

There is also a **PixelColor** object included, which allows you to set the color of the pixel using predefined values. The following predefined colors are included: **red, green, blue, white, fuchsia, aqua, yellow**.

``` c++
// Set the pixel color using a predefined value.
myPixel.setColor(PixelColor.blue());
```



### Set the pixel brightness

The ```setBrightness()```  method allows you to set the brightness of the pixel. The ```brightnessValue``` could be any number from **0** to **255** where **255** is full brightness.

````` c++
// Set the pixel brightness.
myPixel.setBrightness(brightnessValue);
`````



### Blink 

You may call the **Blink** function everywhere in the sketch. 

``` c++
/* 
 * onDuration: 		The time that the pixel will stay ON in the cycle.
 * offDuration: 	The time that the pixel will stay OFF in the cycle.
 * cycles: 			The number times to repeat the ON/OFF cycle.
 * pauseDuration: 	The time that the pixel will be OFF between sequences.
 * sequences: 		The number of times to repeat the sequences.
 * callback: 		The function to call when finished.
 */
myPixel.blink(onDuration, offDuration, cycles, pauseDuration, sequences, callback);
```



### Other methods

Extra methods for different operations with the pixel.

```` c++
/* Turn ON
 * color: 		(optional) A Color object.
 * brightness: 	(optional) A value from 0 to 255.
 */
myPixel.on(color, brightness);

// Turn OFF
myPixel.off();

/* Turn ON for a time then call a callback function.
 * color:       (optional) A Color object.
 * brightness: 	(optional) A value from 0 to 255.
 * onDuration: 	The time that the pixel will stay ON.
 * callback: 	The function to call when finished.
 */
myPixel.onUntil(color, brightness, onDuration, callback);

/* Turn OFF for a time then call a callback function.
 * offDuration: The time that the pixel will stay OFF.
 * callback: 	The function to call when finished.
 */
myPixel.offUntil(offDuration, callback);
````



## Copyright

[MIT](https://github.com/ariascode/MyBlinker/blob/master/LICENSE.md) © [Evert Arias](https://ariascode.com)



