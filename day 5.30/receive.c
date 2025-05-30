

//////////////////////////////////////



#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Receiving message
    msgrcv(msgid, &message, sizeof(message), 1, 0);

    // Display the message
    printf("Data received is: %s \n", message.mesg_text);

    // Destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
