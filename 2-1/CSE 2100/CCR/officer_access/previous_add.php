<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Previously</title>
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
		td,th
		{
			border: 1px solid black;
			margin: 0px;
			text-align: center;
		}
	</style>
</head>
<body>
	<header>
		<img src="../ruet.png">
	</header>
	<div class="w3-col" style="min-height:200px;">
		<table>
			<tr>
				<th>Tender no.</th>
				<th>Add date</th>
				<th>Fixed weight dumbbell</th>
				<th>Adjustable dumbbell</th>
				<th>EZ Curlbar</th>
				<th>Fixed barbell</th>
				<th>Thick-handled barbell</th>
				<th>Triceps bar</th>
				<th>Kettlebell</th>
				<th>Chin-up bar</th>
				<th>Treadmill</th>
				<th>Spin bike</th>
				<th>Sandbag</th>
				<th>Football</th>
			</tr>
			<?php
				while($previously=mysqli_fetch_array($temp))
				{
					echo '<tr>
								<td>'.$previously['tender_no'].'</td>
								<td>'.$previously['add_date'].'</td>
								<td>'.$previously['fixed_weight_dumbbell'].'</td>
								<td>'.$previously['adjustable_dumbbell'].'</td>
								<td>'.$previously['ez_curlbar'].'</td>
								<td>'.$previously['fixed_barbell'].'</td>
								<td>'.$previously['thick_handled_barbell'].'</td>
								<td>'.$previously['triceps_bar'].'</td>
								<td>'.$previously['kettlebell'].'</td>
								<td>'.$previously['cin_up_bar'].'</td>
								<td>'.$previously['treadmill'].'</td>
								<td>'.$previously['spin_bike'].'</td>
								<td>'.$previously['sandbag'].'</td>
								<td>'.$previously['football'].'</td>
						  </tr>';
				}
			?>
		</table>
		<a href="?return_home">Home</a>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>

</html>