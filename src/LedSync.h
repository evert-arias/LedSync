#ifndef LEDSYNC_H
#define LEDSYNC_H

#include "Config.h"
#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>

class Led {
  private:
    byte mPin;
    uint8_t mPolarity = COMMON_NEGATIVE;
    byte mBlinks;
    unsigned int mOnDuration;
    unsigned int mOffDuration;
    unsigned int mPauseDuration;
    unsigned int mSequences;
    unsigned long mStartTime;
    unsigned long mLastRunTime;
    void (*mFinishedCallbackFunction)();
  public:
    Led(byte const pin);
    Led(byte const pin, uint8_t polarity);
    void setPin(byte const pin);
    void setPolarity(uint8_t polarity);
    void blink(unsigned int const onDuration, unsigned int const offDuration, byte const blinks, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)());
    void on();
    void off();
    void onUntil(unsigned int const onDuration, void (*finishedCallbackFunction)());
    void offUntil(unsigned int const offDuration, void (*finishedCallbackFunction)());
    void update();
};

class Color {
  private:
    int my_r;
    int my_g;
    int my_b;
  public:
    Color (int red, int green, int blue);
    Color ();
    Color (String hexstring);
    Color (unsigned long hex);
    void r(int value);
    void g(int value);
    void b(int value);
    int r();
    int g();
    int b();
    Color red();
    Color green();
    Color blue();
    Color white();
    Color fuchsia();
    Color aqua();
    Color yellow();
    Color custom(int red, int green, int blue);
    uint32_t getPackedGRB();
    uint32_t getPackedRGB();

}; extern Color PixelColor;

class NeoPixel {
  private:
    byte mId = 0;
    Color mColor = Color(DEFAULT_PIXEL_COLOR);
    byte mBrightness = DEFAULT_PIXEL_BRIGHTNESS;
    byte mBlinks;
    neoPixelType mNeoPixelType = NEO_GRB + NEO_KHZ800;
    unsigned int mOnDuration;
    unsigned int mOffDuration;
    unsigned int mPauseDuration;
    unsigned int mSequences;
    unsigned long mStartTime = 0;
    unsigned long mLastRunTime;
    void (*mFinishedCallbackFunction)();
  public:
    NeoPixel();
    byte getId();
    void setId(byte id);
    void on();
    void on(const Color& color);
    void on(const Color& color, const byte brightness);
    void off();
    void onUntil(unsigned int const onDuration, void (*finishedCallbackFunction)());
    void onUntil(const Color& color, unsigned int const onDuration, void (*finishedCallbackFunction)());
    void onUntil(const Color& color, const byte brightness, unsigned int const onDuration, void (*finishedCallbackFunction)());
    void offUntil(unsigned int const offDuration, void (*finishedCallbackFunction)());
    void setColor(String hexstring);
    void setColor(unsigned long hex);
    void setColor(Color color);
    void setBrightness(const uint8_t brightness);
    void blink(unsigned int const onDuration, unsigned int const offDuration, byte const blinks, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)());
    void update(Adafruit_NeoPixel *_NeoPixel, byte _pin);
};

class LedSyncClass {
  private:
    byte mPin;
    byte mNumPixels = 0;
    byte mNumLeds = 0;
    neoPixelType mNeoPixelType = NEO_GRB + NEO_KHZ800;
    Adafruit_NeoPixel mNeoPixel = Adafruit_NeoPixel();
    LinkedList<NeoPixel*> mPixelsList = LinkedList<NeoPixel*>();
    LinkedList<Led*> mLedsList = LinkedList<Led*>();
  public:
    LedSyncClass();
    LedSyncClass(byte neoPixelPin);
    LedSyncClass(byte neoPixelPin, neoPixelType _neoPixelType);
    void setNeoPixelPin(byte _pin);
    void setNeoPixelType(neoPixelType _neoPixelType);
    void add(NeoPixel *pixel);
    void add(Led *led);
    void update();
}; extern LedSyncClass LedSync;

#endif
