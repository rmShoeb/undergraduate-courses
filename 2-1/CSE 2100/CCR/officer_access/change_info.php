<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Change info</title>
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
	</style>
</head>

<body>

	<header style="background-color: teal;">
		<img src="../ruet.png">
	</header>


	<div class="w3-col" style="min-height:200px;">
		<p style="color: red;">
			<?php
				if(isset($change_error))
					echo $change_error;
			?>
		</p>
		<p style="color: green;">
			<?php
				if(isset($success))
					echo $success;
			?>
		</p>
		<fieldset>
			<legend>Change Info</legend>
			<form action="?change" method="post">
				<table>
					<tr>
						<td><label for="phone">Change Phone No.:</label></td>
						<td><input type="text" name="phone" id="phone" placeholder="Change Phone Number" maxlength="15"></td>
					</tr>
					<tr>
						<td><label for="email">Change Email Address:</label></td>
						<td><input type="text" name="email" id="email" placeholder="Change Email Address" maxlength="32"></td>
					</tr>
					<tr>
						<td><label for="password">Password:</label></td>
						<td><input type="password" name="password" id="password" placeholder=" Current Password" maxlength="32"></td>
					</tr>
					<tr>
						<td><label for="new_password">Change Password</label></td>
						<td><input type="password" name="new_password" id="new_password" placeholder="New Password" maxlength="32"></td>
					</tr>
					<tr>
						<td><label for="con_new_password">Confirm New Password:</label></td>
						<td><input type="password" name="con_new_password" id="con_new_password" placeholder="Confirm New Password" maxlength="32"></td>
					</tr>
					<tr>
						<td colspan="2">You have to enter your current password for safety measures<br>in case you want to update any information or set a new password.</td>
					</tr>
					<tr>
						<td><a href="?return_home">Go back</a></td>
						<td><input type="submit" name="update" id="update" value="Update"></td>
					</tr>
				</table>
			</form>
		</fieldset>
	</div>

	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>

</body>

</html>