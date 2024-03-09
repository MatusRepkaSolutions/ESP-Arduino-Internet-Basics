# Sending and recieving POST/GET requests with your ESP

POST and GET are crucial steps to master when you want to connect your ESP to a website. In this tutorial we will go trough the basics of how to set this up.

## Difference between POST and GET
Since there is plenty of tutorials and materials about PHP on the internet, I won't be teaching you everything, you can learn more about these request and many more on sites like [this](https://www.w3schools.com/tags/ref_httpmethods.asp).
But I should mention to everyone reading this who lacks the deeper knowledge about PHP that POST is overally much more safer option then GET, but GET could give you way more easier time when programing, if the data you are sending is not personal or can not be misused by anyone, it is completly okay to use GET.

## What you need
In this tutorial we will you the `HTTPClient.h` library, which is already installed on your computer if you followed the [steps](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/1.How%20to%20program%20ESP) in the [1. How to program ESP](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/1.How%20to%20program%20ESP).
You can find more about this library on this [link](https://github.com/espressif/arduino-esp32/tree/master/libraries/HTTPClient).
