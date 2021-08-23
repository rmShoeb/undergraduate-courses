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



	//keep the id
	$temp=mysqli_query($link, 'SELECT id FROM office');
	$id=mysqli_fetch_array($temp);
	$roll=1603013;
	$demi_roll="d__1603013";




	//sign in part
	if(isset($_REQUEST['enter']))
	{
		if((!isset($_POST['id'])) or (!isset($_POST['password'])))
		{
			$error='Enter both Id and Password.';
			include 'sign_in.php';
		}
		else
		{
			$information=mysqli_query($link,'SELECT id, password FROM office');
			if(!$information)
			{
				$error='Unable to continue';
				include 'sign_in.php';
				exit();
			}
			$fetch=mysqli_fetch_array($information);
			if(($_REQUEST['id']==$fetch['id']) and ($_REQUEST['password']==$fetch['password']))
			{
				session_start();
				$_SESSION['admin']=$_REQUEST['id'];
				//counts total requests
				$temp=mysqli_query($link,'SELECT * FROM pending');
				$total_request=mysqli_num_rows($temp);
				//to pass the information about instruments to the next page
				$temp=mysqli_query($link,'SELECT * FROM instrument_info');
				//all the required data are now going to be passed to the page down here
				include 'control_room.php';
			}
			else
			{
				$error='Wrong id or password. Try again with correct information.';
				include 'sign_in.php';
			}
		}
	}





	
	//change office info
	else if(isset($_REQUEST['change_info']))
	{
		include 'change_info.php';
	}
	else if(isset($_REQUEST['change']))
	{
		$change_error='';
		$temp=mysqli_query($link,'SELECT password FROM office');
		$pass=mysqli_fetch_array($temp);
		if(!isset($_REQUEST['password']) or $_REQUEST['password']=='')
		{
			$change_error=$change_error.'Current Password is required to change any field.<br>';
		}
		else if($_REQUEST['password']!=$pass['password'])
		{
			$change_error.='Enter current password correctly.<br>';
		}
		else
		{
			$success='';
			if(isset($_REQUEST['phone']) and $_REQUEST['phone']!='')
			{
				$temp=mysqli_query($link,'UPDATE office SET phone='.$_REQUEST['phone'].' WHERE id='.$id['id']);
				if(!$temp)
					$change_error.='Error changing phone number.<br>';
				else
					$success.='Phone number successfully changed.<br>';
			}
			if(isset($_REQUEST['email']) and $_REQUEST['email']!='')
			{
				$temp=mysqli_query($link,'UPDATE office SET email='.$_REQUEST['email'].' WHERE id='.$id['id']);
				if(!$temp)
					$change_error.='Error changing email.<br>';
				else
					$success.='Eamil successfully changed.<br>';
			}
			if(isset($_REQUEST['new_password']) and ($_REQUEST['new_password']==$_REQUEST['con_new_password']) and $_REQUEST['new_password']!='')
			{
				$temp=mysqli_query($link,'UPDATE office SET password='.$_REQUEST['new_password'].' WHERE id='.$id['id']);
				if(!$temp)
					$change_error.='Error changing password.<br>';
				else
					$success.='Password successfully changed.<br>';
			}
		}
		include 'change_info.php';
	}
	else if(isset($_REQUEST['return_home']))
	{
		$temp=mysqli_query($link,'SELECT * FROM pending');
		$total_request=mysqli_num_rows($temp);
		$temp=mysqli_query($link,'SELECT * FROM instrument_info');
		include 'control_room.php';
	}





	//getting officer history
	else if(isset($_REQUEST['officer_history']))
	{
		$temp=mysqli_query($link,'SELECT name, joindate FROM officer');
		include 'officer_history.php';
	}





	//request checking part
	else if(isset($_REQUEST['requests']))
	{
		$temp=mysqli_query($link,'SELECT * FROM pending');
		include 'pending.php';
	}
	else if(isset($_REQUEST['action']))
	{
		$serial=$_REQUEST['serial'];
		$temp=mysqli_query($link, 'SELECT * FROM pending WHERE serial='.$serial);
		$data=mysqli_fetch_array($temp);
		$instrument=$data['instrument_name'];
		$amount=$data['amount'];
		$request_time=$data['return_time'];
		$request_date=$data['request_date'];
		$collect_date=$data['collect_date'];
		$collect_time=$data['collect_time'];
		$return_time=$data['return_time'];
		if($_REQUEST['action']=='Allow')
		{
			$history=mysqli_query($link,"INSERT INTO history SET
										request_from='$roll',
										instrument_name='$instrument',
										amount='$amount',
										request_date='$request_date',
										request_time='$request_time',
										collect_date='$collect_date',
										collect_time='$collect_time',
										return_time='$return_time',
										decision='1',
										check_time=CURTIME()");
			$student=mysqli_query($link,"UPDATE d__1603013 SET issue='1' WHERE return_time='$return_time'");
		}
		else    			//which means admin has denied the request
		{
			$history=mysqli_query($link,"INSERT INTO history SET
										request_from='$roll',
										instrument_name='$instrument',
										amount='$amount',
										request_date='$request_date',
										request_time='$request_time',
										collect_date='$collect_date',
										collect_time='$collect_time',
										return_time='$return_time',
										decision='0',
										check_time=CURTIME()");
			$student=mysqli_query($link,"UPDATE d__1603013 SET issue='0' WHERE return_time='$return_time'");
		}
		$delete=mysqli_query($link,'DELETE FROM pending WHERE serial='.$serial);
		$temp=mysqli_query($link,'SELECT * FROM pending');
		include 'pending.php';
	}





	//issued request filtering part
	else if(isset($_REQUEST['filter']))
	{
		if(isset($_REQUEST['roll']) and $_REQUEST['roll']!='')
		{
			if($_REQUEST['instrument']=='all')
				$temp=mysqli_query($link,'SELECT * FROM history WHERE request_from='.$_REQUEST['roll']);
			else
				$temp=mysqli_query($link,'SELECT * FROM history WHERE instrument_name='.$_REQUEST['instrument'].'and request_from='.$_REQUEST['roll']);
		}
		else
		{
			if($_REQUEST['instrument']=='all')
				$temp=mysqli_query($link,'SELECT * FROM history');
			else
				$temp=mysqli_query($link,'SELECT * FROM history WHERE instrument_name='.$_REQUEST['instrument']);
		}
		include 'issue_history.php';
	}



/*
	///instrument returned
	else if(isset($_REQUEST['']))*/




	//add new instruments
	else if(isset($_REQUEST['add_new_instrument']))
	{
		include 'add_new_instrument.php';
	}
	else if(isset($_REQUEST['insert_instrument']))
	{
		$sql='INSERT INTO new_instrument SET
				tender_no="'.$_REQUEST['tender_no'].'",
				add_date=CURDATE(),
				fixed_weight_dumbbell="'.$_REQUEST['fixed_weight_dumbbell'].'",
				adjustable_dumbbell="'.$_REQUEST['adjustable_dumbbell'].'",
				ez_curlbar="'.$_REQUEST['ez_curl_bar'].'",
				fixed_barbell="'.$_REQUEST['fixed_barbell'].'",
				thick_handled_barbell="'.$_REQUEST['thick_handled_barbell'].'",
				triceps_bar="'.$_REQUEST['triceps_bar'].'",
				kettlebell="'.$_REQUEST['kettlebell'].'",
				cin_up_bar="'.$_REQUEST['cin_up_bar'].'",
				treadmill="'.$_REQUEST['treadmill'].'",
				spin_bike="'.$_REQUEST['spin_bike'].'",
				sandbag="'.$_REQUEST['sandbag'].'",
				football="'.$_REQUEST['football'].'"';
		$add_new__error='';
		if(!mysqli_query($link,$sql))
			$add_new__error.='Error inserting data. '.mysqli_error($link);
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['fixed_weight_dumbbell'].'" WHERE instrument_name="Fixed weight dumbbell"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['adjustable_dumbbell'].'" WHERE instrument_name="Adjustable dumbbell"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['ez_curl_bar'].'" WHERE instrument_name="EZ Curlbar"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['fixed_barbell'].'" WHERE instrument_name="Fixed barbell"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['thick_handled_barbell'].'" WHERE instrument_name="Thick-handled barbell"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['triceps_bar'].'" WHERE instrument_name="Triceps bar"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['kettlebell'].'" WHERE instrument_name="Kettlebell"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['cin_up_bar'].'" WHERE instrument_name="Chin-up bar"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['treadmill'].'" WHERE instrument_name="Treadmill"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['spin_bike'].'" WHERE instrument_name="Spin bike"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['sandbag'].'" WHERE instrument_name="Sandbag"';
		$sql='UPDATE instrument_info SET ammount="+'.$_REQUEST['football'].'" WHERE instrument_name="Football"';
		include 'add_new_instrument.php';
	}
	else if(isset($_REQUEST['previous_add']))
	{
		$temp=mysqli_query($link,'SELECT * FROM new_instrument');
		include 'previous_add.php';
	}







	//logout
	else if(isset($_REQUEST['logout']))
	{
		unset($_SESSION['admin']);
		include 'sign_in.php';
	}






	//if nothing matched, means user is not logged in, so,
	else
		include 'sign_in.php';
?>