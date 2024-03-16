# Quick PHP explenations
SO we have 5 different .php pages
- connect.php
- index.php
- LED_status.php
- update_data_LED.php
- update_status_LED.php

## connect.php
This site is already eplained in our tutorial [0. PHP Basics](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/0.%20PHP%20basics/connect.php%20)

## update_data_LED.php
This is a same site we use in the tutorial [4. SQL+ESP](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/4.%20SQL%2BESP).
- This page checks if the ESP is already in the database via its MAC+IP addresses. If it finds it's MAC address but the IP address is different, it will update the IP address to the current one.
- If the MAC+IP address is not found in the database, it will create a new record with the current data.
- The database looks like this:
<p align="center">
  <img src="![image](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/97157458-0f6e-4eaa-8856-6e4b9db0e4cc)">
</p>
<p align="center">Database for this tutorial</p>

- The collums `IP` and `MAC` are used to determine which ESP you want to control
- The collum `status` determines what command shoudl ESP execute.

## LED_status.php
- a simple php code where the site checks what is the current status and sends ESP a reply with value 0 or 1
- ESP then knows, what to do based on the reply from site
- in our case "1" = turn on the LED, "0" = turn off the LED

## index.php
- This site is used to monitor and command the ESP.
- The layout looks like this:
  <p align="center">
  <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/4a81d044-ef35-4124-8afd-1dba24f293b1" alt="boot and reset button">
</p>

<p align="center">A simple layout to control an LED via ESP+website.</p>
- The buttons will redirect you to `update_status_LED.php`, which you wont see, because the code will also brings you right back and you can see the status changed depending on what you pressed.

## update_status_LED.php
- A simple site that works together with `index.php`.
- It will change the status in the database for the ESP you choose.
