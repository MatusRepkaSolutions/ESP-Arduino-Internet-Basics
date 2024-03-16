# Controlling your ESP via PHP+SQL

## How and why?
There are plenty of ways how to controll your ESP over the internet, in this tutorial, I will show you a nice easy way I usually use. 
This method allows you to have a good controll and overview about whats happening with your ESP.

## Principle
- We use the code from previous chapter [4. SQL + ESP](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/4.%20SQL%2BESP), but we add a one more colon the in the SQL database.
- The added collon will be named `status`, where we will be changing it's value between 1 and 0 via HTML site that I will also show in this tutorial
- Then we code the ESP to send GET or POST requests, to ask what value the `status` has, if it's a 1, an LED will light on, if it's a zero, the LED will light off.

# STEPS HOW TO DO IT

