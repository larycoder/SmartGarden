<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
* {box-sizing: border-box}
body {font-family: Verdana, sans-serif; margin:0}
.mySlides {display: none}
img {vertical-align: middle;}
/* Slideshow container */
.slideshow-container {
  max-width: 1000px;
  position: relative;
  margin: auto;
}
/* Next & previous buttons */
.prev, .next {
  cursor: pointer;
  position: absolute;
  top: 50%;
  width: auto;
  padding: 16px;
  margin-top: -22px;
  color: white;
  font-weight: bold;
  font-size: 18px;
  transition: 0.6s ease;
  border-radius: 0 3px 3px 0;
  user-select: none;
}
/* Position the "next button" to the right */
.next {
  right: 0;
  border-radius: 3px 0 0 3px;
}
/* On hover, add a black background color with a little bit see-through */
.prev:hover, .next:hover {
  background-color: rgba(0,0,0,0.8);
}
/* Caption text */
.text {
  color: #f2f2f2;
  font-size: 15px;
  padding: 8px 12px;
  position: absolute;
  bottom: 8px;
  width: 100%;
  text-align: center;
}
/* Number text (1/3 etc) */
.numbertext {
  color: #f2f2f2;
  font-size: 12px;
  padding: 8px 12px;
  position: absolute;
  top: 0;
}
/* The dots/bullets/indicators */
.dot {
  cursor: pointer;
  height: 15px;
  width: 15px;
  margin: 0 2px;
  background-color: #bbb;
  border-radius: 50%;
  display: inline-block;
  transition: background-color 0.6s ease;
}
.active, .dot:hover {
  background-color: #717171;
}
/* Fading animation */
.fade {
  -webkit-animation-name: fade;
  -webkit-animation-duration: 1.5s;
  animation-name: fade;
  animation-duration: 1.5s;
}
@-webkit-keyframes fade {
  from {opacity: .4} 
  to {opacity: 1}
}
@keyframes fade {
  from {opacity: .4} 
  to {opacity: 1}
}
/* On smaller screens, decrease text size */
@media only screen and (max-width: 300px) {
  .prev, .next,.text {font-size: 11px}
}
</style>

<div class="slideshow-container">

<div class="mySlides fade">
  <div class="numbertext">1 / 3</div>
  <img src="https://scontent.fhan3-3.fna.fbcdn.net/v/t1.0-9/64582215_1213018805526536_6302720243223494656_n.jpg?_nc_cat=106&_nc_oc=AQmt_FEdwxY5yZCOIH4r603b4qFFUqsrtZ36A9UrZFFdtLYxS_J_3pnawmx5GpACI6o&_nc_ht=scontent.fhan3-3.fna&oh=47f21c8a4e9f2230c398698b1b58237e&oe=5D9AF666" style="width:100%">
</div>

<div class="mySlides fade">
  <div class="numbertext">2 / 3</div>
  <img src="img_snow_wide.jpg" style="width:100%">
</div>

<div class="mySlides fade">
  <div class="numbertext">3 / 3</div>
  <img src="img_mountains_wide.jpg" style="width:100%">
</div>

<a class="prev" onclick="plusSlides(-1)">&#10094;</a>
<a class="next" onclick="plusSlides(1)">&#10095;</a>

</div>
<br>

<div style="text-align:center">
  <span class="dot" onclick="currentSlide(1)"></span> 
  <span class="dot" onclick="currentSlide(2)"></span> 
  <span class="dot" onclick="currentSlide(3)"></span> 
</div>


<div id="chartContainer1" style="height: 500px; width: 100%;"></div>
<br/><br/><br/><br/>
<div id="chartContainer2" style="height: 500px; width: 100%;"></div>
<br/><br/><br/><br/>
<div id="chartContainer3" style="height: 500px; width: 100%;"></div>
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
points.push({
	type: "spline",
		name: entry['index'],
	dataPoints : new_arr
});
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

var slideIndex = 1;
showSlides(slideIndex);
function plusSlides(n) {
  showSlides(slideIndex += n);
}
function currentSlide(n) {
  showSlides(slideIndex = n);
}
function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("mySlides");
  var dots = document.getElementsByClassName("dot");
  if (n > slides.length) {slideIndex = 1}    
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";  
  }
  for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
  }
  slides[slideIndex-1].style.display = "block";  
  dots[slideIndex-1].className += " active";
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

    if ($db->connect()) {
$row = [1, 2, 3, 4];
        foreach ($row as $index) {
            $query_str = "select distinct Data.Time as x, Data.Sensor_Reading as y from Data
				where Data.Sensor_Reading < 1000 and  Data.Sensor_Index = " . $index;
            $result2 = $db->query($query_str);
            $new_array = [];
            while ($row2 = $result2->fetch_assoc()) {
                $n = $row2['y'];
                $new_array[] = $row2;
            }
            $chart[] = ['index' =>$index, 'chart' => $new_array];
        }
            echo '<script type="text/javascript">
                            chart("chartContainer1", ' . json_encode($chart) . ', "Filter 1 ");
					</script>';

					//===========================================================
					$chart = [];
					$row = [5, 6, 7, 8];
					foreach ($row as $index) {
						$query_str = "select distinct Data.Time as x, Data.Sensor_Reading as y from Data
							where Data.Sensor_Reading < 1000 and  Data.Sensor_Index = " . $index;
						$result2 = $db->query($query_str);
						$new_array = [];
						while ($row2 = $result2->fetch_assoc()) {
							$n = $row2['y'];
							$new_array[] = $row2;
						}
						$chart[] = ['index' =>$index, 'chart' => $new_array];
					}
						echo '<script type="text/javascript">
										chart("chartContainer2", ' . json_encode($chart) . ', "Filter 2");
								</script>';

					//===========================================================

					$chart = [];
					$row = [9, 10, 11, 12];
					foreach ($row as $index) {
						$query_str = "select distinct Data.Time as x, Data.Sensor_Reading as y from Data
							where Data.Sensor_Reading < 1000 and  Data.Sensor_Index = " . $index;
						$result2 = $db->query($query_str);
						$new_array = [];
						while ($row2 = $result2->fetch_assoc()) {
							$n = $row2['y'];
							$new_array[] = $row2;
						}
						$chart[] = ['index' =>$index, 'chart' => $new_array];
					}
						echo '<script type="text/javascript">
										chart("chartContainer3", ' . json_encode($chart) . ', "Filter 3");
								</script>';

	}
	

$db->close();

?>


