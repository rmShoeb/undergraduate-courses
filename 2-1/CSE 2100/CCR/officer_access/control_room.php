<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Control room</title>
	<link rel="stylesheet" href="../w3.css">
	<style>
		.w3-col{background-color:#e5e5e5}
		footer
		{
			background-color: black;
			color: white;
			text-align: center;
			font-size: 0.7em;
		}
		li
		{
			list-style: none;
			background-color: teal;
			line-height: 25px;
			color: white;
			text-align: center;
			padding-right: 10px;
			padding-left: 10px;
		}
	</style>
</head>

<body>

	<header style="background-color: teal">
		<img src="../ruet.png">
	</header>

	<div>

		<div class="w3-row">
			<div class="w3-col s4" style="min-height:200px;border-right:8px solid white;padding-right: 25px;">
				<ul>
					<li><a href="?change_info">Change info</a></li><br>
					<li><a href="?officer_history">Officer history</a></li><br>
					<li>
						<form action="?logout" method="get">
							<input type="submit" value="Logout">
						</form>
					</li>
				</ul>
			</div>

			<div class="w3-col s4" style="min-height:200px;border-right:8px solid white;">
				<fieldset>
				<legend>Issue instruments to students</legend>
				<p>
					<?php
						if($total_request>0)
						{
							echo 'There are'.$total_request.'pending requests';
						}
						else
						{
							echo 'There are no available requests.';
						}
					?>
				</p>
				<a href="?requests" style="color: blue;">See all</a>
				</fieldset>
				<fieldset>
				<legend>Previous issues</legend>
				<p style="color: red; text-align: center;">
					<?php
						if(isset($problem))
							echo $problem;
					?>
				</p>
				<p>Filter by</p>
				<form action="?filter" method="post">
				<p>Roll no.: <input type="text" name="roll" id="roll" maxlength="7"></p>
				<p>Instrument:
				<select name="instrument" id="instrument">
					<option value="all">ALL</option>
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
				</p>
				<input type="submit" name="filter" value="filter">
				</form>
				</fieldset>
			</div>

			<div class="w3-col s4" style="min-height:200px;">
				<fieldset>
				<legend>Instrument info</legend>
				<?php
					while($info=mysqli_fetch_array($temp))
						echo $info['instrument_name'].'('.$info['ammount'].')<br>';
				?>
				<a href="?add_new_instrument" style="color: blue;">Add new instruments</a><br>
				<!--a href="" style="color: blue;">Add new type of instrument</a-->
				</fieldset>
			</div>

		</div>

	</div>

	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>

</body>

</html>