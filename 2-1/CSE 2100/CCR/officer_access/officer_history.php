<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Officer history</title>
	<link rel="stylesheet" href="../w3.css">
	<style>
		.w3-col{background-color:#e5e5e5}
		header
		{
			background-color: teal;
		}
		footer
		{
			background-color: black;
			color: white;
			text-align: center;
			font-size: 0.7em;
		}
		th
		{
			min-width: 75px;
			line-height: 20px;
		}
	</style>
</head>
<body>

	<header>
		<img src="../ruet.png">
	</header>

	<div class="w3-col" style="min-height:200px;">
		<fieldset>
			<legend>Officer history</legend>
			<table>
				<tr>
					<th>Serial No.</th>
					<th>Name</th>
					<th>Join Date</th>
				</tr>
				<?php
					$i=1;
					while($data=mysqli_fetch_array($temp))
					{
						echo '<tr>'.
									'<td>'.$i.'</td>'.
									'<td>'.$data['name'].'</td>'.
									'<td>'.$data['joindate'].'</td>'.
							 '</tr>';
						$i++;
					}
				?>
				<tr>
					<td><a href="?return_home">Go back</a></td>
				</tr>
			</table>
		</fieldset>
	</div>

	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>

</body>

</html>