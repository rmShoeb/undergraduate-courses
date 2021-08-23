<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="../w3.css">
  <title>Booking Instrument</title>
	<style>
		.w3-col{background-color:#e5e5e5}
		header{background-color: teal;}
		footer
		{
			background-color: black;
			color: white;
			font-size: 0.7em;
			text-align: center;
		}
	</style>
</head>
<body>
	<header>
		<img src="../ruet.png">
	</header>
	<div>
	  <div class="w3-row">
	    <div class="w3-col s3" style="min-height:300px;border-right:8px solid white;padding-left: 10px;padding-right: 10px;">
	    	<fieldset>
	    		<legend>Instructions</legend>
	    		<ol>
	    			<li>Make sure no field is empty.</li>
	    			<li>You will have to bring your ID card with you when you come to collect your desired instrument.</li>
	    			<li>You have to return the instrument you book the same day you collect them.</li>
	    			<li>You will be held responsible for the instrumenet after you collect the instumnt untill you return it/them.</li>
	    		</ol>
	    	</fieldset>
	    </div>
	    <div class="w3-col s9" style="min-height:300px;padding-left: 25px;padding-right: 25px;">
	    	<fieldset>
	    		<legend>Instrument booking</legend>
	    		<form action="?book" method="post">
	    			<table>
	    				<tr>
	    					<td><label for="instrument">Instrument:</label></td>
	    					<td>
	    						<select name="instrument" id="instrument">
	    							<option value="fixed_weight_dumbbell">Fixed weight dumbbell</option>
	    							<option value="adjustable_dumbbell">Adjustable dumbbell</option>
	    							<option value="ez_curlbar">EZ curlbar</option>
	    							<option value="fixed_barbell">Fixed barbell</option>
	    							<option value="thick_handled_barbell">Thick handled barbell</option>
	    							<option value="triceps_bar">Triceps bar</option>
	    							<option value="treadmill">Treadmill</option>
	    							<option value="spin_bike">Spin bike</option>
	    							<option value="sandbag">Sandbag</option>
	    							<option value="kettlebell">Kettlebell</option>
	    							<option value="chin_up_bar">Chin-up bar</option>
	    							<option value="football">Football</option>
	    						</select>
	    					</td>
	    				</tr>
	    				<tr>
	    					<td><label for="amount">Number of instruments:</label></td>
	    					<td><input type="text" name="amount" maxlength="1"></td>
	    				</tr>
	    				<tr>
	    					<td><label>Date of collecting instrument:</label></td>
	    					<td>
	    						<input type="date" name="date"></td>
	    				</tr>
	    				<tr>
	    					<td><label>Time to collect:</label></td>
	    					<td><input type="time" name="collect_time"></td>
	    				</tr>
	    				<tr>
	    					<td><label>Time to return:</label></td>
	    					<td><input type="time" name="return_time"></td>
	    				</tr>
	    				<tr>
	    					<td><a href="?cancel">Cancel</a></td>
	    					<td><input type="submit" name="proceed" id="proceed" value="Proceed"></td>
	    				</tr>
	    			</table>
	    		</form>
	    	</fieldset>
	    </div>
	  </div>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>
</html>
