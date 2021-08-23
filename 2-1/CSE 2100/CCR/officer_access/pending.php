<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Issue requests</title>
	<link rel="stylesheet" href="../w3.css">
	<style>
		.w3-col{background-color:#e5e5e5}
		footer
		{
			background-color: black;
			color: white;
			font-size: 0.7em;
			text-align: center;
		}
		th,td
		{
			border:1px solid black;
			min-width: 150px;
			line-height: 25px;
		}
	</style>
</head>
<body>
	<header style="background-color: teal;">
		<img src="../ruet.png">
	</header>
	<div class="w3-col" style="min-height:200px;">
		<table>
			<tr>
				<th>Request from</th>
				<th>Request date</th>
				<th>Request time</th>
				<th>Instrument name</th>
				<th>Amount</th>
				<th>Date of collecting</th>
				<th>Time to collect</th>
				<th>Time to return</th>
				<th>Confirm</th>
			</tr>
			<?php
				while($data=mysqli_fetch_array($temp))
				{
					echo '<tr>'.
								'<td>'.$data['request_from'].'</td>'.
								'<td>'.$data['request_date'].'</td>'.
								'<td>'.$data['request_time'].'</td>'.
								'<td>'.$data['instrument_name'].'</td>'.
								'<td>'.$data['amount'].'</td>'.
								'<td>'.$data['collect_date'].'</td>'.
								'<td>'.$data['collect_time'].'</td>'.
								'<td>'.$data['return_time'].'</td>'.
								'<td>
									<form action="" method="get">
										<input type="hidden" name="serial" value="'.$data['serial'].'">
										<input type="submit" name="action" value="Allow">
										<input type="submit" name="action" value="Deny">
									</form>
								</td>'.
						 '</tr>';
				}
			?>
		</table>
		<a href="?return_home">Home</a>
	</div>
	<footer>&copyRajshahi University of Engineering &amp Technology</footer>
</body>

</html>