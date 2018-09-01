#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <math.h>
#include <stdlib.h>

typedef char* string;

void html_create(int t, int d, int c, int car)
{
	 FILE *out_file = fopen("files/index.html", "wb"); // write only
    if (out_file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(-1); // must include stdlib.h
    }

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
    fflush(out_file);
    return;
}
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
		///////////////////// HTML CREATE/////////////////////////
		printf("Creating HTML file\n");
		html_create(trucks,dogs,cats,cars);
		printf("HTML created for user\n");
		///////////////////////////////////////////////////////////

		char html[1024]="files/index.html";
		FILE* fp = fopen(html, "rb");
		fseek(fp, 0, 2);     //file pointer at the end of file
		int sz = ftell(fp);
		int size,code,ini,flag=0;;
		fclose(fp);

		size = sz/4;
		//size += ( sz%4 == 0 ) ? 0:1;
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
		  printf("HTML Sent flag %d size %d\n \n",flag,size);
		  fclose(fp);
		}
		else
		{
			perror("File");
		}

		// CARS

		for(int i=1;i<=cars;i++)
		{
		  char name[1024]="files/car";
		  int length = strlen(name), flag=0;
		  char num = i+'0';
		  name[length++]=num;
		  name[length]='\0';
		  strcat(name,".jpg");

		  printf("Transfer  %s\n",name);
		  FILE* fp = fopen(name, "rb");
		  fseek(fp, 0, 2);    // file pointer at the end of file
		  sz = ftell(fp);   // take a position of file pointer un size variable
		  fclose(fp);
		  size = sz/4;
		  //size += ( sz%4 == 0 ) ? 0:1;
		  code = 100+i;

		  fp = fopen(name, "rb");
		  send(newSocket,(void *)&code,sizeof(int),0);
		  send(newSocket,(void *)&size,sizeof(int),0);

		  printf("Sending %s Now..\n",name);
		  if(fp != NULL)
		  {
		    while(fread(&ini, sizeof(int), 1, fp))
		    {
		      send(newSocket,(void *)&ini,sizeof(int),0);
		      flag++;
		    }
		    printf("%s Sent Successfully! \n \n",name);
		    fclose(fp);
		  }
		  else
		  {
		          perror("File");
		  }
		}

		code = 555;
		send(newSocket,(void *)&code,sizeof(int),0);
	}
	return 0;
}
