<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">

    <!-- google font -->
    <link href="https://fonts.googleapis.com/css?family=Fira+Code&display=swap" rel="stylesheet">
    <style type="text/css">
        body{font-family: 'Fira Code', monospace;}
    </style>

    <title>Quiz - Home</title>
</head>

<body>
    <!-- navigation panel -->
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="#">Quiz</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <!-- <li class="nav-item active">
                        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
                    </li> -->
                    <!-- <li class="nav-item">
                        <a class="nav-link" href="#">Browse</a>
                    </li> -->
                </ul>
                <form class="form-inline my-2 my-lg-0" action="?AddCourse&UserID=<?php echo $UserID;?>" method="post">
                    <input class="form-control mr-sm-2" type="text" placeholder="Course ID" name="CourseID" aria-label="Search" required>
                    <input class="form-control mr-sm-2" type="text" placeholder="Course Title" name="CourseTitle" aria-label="Search" required>
                    <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Add Course</button>
                </form>
            </div>
        </div>
    </nav>

    <p style="margin: 10px;"></p>


    <!-- take a quiz or add questions -->
    <div class="row">
        <div class="col-3 bg-dark text-light">
            <div class="container">
                <p>Available Courses:
                    <table class="table table-dark">
                        <?php foreach($AvailableCourses as $Course)
                        {?>
                            <tr>
                                <td><?php echo $Course['CourseID']?></td>
                                <td><a class="badge badge-light" href="?ShowDetails&ID=<?php echo $Course['ID'];?>&UserID=<?php echo $UserID;?>">Show Details</a></td>
                            </tr>
                        <?php }?>
                    </table>
                </p>
            </div>
        </div>
        <div class="jumbotron col-9">
            <h1 class="display-4 text-center">Hello there!</h1>
            <p class="lead text-center">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium.</p>
            <hr class="my-4">
            <div class="row">
                <div class="col-4"></div>
                <div class="col-4 text-center">
                    <div class="card">
                        <div class="card-header">
                            <a class="btn btn-primary btn-lg" href="#quiz-selector" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Generate a quiz</a>
                        </div>
                        <div class="card-body collapse" id="quiz-selector">
                            <div>
                                <form action="?GenerateQuiz&UserID=<?php echo $UserID;?>" method="post">
                                    <div class="form-group">
                                        <select class="custom-select text-center" name="CourseID" id="inputGroupSelect01">
                                            <?php foreach($AvailableCourses as $Course)
                                            {?>
                                                <option value="<?php echo $Course['ID'];?>"><?php echo $Course['CourseID'];?></option>
                                            <?php }?>
                                        </select>
                                    </div>
                                    <div class="form-group">
                                        <select class="custom-select text-center" name="NumberOfQuestions" id="inputGroupSelect01">
                                            <option value="5">05</option>
                                            <option value="10">10</option>
                                            <option value="15">15</option>
                                            <option value="20">20</option>
                                            <option value="25">25</option>
                                        </select>
                                    </div>
                                    <button class="btn btn-dark btn-lg text-center">Generate</button>
                                </form>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-4"></div>
            </div>
        </div>
    </div>

    <!-- script to show messages, if there is any -->
    <?php if(isset($Message))
    {?>
        <script>
            alert(<?php echo $Message;?>);
        </script>
    <?php
    }?>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>

</html>