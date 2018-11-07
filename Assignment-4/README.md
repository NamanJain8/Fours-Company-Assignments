
You'll need Apache, mySQL and PHP5.3.x installed and working. 

You'll also need to create a database called 'secure_login'.

In the `mysql` terminal, execute: 
```
CREATE DATABASE `secure_login`;
```

Then run the following command in the terminal:
```
mysql -u <username> -p secure_login < secure_login.sql
```

Enter your password when prompted to.

Then in the `mysql` terminal again execute:
```
CREATE USER 'sec_user'@'localhost' IDENTIFIED BY '4Fa98xkHVd2XmnfK';
GRANT SELECT, INSERT, UPDATE ON `secure_login`.* TO 'sec_user'@'localhost';
```

The registration page is now implemented, so you can register as many users as you like.  However you may still need the test_user for testing purposes in the future when we come to adding roles to users.

Also, change `devanshusomani99@gmail.com` with your own Gmail account and `Your_gmail_password` with your actual password in `/includes/forgot.inc.php`.

You will also need to allow less trusted apps access for the working of Forgot-Password-Through-Email-Facility through this link: https://myaccount.google.com/lesssecureapps.
