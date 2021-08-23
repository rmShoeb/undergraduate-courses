<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Sign in</title>
  <link rel="stylesheet" href="../w3.css">
	<style>
	.w3-col {background-color:#e5e5e5}
	header{background-color: teal;}
	footer
	{
		background-color: black;
		color: white;
		font-size: 0.7em;
		text-align: center;
	}
	</style>
	<title>Sign in</title>
</head>

<body>
	<header>
		<img src="../ruet.png">
	</header>
	<div>
		<div class="w3-col" style="min-height:300px;">
			<p style="color: red; text-align: center;">
				<?php
					if(isset($sign_in_error))
						echo $sign_in_error;
					if(isset($error))
						echo $error;
				?>
			</p>
			<fieldset style="margin-left: 500px;margin-right: 500px;margin-top: 50px;">
				<legend>Sign in</legend>
				<form action="?sign_in" method="post">
					<table>
						<tr>
							<td><label for="roll">Roll no.:</label></td>
							<td><input type="text" name="roll" id="roll" placeholder="Roll Number" maxlength="7"></td>
						</tr>
						<tr>
							<td><label for="password">Password:</label></td>
							<td><input type="password" name="password" id="password" placeholder="Password"></td>
						</tr>
						<tr>
							<td colspan="2" align="right"><input type="submit" name="submit" id="submit" value="Sign In"></td>
						</tr>
						<tr>
							<td colspan="2" align="center">Not registered? <a href="?sign_up" style="color: blue;">Register</a></td>
						</tr>
					</table>
				</form>
			</fieldset>
		</div>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>

</html>