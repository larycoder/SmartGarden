<?php 
	$response = array();
	if (isset($_GET)) {
		$Sensor_Index = $_GET['ss_index'];
		$Value = $_GET['val'];	
		echo $Sensor_Index;
		echo $Value;
		
		// include db_connect
		$filepath = realpath(dirname(__FILE__));
		require_once($filepath."/db_connect.php");

		// establish connection to db
		$db = new DB_CONNECT();

		// SQL query to insert data to table 
		if ($db->connect()) {
			$query_str = "INSERT INTO Data (Sensor_Index, Value) VALUES ($Sensor_Index, $Value)";
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

