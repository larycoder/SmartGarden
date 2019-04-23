<?php 

	$response = array();
	if (isset($_GET['moisture'])) {
		$moisture = $_GET('moisture');		// get value 

		// include db_connect
		$filepath = realpath(dirname(__FILE__));
		require_once($filepath."/db_connect.php");

		// establish connection to db
		$db = new DB_CONNECT();
		
		// SQL query to insert data to table 
		$query_res = mysql_query("Insert into test(Moisture) Values('$moisture')");

		if ($query_res) {
			$response['success'] = 1;
			$response['message'] = "success";

			echo json_encode($response);
		}
	}
	
?>