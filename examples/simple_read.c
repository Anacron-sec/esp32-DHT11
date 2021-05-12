/* Simple Read Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_log.h"
#include "dht11.h"


#define TAG "APP_MAIN"

static struct dht11_reading stDht11Reading;

void dht11_test(void *pvParameters)
{
  DHT11_init(GPIO_NUM_4);

  while(1)
  {
    stDht11Reading = DHT11_read();
    if(DHT11_OK == stDht11Reading.status)
    {
      ESP_LOGI(TAG,
               "Temperature: %d °C\tHumidity: %d %%",
               stDht11Reading.temperature,
               stDht11Reading.humidity);
    } 
    else
    {
      ESP_LOGW(TAG,
               "Cannot read from sensor: %s",
               (DHT11_TIMEOUT_ERROR == stDht11Reading.status)
               ?"Timeout"
               :"Bad CRC");
    }
    vTaskDelay(2500 / portTICK_PERIOD_MS);
  }
}

void app_main(void)
{
  xTaskCreate(dht11_test, "dht11_test", configMINIMAL_STACK_SIZE * 3, NULL, 5, NULL);
}