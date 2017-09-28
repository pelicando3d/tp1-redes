#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv)
{
	int s;
	struct sockaddr_in dest;
	char msg_write[100], msg_read[100];
	s = socket(AF_INET, SOCK_STREAM, 0));

	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(9999);
	inet_aton("127.0.0.1", &dest.sin_addr.s_addr);

	connect(s, (struct sockaddr*)&dest, sizeof(dest));

	do {
		scanf("%s", msg_write);
		write(s, msg_write, strlen(msg_write)+1);
		read(s, msg_read, MAXBUF);
	} while (strcmp(msg_read, "bye"));

	close(s);
}
