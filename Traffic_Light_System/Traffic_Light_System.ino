#define GREEN_TIME 10000
#define YELLOW_TIME 2000
#define RED_TIME 10000

const int led_green = 2;
const int led_yellow = 7;
const int led_red = 8;

void setup() 
{
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop()
{
  trafficLight();
}

void ledOn(int x)
{
  digitalWrite(x, HIGH);
}

void ledOff(int x)
{
  digitalWrite(x, LOW);
}

void greenLed()
{
  ledOn(led_green);
  delay(GREEN_TIME);
  ledOff(led_green);
}

void yellowLed()
{
  ledOn(led_yellow);
  delay(YELLOW_TIME);
  ledOff(led_yellow);
}

void redLed()
{
  ledOn(led_red);
  delay(RED_TIME);
  ledOff(led_red);
}

void trafficLight()
{
  for(;;)
  {
    greenLed();
    delay(100);
    yellowLed();
    delay(100);
    redLed();
    delay(100);
  }
}