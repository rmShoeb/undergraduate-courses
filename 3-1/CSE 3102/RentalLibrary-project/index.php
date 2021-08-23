<?php
	
	// connecting to the host
	$link = mysqli_connect('localhost', 'root', '');
	if(!$link)
	{
		$ErrorMessage = "Failed to connect to the server.";
		include 'unable.html.php';
		exit();
	}

	// defining charcter set to be used
	if(!(mysqli_set_charset($link, 'utf8')))
	{
		$ErrorMessage = "Failed to set up environment.";
		include 'unable.html.php';
		exit();
	}

	// connecting to the desired database
	if(!(mysqli_select_db($link, 'student_rental_library')))
	{
		$ErrorMessage = "Failed to connect to the database.";
		include 'unable.html.php';
		exit();
	}

	// processing the request of adding a new member to the table
	if(isset($_REQUEST['member_add']))
	{
		// add student to the member table
		$query = 'INSERT INTO membership VALUES("'.$_REQUEST['member_id'].'", "'.$_REQUEST['student_id'].'")';
		$result = mysqli_query($link, $query);
		// throw an error message if student does not exist or insertion fails
		if(!($result))
		{
			$InsertMemberErrorMessage = 'Member add failed: '.mysqli_error($link);
		}
		// include 'control.php';
		header('Location: .');
		exit();
	}

	//processing the request of adding a new student to the database
	if(isset($_REQUEST['student_add']))
	{
		// check if the student ID starts with 'C' or not
		// but the table already has a trigger for that
		// so, i'll just use that
		$query = 'INSERT INTO student VALUES("'.$_REQUEST['student_id'].'", "'.$_REQUEST['student_name'].'")';
		$result = mysqli_query($link, $query);
		if(!$result)
		{
			$InsertStudentErrorMessage = 'Student add failed: '.mysqli_error($link);
		}
		header('Location: .');
		exit();
	}

	//processing the request of removing a member
	if(isset($_REQUEST['member_remove']))
	{
		// have to delete the member from the 'membership' table
		$query = 'DELETE FROM membership WHERE mem_no = "'.$_REQUEST['member_id'].'"';
		$result = mysqli_query($link, $query);
		if(!$result)
		{
			$DeleteMemberErrorMessage = 'Member remove from membership table failed: ' . mysqli_error($link);
			header('Location: .');
			exit();
		}
		// also, delete all the record of that member from the 'iss_rec' table corresponding to the member
		$query = 'DELETE FROM iss_rec WHERE mem_no = "'.$_REQUEST['member_id'].'"';
		$result = mysqli_query($link, $query);
		if(!$result)
			$DeleteMemberErrorMessage = 'Removing issue record of the member failed: ' . mysqli_error();
		// in case, the first query succeds but the second doesn't, well, i guess it will have to be done manually
		header('Location: .');
		exit();
	}

	// processing the request of removing a student from the database
	if(isset($_REQUEST['student_remove']))
	{
		// remove students issue record, if exists
		$query = 'DELETE FROM iss_rec WHERE iss_rec.mem_no = membership.mem_no AND membership.stud_no = "'.$_REQUEST['student_id'].'"';
		$result = mysqli_query($link, $query);
		if(!$result)
		{
			$DeleteStudentErrorMessage = 'Deleting issue records of the student failed: ' . mysqli_error($link);
			header('Location: .');
			exit();
		}
		// remove membership of the student
		$query = 'DELETE FROM membership WHERE stud_no = "'.$_REQUEST['student_id'].'"';
		$result = mysqli_query($link, $query);
		if(!$result)
		{
			$DeleteStudentErrorMessage = 'Removing membership failed: ' . mysqli_error($link);
			header('Location: .');
			exit();
		}
		// finally, remove the student from the database;
		$query = 'DELETE FROM student WHERE stud_no = "'.$_REQUEST['student_id'].'"';
		$result = mysqli_query($link, $query);
		if(!$result)
			$DeleteStudentErrorMessage = 'Failed to remove student from the database: ' . mysqli_error($link);
		header('Location: .');
		exit();
	}

	//processing the request of adding a new book to the database
	if(isset($_REQUEST['AddBook']))
	{
		$query = 'INSERT INTO book VALUES("'.$_REQUEST['book_id'].'", "'.$_REQUEST['book_name'].'", "'.$_REQUEST['author'].'")';
		$result = mysqli_query($link, $query);

		// will do error handling later

		header('Location: .');
 	}

	// processing the request of issuing a book
	// i'm not sure if 'issuing' is even a word
	if(isset($_REQUEST['issue_book']))
	{
		$query = 'INSERT INTO iss_rec(iss_date, mem_no, book_no) VALUES(CURDATE(), "'.$_REQUEST['mem_no'].'", "'.$_REQUEST['book_no'].'")';
		$result = mysqli_query($link, $query);
		
		// will add error handling later
		
		header('Location: .');
		exit();
	}

	// processing the request of returning a book
	if(isset($_REQUEST['book_return']))
	{
		// delete the corresponding issue record
		$query = 'DELETE FROM iss_rec WHERE iss_no = "'.$_REQUEST['iss_no'].'"';
		$result = mysqli_query($link, $query);
		// throw an error if failed
		if(!$result)
			$BookReturnErrorMessage = 'Failed to update database: ' . mysqli_error($link);
		// return to the same page that requested the process
		header('Location: .');
		exit();
	}

	// processing the task 1
	if(isset($_REQUEST['IssuedOnSpecificDate']))
	{
		$query = 'SELECT student.stude_name, book.book_name, book.author FROM student, membership, book, iss_rec WHERE iss_rec = "'.$_REQUEST['date'].'" AND book.book_no = iss_rec.book_no AND membership.mem_no = iss_rec.mem_no AND student.stud_no = membership.stud_no';
		$result = mysqli_query($link, $query);

		// will add error handling later
		
		while($row = mysqli_fetch_array($result))
		{
			$StudentNames[] = $row['stude_name'];
			$BookNames[] = $row['book_name'];
			$Authors[] = $row['author'];
		}
		$Date = $_REQUEST['date'];
		include 'IssuedOnSpecificDate.html.php';
		exit();
	}

	// processing the task 2
	if(isset($_REQUEST['SpecificAuthor']))
	{
		$query = 'SELECT student.stud_no, student.stude_name FROM student WHERE book.author = "'.$_REQUEST['author_name'].'" AND iss_rec.book_no = book.book_no AND membership.mem_no = iss_rec.mem_no AND student.stud_no = membership.stud_no';
		$result = mysqli_query($link, $query);

		// wil do error handling later
		
		while($row = mysqli_fetch_array($result))
		{
			$StudentIDs[] = $row['stud_no'];
			$StudentNames[] = $row['stude_name'];
		}
		$Author = $_REQUEST['author_name'];
		include 'SpecificAuthor.html.php';
		exit();
	}


	// processing task-3
	if(isset($_REQUEST['EachStudentBookBorrowedCount']))
	{
		$query = 'SELECT student.stud_no, student.stude_name, COUNT(*) AS TotalBorrowed FROM student, membership, iss_rec WHERE iss_rec.mem_no = membership.mem_no AND membership.stud_no = student.stud_no GROUP BY iss_rec.mem_no';
		$result = mysqli_query($link, $query);

		//will do error handling later
		
		while($row = mysqli_fetch_array($result))
		{
			$StudentIDs[] = $row['stud_no'];
			$StudentNames[] = $row['stude_name'];
			$TotalBorrowed[] = $row['TotalBorrowed'];
		}
		include 'EachStudentBookBorrowedCount.html.php';
		exit();
	}

	// processing task-4
	if(isset($_REQUEST['ListLimitReached']))
	{
		$query = 'SELECT student.stud_no, student.stude_name FROM student, membership, iss_rec WHERE student.stud_no = membership.stud_no AND membership.mem_no = iss_rec.mem_no GROUP BY iss_rec.mem_no HAVING COUNT(*) = 3';
		$result = mysqli_query($link, $query);

		// will do error handling later
		
		while($row = mysqli_fetch_array($result))
		{
			$StudentIDs[] = $row['stud_no'];
			$StudentNames[] = $row['stude_name'];
		}
		include 'LimitReachedList.html.php';
		exit();
	}

	// processing task-5
	if(isset($_REQUEST['BookTakenBySpecificStudent']))
	{
		$query = 'SELECT book.book_name FROM student, membership, book, iss_rec WHERE student.stud_no = "'.$_REQUEST['student_id'].'" AND membership.stud_no = student.stud_no AND iss_rec.mem_no = membership.mem_no AND book.book_no = iss_rec.book_no';
		$result = mysqli_query($link, $query);

		// will do error handling later
		
		while($row = mysql_fetch_array($result))
			$Books[] = $row['book_name'];

		$TotalRows = count($Books);

		header('Location: .');
		exit();
	}

	// proceesing task-6
	if(isset($_REQUEST['IssuedToday']))
	{
		$query = 'SELECT DISTINCT(book.book_no), book.book_name, book.author FROM book, iss_rec WHERE iss_rec.book_no = book.book_no AND iss_rec.iss_date = CURRENT_DATE()';
		$result = mysqli_query($link, $query);

		// will do error handling later

		while($row = mysqli_fetch_array($result))
		{
			$BookIDs[] = $row['book_no'];
			$BookNames[] = $row['book_name'];
			$Authors[] = $row['author'];
		}

		include 'IssuedToday.html.php';
		exit();
	}

	// return to home request
	if(isset($_REQUEST['home']))
	{
		include 'control.php';
		exit();
	}
	
	include 'control.php';
?>
