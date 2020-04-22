#include <Ethernet.h>

#include <SPI.h>

#include <PubNub.h>


#include "pitches.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
byte mac[] = {0x00, 0x0E, 0xEF, 0x00, 0x00, 0x34};
char channel[] = "iotchannel";
// Digital IO pin connected to the button. This will be driven with a
// pull-up resistor so the switch pulls the pin to ground momentarily.
// On a high -> low transition the button press logic will execute.
#define BUTTON_PIN   2
#define BUTTON2_PIN   3
#define BUTTON3_PIN   4
#define BUTTON4_PIN   24
#define BUTTON5_PIN   26
#define BUTTON6_PIN   28
#define BUTTON7_PIN   30
#define BUTTON8_PIN   32
#define BUTTON9_PIN   34
#define BUTTON10_PIN   36
#define BUTTON11_PIN   38
#define BUTTON12_PIN   40


#define PIXEL_PIN    6  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 12  // Number of NeoPixels

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)


boolean oldState = HIGH;
boolean oldState2 = HIGH;
boolean oldState3 = HIGH;
boolean oldState4 = HIGH;
boolean oldState5 = HIGH;
boolean oldState6 = HIGH;
boolean oldState7 = HIGH;
boolean oldState8 = HIGH;
boolean oldState9 = HIGH;
boolean oldState10 = HIGH;
boolean oldState11 = HIGH;
boolean oldState12 = HIGH;
int     mode     = 0;    // Currently-active animation mode, 0-1

int melody[] = {
  NOTE_DS3
};

int noteDurations[] = {
  1, 
};


void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(BUTTON4_PIN, INPUT_PULLUP);
  pinMode(BUTTON5_PIN, INPUT_PULLUP);
  pinMode(BUTTON6_PIN, INPUT_PULLUP);
  pinMode(BUTTON7_PIN, INPUT_PULLUP);
  pinMode(BUTTON8_PIN, INPUT_PULLUP);
  pinMode(BUTTON9_PIN, INPUT_PULLUP);
  pinMode(BUTTON10_PIN, INPUT_PULLUP);
  pinMode(BUTTON11_PIN, INPUT_PULLUP);
  pinMode(BUTTON12_PIN, INPUT_PULLUP);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'

   for (int thisNote = 0; thisNote < 1; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
   
    int pauseBetweenNotes = noteDuration * 3.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
 Serial.begin(9600);     
    while (!Ethernet.begin(mac)) {
        Serial.println("Ethernet setup error");
        delay(1000);
    }

    PubNub.begin("pub-c-34594ec4-ac63-48c4-b347-ea229241e0a4", "sub-c-3e0fe9a0-6e87-11ea-bbe3-3ec3e5ef3302");

}

void loop() {
  Ethernet.maintain();
    EthernetClient *client;
    
  // Get current button state.
  boolean newState = digitalRead(BUTTON_PIN);

  // Check if state changed from high to low (button press).
  if((newState == LOW) && (oldState == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    if(newState == LOW) {      // Yes, still low

      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(127,   0,   255), 50);    // purple C
          break;
      
      }

        Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button\":\"1270255\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();
    }
    }
  

  // Set the last-read button state to the old state.
  oldState = newState;


boolean newState2 = digitalRead(BUTTON2_PIN);

  // Check if state changed from high to low (button press).
  if((newState2 == LOW) && (oldState2 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState2 = digitalRead(BUTTON2_PIN);
    if(newState2 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(0,   0,   255), 50);    // blue B
          break;
      
      }
       Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button\":\"00255\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }
  

  // Set the last-read button state to the old state.
  oldState2 = newState2;

  boolean newState3 = digitalRead(BUTTON3_PIN);

  // Check if state changed from high to low (button press).
 if((newState3 == LOW) && (oldState3 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState3 = digitalRead(BUTTON3_PIN);
    if(newState3 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after #1
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(0,   127,  255 ), 50);    // light blue B flat
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button3\":\"0127255\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState3 = newState3;


   boolean newState4 = digitalRead(BUTTON4_PIN);

  // Check if state changed from high to low (button press).
  if((newState4 == LOW) && (oldState4 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState4 = digitalRead(BUTTON4_PIN);
    if(newState3 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(0,   255,  255 ), 50);    // aqua A
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button4\":\"0255255\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState4 = newState4;

   boolean newState5 = digitalRead(BUTTON5_PIN);

  // Check if state changed from high to low (button press).
  if((newState5 == LOW) && (oldState5 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState5 = digitalRead(BUTTON5_PIN);
    if(newState3 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(0,   255,  127 ), 50);    // aqua/green A flat
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button5\":\"0255127\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState5 = newState5;

   boolean newState6 = digitalRead(BUTTON6_PIN);

  // Check if state changed from high to low (button press).
  if((newState6 == LOW) && (oldState6 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState6 = digitalRead(BUTTON6_PIN);
    if(newState6 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(0,   255,  0 ), 50);    // green G
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button6\":\"02550\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState6 = newState6;

   boolean newState7 = digitalRead(BUTTON7_PIN);

  // Check if state changed from high to low (button press).
  if((newState7 == LOW) && (oldState7 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState7 = digitalRead(BUTTON7_PIN);
    if(newState7 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(127,   255,  0 ), 50);    // Light green G flat
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button7\":\"1272550\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState7 = newState7;

   boolean newState8 = digitalRead(BUTTON8_PIN);

  // Check if state changed from high to low (button press).
  if((newState8 == LOW) && (oldState8 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState8 = digitalRead(BUTTON8_PIN);
    if(newState8== LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   255,  0 ), 50);    // yellow F
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button8\":\"2552550\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState8 = newState8;

   boolean newState9 = digitalRead(BUTTON9_PIN);

  // Check if state changed from high to low (button press).
  if((newState9 == LOW) && (oldState9 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState9 = digitalRead(BUTTON9_PIN);
    if(newState9 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   127,  0 ), 50);    // orange E
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button9\":\"2551270\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState9 = newState9;

   boolean newState10 = digitalRead(BUTTON10_PIN);

  // Check if state changed from high to low (button press).
  if((newState10 == LOW) && (oldState10 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState10 = digitalRead(BUTTON10_PIN);
    if(newState10 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   0,  0 ), 50);    // Red E flat
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button10\":\"25500\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState10 = newState10;

   boolean newState11 = digitalRead(BUTTON11_PIN);

  // Check if state changed from high to low (button press).
  if((newState11 == LOW) && (oldState11 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState11 = digitalRead(BUTTON11_PIN);
    if(newState11 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   0,  127), 50);    // pink D
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button11\":\"2550127\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState11 = newState11;

   boolean newState12 = digitalRead(BUTTON12_PIN);

  // Check if state changed from high to low (button press).
  if((newState12 == LOW) && (oldState12 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState12 = digitalRead(BUTTON12_PIN);
    if(newState12 == LOW) {      // Yes, still low
      if(++mode > 1) mode = 0; // Advance to next mode, wrap around after 
      switch(mode) {           // Start the new animation...
        case 0:
          colorWipe(strip.Color(  0,   0,   0), 50);    // Black/off
          break;
        case 1:
          colorWipe(strip.Color(255,   0,  255 ), 50);    // Fushia D flat
          break;
      
      }
      Serial.println("publishing a message");
      char msg[] = "{\"eon\":{\"button12\":\"2550255\"}}";
       client = PubNub.publish(channel, msg);
    if (!client) {
        Serial.println("publishing error");
        delay(1000);
        return;
    }
   
    
    while (client->connected()) {
        while (client->connected() && !client->available());
        char c = client->read();
        Serial.print(c);
    }
    client->stop();
    Serial.println();

      
    }
  }

  // Set the last-read button state to the old state.
  oldState12 = newState12;
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
