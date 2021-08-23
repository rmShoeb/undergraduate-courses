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

    <title>Quiz - Results</title>
</head>

<body>
    <!-- navigation panel -->
    <nav class="navbar navbar-expand-sm navbar-dark bg-dark">
        <div class="container">
            <a class="navbar-brand" href="?StudentHome&UserID=<?php echo $UserID;?>">Quiz</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
        </div>
    </nav>

    <div class="row">
        <div class="col-2"></div>
        <div class="col-8">
            <div class="card text-center">
                <div class="card-header display-4">Your Results</div>
                <div class="card-body">
                    <table class="table">
                        <thead class="thead-default">
                            <tr>
                                <th scope="col">Course ID</th>
                                <th scope="col">Number Of Questions</th>
                                <th scope="col">Correctly Answered</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php foreach($Scores as $Score){?>
                            <tr>
                                <td><?php echo $Score['CourseID'];?></td>
                                <td><?php echo $Score['NumberOfQuestions'];?></td>
                                <td><?php echo $Score['SuccessfullAttempts'];?></td>
                            </tr>
                            <?php }?>
                        </tbody>
                    </table>
                </div>
                <div class="card-footer h4">Keep Studying to Improve!</div>
            </div>
        </div>
        <div class="col-2"></div>
    </div>

</body>
</html>