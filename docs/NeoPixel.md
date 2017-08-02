# NeoPixel Class

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)



### Set color

[Color Class](/docs/Color.md)

The ``` setColor()``` method allow you to set the color of the NeoPixel. If you don't set the color, green will be selected by default.

```c++
// Set the pixel color using a string with the HEX color code.
myPixel.setColor(String);
// Set the pixel color using the HEX color code.
myPixel.setColor(HEX);
// Set the pixel color using a custom color object.
Color customColor(R, G, B);
myPixel.setColor(customColor);
```

There is also a PixelColor object included, which allows you to set the color of the NeoPixel using predefined values. The following predefined colors are included: **red, green, blue, white, fuchsia, aqua, yellow**.

```c++
// Set the pixel color using a predefined value.
myPixel.setColor(PixelColor.blue());
```



### Set brightness

The ```setBrightness()```  method allows you to set the brightness of the pixel. The ```brightnessValue``` could be any number from **0** to **255** where **255** is full brightness. If you don't set the brightness, **127** which is half of full brightness, will be selected by default.

```c++
// Set the pixel brightness.
myPixel.setBrightness(brightnessValue);
```



### Blink

You may call the **Blink** function everywhere in the sketch. 

```c++
myPixel.blink(onDuration, offDuration, cycles, pauseDuration, sequences, callback);
```



### On

Turn ON the NeoPixel.

```` c++
myPixel.on(color, brightness);
````



### Off

Turn OFF the NeoPixel .

```` c++
myPixel.off();
````



### onUntil

Turn ON the NeoPixel for a time then call a callback function.

```` c++
myPixel.onUntil(color, brightness, onDuration, callback);
````



### offUntil

Turn OFF the NeoPixel for a time then call a callback function.

```` c++
myPixel.offUntil(offDuration, callback);
````



### getId

Get the Id of the NeoPixel within the NeoPixelStrip.  It returns a byte data type with with the Id.

```` c++
myPixel.getId();
````



### setId

Set the NeoPixel Id within the NeoPixelStrip. 

```` c++
myPixel.setId();
````





## Copyright

[[MIT](../LICENSE.md) © [Evert Arias](https://ariascode.com)]