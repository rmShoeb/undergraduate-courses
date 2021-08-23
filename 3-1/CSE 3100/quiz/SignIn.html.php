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

    <title>Sign In</title>
</head>

<body>
    <div class="row">
        <div class="col-4"></div>
        <div class="col-4">
            <div class="card">
                <div class="card-header">
                    <h1 style="text-align: center;" class="alert alert-primary" role="alert">
                        <i class="material-icons">account_circle</i>Sign In
                    </h1>
                    <?php if(isset($ErrorMessage)){?>
                        <!-- <script type="text/javascript">
                            document.getElementById("ErrorMessage").style.display = "block";
                        </script> -->
                        <div id="ErrorMessage" style="margin: 10px; text-align: center; color: red;">
                            <?php echo $ErrorMessage;?>
                        </div>
                    <?php }?>
                </div>
                <div class="card-body">
                    <form action="?SignIn" method="post">
                        <div class="form-group">
                            <input type="text" name="UserID" placeholder="ID" class="form-control" maxlength="7" required>
                        </div>
                        <div class="form-group">
                            <input type="password" name="password" placeholder="Password" class="form-control" maxlength="15" required>
                        </div>
                        <div class="form-group" style="text-align: center;">
                            <input type="submit" name="" value="Sign In" class="btn btn-success btn-lg">
                        </div>
                    </form>
                </div>
                <div class="card-footer">
                    <p class="alert alert-light text-center" role="alert">Do not have an account? <a href="?SignUpRequest" class="btn btn-light btn-md">Create an Account</a></p>
                </div>
            </div>
        </div>
        <div class="col-4"></div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>