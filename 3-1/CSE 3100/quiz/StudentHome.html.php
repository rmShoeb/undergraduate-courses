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
    <nav class="navbar navbar-expand-sm navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="#">Quiz</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
                <ul class="navbar-nav">
                    <!-- <li class="nav-item active">
                        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
                    </li> -->
                    <!-- <li class="nav-item">
                        <a class="nav-link" href="#">Browse</a>
                    </li> -->
                    <li class="nav-item">
                        <a class="nav-link" href="?ShowResults&UserID=<?php echo $UserID;?>">Results</a>
                    </li>
                </ul>
                <!-- <form class="form-inline my-2 my-lg-0">
                    planned to add users name and a user icon here
                </form> -->
            </div>
        </div>
    </nav>

    <!-- take a quiz or add questions -->
    <div class="jumbotron">
        <div class="row">
            <div class="col-1"></div>
            <div class="col-10">
                <div class="card">
                    <div class="card-header">
                        <h1 class="display-4 text-center">Hello there!</h1>
                    </div>
                    <div class="card-body">
                        <p class="lead text-center">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium.</p>
                        <hr class="my-4">
                    </div>
                    <div class="card-footer text-center">
                        <div class="row">
                            <div class="col-4"></div>
                            <div class="col-4">
                                <a class="btn btn-primary btn-lg" href="#quiz-selector" data-toggle="collapse" role="button" aria-expanded="false" aria-controls="collapseExample">Take a quiz</a>
                                <div class="collapse" id="quiz-selector">
                                    <p style="margin: 20px;"></p>
                                    <div>
                                        <form action="?TakeQuiz&UserID=<?php echo $UserID;?>" method="post">
                                            <div class="form-group">
                                            <select class="custom-select text-center" id="inputGroupSelect01" name="CourseID">
                                                    <option disabled="disabled">Select a Course</option>
                                                    <?php foreach($AvailableCourses as $Course)
                                                    {?>
                                                        <option value="<?php echo $Course['ID'];?>"><?php echo $Course['CourseID'];?></option>
                                                    <?php }?>
                                                </select>
                                            </div>
                                            <div class="form-group">
                                                <select class="custom-select text-center" id="inputGroupSelect01" name="NumberOfQuestions">
                                                    <option disabled="disabled">Select number of questions</option>
                                                    <option value="5">05</option>
                                                    <option value="10">10</option>
                                                    <option value="15">15</option>
                                                    <option value="20">20</option>
                                                    <option value="25">25</option>
                                                </select>
                                            </div>
                                            <button class="btn btn-dark btn-lg">GO</button>
                                        </form>
                                    </div>
                                </div>
                            </div>
                            <div class="col-4"></div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="col-1"></div>
        </div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>

</html>