# Sending an e-mail via ESP
Before I start this tutorial I want to give a huge thanks to [PHPMailer](https://github.com/PHPMailer/PHPMailer), 
for making a free for use and safe solution to send e-mails via PHP. Follow their repository for more info!

## How does this method works
There are couple of methods how to send e-mails from your ESP, in this one we:
- Program an ESP to send data to a .php webpage (emails addresses you want to send the email to, or text you want to include in your email or anything inside of an e-mail).
- We set up an .php webpage to process this sent data and send an e-mail based on them.

## Start of a tutorial
We structured this tutorial for you to understand the basics how to send an e-mail from your ESP. For this we chose to make a code, which after pressing a button will send an e-mail.
The code `email.ino` is simple:
