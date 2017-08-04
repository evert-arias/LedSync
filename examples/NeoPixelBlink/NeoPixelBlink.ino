/*
 * Copyright (c) 2017, Evert Arias
 * All rights reserved.
 */


#include <LedSync.h>

// NeoPixel Instance
NeoPixel myNeoPixel;

void setup() {
  // Add the NeoPixel to LedSync
  LedSync.add(&myNeoPixel);
  // Start blinking
  myNeoPixel.blink(100, 200, 5, 500, 10, NULL);
}

void loop() {
  LedSync.update();
}
