#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <semphr.h>

#define BUF_SIZE 7
int buffer[BUF_SIZE];
int out = 0;
int in = 0;

//Declaring Semaphore Handles
SemaphoreHandle_t slot_empty;
SemaphoreHandle_t slot_full;

void setup() 
{
  Serial.begin(19200);
  slot_empty = xSemaphoreCreateCounting(BUF_SIZE, BUF_SIZE);
  slot_full = xSemaphoreCreateCounting(BUF_SIZE, 0);

  xTaskCreate(prodTask, "Producer", 128, NULL, 2, NULL);
  xTaskCreate(consTask, "Consumer", 128, NULL, 1, NULL); // Given higher priority to ensure that buffer does not overflow.
}

void loop() 
{
  // put your main code here, to run repeatedly:
}

void prodTask(void *pvParam)
{
  (void) pvParam;
  for(;;)
  {
    int item = random(0, 100);
    Serial.println("Producing: ");
    Serial.println(item);

    xSemaphoreTake(slot_empty, portMAX_DELAY);
    buffer[in] = item;
    in = (in + 1) % BUF_SIZE;

    xSemaphoreGive(slot_full);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

  }
}

void consTask(void *pvParam)
{
  (void) pvParam;
  for(;;)
  {
    xSemaphoreTake(slot_full, portMAX_DELAY);

    int item = buffer[out];
    out = (out + 1) % BUF_SIZE;
    Serial.print("Consuming: ");
    Serial.println(item);

    xSemaphoreGive(slot_empty);
    vTaskDelay(1500 / portTICK_PERIOD_MS);
  }
}

