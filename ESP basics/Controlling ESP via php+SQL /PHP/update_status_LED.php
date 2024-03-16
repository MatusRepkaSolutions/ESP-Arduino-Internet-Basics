<?php
require('connect.php');

// Extracting the request method and determining the action to perform
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST["id"];

    // Determine the action: turn on or turn off
    if ($_POST["action"] === "turn_on") {
        // Update status to 1 (turn on)
        $sql = "UPDATE ESP_LED SET status='1' WHERE id='$id'";
    } elseif ($_POST["action"] === "turn_off") {
        // Update status to 0 (turn off)
        $sql = "UPDATE ESP_LED SET status='0' WHERE id='$id'";
    }

    // Execute the SQL query
    if ($db->query($sql) === TRUE) {
        // If the update is successful, redirect back to the index page
        header("Location: index.php");
        exit();
    } else {
        // If an error occurs, display an error message
        echo "An error occurred with the database connection: " . $db->error;
    }
} else {
    // Redirect to the index page if accessed directly without a proper request
    header("Location: index.php");
    exit();
}

$db->close();
?>
