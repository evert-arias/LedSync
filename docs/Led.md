# LED Object

[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)



### Blink

Blink the LED with required cycles and sequences.

```c++
// onDuration: 		[required] The time that the pixel will stay ON in the cycle.
// offDuration: 	[required] The time that the pixel will stay OFF in the cycle.
// cycles: 			[required] The number times to repeat the ON/OFF cycle.
// pauseDuration: 	[required] The time that the pixel will be OFF between sequences.
// sequences: 		[required] The number of times to repeat the sequences.
myLed.blink(onDuration, offDuration, cycles, pauseDuration, sequences, callback);
```

### On

Turn ON the LED.

```c++
// color: 		[optional] A Color object.
// brightness: 	[optional] A value from 0 to 255.
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
// onDuration: 	[required] The time that the pixel will stay ON.
// callback: 	[required] The function to call when finished.
myLed.onUntil(onDuration, callback);
```

### offUntil

Turn OFF the LED for a time then call a callback function.

```c++
// offDuration: [required] The time that the pixel will stay OFF.
// callback: 	[required] The function to call when finished.
myLed.offUntil(offDuration, callback);
```



### setPolarity

Set the LED polarity. Allowed values: **COMMON_NEGATIVE**, **COMMON_POSITIVE**.

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