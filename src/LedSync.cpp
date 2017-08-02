#include "LedSync.h"

Led::Led(byte const pin): mPin(pin), mStartTime(0){
  mPolarity = COMMON_NEGATIVE;
  pinMode(pin, OUTPUT);
  if(mPolarity == COMMON_NEGATIVE){
    digitalWrite(pin, LOW);
  } else if(mPolarity == COMMON_POSITIVE){
    digitalWrite(pin, HIGH);
  };
};
Led::Led(byte const pin, uint8_t polarity): mPin(pin), mPolarity(polarity), mStartTime(0){
  pinMode(pin, OUTPUT);
  if(mPolarity == COMMON_NEGATIVE){
    digitalWrite(pin, LOW);
  } else if(mPolarity == COMMON_POSITIVE){
    digitalWrite(pin, HIGH);
  };
};
void Led::setPin(byte const pin){
  mPin = pin;
  pinMode(pin, OUTPUT);
  if(mPolarity == COMMON_NEGATIVE){
    digitalWrite(pin, LOW);
  } else if(mPolarity == COMMON_POSITIVE){
    digitalWrite(pin, HIGH);
  };
  mStartTime = 0;
};
void Led::setPolarity(uint8_t polarity){
  mPolarity = polarity;
  if(mPolarity == COMMON_NEGATIVE){
    digitalWrite(mPin, LOW);
  } else if(mPolarity == COMMON_POSITIVE){
    digitalWrite(mPin, HIGH);
  };
};
void Led::blink(unsigned int const onDuration, unsigned int const offDuration, byte const blinks, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)()){
  mOnDuration = onDuration ? max(MINIMUM_INTERVAL, onDuration) : 0;
  mOffDuration = offDuration ? max(MINIMUM_INTERVAL, offDuration) : 0;
  mBlinks = blinks;
  mPauseDuration = pauseDuration ? max(MINIMUM_INTERVAL, pauseDuration) : 0;;
  mSequences = sequences;
  mFinishedCallbackFunction = finishedCallbackFunction;
  mStartTime = max(millis(), 1);
  mLastRunTime = 0;
  update();
};
void Led::on(){
  blink(1, 0, 1, 0, 0, NULL);
};
void Led::off(){
  blink(0, 0, 0, 1, 0, NULL);
};
void Led::onUntil(unsigned int const onDuration, void (*finishedCallbackFunction)()){
  blink(onDuration, 0, 1, 0, 1, finishedCallbackFunction);
};
void Led::offUntil(unsigned int const offDuration, void (*finishedCallbackFunction)()){
  blink(0, 0, 0, offDuration, 1, finishedCallbackFunction);
};
void Led::update(){
  unsigned long currentTime = millis();
  if (currentTime - mLastRunTime < MINIMUM_INTERVAL) {
    return;
  }
  mLastRunTime = currentTime;
  if (!mStartTime || !mPin) {
    return;
  }

  unsigned long elapsedTime = currentTime - mStartTime;
  unsigned int blinkDuration = mOnDuration + mOffDuration;
  unsigned int sequenceDuration = blinkDuration * mBlinks + mPauseDuration - mOffDuration;

  if (!sequenceDuration || (mSequences != 0 && elapsedTime / sequenceDuration >= mSequences)) {
    mStartTime = 0;
    if (mFinishedCallbackFunction) {
      mFinishedCallbackFunction();
    }
    return;
  };

  unsigned int blinkingDuration = blinkDuration * mBlinks;
  unsigned int timeInSequence = elapsedTime % sequenceDuration;
  if (timeInSequence < blinkingDuration && timeInSequence % blinkDuration < mOnDuration) {
    if(mPolarity == COMMON_NEGATIVE){
      digitalWrite(mPin, HIGH);
    } else if (mPolarity == COMMON_POSITIVE){
      digitalWrite(mPin, LOW);
    }
  } else {
    if(mPolarity == COMMON_NEGATIVE){
      digitalWrite(mPin, LOW);
    } else if(mPolarity == COMMON_POSITIVE){
      digitalWrite(mPin, HIGH);
    };
  };
};

Color::Color(int red, int green, int blue): my_r(red),my_g(green),my_b(blue){};
Color::Color(): my_r(0),my_g(0),my_b(255){};
Color::Color(String hexstring): my_r((int) strtol( &hexstring[1], NULL, 16) >> 16), my_g((int) strtol( &hexstring[1], NULL, 16) >> 8 & 0xFF), my_b((int) strtol( &hexstring[1], NULL, 16) & 0xFF){};
Color::Color(unsigned long hex):my_r((hex & 0xff0000) >> 16), my_g((hex & 0x00ff00) >> 8), my_b((hex & 0x0000ff)){};
void Color::r(int value){
  my_r = value;
};
void Color::g(int value){
  my_g = value;
};
void Color::b(int value){
  my_b = value;
};
int Color::r(){return my_r;}
int Color::g(){return my_g;}
int Color::b(){return my_b;}
Color Color::red(){
  return Color(255,0,0);
};
Color Color::green(){
  return Color(0,255,0);
};
Color Color::blue(){
  return Color(0,0,255);
};
Color Color::white(){
  return Color(255,255,255);
};
Color Color::fuchsia(){
  return Color(255,0,255);
};
Color Color::aqua(){
  return Color(0,255,255);
};
Color Color::yellow(){
  return Color(255,255,0);
};
Color Color::custom(int red, int green, int blue){
  return Color(red, green, blue);
};
uint32_t Color::getPackedGRB(){
  return ((uint32_t)my_r << 16) | ((uint32_t)my_g <<  8) | my_b;
};
uint32_t Color::getPackedRGB(){
  return ((uint32_t)my_g << 16) | ((uint32_t)my_r <<  8) | my_b;
};
Color PixelColor;

NeoPixel::NeoPixel(){
  off();
};
byte NeoPixel::getId(){
  return mId;
};
void NeoPixel::setId(byte id){
  mId = id;
};
void NeoPixel::on(){
  blink(1, 0, 1, 0, 0, NULL);
};
void NeoPixel::on(const Color& color){
  mColor = color;
  blink(1, 0, 1, 0, 0, NULL);
};
void NeoPixel::on(const Color& color, const byte brightness){
  mColor = color;
  mBrightness = brightness;
  blink(1, 0, 1, 0, 0, NULL);
};
void NeoPixel::off(){
  blink(0, 0, 0, 1, 0, NULL);
};
void NeoPixel::onUntil(unsigned int const onDuration, void (*finishedCallbackFunction)()){
  blink(onDuration, 0, 1, 0, 1, finishedCallbackFunction);
};
void NeoPixel::onUntil(const Color& color, unsigned int const onDuration, void (*finishedCallbackFunction)()){
  mColor = color;
  blink(onDuration, 0, 1, 0, 1, finishedCallbackFunction);
};
void NeoPixel::onUntil(const Color& color, const byte brightness, unsigned int const onDuration, void (*finishedCallbackFunction)()){
  mColor = color;
  mBrightness = brightness;
  blink(onDuration, 0, 1, 0, 1, finishedCallbackFunction);
};
void NeoPixel::offUntil(unsigned int const offDuration, void (*finishedCallbackFunction)()){
  blink(0, 0, 0, offDuration, 1, finishedCallbackFunction);
};
void NeoPixel::setColor(String hexstring){
  mColor = Color(hexstring);
};
void NeoPixel::setColor(unsigned long hex){
  mColor = Color(hex);
};
void NeoPixel::setColor(Color color){
  mColor = color;
};
void NeoPixel::setBrightness(const uint8_t brightness){
  mBrightness = brightness;
};
void NeoPixel::blink(unsigned int const onDuration, unsigned int const offDuration, byte const blinks, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)()){
  mOnDuration = onDuration ? max(MINIMUM_INTERVAL, onDuration) : 0;
  mOffDuration = offDuration ? max(MINIMUM_INTERVAL, offDuration) : 0;
  mBlinks = blinks;
  mPauseDuration = pauseDuration ? max(MINIMUM_INTERVAL, pauseDuration) : 0;;
  mSequences = sequences;
  mFinishedCallbackFunction = finishedCallbackFunction;
  mStartTime = max(millis(), 1);
  mLastRunTime = 0;
};
void NeoPixel::update(Adafruit_NeoPixel *_NeoPixel, byte _pin){
  unsigned long currentTime = millis();
  if (currentTime - mLastRunTime < MINIMUM_INTERVAL) {
    return;
  }
  mLastRunTime = currentTime;
  if (!mStartTime || !_pin) {
    return;
  }

  unsigned long elapsedTime = currentTime - mStartTime;
  unsigned int blinkDuration = mOnDuration + mOffDuration;
  unsigned int sequenceDuration = blinkDuration * mBlinks + mPauseDuration - mOffDuration;

  if (!sequenceDuration || (mSequences != 0 && elapsedTime / sequenceDuration >= mSequences)) {
    mStartTime = 0;
    if (mFinishedCallbackFunction) {
      mFinishedCallbackFunction();
    }
    return;
  }

  unsigned int blinkingDuration = blinkDuration * mBlinks;
  unsigned int timeInSequence = elapsedTime % sequenceDuration;
  if (timeInSequence < blinkingDuration && timeInSequence % blinkDuration < mOnDuration) {
    _NeoPixel->setPixelColor(mId, mColor.getPackedRGB());
    _NeoPixel->setBrightness(mBrightness);
    _NeoPixel->show();
  } else {
    _NeoPixel->setPixelColor(mId, _NeoPixel->Color(0, 0, 0));
    _NeoPixel->show();
  }
};

LedSyncClass::LedSyncClass():mPin(DEFAULT_NEOPIXEL_PIN), mNumPixels(0){
  mNeoPixel.setPin(mPin);
  mNeoPixel.updateType(mNeoPixelType);
};
LedSyncClass::LedSyncClass(byte neoPixelPin):mPin(neoPixelPin), mNumPixels(0){
  mNeoPixel.setPin(mPin);
  mNeoPixel.updateType(mNeoPixelType);
};
LedSyncClass::LedSyncClass(byte neoPixelPin, neoPixelType _neoPixelType):mPin(neoPixelPin), mNumPixels(0), mNeoPixelType(_neoPixelType){
  mNeoPixel.setPin(mPin);
  mNeoPixel.updateType(mNeoPixelType);
};
void LedSyncClass::setNeoPixelPin(byte _pin){
  mNeoPixel.setPin( _pin);
};
void LedSyncClass::setNeoPixelType(byte _neoPixelType){
  mNeoPixel.updateType(_neoPixelType);
};
void LedSyncClass::add(NeoPixel *pixel){
  pixel->setId(mNumPixels);
  mPixelsList.add(pixel);
  mNumPixels++;
  mNeoPixel.updateLength(mNumPixels);
  mNeoPixel.begin();
};
void LedSyncClass::add(Led *led){
  mLedsList.add(led);
  mNumLeds++;
};
void LedSyncClass::update(){
  for (size_t i = 0; i < mNumPixels; i++) {
    mPixelsList.get(i)->update(&mNeoPixel, mPin);
  };
  for (size_t i = 0; i < mNumLeds; i++) {
    mLedsList.get(i)->update();
  };
  delay(20);
}; LedSyncClass LedSync;
