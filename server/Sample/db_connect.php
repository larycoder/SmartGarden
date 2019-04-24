<?php

/**
 * A class file to handle connection to database
 */
	class DB_CONNECT {

		private $this->conn;    // store the connection 

		// establish connection to the database and return it 
		function connect() {
			$filepath = realpath(dirname(__FILE__));
			require_once($filepath."/dbconfig.php");

			// connect to the mysql database
			$this->conn = mysqli_connect(HOST, USER, PASSWORD, DATABASE);

			// Check connection
			if (mysqli_connect_errno())
			{
				echo "Failed to connect to MySQL: " . mysqli_connect_error();
				return False;
			}

			return True;
		}

		// receive query string and run it on DB 
		function query($query_str){
			$qresult = mysqli_query($this->conn, $query_str);
			return $qresult;
		}

		// disconnect from the database 
		function close() {
			// closing db connection
			mysqli_close($this->conn);
		}
	}
?>