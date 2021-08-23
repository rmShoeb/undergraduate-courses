<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <!-- google icons -->
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">

    <!-- google font -->
    <link href="https://fonts.googleapis.com/css?family=Fira+Code&display=swap" rel="stylesheet">
    <style type="text/css">
        body{font-family: 'Fira Code', monospace;}
    </style>

    <title>Quiz - Course Details</title>
</head>

<body>
    <!-- navigation panel -->
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="?TeacherHome&UserID=<?php echo $UserID;?>">Quiz</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <!-- <li class="nav-item active">
                        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
                    </li> -->
                    <li class="nav-item">
                        <a class="nav-link" href="?BrowseQuestions&CourseID=<?php echo $Course['id'];?>&UserID=<?php echo $UserID;?>">Browse Questions</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>

    <p style="margin: 10px;"></p>


    <div class="row">
        <div class="col-3 bg-dark text-light">
            <div class="container">
                <p>Course Code: <?php echo $Course['CourseID'];?></p>
                <p>Title: <?php echo $Course['CourseTitle'];?></p>
            </div>
        </div>
        <div class="col-6 card">
            <div class="card-header">Add a new question</div>
            <div class="card-body">
                <form action="?AddQuestion&ID=<?php echo $Course['id'];?>&UserID=<?php echo $UserID;?>" method="post">
                    <div class="form-group">
                        <!-- <label for="question">Question</label> -->
                        <input type="text" name="question" id="question" placeholder="Question Text" minlength="10" maxlength="200" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option1">Option 1</label> -->
                        <input type="text" name="Option1" id="Option1" placeholder="Option 1" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option2">Option 2</label> -->
                        <input type="text" name="Option2" id="Option2" placeholder="Option 2" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option3">Option 3</label> -->
                        <input type="text" name="Option3" id="Option3" placeholder="Option 3" minlength="2" maxlength="100" class="form-control" required>
                    </div>
                    <div class="form-group">
                        <!-- <label for="Option4">Option 4</label> -->
                        <input type="text" name="Option4" id="Option4" placeholder="Option 4" minlength="2" maxlength="100" class="form-control" required>
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
                    <button type="submit" class="btn btn-dark btn-sm">Add Question</button>
                </form>
            </div>
        </div>
        <div class="col-3"></div>
    </div>


    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>

</html>