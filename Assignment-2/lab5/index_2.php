<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Lab-5 Part-2</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

    <style>
        body{
            background-color: rgba(17, 19, 35, 0.18);
        }
        table, th, td {
            border: 1px solid black;
            border-collapse: collapse;
            text-align: center;
            border-spacing: 15px;
            padding: 5px;
            align: center;
            font-size: 20px;
        }
        input{
            color: rgba(0, 0, 233, 0.53);
        }
        h2, h1{
            text-align: center;
        }
    </style>
</head>
<body>
<br><h1><b> MySQL Assignment Lab-5 Part-2</b> </h1><br>
     <?php
// define variables and set to empty values
$id = $dept = $last_name = $dept_no = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $id = test_input($_POST["id"]);
  $dept = test_input($_POST["dept"]);
  $last_name = test_input($_POST["last_name"]);
  $dept_no = test_input($_POST["dept_no"]);
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>
    <br><br>
<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "employees";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// echo $id;

$sql = "select g.dept_name, COUNT(*) as freq from (select p.*, k.dept_name from (select e.emp_no, d.dept_no from employees e join current_dept_emp d on e.emp_no = d.emp_no) p join departments k on p.dept_no = k.dept_no) g group by g.dept_name order by freq desc limit 1";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    echo "<table align='center'><tr><th>MOST POPULATED DEPARTMENT   </th>  <th>    EMPLOYEE COUNT</th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>". $row["dept_name"]. " </td><td> ". $row["freq"] . "</td></tr></table>";
        // echo $row;
    }
} else {
    echo "0 results";
}




echo "<br><br>";
// echo $id;


$conn->close();
?>
<h2><a href="index.php">Go Back to Lab-5 Main Page</a></h2><br>
</h2></center>
</body>
</html>
