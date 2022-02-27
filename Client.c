#include<stdio.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	char fname[50], buffer[50];
	int s, n, source, file;
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(15000);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Socket Not Created\n");
	}
	connect(s, (struct sockaddr*)&address, sizeof(address));
	printf("Enter the file name:\n");
	scanf("%s", fname);
	printf("Sending request\n");
	send(s, fname, sizeof(fname), 0);
	if ((n = recv(s, buffer, sizeof(buffer), 0)) > 0) {
		printf("Recieved Successfully\n");
		printf("Contents:%s", buffer);
	} 
	else {
		printf("File doesn't exists\n");
	}
	close(file);
	return 0;
}
