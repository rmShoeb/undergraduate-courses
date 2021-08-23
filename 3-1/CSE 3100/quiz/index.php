<?php
	// =====================================================================
	// creating link to localhost
	// =====================================================================
	$link = mysqli_connect('localhost', 'root', '');

	// =====================================================================
	// selecting database
	// =====================================================================
	mysqli_select_db($link, 'quiz');


	// =====================================================================
	// handling routes
	// =====================================================================
	// =====================================================================
	// this request comes from the sign up form's page
	// =====================================================================
	if(isset($_REQUEST['SignInRequest']))
	{
		include 'SignIn.html.php';
		exit();
	}

	// =====================================================================
	// this request comes from the sign in page
	// only if a guest wnats become a user
	// =====================================================================
	if(isset($_REQUEST['SignUpRequest']))
	{
		$ErrorMessage = "";
		include 'SignUp.html.php';
		exit();
	}

	// =====================================================================
	// handling the request of a guest to become a user
	// =====================================================================
	if(isset($_REQUEST['SignUp']))
	{
		// $ErrorMessage = '';
		// $UserCount = 0;
		// chacking for duplication
		$query 	= 'SELECT * FROM userinfo WHERE StudentTeacherID = "'.$_REQUEST['UserID'].'"';
		$result = mysqli_query($link, $query);
		// $UserCount = mysqli_num_rows($result);
		if(mysqli_num_rows($result) > 0)
		{
			$ErrorMessage = "User already exists.";
			include 'SignUp.html.php';
			exit();
		}


		//as the user is not duplicate
		//we are going to (try to) sign him/her up
		$query = 'INSERT INTO userinfo(FirstName, LastName, StudentTeacherID, email, UserType, UserPassword) VALUES("'.$_REQUEST['FirstName'].'", "'.$_REQUEST['LastName'].'", "'.$_REQUEST['UserID'].'", "'.$_REQUEST['email'].'", "'.$_REQUEST['UserType'].'", "'.$_REQUEST['password'].'")';
		$result = mysqli_query($link, $query);
		if($result)
		{
			$query  = 'SELECT * FROM courses ORDER BY CourseID';
			$result = mysqli_query($link, $query);
			while($row = mysqli_fetch_array($result))
			{
				$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle' => $row['CourseTitle']);
			}
			if($_REQUEST['UserType'] == 'student')
			{
				$UserID = $_REQUEST['UserID'];
				include 'StudentHome.html.php';
				exit;
			}
			else
			{
				$UserID = $_REQUEST['UserID'];
				include 'TeacherHome.html.php';
				exit();
			}
		}
		else
		{
			$ErrorMessage = 'Failed to create account: ' . mysqli_error($link);
			include 'SignUp.html.php';
			exit();
		}
	}


	// =================================================================
	// handling the request of a potential user login
	// =================================================================

	if(isset($_REQUEST['SignIn']))
	{
		$query  = 'SELECT UserType, UserPassword FROM userinfo WHERE StudentTeacherID = "'.$_REQUEST['UserID'].'"';
		$result = mysqli_query($link, $query);

		//if the user does not exist
		if($result and (mysqli_num_rows($result) != 1))
		{
			$ErrorMessage = "ID does not exist";
			include 'SignIn.html.php';
			exit();
		}

		//if user exists and query succeeds
		//check if password is correct
		else if($result and (mysqli_num_rows($result) == 1))
		{
			$row = mysqli_fetch_array($result);
			if($row['UserPassword'] == $_REQUEST['password'])	//information is correct
			{
				$UserType 	= $row['UserType'];
				$UserID 	= $_REQUEST['UserID'];
				$query 		= 'SELECT * FROM courses ORDER BY CourseID';
				$result 	= mysqli_query($link, $query);
				while($row = mysqli_fetch_array($result))
				{
					$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle' => $row['CourseTitle']);
				}
				if($UserType == 'student')
				{
					$UserID = $_REQUEST['UserID'];
					include 'StudentHome.html.php';
					exit;
				}
				else
				{
					$UserID = $_REQUEST['UserID'];
					include 'TeacherHome.html.php';
					exit();
				}
			}
			else 			//password is incorrect
			{
				$ErrorMessage = 'Incorrect password';
				include 'SignIn.html.php';
				exit();
			}
		}

		//something unforseen happens
		else
		{
			$ErrorMessage = 'Failed to sign in: ' . mysqli_error($link);
			include 'SignIn.html.php';
			exit();
		}
	}



	// =============================================================
	// handling the requests coming from 'student-type' users
	// =============================================================
	if(isset($_REQUEST['StudentHome']))
	{
		$UserID 	= $_REQUEST['UserID'];
		$query 		= 'SELECT * FROM courses ORDER BY CourseID';
		$result 	= mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle'=> $row['CourseTitle']);
		}
		include 'StudentHome.html.php';
		exit();
	}
	
	if(isset($_REQUEST['ShowResults']))
	{
		$UserID = $_REQUEST['UserID'];
		$query  = 'SELECT quiz_data.NumberOfQuestions, quiz_data.SuccessfullAttempts, courses.CourseID FROM quiz_data, courses WHERE courses.id = quiz_data.CourseID AND UserID = "'.$UserID.'" ORDER BY quiz_data.QuizID DESC';
		$result = mysqli_query($link, $query);

		while($row = mysqli_fetch_array($result))
		{
			// $Scores[] = array("NumberOfQuestions"=>$row['NumberOfQuestions'], "SuccessfullAttempts"=>$row['SuccessfullAttempts'], "CourseID"=>$row['CourseID']);
			$Scores[] = $row;
		}

		include 'ShowResults.html.php';
		exit();
	}

	if (isset($_REQUEST['TakeQuiz']))
	{
		// queries and logics
		$query  = 'SELECT * FROM question WHERE CourseID = "'.$_REQUEST['CourseID'].'" ORDER BY RAND() LIMIT ' . $_REQUEST['NumberOfQuestions'];
		$result = mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$questions[] = $row;
		}
		
		$Time 		= $_REQUEST['NumberOfQuestions'] * 60;
		$UserID 	= $_REQUEST['UserID'];
		$CourseID 	= $_REQUEST['CourseID'];
		include 'QuizOngoing.html.php';
		exit();
	}



	if(isset($_REQUEST['CheckAnswers']))
	{
		$QuestionsAndAnswers 	= $_POST;
		$QuestionID 			= array_keys($QuestionsAndAnswers);
		$NumberOfQuestions		= sizeof($QuestionsAndAnswers);
		$SuccessfullAttempts	= 0;
		$CourseID 				= $_REQUEST['CourseID'];
		$StudentID 				= $_REQUEST['StudentID'];

		for($i=0; $i<$NumberOfQuestions; $i++)
		{
			$query 			= 'SELECT * FROM question WHERE QuestionID = "'.$QuestionID[$i].'"';
			$QuestionData 	= mysqli_fetch_array(mysqli_query($link, $query));
			$ResultArray[]	= array("QuestionText"=>$QuestionData['QuestionText'], "CorrectOption"=>$QuestionData['CorrectOption'], "AnsweredOption"=>$QuestionsAndAnswers["$QuestionID[$i]"], "1"=>$QuestionData['Option1'], "2"=>$QuestionData['Option2'], "3"=>$QuestionData['Option3'], "4"=>$QuestionData['Option4']);
			if($QuestionData['CorrectOption'] == $QuestionsAndAnswers["$QuestionID[$i]"])
				$SuccessfullAttempts++;
		}

		$Percentage = ($SuccessfullAttempts/$NumberOfQuestions)*100;

		$query  = 'INSERT INTO quiz_data(UserID, NumberOfQuestions, SuccessfullAttempts, CourseID) VALUES("'.$StudentID.'", "'.$NumberOfQuestions.'", "'.$SuccessfullAttempts.'", "'.$CourseID.'")';
		$result = mysqli_query($link, $query);

		include 'ShowResult.html.php';
		exit();
	}



	// =============================================================
	// handling the requests coming from 'teacher-type' users
	// =============================================================
	// add a new course
	if(isset($_REQUEST['AddCourse']))
	{
		//check if the course already exists or not
		$query = 'SELECT * FROM courses WHERE CourseID = "'.$_REQUEST['CourseID'].'"';
		if(mysqli_num_rows(mysqli_query($link, $query)) > 0)
		{
			$Message 	= 'Course already exists.';
			$query 		= 'SELECT * FROM courses ORDER BY CourseID';
			$result 	= mysqli_query($link, $query);
			while($row = mysqli_fetch_array($result))
			{
				$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle' => $row['CourseTitle']);
			}
			include 'TeacherHome.html.php';
			exit();
		}
		else
		{
			$query  = 'INSERT INTO courses(CourseID, CourseTitle) VALUES("'.$_REQUEST['CourseID'].'", "'.$_REQUEST['CourseTitle'].'")';
			$result = mysqli_query($link, $query);
			if($result)
			{
				$query  = 'SELECT * FROM courses ORDER BY CourseID';
				$result = mysqli_query($link, $query);
				while($row = mysqli_fetch_array($result))
				{
					$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle' => $row['CourseTitle']);
				}
				$Message = 'Course Added.';
				include 'TeacherHome.html.php';
				exit();
			}
			else
			{
				$Message = 'Failed to add Course to database: ' . mysqli_error($link);
				include 'TeacherHome.html.php';
				exit();
			}
		}
	}


	//show course details
	if(isset($_REQUEST['ShowDetails']))
	{
		// logics
		$query  = 'SELECT * FROM courses WHERE id = "'.$_REQUEST['ID'].'"';
		$Course = mysqli_fetch_array(mysqli_query($link, $query));
		$UserID	= $_REQUEST['UserID'];
		include 'CourseDetails.html.php';
		exit();
	}


	//add question and reroute to course details page
	if(isset($_REQUEST['AddQuestion']))
	{
		$query = 'INSERT INTO question(QuestionText, Option1, Option2, Option3, Option4, CorrectOption, CourseID) VALUES("'.$_REQUEST['question'].'", "'.$_REQUEST['Option1'].'", "'.$_REQUEST['Option2'].'", "'.$_REQUEST['Option3'].'", "'.$_REQUEST['Option4'].'", "'.$_REQUEST['CorrectAnswer'].'", "'.$_REQUEST['ID'].'")';
		if(mysqli_query($link, $query))
			$message = 'Question Added Successfully.';
		else
			$message = 'Failed to add question: ' . mysqli_error($link);
		$query  = 'SELECT * FROM courses WHERE id = "'.$_REQUEST['ID'].'"';
		$Course = mysqli_fetch_array(mysqli_query($link, $query));
		$UserID	= $_REQUEST['UserID'];
		include 'CourseDetails.html.php';
		exit();
	}




	// when teacher wants to visit the homepage
	if(isset($_REQUEST['TeacherHome']))
	{
		$UserID 	= $_REQUEST['UserID'];
		$query 		= 'SELECT * FROM courses ORDER BY CourseID';
		$result 	= mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$AvailableCourses[] = array('ID' => $row['id'], 'CourseID' => $row['CourseID'], 'CourseTitle' => $row['CourseTitle']);
		}
		include 'TeacherHome.html.php';
		exit();
	}




	// help the teacher to generate a quiz for his/her students
	if(isset($_REQUEST['GenerateQuiz']))
	{
		$CourseID 			= $_REQUEST['CourseID'];
		$NumberOfQuestions	= $_REQUEST['NumberOfQuestions'];
		$UserID				= $_REQUEST['UserID'];

		$query  = 'SELECT * FROM question WHERE CourseID = "'.$CourseID.'" ORDER BY RAND() LIMIT '.$NumberOfQuestions;
		$result = mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$questions[] = $row;
		}

		include 'GenerateQuiz.html.php';
		exit();
	}



	if(isset($_REQUEST['BrowseQuestions']))
	{
		$CourseID 			= $_REQUEST['CourseID'];
		$UserID				= $_REQUEST['UserID'];

		$query  = 'SELECT * FROM question WHERE CourseID = "'.$CourseID.'" ORDER BY QuestionID DESC';
		$result = mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$questions[] = $row;
		}

		include 'BrowseQuestions.html.php';
		exit();
	}



	if(isset($_REQUEST['GotoEditQuestion']))
	{
		$CourseID 		= $_REQUEST['CourseID'];
		$UserID			= $_REQUEST['UserID'];
		$QuestionID		= $_REQUEST['QuestionID'];


		$query 			= 'SELECT * FROM question WHERE QuestionID = "'.$QuestionID.'"';
		$result 		= mysqli_query($link, $query);
		if($result)
		{
			$row 		= mysqli_fetch_array($result);
			// $question[] = $row;

			include 'EditQuestion.html.php';
			exit();
		}
	}




	if(isset($_REQUEST['DeleteQuestion']))
	{
		$CourseID 		= $_REQUEST['CourseID'];
		$UserID			= $_REQUEST['UserID'];
		$QuestionID		= $_REQUEST['QuestionID'];


		$query 			= 'DELETE FROM question WHERE QuestionID = "'.$QuestionID.'"';
		if(mysqli_query($link, $query))
		{
			$query  	= 'SELECT * FROM question WHERE CourseID = "'.$CourseID.'" ORDER BY QuestionID DESC';
			$result 	= mysqli_query($link, $query);
			while($row = mysqli_fetch_array($result))
			{
				$questions[] = $row;
			}

			include 'BrowseQuestions.html.php';
			exit();
		}
	}




	if(isset($_REQUEST['EditQuestion']))
	{
		$QuestionID 	= $_REQUEST['QuestionID'];
		$QuestionText 	= $_REQUEST['question'];
		$Option1		= $_REQUEST['Option1'];
		$Option2		= $_REQUEST['Option2'];
		$Option3		= $_REQUEST['Option3'];
		$Option4		= $_REQUEST['Option4'];
		$CorrectOption	= $_REQUEST['CorrectAnswer'];
		$CourseID 		= $_REQUEST['CourseID'];
		$UserID 		= $_REQUEST['UserID'];

		$query 			=  'UPDATE question SET 
								QuestionText 	= "'.$QuestionText.'",
								Option1			= "'.$Option1.'",
								Option2 		= "'.$Option2.'",
								Option3 		= "'.$Option3.'",
								Option4 		= "'.$Option4.'",
								CorrectOption 	= "'.$CorrectOption.'"
							WHERE QuestionID 	= "'.$QuestionID.'"';

		if(mysqli_query($link, $query))
			$message 	= 'Question Added Successfully.';
		else
			$message 	= 'Failed to add question: ' . mysqli_error($link);

		$query  		= 'SELECT * FROM question WHERE CourseID = "'.$CourseID.'" ORDER BY QuestionID DESC';
		$result 		= mysqli_query($link, $query);
		while($row = mysqli_fetch_array($result))
		{
			$questions[] = $row;
		}

		include 'BrowseQuestions.html.php';
		exit();
	}





	//===========================================================
	// include this as default
	// ==========================================================
	include 'SignIn.html.php';
	exit();
?>