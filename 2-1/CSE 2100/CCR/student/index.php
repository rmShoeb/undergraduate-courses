<?php
	//databse connection start
	$link=mysqli_connect('localhost','root','');	//to check if connection to server was successful
	if(!$link)										//if not, kill the page
	{
		$error='Could not connect to server.';		//this variable will carry an error massage to the preceeding page
		include 'sign_in.php';
		exit();
	}
	if(!mysqli_set_charset($link,'utf8'))			//to encode all the data in the right way
	{
		$error='Unable to continue.';
		include 'sign_in.php';
		exit();										//if not successful, kill the page
	}
	if(!mysqli_select_db($link,'project'))			//to connect to the desired databse
	{
		$error='Could not connect to database';
		include 'sign_in.php';
		exit();										//if failed, kill the page
	}
	//databse connected




	$roll=1603013;
	$demi_roll='d__1603013';



	


	//authentication for user to sign in
	if(isset($_REQUEST['sign_in']))
	{
		if(isset($_REQUEST['roll']) and $_REQUEST['roll']!='' and isset($_REQUEST['password']) and $_REQUEST['password']!='')
		{
			$roll=$_REQUEST['roll'];
			$demi_roll='d__'.$roll;
			$sign_in_error='';
			$sql=mysqli_query($link,'SELECT password FROM student WHERE roll_no='.$roll);
			if(!$sql)
			{
				$sign_in_error.='Roll does no exist.<br>';
				include 'sign_in.php';
				exit();
			}
			$password=mysqli_fetch_array($sql);
			if($_REQUEST['password']!=$password['password'])
			{
				$sign_in_error.='Wrong password.<br>';
				include 'sign_in.php';
				exit();
			}
			session_start();
			$_SESSION['student']=$roll;
			$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
			include 'student.php';
		}
	}





	//new user found
	else if(isset($_REQUEST['sign_up']))
	{
		include 'sign_up.php';
	}
	else if(isset($_REQUEST['register']))
	{
		if(isset($_REQUEST['roll']) and $_REQUEST['roll']!='' and
			isset($_REQUEST['mobile']) and $_REQUEST['mobile']!='' and
			isset($_REQUEST['email']) and $_REQUEST['email']!='' and
			isset($_REQUEST['password']) and $_REQUEST['password']!='' and
			isset($_REQUEST['con_password']) and $_REQUEST['con_password']!='' and
			$_REQUEST['password']==$_REQUEST['con_password'])
		{
			$roll=$_REQUEST['roll'];
			$demi_roll='d__'.$roll;
			$create_table=mysqli_query($link,'CREATE TABLE '.$demi_roll.'('.
											'input_no INT NOT NULL AUTO_INCREMENT PRIMARY KEY,'.
						 					'booking_date DATE,'.
						 					'booking_time TIME,'.
						 					'instrument_name CHAR(32),'.
						 					'amount INT,'.
						 					'collect_date DATE,'.
						 					'collect_time TIME,'.
						 					'return_time TIME,'.
						 					'issue INT'.
						 					')DEFAULT CHARSET utf8');
			$sign_up_error='';
			if(!$create_table)
			{
				$sign_up_error.='Error creating table<br>';
				include 'sign_up.php';
				exit();
			}

			$password=$_REQUEST['password'];
			$phone=$_REQUEST['mobile'];
			$email=$_REQUEST['email'];

			$create_account=mysqli_query($link,"INSERT INTO student (roll_no, password, phone, email) VALUES('$roll','$password','$phone','$email')");
			/*$create_account=mysqli_query($link,'INSERT INTO student SET 
												roll_no='.$roll.',
												password='.$_REQUEST['password'].',
												phone='.$_REQUEST['mobile'].',
												email='.$_REQUEST['email']);*/
			if(!$create_account)
			{
				$sign_up_error.='Could not create account.<br>';
				include 'sign_up.php';
				exit();
			}
			session_start();
			$_SESSION['student']=$roll;
			$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
			include 'student.php';
		}
		else
		{
			$sign_up_error='Every field is required.';
			include 'sign_up.php';
		}
	}







	//profile page
	//student can change email address, phone number and password here.
	else if(isset($_REQUEST['profile']))
	{
		$sql=mysqli_query($link, "SELECT email, phone FROM student WHERE roll_no='$roll'");
		include 'profile.php';
	}
	else if(isset($_REQUEST['change']))
	{
		if(isset($_REQUEST['change_phone']) and $_REQUEST['change_phone']!='')
			$sql=mysqli_query($link,'UPDATE student SET phone='.$_REQUEST['phone'].' WHERE roll_no='.$roll);
		if(isset($_REQUEST['change_email']) and $_REQUEST['change_email']!='')
			$sql=mysqli_query($link,'UPDATE student SET email='.$_REQUEST['change_email'].' WHERE roll_no='.$roll);
		if(isset($_REQUEST['change_password']) and $_REQUEST['change_password']!='')
			$sql=mysqli_query($link,'UPDATE student SET password='.$_REQUEST['change_password'].' WHERE roll_no='.$roll);
		$sql=mysqli_query($link, 'SELECT email, phone FROM student WHERE roll_no='.$roll);
		include 'profile.php';
	}
	else if(isset($_REQUEST['return']))
	{
		$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
		include 'student.php';
	}







	//booking page
	else if(isset($_REQUEST['booking']))
	{
		include 'booking.php';
	}
	else if(isset($_REQUEST['cancel']))
	{
		$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
		include 'student.php';
	}
	else if(isset($_REQUEST['book']))
	{
		/*$sql=mysqli_query($link,'INSERT INTO pending SET
								request_from='.$roll.',
								request_date=CURDATE(),
								request_time=CURTIME(),
								instrument_name='.$_REQUEST['instrument'].',
								amount='.$_REQUEST['amount'].',
								collect_date='.$_REQUEST['date'].',
								collect_time='.$_REQUEST['collect_time'].',
								return_time='.$_REQUEST['return_time']);*/
		$instrument=$_REQUEST['instrument'];
		$amount=$_REQUEST['amount'];
		$collect_date=$_REQUEST['date'];
		$collect_time=$_REQUEST['collect_time'];
		$return_time=$_REQUEST['return_time'];

		$sql=mysqli_query($link,"INSERT INTO pending (request_from, request_date, request_time, instrument_name, amount, collect_date, collect_time, return_time) VALUES('$roll', 'CURDATE()', 'CURTIME()', '$instrument', '$amount', '$collect_date', '$collect_time', '$return_time')");
		/*$sql=mysqli_query($link,'INSERT INTO '.$demi_roll.' SET
								booking_date=CURDATE(),
								booking_time=CURTIME(),
								instrument_name='.$_REQUEST['instrument'].',
								amount='.$_REQUEST['amount'].',
								collect_date='.$_REQUEST['date'].',
								collect_time='.$_REQUEST['collect_time'].',
								return_time='.$_REQUEST['return_time']);*/
		$sql=mysqli_query($link, "INSERT INTO d__1603013 (booking_date, booking_time, instrument_name, amount, collect_date, collect_time, return_time) VALUES('CURDATE()', 'CURTIME()', '$instrument', '$amount', '$collect_date', '$collect_time', '$return_time')");
		$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
		include 'student.php';
	}





	///refresh the homepage
	else if(isset($_REQUEST['refresh']))
	{
		$sql=mysqli_query($link, 'SELECT * FROM '.$demi_roll.' ORDER BY input_no DESC LIMIT 10');
		include 'student.php';
	}






	//logout
	else if(isset($_REQUEST['logout']))
	{
		unset($_SESSION['student']);
		include 'sign_in.php';
	}





	//nothing matched, means user is not signed in, so
	else
	{
		include 'sign_in.php';
	}
?>