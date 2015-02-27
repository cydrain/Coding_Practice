<?php $this->pageTitle = 'FlyOnTime.us: Statistics - '.$Name; ?>

<table border=0 cellpadding=0 cellspacing=0 width="100%">
<tr>
	<td align="center">
	
		<table border=0 cellpadding=0 cellspacing=0 width="800px">
		<tr>
			<td align="left">

				<br />
				<h1>
					Route Statistics - <?php echo $Name; ?>
				</h1>
				<br />
				
				<script type="text/javascript" src="http://www.google.com/jsapi?key=ABQIAAAAhD9h1r6o4CX5R6aR5Sm7chSk0bEoTe4xv8Xwjuk4IV3JR0xuqxSCWSPF07wu9P2WbpcpovPoKtafwQ"></script>
				
				
				<script type="text/javascript">
				  google.load("visualization", "1", {packages:["barchart"]});
				  google.setOnLoadCallback(drawChart);
				  function drawChart() {
					var data = new google.visualization.DataTable();
					data.addColumn('string', 'Route');
					data.addColumn('number', '<?php echo $DataTitle; ?>');
					data.addRows(<?php echo count($Routes); ?>);
					
					<?php
					$max_abs_data_value = 0;
					
					$i = 0;
					foreach($Routes as $route)
					{
					if(abs($route['Ontime'][$DataValue]) > $max_abs_data_value)
						$max_abs_data_value = abs($route['Ontime'][$DataValue]);
					?>
					
					data.setValue(<?php echo $i; ?>, 0, '<?php echo $route['Ontime']['origin'].' - '.$route['Ontime']['dest']; ?>');
					data.setValue(<?php echo $i; ?>, 1, <?php echo $route['Ontime'][$DataValue]*$MultiplyBy; ?>);
					
					<?php
					$i++;
					}
					?>
				
					var chart = new google.visualization.BarChart(document.getElementById('chart_div'));
					chart.draw(data, {width: 650, height: 2000, is3D: true, legend: 'bottom', axisFontSize: 10, legendFontSize: 16});
				  }
				</script>
				
				<script type="text/javascript">
				  google.load("maps", "2.x");
				  google.setOnLoadCallback(initialize_map);
				  
				  function initialize_map() {
					var map = new google.maps.Map2(document.getElementById("map_canvas"));
					map.setCenter(new google.maps.LatLng(39.0904320, -94.5836530), 4);
					
					<?php
					$max_line_thickness = 10;
					
					foreach($Routes as $route)
					{
					$line_thickness = round((abs($route['Ontime'][$DataValue])/$max_abs_data_value)*$max_line_thickness);
					if($line_thickness < 1)
						$line_thickness = 1;
					
					if(isset($Geocodes[$route['Ontime']['origin']]) && isset($Geocodes[$route['Ontime']['dest']]))
					{
					?>
					
					map.addOverlay( new google.maps.Polyline([new google.maps.LatLng(<?php echo $Geocodes[$route['Ontime']['origin']]['Lat']; ?>, <?php echo $Geocodes[$route['Ontime']['origin']]['Lng']; ?>), new google.maps.LatLng(<?php echo $Geocodes[$route['Ontime']['dest']]['Lat']; ?>, <?php echo $Geocodes[$route['Ontime']['dest']]['Lng']; ?>)], "#ff0000", <?php echo $line_thickness; ?>) );
					
					<?php
					}
					}
					?>
				  }
				</script>
				
				
				<div id="map_canvas" style="width: 100%; height: 400px"></div>
				
				<br />
				
				

			</td>
		</tr>
		</table>
		
		<div id='chart_div'></div>

	</td>
</tr>
</table>

