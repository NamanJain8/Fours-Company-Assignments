#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <math.h>

typedef char* string;

int main()
{
	int welcomeSocket, newSocket;
	char input[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;

	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5432);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	while(1)
	{
		if(listen(welcomeSocket,5)==0)
		  printf("I'm listening\n");
		else
		  printf("Error\n");

		addr_size = sizeof serverStorage;
		newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

	
		recv(newSocket, input, 1024, 0);
		printf("Request received for %s\n",input);

		///////////// PARSING THE REQUEST ////////////
		char *token = strtok(input, " ");
		int cars=0,dogs=0,cats=0,trucks=0,i=0;

		while(token) 
		{
		    if(token[0]>='a' && token[0]<='z')
		    {
		      if(token[0]=='c' && token[1]=='a' && token[2]=='r')
		        cars = i;
		      else if(token[0]=='t')
		        trucks = i;
		      else if(token[0]=='c' && token[1]=='a' && token[2]=='t')
		        cats = i;
		      else if(token[0]=='d')
		        dogs = i;
		    }
		    else
		    {
		      i = token[0]-'0';
		    }

		    token = strtok(NULL, " ");
		}

		printf("%d cars , %d cats , %d trucks , %d dogs\n",cars,cats,trucks,dogs);

		///////////////////// Parsed /////////////////////////////

		//// Create HTML file ///////////////////

		FILE *out_file = fopen("files/index.html", "w");
		int t= trucks, d=dogs,c=cats, car=cars;

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



		char html[1024]="files/index.html";
		FILE* fp = fopen(html, "rb");
		fseek(fp, 0, 2);     //file pointer at the end of file 
		int sz = ftell(fp);
		int size,code,ini,flag=0;; 
		fclose(fp); 

		size = sz/4;
		size += ( sz%4 == 0 ) ? 0:1;
		code = 999;
		
		fp = fopen(html, "rb");
		send(newSocket,(void *)&code,sizeof(int),0);
		send(newSocket,(void *)&size,sizeof(int),0); 
		printf("Start HTML send\n");
		if(fp != NULL)
		{
		  while(fread(&ini, sizeof(int), 1, fp)) 
		  {
		    send(newSocket,(void *)&ini,sizeof(int),0);
		    flag++;  	               
		  }
		  printf("HTML Sent \n \n");
		  fclose(fp);
		} 
		else 
		{
			perror("File");
		}
		
		code = 555;
		send(newSocket,(void *)&code,sizeof(int),0);
	}
	return 0;
}
