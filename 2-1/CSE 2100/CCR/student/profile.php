<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Profile(<?php echo $roll;?>)</title>
	<link rel="stylesheet" href="../w3.css">
	<style>
		.w3-col{background-color:#e5e5e5}
		header{background-color: teal;}
		footer
		{
			color: white;
			font-size: 0.7em;
			text-align: center;
			background-color: black;
		}
	</style>
</head>
<body>
	<header>
		<img src="../ruet.png">
	</header>
	<div class="w3-col" style="min-height:200px;">
		<?php
			$data=mysqli_fetch_array($sql);
			echo 'Roll No.: '.$roll.'<br>';
			echo 'Phone: '.$data['phone'].'<br>';
			echo 'Email: '.$data['email'].'<br>';
		?>
		<form action="?change" method="post">
			<table>
				<tr>
					<td><label for="change_phone">Change Phone:</label></td>
					<td><input type="text" name="change_phone" id="change_phone" placeholder="Change phone number" maxlength="15"></td>
				</tr>
				<tr>
					<td><label for="change_email">Change Email:</label></td>
					<td><input type="text" name="change_email" id="change_email" placeholder="Change Email Address" maxlength="32"></td>
				</tr>
				<tr>
					<td><label for="change_password">Change Password:</label></td>
					<td><input type="password" name="change_password" id="change_password" placeholder="Change Password" maxlength="32"></td>
				</tr>
				<tr>
					<td><a href="?return">Home</a></td>
					<td><input type="submit" value="Change Information"></td>
				</tr>
			</table>
		</form>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>

</html>