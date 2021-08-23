<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Sign in</title>
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
	</style>
</head>
<body>
	<header style="background-color: teal;">
		<img src="../ruet.png">
	</header>
	<div>
		<div class="w3-col" style="min-height:200px;">
			<p style="color: red; text-align: center;">
				<?php
					if(isset($error))		//the condition is to check if there is any error message, 'cause I don't want to show any php default error message here.
						echo $error;		//in case, the user id or password is wrong, this part will show an error message
				?>
			</p>
			<fieldset style="margin-left: 500px;margin-right: 500px; margin-top: 5px;">
				<legend>Sign In</legend>
				<form action="?enter" method="post">
					<table>
						<tr>
							<td><label for="id">ID:</label></td>
							<td><input type="text" name="id" id="id" placeholder="Identity Number"></td>
						</tr>
						<tr>
							<td><label for="password">Password:</label></td>
							<td><input type="password" name="password" id="password" placeholder="Password"></td>
						</tr>
						<tr>
							<td colspan="2" align="right"><input type="submit" name="submit" id="submit" value="Sign in"></td>
						</tr>
					</table>
				</form>
			</fieldset>
		</div>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp technology
	</footer>
</body>

</html>