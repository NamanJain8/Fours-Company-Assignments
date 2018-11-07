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
    <br><h1><b> MySQL Assignment Lab-5 Part-3</b> </h1><br>
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
    </form>
<center><h2>
    <h2><a href="index.php">Go Back to Lab-5 Main Page</a></h2><br><br>
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

$sql = "select g.* from (select e.*, d.dept_no, TIMESTAMPDIFF(MONTH, e.hire_date, now()) as months_worked from employees e join current_dept_emp d on d.emp_no = e.emp_no where d.to_date='9999-01-01') g where g.dept_no='$dept_no' order by months_worked";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    echo "<table align='center'><tr><th>ID      </th>  <th>    BIRTH DATE     </th>  <th>     NAME     </th>  <th>     GENDER     </th>  <th>      HIRE_DATE    </th>  <th>    DEPT_NO    </th>  <th>   TENURE (MONTHS)</th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr><td>".$row["emp_no"]."  </td><td>  ".$row["birth_date"]."  </td><td>  ".$row["first_name"]." ".$row["last_name"]."  </td><td>  ".$row["gender"]."  </td><td>  ".$row["hire_date"]."  </td><td>  ".$row["dept_no"]."  </td><td> ".$row["months_worked"]."</td></tr>";
    }
    echo "</table>";
} else {
    echo "0 results";
}


$conn->close();
?>
</h2></center>
</body>
</html>
