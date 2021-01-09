<style>
* {
  box-sizing: border-box;
}

body {
  margin: 0;
  font-family: Arial;
}

.header {
  text-align: center;
  padding: 32px;
}

.row {
  display: -ms-flexbox; /* IE10 */
  display: flex;
  -ms-flex-wrap: wrap; /* IE10 */
  flex-wrap: wrap;
  padding: 0 4px;
}

/* Create four equal columns that sits next to each other */
.column {
  -ms-flex: 25%; /* IE10 */
  flex: 25%;
  max-width: 25%;
  padding: 0 4px;
}

.column img {
  margin-top: 8px;
  vertical-align: middle;
  width: 100%;
}

/* Responsive layout - makes a two column-layout instead of four columns */
@media screen and (max-width: 800px) {
  .column {
    -ms-flex: 50%;
    flex: 50%;
    max-width: 50%;
  }
}

/* Responsive layout - makes the two columns stack on top of each other instead of next to each other */
@media screen and (max-width: 600px) {
  .column {
    -ms-flex: 100%;
    flex: 100%;
    max-width: 100%;
  }
}

</style>


<h2> USTH Smart Green Garden</h2>

<div class="row">
  <div class="column" >
            <img src="images/system.png" alt="System Overall" style="width:100%">
  </div>
  <div class="column" >
            <img src="images/protocol.png" alt="Protocol" style="width:100%">
  </div>
  <div class="column" >
            <img src="images/IMG_3293.png" alt= "Demo" style="width:100%">
  </div>
</div>
<br/></br><br/><br/>

#<div id="chartContainer1" style="height: 400px; width: 100%;"></div>
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

