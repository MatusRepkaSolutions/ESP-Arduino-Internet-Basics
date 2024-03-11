<?php
// insert data From GET request into variables
$ipAddress = $_GET['ip']; 
$macAddress = $_GET['mac'];

/*this is a connection between your site and your database. 
If you dont know how this works, visit our github - SQL basics - for easy tutorial*/
require('connect.php');

// checking if there is already this MAC address in the database
$sql = "SELECT * FROM ESP WHERE MAC='$macAddress'";
$result = $db->query($sql);

if ($result->num_rows > 0) {
    //If it found this MAC adress in the database > just update the IP address to the current one
    $sql = "UPDATE ESP SET IP='$ipAddress' WHERE MAC='$macAddress'";
    
    if ($db->query($sql) === TRUE) {
        //giving ESP a response about what happend
        echo "An IP address was updated for this MAC address";
    } else {
        //if there was an error, this gives you back the error code in your Serial Monitor
        echo "Error updating record: " . $db->error;
    }
} else {
    /*In this case, the MAC address was not found, so a new row in a database 
    will be created with current MAC and IP addresses*/
    $sql = "INSERT INTO ESP (IP, MAC) VALUES ('$ipAddress', '$macAddress')";
    
    if ($db->query($sql) === TRUE) {
        //giving ESP a response about what happend
        echo "Created a new record in the database";
    } else {
        //if there was an error, this gives you back the error code in your Serial Monitor
        echo "Error creating record: " . $db->error;
    }
}

$db->close();
?>
