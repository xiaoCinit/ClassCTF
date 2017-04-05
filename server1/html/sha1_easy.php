<?php
   if (isset($_GET['view-source'])) {
        show_source(__FILE__);
        exit();
    }

 if (isset($_GET['name']) and isset($_GET['password'])) {
    $name = $_GET['name'];
    $password = $_GET['password'];
    if ($name == $password) {
        print 'Your password can not be your name.';
    } else if (sha1($name) === sha1($password)) {
      	include('../lib.php');
	die('good job! Next step is : '.$step3);
    } else {
        print '<p class="alert">Invalid password.</p>';
    }
}
?>
<html>
<head>
	<title>sha1_puzzle</title>
	<link rel='stylesheet' href='style.css' type='text/css'>
</head>
<body>


<section class="login">
	<div class="title">
		<a>Welcome to Evilc's Hash Hell LOL!</a>
	</div>

	<form method="get">
		<input type="text" required name="name" placeholder="Name"/><br/>
		<input type="text" required name="password" placeholder="Password" /><br/>
		<input type="submit"/>
	</form>
</section>
<br />
<a href="?view-source">view-source</a>
</body>
</html>
