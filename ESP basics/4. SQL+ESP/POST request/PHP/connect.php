<?php  
//you have to fill this out
$dbHost     = "localhost";  
$dbUsername = "your_db_Login_username";  
$dbPassword = "your_db_login_password"; 
$dbName     = "your_db_name";  
  
/* Create a $db variable you can then use in any code on your website once you include it.
If you are unsure how this works, visit our repository - 0. PHP basics - for easy tutorials*/
$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);  
  
// If there was an error in the connection, this will let you know
if ($db->connect_error) {  
    die("Error: " . $db->connect_error);  
}
