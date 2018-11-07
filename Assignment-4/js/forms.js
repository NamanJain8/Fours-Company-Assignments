/*
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

 function levenshteinDistance (s, t) {
     if (!s.length) return t.length;
     if (!t.length) return s.length;

     return Math.min(
         levenshteinDistance(s.substr(1), t) + 1,
         levenshteinDistance(t.substr(1), s) + 1,
         levenshteinDistance(s.substr(1), t.substr(1)) + (s[0].toUpperCase() !== t[0].toUpperCase() ? 1 : 0)
     ) + 1;
 }

 function strength(s){
     var common = ["password", "123456", "12345678", "12345", "qwerty", "abc123", "football", "monkey", "123456789", "1234567", "letmein", "111111", "1234", "1234567890", "dragon", "baseball", "trustno1", "iloveyou", "princess", "adobe123", "123123", "welcome", "login", "admin", "solo", "master", "sunshine", "photoshop", "1qaz2wsx", "ashley", "mustang", "121212", "starwars", "bailey", "access", "flower", "passw0rd", "shadow", "michael", "654321", "jesus", "password1", "superman", "hello", "696969", "qwertyuiop", "hottie", "freedom", "qazwsx", "ninja", "azerty", "loveme", "whatever", "batman", "zaq1zaq1", "Football", "000000"];

     // var common = ["zaq1zaq1"];
     var len = common.length;
     // alert('Length of array is '+ len);
     var i,min=100,tmp;
     for (i = 0; i < len; i++) {
         tmp = levenshteinDistance(s, common[i]);
         if(tmp < min){
             min = tmp;
         }
     }
     return min;
 }

 function myFunction() {
    var x = document.getElementById("password").value;
    var str = strength(x);
    var l = password.value.length;
    var t = ((str - l)/str)*100;
    // alert('Your Password Strength (According to Common Words) is ' + t + '%');
    document.getElementById("demo").innerHTML = t;
}

function myFunction2() {
   var x = document.getElementById("newpassword").value;
   var str = strength(x);
   var l = newpassword.value.length;
   var t = ((str - l)/str)*100;
   // alert('Your Password Strength (According to Common Words) is ' + t + '%');
   document.getElementById("demo").innerHTML = t;
}

function formhash(form, password) {
    // Create a new element input, this will be our hashed password field.
    var p = document.createElement("input");

    // Add the new element to our form.
    form.appendChild(p);
    p.name = "p";
    p.type = "hidden";
    p.value = hex_sha512(password.value);

    // Make sure the plaintext password doesn't get sent.
    password.value = "";

    // Finally submit the form.
    form.submit();
}

function regformhash(form, uid, email, password, conf, security, answer) {
    // Check each field has a value

    if (uid.value == '' || email.value == '' || password.value == '' || conf.value == '' || security.value == '' || answer.value == '') {
        alert('You must provide all the requested details. Please try again');
        return false;
    }

    // Check the username
    re = /^\w+$/;
    if(!re.test(form.username.value)) {
        alert("Username must contain only letters, numbers and underscores. Please try again");
        form.username.focus();
        return false;
    }

    // Check that the password is sufficiently long (min 6 chars)
    // The check is duplicated below, but this is included to give more
    // specific guidance to the user
    if (password.value.length < 6) {
        alert('Passwords must be at least 6 characters long.  Please try again');
        form.password.focus();
        return false;
    }

    // At least one number, one lowercase and one uppercase letter
    // At least six characters
    var re = /(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}/;
    if (!re.test(password.value)) {
        alert('Passwords must contain at least one number, one lowercase and one uppercase letter.  Please try again');
        return false;
    }

    // Check password and confirmation are the same
    if (password.value != conf.value) {
        alert('Your password and confirmation do not match. Please try again');
        form.password.focus();
        return false;
    }

    // var str = strength(password.value);
    // alert('Your Password Strength is ' + str);

    // Create a new element input, this will be our hashed password field.
    var p = document.createElement("input");

    // Add the new element to our form.
    form.appendChild(p);
    p.name = "p";
    p.type = "hidden";
    p.value = hex_sha512(password.value);

    // Create a new element input, this will be our hashed password field.
    var ans = document.createElement("input");

    // Add the new element to our form.
    form.appendChild(ans);
    ans.name = "ans";
    ans.type = "hidden";
    ans.value = hex_sha512(answer.value);

    // Make sure the plaintext password doesn't get sent.
    answer.value = "";

    // Make sure the plaintext password doesn't get sent.
    password.value = "";
    conf.value = "";

    // Finally submit the form.
    form.submit();
    return true;
}


function randomstring(length, chars) {
    var result = '';
    for (var i = length; i > 0; --i) result += chars[Math.floor(Math.random() * chars.length)];
    return result;
}

function forgotregformhash(form, uid, email) {
    // Check each field has a value
    if (uid.value == '' || email.value == '') {
        alert('You must provide all the requested details. Please try again');
        return false;
    }
    // alert('Yaha aaya');

    // Check the username
    re = /^\w+$/;
    if(!re.test(form.username.value)) {
        alert("Username must contain only letters, numbers and underscores. Please try again");
        form.username.focus();
        return false;
    }

    // Create a new element input, this will be our hashed password field.
    var p = document.createElement("input");

    var rString = randomstring(4, 'abcdefghijklmnopqrstuvwxyz');
    var rString2 = randomstring(3, '0123456789');
    var rString3 = randomstring(3, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ');
    var j = rString.concat(rString2, rString3);

    // Add the new element to our form.
    form.appendChild(p);
    p.name = "p";
    p.type = "hidden";
    // p.value = hex_sha512(password.value);
    p.value = hex_sha512(j);

    var p2 = document.createElement("input");
    form.appendChild(p2);
    p2.name = "p2";
    p2.type = "hidden";
    // p.value = hex_sha512(password.value);
    p2.value = j;

    // Finally submit the form.
    form.submit();
    return true;
}

function forgotregformhashsec(form, uid, security, answer, newpassword, newconfirmpwd) {
    // Check each field has a value
    if (uid.value == '' || security.value == '' || answer.value == '' || newpassword.value == '' || newconfirmpwd.value == '') {
        alert('You must provide all the requested details. Please try again');
        return false;
    }
    // alert('Yaha aaya');

    // Check the username
    re = /^\w+$/;
    if(!re.test(form.username.value)) {
        alert("Username must contain only letters, numbers and underscores. Please try again");
        form.username.focus();
        return false;
    }

    if (newpassword.value.length < 6) {
        alert('Passwords must be at least 6 characters long.  Please try again');
        form.newpassword.focus();
        return false;
    }

    // At least one number, one lowercase and one uppercase letter
    // At least six characters
    var re = /(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,}/;
    if (!re.test(newpassword.value)) {
        alert('Passwords must contain at least one number, one lowercase and one uppercase letter.  Please try again');
        return false;
    }

    if (newpassword.value != newconfirmpwd.value) {
        alert('Your new password and new confirmation do not match. Please try again');
        form.newpassword.focus();
        return false;
    }

    // Create a new element input, this will be our hashed password field.
    var p = document.createElement("input");

    // var rString = randomstring(4, 'abcdefghijklmnopqrstuvwxyz');
    // var rString2 = randomstring(3, '0123456789');
    // var rString3 = randomstring(3, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ');
    // var j = rString.concat(rString2, rString3);

    // Add the new element to our form.
    form.appendChild(p);
    p.name = "p";
    p.type = "hidden";
    // p.value = hex_sha512(password.value);
    p.value = hex_sha512(newpassword.value);

    // var p2 = document.createElement("input");
    // form.appendChild(p2);
    // p2.name = "p2";
    // p2.type = "hidden";
    // // p.value = hex_sha512(password.value);
    // p2.value = j;

    // Create a new element input, this will be our hashed password field.
    var ans = document.createElement("input");

    // Add the new element to our form.
    form.appendChild(ans);
    ans.name = "ans";
    ans.type = "hidden";
    ans.value = hex_sha512(answer.value);

    // Make sure the plaintext password doesn't get sent.
    answer.value = "";
    newpassword.value = "";
    newconfirmpwd.value = "";

    // Finally submit the form.
    form.submit();
    return true;
}
