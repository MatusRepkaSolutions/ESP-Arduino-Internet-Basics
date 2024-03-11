# Sending data from ESP to SQL

## Why
Working with SQL is crucial if you want to have a proper control over your microcontrollers, especially
if you work with more then one microcontroller.

In this case we show you how to insert or update your ESP's IP address based on it's MAC address.

## MAC vs IP address
- Your IP address can change or you can have more microcontrollers connected the the same IP address.
  - This might create a lot of troubles, as you would not have any controll over which microtroller you are sending your commands to.
- This is easly fixed by also using your microcontrollers MAC addres as these adresses are never changing and are original for each microcontroller.

## How it works
- In our solution, your microcontroller will send it's IP and MAC address to the website, your PHP code will find, if the MAC adrress you sent it is already in the database.
  - If it's in the database, it will update it's IP adress to the current one
  - If it's not in the database, it will create a new record with current data 
