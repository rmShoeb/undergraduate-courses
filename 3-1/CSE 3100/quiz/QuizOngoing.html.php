<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <!-- google font -->
    <link href="https://fonts.googleapis.com/css?family=Fira+Code&display=swap" rel="stylesheet">
    <style type="text/css">
        body{font-family: 'Fira Code', monospace;}
    </style>

    <!-- javascript for timeout  -->
    <script type="text/javascript">
        function TimeOut()
        {
            if(TimeLeft <= 0)
            {
                clearTimeout(time);
                document.getElementById('QuizForm').submit();
            }
            else
            {
                var minuite = Math.floor(TimeLeft/60);
                var second  = TimeLeft % 60;

                if(minuite < 10)
                    minuite = "0" + minuite;
                if(second < 10)
                    second = "0" + second;

                document.getElementById('timer').innerHTML = minuite + ' : ' + second;
            }
            TimeLeft--;
            var time = setTimeout(function(){TimeOut()}, 1000);
        }
    </script>

    <title>Quiz</title>
</head>

<body onload="TimeOut()">
    <div class="row">
        <div class="col-2"></div>
        <div class="col-8">
            <p style="margin: 15px;"></p>
            <div class="card-header sticky-top bg-dark text-light">
                <div class="row">
                    <div class="col-10 text-center text-uppercase h3">Answer all the questions on time</div>
                    <script type="text/javascript">
                        TimeLeft = <?php echo $Time;?>;
                    </script>
                    <div class="col-2 text-center" id="timer">timer</div>
                </div>
            </div>
            <div class="card-body">
                <div class="container">
                    <form method="post" action="?CheckAnswers&StudentID=<?php echo $UserID;?>&CourseID=<?php echo $CourseID;?>" id="QuizForm">
                        <?php $i = 1;
                        foreach($questions as $question)
                        {?>
                            <table class="table table-hover">
                                <thead class="thead-light">
                                    <tr>
                                        <th scope="col"><?php echo $i++ . '. ';
                                        echo $question['QuestionText'];?></th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <tr>
                                        <td>
                                            <input type="radio" value="1" name="<?php echo $question['QuestionID']; ?>">
                                            <?php echo $question['Option1'];?>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <input type="radio" value="2" name="<?php echo $question['QuestionID']; ?>">
                                            <?php echo $question['Option2'];?>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <input type="radio" value="3" name="<?php echo $question['QuestionID']; ?>">
                                            <?php echo $question['Option3'];?>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>
                                            <input type="radio" value="4" name="<?php echo $question['QuestionID']; ?>">
                                            <?php echo $question['Option4'];?>
                                        </td>
                                    </tr>
                                    <!-- default answer if question is not answered -->
                                    <tr>
                                        <td>
                                            <input type="radio" value="0" name="<?php echo $question['QuestionID']; ?>" style="display: none;" checked="checked">
                                        </td>
                                    </tr>
                                </tbody>
                            </table>
                        <?php }?>
                        <div class="row">
                            <div class="col-3">
                                <a href="?StudentHome&UserID=<?php echo $UserID;?>" class="btn btn-lg btn-danger">Cancel quiz</a>
                            </div>
                            <div class="col-6"></div>
                            <div class="col-3">
                                <!-- <input type="submit" name="submit" value="Check answers" class="btn btn-lg btn-warning"> -->
                                <button class="btn btn-lg btn-warning">Check Answers</button>
                            </div>
                        </div>
                    </form>
                </div>
            </div>

    <!--         <div class="progress">
                <div class="progress-bar" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100"></div>
            </div>
            <p class="btn btn-lg btn-light d-flex justify-content-center">Progress</p> -->
            <div class="card-footer">
                <p class="text-center bg-dark text-light">Make sure you answered all the questions correctly.</p>
            </div>
        </div>
        <div class="col-2"></div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>