# ESP32-DHT11
Esp-idf driver for DHT11 temperature and humidity sensor

## Install
Use Platformio to install this [link](https://platformio.org/lib/show/5817/ESP32-DHT11)<br/>
or <br/>
Clone this repo inside [esp]/esp-idf/components folder

## How to use
Import dht11.h inside your program, initialize the device with DHT11_init(gpio_num) and then call DHT11_read() whenever you need to read from the DHT11 sensor.<br/>
DHT11_read() returns a struct with temperature and humidity and a status code of the operation for error checking.<br/>

Check the examples folder for more information.

<b>WARNING</b>: DHT11_read() is a blocking function.
