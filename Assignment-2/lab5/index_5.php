<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Four's Company Lab5</title>
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
    <br><h1><b> MySQL Assignment Lab-5 Part-5</b> </h1><br>
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
<form name="form1" class="form-horizontal" method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">


    <div class="form-group">
        <label class="control-label col-sm-2" for="4">Dept Number :</label>
        <div class="col-sm-9">
            <input id="4" name="dept_no" class="form-control" type="text" maxlength="20"/>
        </div>
    </div>
    <br>
  <center>
  <div class="form-group">
      <div class="col-sm-offset-5 col-sm-2">
          <input id="7" name="submit" value="Submit" class="form-control" type="submit" />
      </div>
  </div>
  </center>
</form><br>
<center><h2>
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

$sql = "select q.title, AVG(CASE when q.gender='M' then q.salary end) as avg_male_salary, AVG(CASE when q.gender='F' then q.salary end) as avg_female_salary from (select f.emp_no, f.gender, f.salary, f.title from (select e.emp_no, e.gender, p.salary, p.title, p.dept_no from (select s.*, d.dept_no from current_dept_emp d inner join (select a.*, b.salary from salaries b join titles a on (a.emp_no = b.emp_no and a.to_date = b.to_date)) s on (s.emp_no = d.emp_no and s.to_date = d.to_date)) p join employees e on e.emp_no = p.emp_no) f where dept_no = '$dept_no') q group by q.title";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    echo "<table align='center'><tr><th>TITLE     </th>  <th>     AVERAGE MALE SALARY     </th>  <th>     AVERAGE FEMALE SALARY     </th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>". $row["title"]. " </td><td> ". $row["avg_male_salary"] . " </td><td> ". $row["avg_female_salary"] . "</td></tr>";
    }
    echo "</table>";
} else {
    echo "0 results";
}


echo "<br>";
// echo $id;



$conn->close();
?>
<h2><a href="index.php">Go Back to Lab-5 Main Page</a></h2><br>
</h2></center>
</body>
</html>
