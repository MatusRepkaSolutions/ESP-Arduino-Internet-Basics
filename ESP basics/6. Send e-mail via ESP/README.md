# Sending an e-mail via ESP
Before I start this tutorial I want to give a huge thanks to [PHPMailer](https://github.com/PHPMailer/PHPMailer), 
for making a free for use and safe solution to send e-mails via PHP. Follow their repository for more info!

## How does this method works
There are couple of methods how to send e-mails from your ESP, in this one we:
- Program an ESP to send data to a .php webpage (emails addresses you want to send the email to, or text you want to include in your email or anything inside of an e-mail).
- We set up an .php webpage to process this sent data and send an e-mail based on them.

## Security
Since we are sending an e-mails, we need to use more secure method of requests. For this we are strictly using POST requsts only. If you are unsure how this requests work, visit our tutorial [3. POST and GET](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/3.%20POST%20and%20GET)

## Start of a tutorial
We structured this tutorial for you to understand the basics how to send an e-mail from your ESP. For this we chose to make a code, which after pressing a button will send an e-mail.
### In the `email.ino` you need to:
- Change your WiFi and website paths:
```cpp
//data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

//path to the website
String HOST_NAME = "your_domain"; //example: "https://github.com"
String PATH_NAME = "path1"; //in our tutorial we use "send.php"
```
- Change the e-mail recipment
```cpp
String postData = "MAIL=example@mail.com";
```
### For `send.php` to work you need:
1. Download the scr folder from [PHPMailer](https://github.com/PHPMailer/PHPMailer), it is also included in our repository [here](https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/tree/main/ESP%20basics/6.%20Send%20e-mail%20via%20ESP/PHPMailer).
   - The whole `scr` folder needs to be uploaded in the files of your website
2.
