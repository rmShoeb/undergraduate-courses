<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="../w3.css">
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
	<div class="w3-col" style="min-height:200px;">
		<p style="color: red;">
		<?php
			if(isset($add_new__error))
				echo $add_new__error;
		?>
		<p>
		<form action="?insert_instrument" method="post">
			<table>
				<tr>
					<td><label for="tender_no">Tender: </label></td>
					<td><input type="text" name="tender_no" id="tender_no" placeholder="Tender" maxlength="20"></td>
				</tr>
				<tr>
					<td><label for="fixed_weight_dumbbell">Fixed weight dumbbell: </label></td>
					<td><input type="text" name="fixed_weight_dumbbell" id="fixed_weight_dumbbell" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="adjustable_dumbbell">Adjustable dumbbell: </label></td>
					<td><input type="text" name="adjustable_dumbbell" id="adjustable_dumbbell" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="ez_curl_bar">EZ Curlbar:</label></td>
					<td><input type="text" name="ez_curl_bar" id="ez_curl_bar" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="fixed_barbell">Fixed barbell:</label></td>
					<td><input type="text" name="fixed_barbell" id="fixed_barbell" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="thick_handled_barbell">Thick handled barbell: </label></td>
					<td><input type="text" name="thick_handled_barbell" id="thick_handled_barbell" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="triceps_bar">Triceps bar:</label></td>
					<td><input type="text" name="triceps_bar" id="triceps_bar" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="kettlebell">Kettlebell:</label></td>
					<td><input type="text" name="kettlebell" id="kettlebell" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="cin_up_bar">Chin-up bar</label></td>
					<td><input type="text" name="cin_up_bar" id="cin_up_bar" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="treadmill">Treadmill:</label></td>
					<td><input type="text" name="treadmill" id="treadmill" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="spin_bike">Spin bike:</label></td>
					<td><input type="text" name="spin_bike" id="spin_bike" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="sandbag">Sandbag</label></td>
					<td><input type="text" name="sandbag" id="sandbag" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><label for="football">Football:</label></td>
					<td><input type="text" name="football" id="football" placeholder="Amount" maxlength="2"></td>
				</tr>
				<tr>
					<td><a href="?return_home">Return home</a></td>
					<td><input type="submit" value="Add"></td>
				</tr>
			</table>
		</form>
		<p><a href="?previous_add">See previous lists</a></p>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>
</html>
