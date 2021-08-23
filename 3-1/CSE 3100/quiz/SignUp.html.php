<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <!-- !-- google icons -->
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">

    <!-- google font -->
    <link href="https://fonts.googleapis.com/css?family=Fira+Code&display=swap" rel="stylesheet">
    <style type="text/css">
        body {
            font-family: 'Fira Code', monospace;
        }
    </style>

    <title>Register Now</title>
</head>

<body>
    <div class="row">
        <div class="col-4"></div>
        <div class="col-4">
            <div class="card">
                <div class="card-header text-center">
                    <h3 class="alert alert-heading" role="alert">
                        <i class="material-icons">perm_identity</i>Register Now
                    </h3>
                    <?php if(isset($ErrorMessage)){?>
                        <div id="ErrorMessage" style="margin: 10px; text-align: center; color: red;">
                            <?php echo $ErrorMessage;?>
                        </div>
                    <?php }?>
                </div>
                <div class="card-body">
                    <form action="?SignUp" method="post" id="loginForm">
                        <div class="row">
                            <div class="form-group col-lg-12">
                                <label for="FirstName">First Name</label>
                                <input type="text" class="form-control" name="FirstName" maxlength="25" minlength="2" id="FirstName" placeholder="First Name" required>
                            </div>
                            <div class="form-group col-lg-12">
                                <label for="LastName">Last Name</label>
                                <input type="text" class="form-control" name="LastName" maxlength="15" minlength="2" id="LastName" placeholder="Last Name" required>
                            </div>
                            <div class="form-group col-lg-12">
                                <label for="UserID">ID</label>
                                <input type="text" class="form-control" name="UserID" maxlength="7" minlength="5" id="UserID" placeholder="Your ID" required>
                            </div>
                            <div class="form-group col-lg-12">
                                <label for="email">Email</label>
                                <input type="email" class="form-control" id="email" name="email" placeholder="Valid Email" required>
                            </div>
                            <div class="form-group col-lg-12">
                                <label for="UserType">User Type</label>
                                <select class="form-control" id="UserType" name="UserType">
                                    <option value="student">Student</option>
                                    <option value="teacher">Teacher</option>
                                </select>
                            </div>
                            <div class="form-group col-lg-12">
                                <label for="password">Password</label>
                                <input type="password" class="form-control" name="password" maxlength="25" minlength="5" id="password" placeholder="Password" required>
                            </div>
                        </div>
                        <div class="text-center">
                            <button class="btn btn-success loginbtn">Register</button>
                        </div>
                    </form>
                </div>
                <div class="card-footer">
                    <div class="text-center">
                        <p class="alert alert-light text-center" role="alert">Already have an account?<br><a href="?SignInRequest" class="btn btn-light btn-md">Sign In</a></p>
                    </div>
                </div>
            </div>
        </div>
        <div class="col-4"></div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    
</body>

</html>