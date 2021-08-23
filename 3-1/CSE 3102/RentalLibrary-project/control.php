<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <title>Control Panel</title>
  </head>
  <body>
    <nav class="navbar navbar-dark bg-dark">
      <div class="container">
        <a href="#" class="navbar-brand">Rental Library Management</a>
      </div>
    </nav>

    <div class="container" style="text-align: center;">
    	<div class="jumbotron">
	        <h1 class="display-4">Welcome to Rental Library Management</h1>
	        <p class="lead">Some demo text: Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.</p>
	        <hr class="my-4">

	        <!-- add member button -->
	        <a href="#member_add" class="btn btn-primary btn-lg" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Add a member</a>
	        <!-- add student button -->
	        <a href="#student_add" class="btn btn-primary btn-lg" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Add a Student</a><br>
	        <p style="margin: 10px;"></p>

            <!-- the message to be shown due to failure during member addition -->
            <?php 
                if(isset($InsertMemberErrorMessage))
                {?>
                    <p class="alert alert-danger" role="alert">
                        <?php
                            echo $InsertMemberErrorMessage;
                        ?>
                    </p>
                <?php }
            // message to be shown in case of succes
                else
                ?>
            <p class="alert alert-success" role="alert">
                <?php 
                    echo "Member added to the database.";
                ?>
            </p>

            <!-- the message to be shown if any error rises while inserting a student data into the database -->
            <?php 
                if(isset($InsertStudentErrorMessage))
                {?>
                    <p class="alert alert-danger" role="alert">
                        <?php
                            echo $InsertStudentErrorMessage;
                        ?>
                    </p>
                <?php }
            // message to be shown in case of succes
                else
                ?>
            <p class="alert alert-success" role="alert">
                <?php 
                    echo "Student added to the database.";
                ?>
            </p>

	        <!-- add member collapsible form -->
	        <div class="collapse" id="member_add">
	        	<form action="?member_add" method="post">
	        		<div class="form-group" style="margin-left: 30%; margin-right: 30%">
	        			<input class="form-control" type="text" name="member_id" placeholder="Member ID" maxlength="5" required>
	        			<input type="text" class="form-control" name="student_id" placeholder="Student ID" maxlength="8" required>
	        			<input type="submit" name="" class="btn btn-success btn-lg" value="ADD">
	        		</div>
	        	</form>
	        </div>

	        <!-- add student collapsible form -->
	        <div class="collapse" id="student_add">
	        	<form action="?student_add" method="post">
	        		<div class="form-group" style="margin-left: 30%; margin-right: 30%">
	        			<input class="form-control" type="text" name="student_id" placeholder="Student ID" maxlength="8" required>
	        			<input type="text" class="form-control" name="student_name" placeholder="Student Name" maxlength="45" required>
	        			<!-- <a href="#" class="btn btn-lg btn-success">ADD</a> -->
	        			<input type="submit" name="" class="btn btn-success btn-lg" value="ADD">
	        		</div>
	        	</form>
	        </div>

	        <p style="margin: 10px;"></p>

	        <!-- member remove button -->
	        <a href="#member_remove" class="btn btn-warning btn-lg" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Remove a Member</a>

	        <!-- student remove button -->
	        <a href="#student_remove" class="btn btn-warning btn-lg" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Remove a student</a>
	        <p style="margin: 10px;"></p>

            <!-- the message to be shown due to failure during member removal -->
            <?php 
                if(isset($DeleteMemberErrorMessage))
                {?>
                    <p class="alert alert-danger" role="alert">
                        <?php
                            echo $DeleteMemberErrorMessage;
                        ?>
                    </p>
                <?php }
            // message to be shown in case of succes
                else
                ?>
            <p class="alert alert-success" role="alert">
                <?php 
                    echo "Member removed from the databse.";
                ?>
            </p>

            <!-- the message to be shown if any error rises while deleting a student data into the database -->
            <?php 
                if(isset($DeleteStudentErrorMessage))
                {?>
                    <p class="alert alert-danger" role="alert">
                        <?php
                            echo $DeleteStudentErrorMessage;
                        ?>
                    </p>
                <?php }
            // message to be shown in case of succes
                else
                ?>
            <p class="alert alert-success" role="alert">
                <?php 
                    echo "Student removed from the database.";
                ?>
            </p>

	        <!-- member remove collapsible form -->
	        <div class="collapse" id="member_remove" style="margin-left: 35%; margin-right: 30%">
	        	<form action="?member_remove" method="post" class="form-inline">
	        		<div class="form-group">
	        			<input type="text" name="member_id" class="form-control" placeholder="Member ID" maxlength="5" required>
	        			<input type="submit" name="" class="btn btn-danger btn-lg" value="REMOVE">
	        		</div>
	        	</form>
	        </div>
	        <p style="margin: 10px;"></p>

	        <!-- student remove collapsible form -->
	        <div class="collapse" id="student_remove" style="margin-left: 35%; margin-right: 30%">
	        	<form action="?student_remove" method="post" class="form-inline">
	        		<div class="form-group">
	        			<input type="text" name="student_id" class="form-control" placeholder="Student ID" maxlength="8" required>
	        			<input type="submit" name="" class="btn btn-danger btn-lg" value="REMOVE">
	        		</div>
	        	</form>
	        </div>
    	</div>
    </div>


	<!-- here comes the real tasks from the lab -->
    <div class="container">
    	<!-- special task -->
        <!-- a new book is added to the database -->
        <div>
            <p class="alert alert-info" role="role">Add a new book:</p>
            <form action="?AddBook" method="post">
                <div class="form-group">
                    <input type="text" name="book_id" placeholder="Book ID" class="form-control" maxlength="5" required>
                    <input type="text" name="book_name" placeholder="Book Title" class="form-control" maxlength="45" required>
                    <input type="text" name="author" placeholder="Author" class="form-control" maxlength="45" required>
                    <input type="submit" name="" class="btn btn-success btn-lg" value="ADD BOOK">
                </div>
            </form>
        </div>
        <!-- a book is to be issued -->
        <div>
            <p class="alert alert-info" role="alert">Issue a book:</p>
            <form action="?issue_book" method="post">
                <div class="form-group">
                    <!-- we are not going to ask for the iss_no because it is set to be auto incremented in the database. so no need to insert it. -->
                    <!-- we are not going to be ask for issue date, because in the backend, we will save the date as cuurent date. oviously we are going to issue book for that day, not any other. -->
                    <input type="text" name="mem_no" placeholder="Member ID" class="form-control" maxlength="5" required>
                    <input type="text" name="book_no" placeholder="Book ID" class="form-control" maxlength="5" required>
                    <input type="submit" name="" class="btn btn-success btn-lg" value="ISSUE">
                </div>
            </form>
        </div>
        <p style="margin: 20px;"></p>

        <!-- a book is to be returned -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">Book returned:</p>
    		<p style="margin: 20px;"></p>
    		<form action="?book_return" method="post" class="form-inline">
    			<div class="form-group">
    				<input type="text" name="iss_no" placeholder="Issue No" class="form-control" required>
    				<input type="submit" name="" class="btn btn-success btn-lg" value="RETURN">
    			</div>
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>
        <?php 
                if(isset($BookReturnErrorMessage))
                {?>
                    <p class="alert alert-danger" role="alert">
                        <?php
                            echo $BookReturnErrorMessage;
                        ?>
                    </p>
                <?php }
            // message to be shown in case of succes
                else
                ?>
            <p class="alert alert-success" role="alert">
                <?php 
                    echo "Database updated successfully.";
                ?>
            </p>

    	<!-- task-1 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">List all the <strong>student</strong> and <strong>book name, author</strong> issued on: </p>
    		<p style="margin: 15px;"></p>
    		<form action="?IssuedOnSpecificDate" method="post" class="form-inline">
				<div class="form-group">
					<input type="date" name="date" class="form-control" required>
					<input type="submit" name="" class="btn btn-info btn-lg" value="FIND">
    			</div>
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>

    	<!-- task-2 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">List the details of <strong>students</strong> who borrowed the book of: </p>
    		<p style="margin: 20px;"></p>
    		<form action="?SpecificAuthor" method="post" class="form-inline">
				<div class="form-group">
					<input type="text" name="author_name" class="form-control" placeholder="Author Name" required>
					<input type="submit" name="" class="btn btn-info btn-lg" value="FIND">
    			</div>
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>

    	<!-- task-3 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">Give a <strong>count</strong> of <strong>how many books</strong> have been borrowed by each student.</p>
    		<p style="margin: 20px;"></p>
    		<form action="?EachStudentBookBorrowedCount" method="post">
    			<input type="submit" name="" class="btn btn-info btn-lg" value="GO">
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>

    	<!-- task-4 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">List the <strong>students</strong> who reached the borrowed limit 3:</p>
    		<p style="margin: 20px;"></p>
    		<form action="?ListLimitReached" method="post">
    			<input type="submit" name="" class="btn btn-info btn-lg" value="GO">
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>

    	<!-- task-5 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">List the <strong>books</strong> taken by:</p>
    		<p style="margin: 20px;"></p>
    		<form action="?BookTakenBySpecificStudent" method="post" class="form-inline">
    			<div>
    				<input type="text" name="student_id" placeholder="Student ID" maxlength="8" class="form-control" required>
    				<input type="submit" name="" class="btn btn-info btn-lg" value="FIND">
    			</div>
    		</form>
            <table class="table table-hover">
                <thead>
                    <tr>
                        <th scope="col">Book Title</th>
                    </tr>
                </thead>
                <tbody>
                    <?php
                    for($i=0; $i<$TotalRows; $i++) ?>
                        <tr><td><?php echo $Books[$i]; ?></td></tr>
                </tbody>
            </table>
    	</div>
    	<p style="margin: 20px;"></p>

    	<!-- task-6 -->
    	<div>
    		<p class="alert alert-info d-inline" role="alert">List the <strong>book details issued as of today:</strong></p>
    		<p style="margin: 20px;"></p>
    		<form action="?IssuedToday" method="post">
    			<input type="submit" name="" class="btn btn-info btn-lg" value="GO">
    		</form>
    	</div>
    	<p style="margin: 20px;"></p>
    </div>

    <!-- footer -->
    <footer class="bg-secondary">
    	<div class="container">
    		<p style="text-align: center;">@Rental Library Management</p>
    	</div>
    </footer>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
