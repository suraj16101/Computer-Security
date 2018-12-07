
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>

struct sockaddr_in client_socket;
int text;
int fd, connection,port = 5000;
int errnum=0;
char message[1024] = "";
char temp[100]="";
SSL_CTX *ctx;
SSL *ssl;
int flag=0;

void CTX_init() {
	SSL_METHOD *method;

	flag=0;

	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	flag=1;

	method = TLSv1_2_client_method();
	flag=2;

	if ((ctx = SSL_CTX_new(method)) != NULL) {
		
	}
	else{
		printf("Error ctx\n");
		exit(1);
	}

}
int main() {

	SSL_library_init();
	CTX_init();
	ssl = SSL_new(ctx);

	fd = socket(AF_INET, SOCK_STREAM, 0);

    int a=0;
	if (fd > 0) {
        a=1;
		client_socket.sin_family = AF_INET;
        a=2;
		client_socket.sin_port = htons(port);
        a=3;

	if (inet_pton(AF_INET, "127.0.0.1", &client_socket.sin_addr) >0) {
		
	}
	else{
		printf("Error2\n");
		exit(1);
	}

	if(connect(fd, (struct sockaddr *) &client_socket, sizeof(client_socket)) == 0) {
		
	}
	else{
		printf("Error3\n");
		exit(1);
	}

	SSL_set_fd(ssl, fd);

	if (SSL_connect(ssl) != -1) {
		
	}
	else{
		printf("Error ssl connect\n");
		exit(1);
	}

	while(1) {

		printf("Input Message:\n");
		fgets(message, 1024, stdin);
		SSL_write(ssl, message,strlen(message));
		message[0] = '\0';
		int bytes = SSL_read(ssl, message, sizeof(message));
		if (bytes <= 0) {
			
		}
		else{
			message[bytes] = 0;
			printf("Message Received: %s\n", message);
			message[0] = '\0';
		}
	}

	SSL_free(ssl);
	close(fd);
	SSL_CTX_free(ctx);

		
	}
	else{
		printf("Error1\n");
		exit(1);
	}

	
	return 0;
}
