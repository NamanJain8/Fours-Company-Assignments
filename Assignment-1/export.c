#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef char* string;

int main(int argc, char** argv){

    FILE *out_file = fopen("test.html", "w"); // write only

    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

    int t = 1, d = 2, c = 3, car = 4;
    string a="",b="",n="",n1="";


    if(t==1){
        a = "<div class=\"column1\"><img src=\"truck1.jpg\" style=\"width:100%%\"></div>";
    }
    else if(t==2){
        a = "<div class=\"column2\"><img src=\"truck1.jpg\" style=\"width:100%%\"></div><div class=\"column2\"><img src=\"truck2.jpg\" style=\"width:100%%\"></div>";
    }
    else if(t==3){
        a = "<div class=\"column3\"><img src=\"truck1.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"truck2.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"truck3.jpg\" style=\"width:100%%\"></div>";
    }
    else if(t==4){
        a = "<div class=\"column4\"><img src=\"truck1.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"truck2.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"truck3.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"truck4.jpg\" style=\"width:100%%\"></div>";
    }


    if(d==1){
        b = "<div class=\"column1\"><img src=\"dog1.jpg\" style=\"width:100%%\"></div>";
    }
    else if(d==2){
        b = "<div class=\"column2\"><img src=\"dog1.jpg\" style=\"width:100%%\"></div><div class=\"column2\"><img src=\"dog2.jpg\" style=\"width:100%%\"></div>";
    }
    else if(d==3){
        b = "<div class=\"column3\"><img src=\"dog1.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"dog2.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"dog3.jpg\" style=\"width:100%%\"></div>";
    }
    else if(d==4){
        b = "<div class=\"column4\"><img src=\"dog1.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"dog2.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"dog3.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"dog4.jpg\" style=\"width:100%%\"></div>";
    }


    if(c==1){
        n = "<div class=\"column1\"><img src=\"cat1.jpg\" style=\"width:100%%\"></div>";
    }
    else if(c==2){
        n = "<div class=\"column2\"><img src=\"cat1.jpg\" style=\"width:100%%\"></div><div class=\"column2\"><img src=\"cat2.jpg\" style=\"width:100%%\"></div>";
    }
    else if(c==3){
        n = "<div class=\"column3\"><img src=\"cat1.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"cat2.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"cat3.jpg\" style=\"width:100%%\"></div>";
    }
    else if(c==4){
        n = "<div class=\"column4\"><img src=\"cat1.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"cat2.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"cat3.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"cat4.jpg\" style=\"width:100%%\"></div>";
    }

    if(car==1){
        n1 = "<div class=\"column1\"><img src=\"car1.jpg\" style=\"width:100%%\"></div>";
    }
    else if(car==2){
        n1 = "<div class=\"column2\"><img src=\"car1.jpg\" style=\"width:100%%\"></div><div class=\"column2\"><img src=\"car2.jpg\" style=\"width:100%%\"></div>";
    }
    else if(car==3){
        n1 = "<div class=\"column3\"><img src=\"car1.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"car2.jpg\" style=\"width:100%%\"></div><div class=\"column3\"><img src=\"car3.jpg\" style=\"width:100%%\"></div>";
    }
    else if(car==4){
        n1 = "<div class=\"column4\"><img src=\"car1.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"car2.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"car3.jpg\" style=\"width:100%%\"></div><div class=\"column4\"><img src=\"car4.jpg\" style=\"width:100%%\"></div>";
    }


    fprintf(out_file, "    <html><head><style>* {    box-sizing: border-box;} img {display: block;    margin-left: auto;margin-right: auto;} .column3 {    float: left;    width: 33.33%%;    padding: 5px;} .column2 {    float: left;    width: 49%%;    padding: 5px;} .column4 {    float: left;    width: 25%%;    padding: 5px;} .column1 {    float: left;    width: 100%%;    padding: 5px;}/* Clearfix (clear floats) */.row::after {    content: "";    clear: both;    display: table;}</style><title>Fours Company Assignment-1</title>      </head>    <body bgcolor=\"5FFBB9\">    <div class=\"container-fluid\"><div class=\"row\">%s</div> <div class=\"row\">%s</div> <div class=\"row\">%s</div> <div class=\"row\">%s</div> </div>    </body></html>\n", a, b, n, n1);

    return 0;
}
