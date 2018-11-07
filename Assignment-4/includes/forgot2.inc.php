<?php

/*
 * Copyright (C) 2013 peter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

include_once 'db_connect.php';
include_once 'psl-config.php';

$error_msg = "";
if (isset($_POST['username'], $_POST['p'], $_POST['security'], $_POST['ans'])) {

    // Sanitize and validate the data passed in
    $username = filter_input(INPUT_POST, 'username', FILTER_SANITIZE_STRING);
    $security = filter_input(INPUT_POST, 'security', FILTER_SANITIZE_STRING);
    $answer = filter_input(INPUT_POST, 'ans', FILTER_SANITIZE_STRING);

    $password = filter_input(INPUT_POST, 'p', FILTER_SANITIZE_STRING);
    // $actual_password = filter_input(INPUT_POST, 'newconfirmpwd', FILTER_SANITIZE_STRING);

    // $error_msg .= '<p class="error">Pahucha yaha</p>';

    // if (strlen($password) != 128) {
    //     // The hashed pwd should be 128 characters long.
    //     // If it's not, something really odd has happened
    //     $error_msg .= '<p class="error">Invalid password configuration.</p>';
    // }

    // Username validity and password validity have been checked client side.
    // This should should be adequate as nobody gains any advantage from
    // breaking these rules.




    $sql = "SELECT id, answer, answer_salt FROM members WHERE username = ? and security = ? LIMIT 1";
    $pre = $mysqli->prepare($sql);
    $pre->bind_param('ss', $username, $security);
    $pre->execute();
    $res = $pre->get_result();
    if ($res->num_rows == 0) {
        $error_msg .= '<p class="error">This Username and Email and Security Question/Answer Combination does not belong to any registered individual.</p>';
    }
    else{
        while ($row = $res->fetch_assoc()) {
            $id = $row['id'];
            $db_answer = $row['answer'];
            $answer_salt = $row['answer_salt'];
            $answer = hash('sha512', $answer . $answer_salt);
            if($db_answer != $answer){
                $error_msg .= '<p class="error">This Username and Email and Security Question/Answer Combination does not belong to any registered individual.</p>';
            }
            // $error_msg .= '<p class="error">'.$id.'</p>';
        }
    }

    // TODO:
    // We'll also have to account for the situation where the user doesn't have
    // rights to do registration, by checking what type of user is attempting to
    // perform the operation.

    if (empty($error_msg)) {
        // the message
        // $msg = "Hi ". $username . ". Your new password for Fours' Company Secure Login is ". $password;

        // send email
        // mail($email,"Fours' Company Secure Login Password Change",$msg);

        // $sql2 = "DELETE FROM members WHERE username = ? and email = ? LIMIT 1";
        // $pre2 = $mysqli->prepare($sql2);
        // $pre2->bind_param('ss', $username, $email);
        // $pre2->execute();

        // $error_msg .= '<p class="error">Your new password is ' . $actual_password . '</p>';

        // Create a random salt
        $random_salt = hash('sha512', uniqid(openssl_random_pseudo_bytes(16), TRUE));

        // // // Create salted password
        $password = hash('sha512', $password . $random_salt);

        // // // Insert the new user into the database
        if ($insert_stmt = $mysqli->prepare("UPDATE members SET password = ?, salt = ? WHERE id = ?")) {
            $insert_stmt->bind_param('sss', $password, $random_salt, $id);
            // Execute the prepared query.
            if (! $insert_stmt->execute()) {
                header('Location: ../error.php?err=Registration failure: INSERT');
                exit();
            }
        }
        header('Location: ./forgot_success_2.php');
        exit();
    }
}
