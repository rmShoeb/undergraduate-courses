<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="../w3.css">
  <title>History</title>
	<style>
	.w3-col{background-color:#e5e5e5}
	li
	{
		list-style: none;
		line-height: 25px;
		background-color: teal;
		text-align: center;
		color: white;
	}
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
		min-width: 110px;
		border: 1px solid black;
		line-height: 25px;
	}
	</style>
</head>
<body>
	<header>
		<img src="../ruet.png">
	</header>
	<div>
	  <div class="w3-row">
	    <div class="w3-col s3" style="min-height:280px;border-right:8px solid white;padding-right: 25px;">
	    	<ul>
	    		<li><a href="?profile">Profile</a></li>
	    		<br>
	    		<li>
	    			<form action="?logout" method="post">
						<input type="submit" value="Logout">
					</form>
				</li>
	    	</ul>
	    </div>
	    <div class="w3-col s9" style="min-height:280px;padding-left: 25px;padding-right: 25px;">
	    	<fieldset style="margin-top: 10px;">
	    		<legend>Your bookings</legend>
	    		<table>
	    			<tr>
	    				<th>Booking date</th>
	    				<th>Booking time</th>
	    				<th>Instrument</th>
	    				<th>Amount</th>
	    				<th>Date of taking</th>
	    				<th>Time of taking</th>
	    				<th>Time of return</th>
	    				<th>Issue</th>
	    			</tr>
	    			<?php
	    				while($data=mysqli_fetch_array($sql))
	    				{
	    					echo '<tr>'.
	    								'<td>'.$data['booking_date'].'</td>'.
	    								'<td>'.$data['booking_time'].'</td>'.
	    								'<td>'.$data['instrument_name'].'</td>'.
	    								'<td>'.$data['amount'].'</td>'.
	    								'<td>'.$data['collect_date'].'</td>'.
	    								'<td>'.$data['collect_time'].'</td>'.
	    								'<td>'.$data['return_time'].'</td>';
	    					if($data['issue']=='0')
	    						echo '<td style="color:red;">Denied</td>';
	    					else if($data['issue']=='1')
	    						echo '<td style="color:green;">Allowed</td>';
	    					else
	    						echo '<td>Pending</td>';
	    					echo '</tr>';
	    				}
	    			?>
	    			<tr>
	    				<td><a href="?refresh">Refresh</a></td>
	    				<td colspan="7" align="right"><a href="?booking">book instrument</a></td>
	    			</tr>
	    		</table>
	    	</fieldset>
	    </div>
	  </div>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>

</body>
</html>