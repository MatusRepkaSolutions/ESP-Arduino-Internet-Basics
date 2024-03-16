<!DOCTYPE html>
<?php
    require('connect.php');
?>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Index</title>
    <meta name="copyright" content="DaI">
    <meta name="description" content="">
    <meta name="keywords" content="">
    <style> 
    /* Basic table styling */
        table {
            border-collapse: collapse;
            width: 50%;
            margin: 20px auto;
        }

        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: center;
        }

        th {
            background-color: #f2f2f2;
        }

        .button {
            display: block;
            width: 100px;
            margin: 10px auto;
        }
    </style>
</head>
<body>
    <table>
        <tr>
            <th>ID</th>
            <th>IP Address</th>
            <th>MAC Address</th>
            <th>Status</th>
            <th>Actions</th>
        </tr>
        <?php
        // Connect to the database and retrieve the entire table of LEDs
        $sql = "SELECT * FROM ESP_LED";
        $result = $db->query($sql);

        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                // Display each row from the database
                echo "<tr>";
                echo "<td>".$row['id']."</td>";
                echo "<td>".$row['IP']."</td>";
                echo "<td>".$row['MAC']."</td>";
                echo "<td>".$row['status']."</td>";
                echo "<td>";
                // Button to redirect to update the status of the LED (turn on/off)
                echo "<form action='update_status_LED.php' method='post'>";
                echo "<input type='hidden' name='id' value='".$row['id']."'>"; // Record the row in the table
                echo "<input type='hidden' name='action' value='turn_on'>";  // Record the action to perform
                echo "<input type='submit' class='button' value='LED ON'>";
                echo "</form>";
                echo "<form action='update_status_LED.php' method='post'>";
                echo "<input type='hidden' name='id' value='".$row['id']."'>";// Record the row in the table
                echo "<input type='hidden' name='action' value='turn_off'>"; // Record the action to perform
                echo "<input type='submit' class='button' value='LED OFF'>";
                echo "</form>";
                echo "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='5'>No records in the table</td></tr>"; // If the database is empty
        }
        ?>
    </table>
</body>
</html>
