<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Speciic Authors Books</title>
</head>

<body>
    <nav class="navbar navbar-dark bg-dark">
      <div class="container">
        <a href="?home" class="navbar-brand">Rental Library Management</a>
      </div>
    </nav>

    <!-- show retrieved data -->
    <div class="container">
        <?php 
        if(isset($DataRetriveErrorMessage))
        {?>
            <p class="alert alert-danger" role="alert">
                <?php
                    echo $DataRetrieveErrorMessage;
                ?>
            </p>
        <?php } 
        $TotalRows = count($StudentNames);
        ?>
        <p class="alert alert-success" role="alert" style="text-align: center;">Results showing for author: <?php echo $Author;?></p>
        <table class="table table-hover">
            <thead class="thead-light">
                <tr>
                    <th scope="col">Student ID</th>
                    <th scope="col">Student Name</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <?php
                    for($i=0; $i<$TotalRows; $i++)
                    {?>
                        <td><?php echo $StudentIDs[$i]; ?></td>
                        <td><?php echo $StudentNames[$i]; ?></td>
                    <?php }
                    ?>
                </tr>
            </tbody>
        </table>
    </div>

    <a href="?home" class="btn btn-primary btn-lg">Return to Home</a>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>