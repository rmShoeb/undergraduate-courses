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

    <title>Questions - Browse</title>
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


    <div class="row">
        <div class="col-1"></div>
        <div class="col-10">
            <table class="table table-bordered">
                <thead class="text-center">
                    <tr>
                        <th scope="col">Question</th>
                        <th scope="col">Correct Option</th>
                        <th scope="col">Edit</th>
                        <th scope="col">Delete</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach($questions as $question){?>
                    <tr>
                        <td>
                            <?php echo $question['QuestionText'];?><br>
                            1. <?php echo $question['Option1'];?><br>
                            2. <?php echo $question['Option2'];?><br>
                            3. <?php echo $question['Option3'];?><br>
                            4. <?php echo $question['Option4'];?>
                        </td>
                        <td class="text-center">
                            <?php echo $question['CorrectOption'];?>
                        </td>
                        <!-- <td>Edit</td> -->
                        <td class="text-center">
                            <a href="?GotoEditQuestion&QuestionID=<?php echo $question['QuestionID'];?>&CourseID=<?php echo $CourseID;?>&UserID=<?php echo $UserID;?>">
                                <i class="material-icons">update</i>
                            </a>
                        </td>
                        <!-- <td>Delete</td> -->
                        <td class="text-center">
                            <a href="?DeleteQuestion&QuestionID=<?php echo $question['QuestionID'];?>&CourseID=<?php echo $CourseID;?>&UserID=<?php echo $UserID;?>">
                                <i class="material-icons">delete</i>
                            </a>
                        </td>
                    </tr>
                    <?php }?>
                </tbody>
            </table>
            <a href="?ShowDetails&&UserID=<?php echo $UserID;?>&ID=<?php echo $CourseID;?>">
                <i class="material-icons">keyboard_arrow_left</i>go back
            </a>
        </div>
        <div class="col-1"></div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>
