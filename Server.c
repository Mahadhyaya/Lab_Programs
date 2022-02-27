#include<stdio.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	char fname[50], buffer[50];
	int s, n, source, file, len;
	struct sockaddr_in address;
	struct sockaddr_in cli;
	address.sin_family = AF_INET;
	address.sin_port = htons(15000);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	printf("Waiting for request:\n");
	s = socket(AF_INET, SOCK_STREAM, 0);
	bind(s, (struct sockaddr*)&address, sizeof(address));
	listen(s,1);
	source = accept(s, (struct sockaddr*)&cli, &len);
	recv(source, fname, sizeof(fname), 0);
	printf("Request for file\n");
	file = open(fname, O_RDONLY);
	if (file < 0) {
		printf("Not Found\n");
		send(source, "File Not Found", 0, 0);
	} else {
		printf("File found and Sent successfully\n");
	}
	if ((n = read(file, buffer, sizeof(buffer))) > 0) {
		send(source, buffer, n, 0);
	}
	close(file);
	return 0;
}
