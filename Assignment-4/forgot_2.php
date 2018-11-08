<?php
/**
 * Copyright (C) 2013 peredur.net
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
include_once 'includes/forgot2.inc.php';
include_once 'includes/functions.php';
?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Secure Login: Forgot Password</title>
        <script type="text/JavaScript" src="js/sha512.js"></script>
        <script type="text/JavaScript" src="js/forms.js"></script>
        <link rel="stylesheet" href="styles/main.css" />
    </head>
    <body>
    <center>
    <h1>Fours Company</h1>
        <!-- Registration form to be output if the POST variables are not
        set or if the registration script caused an error. -->
        <h1>Forgot Password</h1>
        <?php
        if (!empty($error_msg)) {
            echo $error_msg;
        }
        ?>
        <form method="post" name="registration_form" action="<?php echo esc_url($_SERVER['PHP_SELF']); ?>">
            Username: <input type='text' name='username' id='username' /><br>
            Security Question: <select name="security" id="security">
                                    <option value="0">What was your mother's maiden name?</option>
                                    <option value="1">What was the name of the first school you visited?</option>
                                </select><br>
            Answer to Security Question (Beware of Capital Letters and Special Symbols): <input type="text" name="answer" id="answer" /><br>
            New Password: <input type="password"
                                   name="newpassword"
                                   id="newpassword"  onkeyup="myFunction2()"/>        Password Strength: <span id="demo"></span>%<br>
            Confirm New password: <input type="password"
                                     name="newconfirmpwd"
                                     id="newconfirmpwd" /><br>
            <input type="button"
                   value="Click Here to get your new password"
                   onclick="return forgotregformhashsec(this.form,
                                   this.form.username,
                                   this.form.security,
                                   this.form.answer,
                                   this.form.newpassword,
                                   this.form.newconfirmpwd);" />
        </form>
        <p>Return to the <a href="index.php">login page</a>.</p>
    </body>
</html>
