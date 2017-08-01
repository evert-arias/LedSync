# NeoPixel Object Methods

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)



### Set color

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

```c++
// Set the pixel color using a predefined value.
myPixel.setColor(PixelColor.blue());
```



### Set brightness

The ```setBrightness()```  method allows you to set the brightness of the pixel. The ```brightnessValue``` could be any number from **0** to **255** where **255** is full brightness.

```c++
// Set the pixel brightness.
myPixel.setBrightness(brightnessValue);
```



### Blink

You may call the **Blink** function everywhere in the sketch. 

```c++
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



### On

Turn ON the NeoPixel.

```` c++
/* Turn ON
 * color: 		(optional) A Color object.
 * brightness: 	(optional) A value from 0 to 255.
 */
myPixel.on(color, brightness);
````



### Off

Turn OFF the NeoPixel .

```` c++
// Turn OFF
myPixel.off();
````



### onUntil

Turn ON the NeoPixel for a time then call a callback function.

```` c++
/* onUntil
 * color:       (optional) A Color object.
 * brightness: 	(optional) A value from 0 to 255.
 * onDuration: 	The time that the pixel will stay ON.
 * callback: 	The function to call when finished.
 */
myPixel.onUntil(color, brightness, onDuration, callback);
````



### offUntil

Turn OFF the NeoPixel for a time then call a callback function.

```` c++
/* offUntil
 * offDuration: The time that the pixel will stay OFF.
 * callback: 	The function to call when finished.
 */
myPixel.offUntil(offDuration, callback);
````





[MIT](https://github.com/ariascode/MyBlinker/blob/master/LICENSE.md) © [Evert Arias](https://ariascode.com)