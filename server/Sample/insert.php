<?php 

	$response = array();
	if (isset($_GET['moisture'])) {
		$moisture = $_GET['moisture'];		// get value 	
		echo $moisture;

		// include db_connect
		$filepath = realpath(dirname(__FILE__));
		require_once($filepath."/db_connect.php");

		// establish connection to db
		$db = new DB_CONNECT();
		
		// SQL query to insert data to table 
		if ($db->connect()) {
			$query_str = "INSERT INTO test (Moisture) VALUES (420)";

			if (false === $qresult) {
			  printf("error");
			}
			else {
			  echo 'done.';
			}
		}
	}	
	
?>
