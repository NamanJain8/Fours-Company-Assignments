<html>
<head><meta charset="UTF-8">
    <title>Lab-6 MongoDB</title>
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
            font-size: 25px;
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
    <br><h1><b> MongoDB Assignment Lab-6</b> </h1>
<h2><center>
<br>

<?php
    require '/var/www/html/vendor/autoload.php';

    // connect to mongodb
   $m = new MongoDB\Client("mongodb://localhost:27017");
   // echo "Connection to database successfully";

   // select a database
   $db = $m->mydb;
   // echo "Database mydb selected";
   $collection = $db->mycollection;
   // echo "Collection selected succsessfully";

   $pipeline = array( array( '$group' => array( '_id' => '$DISTRICT', 'crimes' => array('$sum' => 1) ) ), array('$sort' => array('crimes' => -1)), array('$limit' => 1) );

   $cursor = $collection->aggregate($pipeline);

   foreach ($cursor as $document) {
       echo "Part-1: <br><br><table align='center'><tr><th>City with Maximum Crimes</th> <th>Crime Count</th></tr>";
       echo "<tr><td> " .$document["_id"] . "</td><td> " . $document["crimes"] . "</td></tr></table><br><br>";
   }

   $pipeline = array( array( '$group' => array(  '_id' => '$DISTRICT', 'Pending' => array( '$sum' => array( '$cond' => array( array( '$eq' => array( '$Status','Pending' ) ),1,0  ) ) )   , 'Total' => array( '$sum' => 1 )  )  )  , array( '$project' => array( '_id' => 1, 'Inefficiency' => array( '$divide' => array( '$Pending', '$Total' ) ) )   )  , array( '$sort' => array( 'Inefficiency' => -1 ) ) , array( '$limit' => 1 )    );

   $cursor = $collection->aggregate($pipeline);

   foreach ($cursor as $document) {
       echo "Part-2: <br><br><table align='center'><tr><th>Most Inefficient City in completing investigations</th> <th>Percent Pending Investigations</th></tr>";
       echo "<tr><td> " .$document["_id"] . "</td><td> " . $document["Inefficiency"]*100 . "%</td></tr></table><br><br>";
      // echo "Police station is the most inefficient in completing investigations = " . $document["_id"] . " which has " . $document["Inefficiency"]*100 . "% investigations still pending<br><br>";
   }

   $pipeline = array(array(  '$project' => array( '_id' => 0, 'Act_Section' => 1 )  ) , array( '$unwind' => '$Act_Section' ),         array( '$group' => array( '_id' => '$Act_Section', 'count' => array( '$sum' => 1 ) ) ),  array( '$sort' => array( 'count' => -1 ) ) , array( '$limit' => 1 ));

   $cursor = $collection->aggregate($pipeline);

   foreach ($cursor as $document) {
       echo "Part-3: <br><br><table align='center'><tr><th>Crime Law Applied Most Uniqely</th> <th>Frequency</th></tr>";
       echo "<tr><td> " .$document["_id"] . "</td><td> " . $document["count"] . "</td></tr></table><br>";
      // echo "Crime Law Applied Most Uniqely = " . $document["_id"] . " which is applied " . $document["count"] . "   times<br><br>";
   }

   $pipeline = array(array(  '$project' => array( '_id' => 0, 'Act_Section' => 1 )  ) , array( '$unwind' => '$Act_Section' ),         array( '$group' => array( '_id' => '$Act_Section', 'count' => array( '$sum' => 1 ) ) ),  array( '$sort' => array( 'count' =>  1 ) ) , array( '$limit' => 1 ));

   $cursor = $collection->aggregate($pipeline);

   foreach ($cursor as $document) {
       echo "<table align='center'><tr><th>Crime Law Applied Least Uniqely</th> <th>Frequency</th></tr>";
       echo "<tr><td> " .$document["_id"] . "</td><td> " . $document["count"] . "</td></tr></table><br><br>";
      // echo "Crime Law Applied Least Uniqely = " . $document["_id"] . " which is applied " . $document["count"] . " times<br><br>";
   }

?>
<a href="../index.html">Go Back to Main Assignment Page</a> <br><br>
</center></h2>
</body>

</html>
