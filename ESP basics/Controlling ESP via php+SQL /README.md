# Controlling your ESP via PHP+SQL

## How and why?
There are plenty of ways how to controll your ESP over the internet, in this tutorial, I will show you a nice easy way I usually use. 
This method allows you to have a good controll and overview about whats happening with your ESP.

For this tutorial we chose a control an LED via website that looks like this:
<p align="center">
  <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/4a81d044-ef35-4124-8afd-1dba24f293b1" alt="boot and reset button">
</p>

<p align="center">A simple layout to control an LED via ESP+website.</p>

## Principle
- We use the code from previous chapter [4. SQL + ESP](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/4.%20SQL%2BESP), but we add a one more colon the in the SQL database.
- The added collon will be named `status`, where we will be changing it's value between 1 and 0 via HTML site that we will also show in this tutorial
- Then we code the ESP to send GET or POST requests, to ask what value the `status` has, if it's a 1, an LED will light on, if it's a zero, the LED will light off.

# How to try this
To try our solution out, you dont need to change anything in the PHP or SQL section besides connect `connect.php` to which you will find a tutorial [0. PHP basics](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/0.%20PHP%20basics/connect.php%20), and some minor changes in the `control_led.ino`.

## Set up `control_led.ino`
This is the only part you have to touch in the whole tutorial:
```cpp
//data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

//path to the website
String HOST_NAME = "your_domain"; //example: "https://github.com"
String PATH_NAME = "path1"; //in our tutorial we use "update_data_LED.php"
String PATH_NAME2 = "path2"; //in our tutorial we use "LED_status.php"

/* Time between each request.
This determines the response time of your ESP to any change on the website,
in this example we go for 250ms, but you can go lower, becareful though, not to DDOS your website. */
unsigned long lastTime = 0;
unsigned long timerDelay = 250;
```
- The `ssid` and `passowrd` need no explenation.
- `HOST_NAME` is the domain you are using.
- `PATH_NAME` is the path to a site that will register/update your ESP in the database, in our tutorial we use the path `update_data_LED.php`
- `PATH_NAME2` is the path to a site where ESP is asking for the status of the LED, in this tutorial we use the path `LED_status.php`
- lastly `lastTime` and `timerDelay` determine how often will your ESP ask the the status, in this case we are asking every 250ms

If you wonder how any of the PHP sites works, visit [`README`](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/Controlling%20ESP%20via%20php%2BSQL%20/PHP) in the PHP section of this tutorial.

