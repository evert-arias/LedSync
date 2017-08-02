# LED Class

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)



### Blink

Blink the LED with required cycles and sequences.

```c++
myLed.blink(onDuration, offDuration, cycles, pauseDuration, sequences, callback);
```



### On

Turn ON the LED.

```c++
myLed.on(color, brightness);
```



### Off

Turn OFF  the LED

```c++
myLed.off();
```



### onUntil

Turn ON the LED for a time then call a callback function.

```c++
myLed.onUntil(onDuration, callback);
```



### offUntil

Turn OFF the LED for a time then call a callback function.

```c++
myLed.offUntil(offDuration, callback);
```



### setPolarity

Set the LED polarity.

```` c++
myLed.setPolarity(COMMON_POSITIVE);
````



### setPin

Set the pin number where the LED is connected.

```` c++
myLed.setPin(pin);
````





## Copyright

[[MIT](../LICENSE.md) © [Evert Arias](https://ariascode.com)]