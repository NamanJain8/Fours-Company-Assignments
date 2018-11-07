<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Lab-5 Part-1</title>
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
        h1, h2{
            text-align: center;
        }
    </style>
</head>
<body>
    <br><h1><b> MySQL Assignment Lab-5 Part-1</b> </h1>
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
            <label class="control-label col-sm-2" for="1">ID :</label>
            <div class="col-sm-9">
                <input id="1" name="id" class="form-control" type="text" maxlength="20"/>
            </div><center>
            <p id="id_error"></p></center>
        </div>

        <div class="form-group">
            <label class="control-label col-sm-2" for="2">Last Name :</label>
            <div class="col-sm-9">
                <input id="2" name="last_name" class="form-control" type="text" maxlength="200"/>
            </div><center>
            <p id="name_error"></p></center>
        </div>

        <div class="form-group">
            <label class="control-label col-sm-2" for="3">Department :</label>
            <div class="col-sm-9">
                <input id="3" name="dept" class="form-control" type="text" maxlength="200"/>
            </div><center>
            <p id="dept_error"></p></center>
        </div>
        <!--<div class="form-group">
            <label class="control-label col-sm-2" for="4">Dept Number (For 3rd and 5th part) :</label>
            <div class="col-sm-9">
                <input id="4" name="dept_no" class="form-control" type="text" maxlength="20"/>
            </div>
        </div>-->
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
    <a href="index.php">Go Back to Lab-5 Main Page</a><br>
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
echo "<br>";
$sql = "SELECT g.* FROM (select p.*, k.dept_name from (select e.*, d.dept_no from employees e join current_dept_emp d on e.emp_no = d.emp_no) p join departments k on p.dept_no = k.dept_no) g where g.emp_no='$id' or g.last_name='$last_name' or g.dept_name='$dept'";
// $sql = "SELECT * FROM employees limit 30";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    echo "<table align='center'><tr><th>ID      </th>  <th>    BIRTH DATE     </th>  <th>     NAME     </th>  <th>     GENDER     </th>  <th>      HIRE_DATE    </th>  <th>    DEPT_NO    </th>  <th>    DEPT_NAME</th></tr>";
    while($row = $result->fetch_assoc()) {
        // echo $row[1];
        echo "<tr><td>".$row["emp_no"]."  </td><td>  ".$row["birth_date"]."  </td><td>  ".$row["first_name"]." ".$row["last_name"]."  </td><td>  ".$row["gender"]."  </td><td>  ".$row["hire_date"]."  </td><td>  ".$row["dept_no"]."  </td><td> ".$row["dept_name"]."</td></tr>";
        // echo $row;
    }
    echo "</table>";
} else {
    echo "0 results";
}

echo "<br><br><br>";
// echo $id;



$conn->close();
?>
</h2></center>
</body>
</html>
