#include <avr/io.h>
#include <util/delay.h>

volatile int count = 4; // Countdown value (4 seconds)
volatile bool counting = false;

#define LED_PIN 7
#define BUTTON_PIN 2

void setup() 
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH); // Set LED to ON
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin

    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B = (1 << WGM12); // Set CTC mode
    OCR1A = 62499;
    TCCR1B |= (1 << CS12); // Prescaler to 256
}

void loop() 
{
  if (digitalRead(BUTTON_PIN) == HIGH && !counting) 
  {
    counting = true;
    count = 4;
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Timer started, counting down from 4 seconds");
    delay(200);
  }

  if (counting) 
  {
    while (!(TIFR1 & (1 << OCF1A)));
    TIFR1 |= (1 << OCF1A);

    if (count > 0) 
    {
      Serial.print("Counting down: ");
      Serial.println(count);
      count--;
    }
    else 
    {
      digitalWrite(LED_PIN, LOW);
      counting = false;
      Serial.println("Counting finished, LED turned OFF");
    }
  }
}
