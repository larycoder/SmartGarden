<?php
	
$type_name = array("moisture", "air", "heat");
$sensor_id = array("SEN0114", "SEN0193", "SEN0169");
$name = array("Electric sensor", "Capacitive sensor", "Temperature sensor");
$coordinate = array(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

$filepath = realpath(dirname(__FILE__));
require_once($filepath."/db_connect.php");

// establish connection to db
$db = new DB_CONNECT();

// SQL query to insert data to table 
if ($db->connect()) {
	for ($i=0; $i < 10; $i++) {
		$type = rand(0, 2);

		// insert into Sensor_Type table 
		$qstr = "INSERT INTO Sensor_Type(Type_ID, Type_Name) VALUES($type, '$type_name[$type]');";
		$qresult = $db->query($qstr);

		// insert into Sensor_List table
		$qstr = "INSERT INTO Sensor_List(Sensor_ID, Type_ID, Name) VALUES('$sensor_id[$type]', $type, '$name[$type]');";
		$qresult = $db->query($qstr);

		// insert into Individual_Sensor table
		$qstr = "INSERT INTO Individual_Sensor(Sensor_ID, Coordinate) VALUES('$sensor_id[$type]', $coordinate[$i]);";
		$qresult = $db->query($qstr);

	}

	for ($i=0; $i < 100; $i++) { 
		// insert into Data table
		sleep(2);
		$index = rand(1, 10); 
		$val = rand(400, 600);
		$qstr = "INSERT INTO Data(Time, Sensor_Index, Value) VALUES(CURRENT_TIME(), $index, $val);";
		$qresult = $db->query($qstr);

	}
}
	
?>
