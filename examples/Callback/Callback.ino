/*
 * Copyright (c) 2017, Evert Arias
 * All rights reserved.
 */

#include <LedSync.h>

// Led Instance
Led myLed(4);

void onFinished(){
  Serial.println("Done!");
}

void setup() {
  Serial.begin(9600);
  // Add the Led to LedSync
  LedSync.add(&myLed);
  // Start blinking
  myLed.blink(100, 200, 5, 500, 10, onFinished);
}

void loop() {
  LedSync.update();
}

