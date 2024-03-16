# Connection to you SQL
If you run a website with more then one page, where you need a connection with your database, using a connect.php is a 
quality of life saving trick. By creating a connect.php you can just include it at the start of your code at anywebsite 
without need of endless copying and creating a connection.

## Creating a connect.php using cloud database
- Take a `connect.php` from this repository.
- First you need to fill out this four rows.
- You usually leave `$dbHost` as `localhost` - expecting your database is on the same server host as your domain. 
```php
  $dbHost     = "localhost";  
  $dbUsername = "your_db_Login_username";  
  $dbPassword = "your_db_login_password"; 
  $dbName     = "your_db_name";  
```
| $dbUsername and $dbPassword                           | $dbName                                       |
| ----------------------------------------------------- | --------------------------------------------- |
| <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/b8724833-6fa3-4f51-8af8-000327d32ef4" alt="Step 1"> | <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/1e44a5f8-945e-4947-b5b5-ed7d8902c32d" alt="Step 2"> |

-In this example the resulting `connect.php` code looks like this:
```php
<?php
//database info
$dbHost     = "localhost";  
$dbUsername = "id21876816_makajos";  
$dbPassword = "Password123!"; 
$dbName     = "id21876816_makajos";  
  
// writing a path under the variable $db
$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);  
  
// If there was an error in the connection, this will let you know
if ($db->connect_error) {  
    die("Error: " . $db->connect_error);  
}
```
- Now its crutial to understand the next line in the code:
```php
$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName); 
```
- Variable `$db` can be then used in any webpage code where you first include your `connect.php` file.
- For example in our code to send:
```php
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
...
```
  - first you `require('connect.php');` - loading your connect.php in this current code.
  - then just simply using the variable `$db` to carry out the istructions to the SQL.
  - the benefit is you dont have to worry every again about creating the path or anything, you just simply include your `connect.php` and use the `$db` variable

