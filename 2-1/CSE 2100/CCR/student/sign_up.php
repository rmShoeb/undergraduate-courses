<!DOCTYPE html>
<html lang="en">

<head>
  <meta http-equiv="content-type" content="text/html" charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Sign up</title>
  <link rel="stylesheet" href="../w3.css">
  <title>Register</title>
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
	<div>
	  <div class="w3-row">
	    <div class="w3-col s3" style="min-height:280px;border-right:8px solid white;">
	    	<fieldset style="margin-left: 10px;margin-right: 10px;margin-top: 5px;">
	    		<legend>Instructions</legend>
	    		<ol>
	    			<li>Make sure no field is empty.</li>
	    			<li>Make sure you have typed in your roll number in full length i.e. 1603xxx.</li>
	    			<li>Do not use any phone number that is not active.</li>
	    			<li>Use a strong password which you can remember easily.</li>
	    		</ol>
	    	</fieldset>
	    </div>
	    <div class="w3-col s9" style="min-height:280px;">
	    	<fieldset style="margin-left: 20px;margin-right: 20px;margin-top: 5px">
	    		<legend>Fill in the form</legend>
	    		<p style="color: red;">
	    			<?php
		    			if(isset($sign_up_error))
		    				echo $sign_up_error;
		    		?>
	    		</p>
	    		<form method="post" action="?register">
	    			<table>
	    				<tr>
	    					<td><label for="roll">Roll no.:</label></td>
	    					<td><input type="text" name="roll" id="roll" placeholder="Roll Number" maxlength="7"></td>
	    				</tr>
	    				<tr>
	    					<td><label for="mobile">Mobile:</label></td>
	    					<td><input type="text" name="mobile" id="mobile" placeholder="Mobile Number" maxlength="14"></td>
	    				</tr>
	    				<tr>
	    					<td><label for="email">Email:</label></td>
	    					<td><input type="email" name="email" id="email" placeholder="email"></td>
	    				</tr>
	    				<tr>
	    					<td><label for="password">Password:</label></td>
	    					<td><input type="password" name="password" id="password" placeholder="Password" maxlength="32"></td>
	    				</tr>
	    				<tr>
	    					<td><label for="con_password">Confirm Password:</label></td>
	    					<td><input type="password" name="con_password" id="con_password" placeholder="Confirm Password" maxlength="32"></td>
	    				</tr>
	    				<tr>
	    					<td colspan="2" align="right"><input type="submit" name="register" id="register" value="Register"></td>
	    				</tr>
	    			</table>
	    		</form>
	    	</fieldset>
	    </div>
	  </div>
	</div>
	<footer>
		&copyRajshahi University of Engineering &amp Technology
	</footer>
</body>
</html>