<?php 
	$response = array();
	if (isset($_GET)) {
		
		$Sensor_ID = $_GET['ss_id'];	
		$Position = $_GET['pos'];

		// include db_connect
		$filepath = realpath(dirname(__FILE__));
		require_once($filepath."/db_connect.php");

		// establish connection to db
		$db = new DB_CONNECT();

		// SQL query to insert data to table 
		if ($db->connect()) {
			$query_str = "INSERT INTO Individual_Sensor (Sensor_ID, Position) VALUES ('$Sensor_ID', '$Position')";
			$qresult = $db->query($query_str);

			if (false === $qresult) {
			  echo 'Error';
			}
			else {
			  echo 'Done.';
			}
		}
	}
?>

