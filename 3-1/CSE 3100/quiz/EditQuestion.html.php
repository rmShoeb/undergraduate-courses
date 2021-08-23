<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <!-- google icons -->
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">

    <!-- google font -->
    <link href="https://fonts.googleapis.com/css?family=Fira+Code&display=swap" rel="stylesheet">
    <style type="text/css">
        body{font-family: 'Fira Code', monospace;}
    </style>

    <title>Questions - Edit</title>
</head>

<body>
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="?TeacherHome&UserID=<?php echo $UserID;?>">Quiz</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
        </div>
    </nav>



    <p style="margin: 10px;"></p>


    <div class="row">
        <div class="col-3"></div>
        <div class="col-6 card">
            <div class="card-header">Make necessary changes</div>
            <div class="card-body">
                <form action="?EditQuestion&CourseID=<?php echo $CourseID;?>&UserID=<?php echo $UserID;?>&QuestionID=<?php echo $QuestionID;?>" method="post">
                    <div class="form-group">
                        <!-- <label for="question">Question</label> -->
                        <input type="text" name="question" id="question" value="<?php echo $row['QuestionText'];?>" minlength="10" maxlength="200" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option1">Option 1</label> -->
                        <input type="text" name="Option1" id="Option1" value="<?php echo $row['Option1']?>" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option2">Option 2</label> -->
                        <input type="text" name="Option2" id="Option2" value="<?php echo $row['Option2']?>" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option3">Option 3</label> -->
                        <input type="text" name="Option3" id="Option3" value="<?php echo $row['Option3']?>" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option4">Option 4</label> -->
                        <input type="text" name="Option4" id="Option4" value="<?php echo $row['Option4']?>" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group w-25">
                        <select class="form-control" name="CorrectAnswer">
                            <option disabled="disabled">Correct Answer</option>
                            <option value="1">Option 1</option>
                            <option value="2">Option 2</option>
                            <option value="3">Option 3</option>
                            <option value="4">Option 4</option>
                        </select>
                    </div>
                    <button type="submit" class="btn btn-dark btn-sm">Update Question</button>
                </form>
            </div>
        </div>
        <div class="col-3"></div>
    </div>



    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>