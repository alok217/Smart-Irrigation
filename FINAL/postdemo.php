<?php
    $servername = "localhost";
    $username = "root";
    $password = "rahul";
    $dbname = "test_arduino";
 
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }
 
    //Get current date and time
    date_default_timezone_set('Asia/Kolkata');
    $d = date("Y-m-d");
    //echo " Date:".$d."<BR>";
    $t = date("H:i:s");
 
   //if(!empty($_POST['soil']) && !empty($_POST['water']))
    //{
    	$soil = $_POST['soil'];
    	$water = $_POST['water'];
    	
    	if ($soil==0 && $water > 200) 
    	{
    		$status="ON";
    		echo "1";
    	}
    	else
    	{
    		$status="OFF";
    		echo "0";
    	}

 
	   $sql = "INSERT INTO garduino (soil, water, status, Date, Time)
		
		VALUES ('".$soil."', '".$water."','".$status."', '".$d."', '".$t."')";
 
		if ($conn->query($sql) === TRUE) {
		    //echo "OK";
		} else {
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
	//}
	//echo "Soil =",$soil;
	//echo $soil;
	//echo "\n";
	//echo "Water =";
	//echo $water;
	//echo "\n";

	$conn->close();
?>