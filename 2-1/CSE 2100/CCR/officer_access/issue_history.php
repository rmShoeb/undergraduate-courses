<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>History</title>
	<link rel="stylesheet" href="../w3.css">
	<style>
		.w3-col{background-color:#e5e5e5}
		footer
		{
			color: white;
			font-size: 0.7em;
			text-align: center;
			background-color: black;
		}
		th, td
		{
			border: 1px solid black;
			min-width: 100px;
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
				<th>Instrument name</th>
				<th>Amount</th>
				<th>Request date</th>
				<th>Request time</th>
				<th>Collect date</th>
				<th>Collect time</th>
				<th>Return time</th>
				<th>Decision</th>
				<th>Checked at</th>
				<th>Returned</th>
			</tr>
			<?php
				while($data=mysqli_fetch_array($temp))
				echo '<tr>
							<td>'.$data['request_from'].'</td>
							<td>'.$data['instrument_name'].'</td>
							<td>'.$data['amount'].'</td>
							<td>'.$data['request_date'].'</td>
							<td>'.$data['request_time'].'</td>
							<td>'.$data['collect_date'].'</td>
							<td>'.$data['collect_time'].'</td>
							<td>'.$data['return_time'].'</td>
							<td>'.$data['decision'].'</td>
							<td>'.$data['check_time'].'</td>';
				if($data['returned']!='NULL')
					echo '<td>'.$data['returned'].'</td';
				else
				{
					echo '<td><form action="" method="get">
								<input type="hidden">
								<input type="submit" name="action" value="Returned">
						  </form></td>';
				}
				echo '</tr>';
			?>
		</table>
		<a href="?return_home">Home</a>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp technology
	</footer>
</body>

</html>