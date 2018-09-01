#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <math.h>


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
