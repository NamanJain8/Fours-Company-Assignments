#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
  int clientSocket;
  char buffer[1024];
  scanf("%[^\n]%*c",buffer);

  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(5432);

  serverAddr.sin_addr.s_addr = inet_addr("172.17.0.2");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  send(clientSocket,buffer,1024,0);

  /*get in all files*/
  // 10* 20* 30* 40* 999 555
  int ini,packs,name,length;
  char n_string[50];  
  while(1)
  {
    recv(clientSocket,&name,sizeof(int),0);
    if(name == 555)
    {
      printf("End of File Receive\n");
      break;
    }
    
    // printf("%s\n", );
    recv(clientSocket,&packs,sizeof(int),0);
    //recv(clientSocket,&name,sizeof(int),0);
    printf("Pack %d name %d\n",packs,name );
    if(name/100 == 1)
    {
      strcpy(n_string,"car");
    }
    else
      if(name/100 == 2)
      {
        strcpy(n_string,"cat");
      }
      else
        if(name/100 == 3)
        {
          strcpy(n_string,"dog");
        }
        else
          if(name/100 == 4)
          {
            strcpy(n_string,"truck");
          }
          else
            if(name == 999)
            {
              strcpy(n_string,"index.html");
            }
            else
            {
              printf("Something's Wrong here :Invalid Response from server\n");
              break;
            }
  if(name/100 !=9)
  {
    length = strlen(n_string);
    n_string[length++]='0'+ (name%100);
    n_string[length]='\0';
    strcat(n_string,".jpg");
  }         
    FILE* fp = fopen(n_string, "wb");
    printf("Receiving %s .. \n",n_string);
    while(packs)
    {
      recv(clientSocket,&ini,sizeof(int),0);
      packs--;
    fwrite(&ini, sizeof(int), 1, fp);   
    }
    fclose(fp);
    printf("Received %s successfully!: \n",n_string);
  }
  return 0;
}
