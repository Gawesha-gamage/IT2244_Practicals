//send
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

//structure for message queue
struct mesg_buffer{
	long mesg_type;
	char mesg_text[100];
	
}message;
int main()
{
key_t key;
int msgid;

//ftok to genetate unique key
key=ftok("progfile",65);

//msgget creates a message queue
//and returns idenifier

msgid=msgget(key,0666 | ICP_CREAT);
message.mesg_type=1;

printf("write data:");
fgets(message.mesg_text,MAX,stdin);
//msgsnd to send message
msgsnd(mgsid,&message,sizeof(message),0);
//display the message
printf("Data send is: %s \n",message.mesg_text);

return 0;
	
}


