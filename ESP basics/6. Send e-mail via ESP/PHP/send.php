<?php
// Path to the src files
require 'src/Exception.php'; 
require 'src/PHPMailer.php'; 
require 'src/SMTP.php'; 

use PHPMailer\PHPMailer\PHPMailer; 
use PHPMailer\PHPMailer\Exception; 

// Check if the request method is POST and the MAIL parameter is set
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['MAIL'])) {
    $MAIL = $_POST['MAIL']; // Get the email address from the POST request

    // Create a new instance of PHPMailer
    $mail = new PHPMailer(true);
    try {
        $mail->isSMTP(); // Set mailer to use SMTP
        $mail->SMTPDebug = 0; 
        $mail->Host = 'smtp.gmail.com'; // Set the SMTP server - depends on your SMTP provider
        $mail->Port = 587; // Set the SMTP port - depends on your SMTP provider
        $mail->SMTPSecure = 'tls'; // Set the encryption mechanism
        $mail->SMTPAuth = true; // Enable SMTP authentication
        $mail->Username = 'repkamatut2@gmail.com'; // SMTP username - depends on your SMTP provider (in case of gmail - it's your email)
        $mail->Password = 'xXxXxXxXxXxXxXx'; // SMTP password - depends on your SMTP provider - you need to generate this
        $mail->setFrom('sender_email', 'sender_name'); // Set the sender email and name (the email you want to send this from)
        $mail->addAddress($MAIL, 'reciever_name'); // Set the recipient
        $mail->Subject = 'Subject_text'; // Set the subject
        $mail->isHTML(true); // Set email format to HTML
        $mail->Body = 'Body_text'; // Set the body

        // Send email
        $mail->send();
        http_response_code(200); // Send HTTP response code indicating success
    } catch (Exception $e) {
        http_response_code(500); // Send HTTP response code indicating server error
        echo 'Message could not be sent. Mailer Error: ', $mail->ErrorInfo; // Display error message
    }
}
?>

