<style>
* {
  box-sizing: border-box;
}

/* Create two equal columns that floats next to each other */
.column {
  float: left;
  width: 50%;
  padding: 10px;
  height: 300px; /* Should be removed. Only for demonstration */
}

/* Clear floats after the columns */
.row:after {
  content: "";
  display: table;
  clear: both;
}
</style>

<h2> USTH Smart Green Garden</h2>

<div class="row">
  <div class="column" > 
            <img src="images/system.png" alt="System Overall">
  </div>
  <div class="column" > 
            <img src="images/protocol.png" alt="Protocol"> 
  </div>
</div>
<br/></br><br/><br/>

<div id="chartContainer1" style="height: 400px; width: 100%;"></div>
<br/><br/><br/><br/>
<div id="chartContainer2" style="height: 400px; width: 100%;"></div>
<br/><br/><br/><br/>
<div id="chartContainer3" style="height: 400px; width: 100%;"></div>
 <script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
 <script>
function chart(chartId = "chartContainer1", _data, nameChart) {
	console.log(_data)
points = [];
	_data.forEach(function(entry) {
		new_arr = [];
	entry['chart'].forEach(function(i) {
		new_arr.push({
	label : i['x'],
	y : parseInt(i['y'])
	});
});
points.push({
	type: "spline",
		name: entry['index'],
		showInLegend: true,
	dataPoints : new_arr
});
});
console.log(points)
var chart = new CanvasJS.Chart(chartId, {
	theme:"light2",
	animationEnabled: true,
	title:{
		text: nameChart
	},
	axisY :{
		includeZero: false,
		title: "Moisture Values",
	},
	legend:{
		cursor:"pointer",
		itemclick : toggleDataSeries
	},
	toolTip: {
		shared: true
	},
	data:points
});
chart.render();
}

function toggleDataSeries(e) {
	if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible ){
		e.dataSeries.visible = false;
	} else {
		e.dataSeries.visible = true;
	}
	chart.render();
}
</script>
<?php
//select individual_sensor.Sensor_Index from individual_sensor where individual_sensor.Sensor_ID = 'SEN0169'
$sensor_arr = ['SEN0169', 'SEN0114', 'SEN0193'];
$response = array();
// include db_connect
$filepath = realpath(dirname(__FILE__));
require_once $filepath . "/db_connect.php";

// establish connection to db
$db = new DB_CONNECT();

foreach ($sensor_arr as $item) {
    // SQL query to insert Data to table
    if ($db->connect()) {
        $query_str = "select Individual_Sensor.Sensor_Index from Individual_Sensor where Individual_Sensor.Sensor_ID = '" . $item . "'";
        $result = $db->query($query_str);
		$chart = [];
        while ($row = $result->fetch_assoc() ) {
            $query_str = "select distinct Data.Time as x, Data.Sensor_Reading as y from Individual_Sensor, Data
				where Individual_Sensor.Sensor_ID = '" . $item . "' and Data.Sensor_Index = " . $row["Sensor_Index"] . " and Individual_Sensor.Sensor_Index = Data.Sensor_Index
				order by Individual_Sensor.Sensor_Index asc";
            $result2 = $db->query($query_str);
            $new_array = [];
            while ($row2 = $result2->fetch_assoc()) {
                $n = $row2['y'];
                $new_array[] = $row2;
            }
            $chart[] = ['index' => $row["Sensor_Index"], 'chart' => $new_array];
        }
        #if ($item == 'SEN0169') {
        #    echo '<script type="text/javascript">
        #                    chart("chartContainer1", ' . json_encode($chart) . ', "SEN0169");
        #				</script>';
        #}
        if ($item == 'SEN0114') {
            echo '<script type="text/javascript">
								chart("chartContainer2", ' . json_encode($chart) . ',"SEN0114");
						</script>';
        } else if ($item == 'SEN0193') {
            echo '<script type="text/javascript">
									chart("chartContainer3", ' . json_encode($chart) . ', "SEN0193");
							1</script>';
        }
    }
}
$db->close();

?>

