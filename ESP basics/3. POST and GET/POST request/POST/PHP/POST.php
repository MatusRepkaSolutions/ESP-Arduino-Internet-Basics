<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get message from POST request from ESP
    $message_from_ESP = $_POST['message'];

    if ($message_from_ESP == "Hello_There") {
        echo "General_Kenobi";
    } else {
        // Status is 0 and send a message about it to ESP
        echo "$message_from_ESP";
    }
}
?>
