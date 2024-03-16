<?php
require('connect.php');

// Check if the request method is GET
if ($_SERVER["REQUEST_METHOD"] == "GET") {
    // Retrieve IP and MAC address from the GET request sent by ESP
    $ipAddress = $_GET['ip'];
    $macAddress = $_GET['mac'];

    // Search for the IP and MAC address in the database
    $sql = "SELECT status FROM ESP_LED WHERE IP='$ip' AND MAC='$mac'";
    $result = $db->query($sql);

    if ($result->num_rows > 0) {
        // If IP and MAC address found in the database
        $row = $result->fetch_assoc();
        $status = $row['status'];
        
        // If status is 1, send "ON" to ESP
        if ($status == 1) {
            echo "ON";
        } else {
            // If status is 0, send "OFF" to ESP
            echo "OFF";
        }
    } else {
        // If IP and MAC address not found in the database
        echo "Can't find this IP and MAC addresses";
    }
} else {
    // If there is an error in the request method
    echo "Something went wrong";
}

$db->close();
?>
