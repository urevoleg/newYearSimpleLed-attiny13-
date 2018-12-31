#include <avr/delay.h>


byte led = 0;           // the PWM pin the LED is attached to
byte brightness = 0;    // how bright the LED is
byte fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  //************* EFFECT 1 (slow fade) *********************************
  unsigned long start1 = millis();
  while (millis() - start1 <= 15000) {
    // set the brightness of pin 9:
    analogWrite(led, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    _delay_ms(30);
  }

  // ****************** EFFECT 2 (var strobe) *************************
  start1 = millis();
  int delayStrobe = 10;
  while (millis() - start1 <= 10000) {
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
    _delay_ms(10);                       // wait for a second
    digitalWrite(led, HIGH);    // turn the LED off by making the voltage LOW
    delay(delayStrobe);
    delayStrobe += 2;
  }
  start1 = millis();
  while (millis() - start1 <= 10000) {
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
    _delay_ms(10);                       // wait for a second
    digitalWrite(led, HIGH);    // turn the LED off by making the voltage LOW
    delay(delayStrobe);
    delayStrobe -= 2;
  }

  //************* EFFECT 3 (fast fade with stop time) *********************************
  start1 = millis();
  while (millis() - start1 <= 15000) {
    // set the brightness of pin 9:
    analogWrite(led, brightness);

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    if (brightness >= 255) {
      unsigned long start2 = millis();
      while (millis() - start2 < 750) {}
    }
    // wait for 30 milliseconds to see the dimming effect
    _delay_ms(5);
  }

  // ****************** EFFECT 4 (const strobe) *************************
  start1 = millis();
  while (millis() - start1 <= 15000) {
    digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
    _delay_ms(10);                       // wait for a second
    digitalWrite(led, HIGH);    // turn the LED off by making the voltage LOW
    _delay_ms(1000);
  }

}
