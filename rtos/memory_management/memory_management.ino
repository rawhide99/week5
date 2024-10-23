#include <Arduino_FreeRTOS.h>
#include <task.h>

#define NUM_TASKS 3
#define BUF_SIZE 10

void memoryTask(void *pvParam); // Function prototype

void setup() 
{
  Serial.begin(9600);
  for(int i = 0; i < NUM_TASKS; i++)
  {
    if (xTaskCreate(memoryTask, "allocate_memory", 1000, (void*)i, 2, NULL) != pdPASS) 
    {
      Serial.println("Task creation failed!");
    }
  }
  vTaskStartScheduler();
}

void loop() 
{
    // Empty loop
}

void memoryTask(void *pvParam)
{
  int taskId = (int)pvParam;
  while(true)
  {
    Serial.print("Task ");
    Serial.print(taskId);
    Serial.println(" is running.");
    
    char *buffer = (char*) pvPortMalloc(BUF_SIZE);
    if(buffer != NULL)
    {
      snprintf(buffer, BUF_SIZE, "Task %d", taskId);
      Serial.println(buffer);
      vPortFree(buffer);
    }
    else
    {
      Serial.print("Task ");
      Serial.print(taskId);
      Serial.println(": Memory allocation failed!");
    }
    vTaskDelay(pdMS_TO_TICKS(1000 + (taskId * 500)));
  }
}
