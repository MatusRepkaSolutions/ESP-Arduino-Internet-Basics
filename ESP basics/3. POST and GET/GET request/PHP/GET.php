<?php
//Made by MatusRepkaSolutions - ESP-Arduino-Internet-Basics
//This php is made as simple as possible just to showcase this basic type of communication between ESP and website
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    // Get message from GET request from ESP
    $message_from_ESP = $_GET['message']; //write the GET request under variable $message_from_ESP

    if ($message_from_ESP == "Hello_There") {
        //A surprising message, but a welcomed one
       echo "General_Kenobi";
    } else {
        //A message was something else
        echo "Response";
    }
}
?>
