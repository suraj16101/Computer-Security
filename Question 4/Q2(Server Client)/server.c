#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>

struct sockaddr_in server_socket;
int fd, connection;
char temp[100]="";
char message[1024] = "";
int port = 5000;
int text;
SSL_CTX *ctx;
char num[100]="";
char* cert = "mycert.pem";
char* key = "mycert.pem";
int errnum=0;

void load_cert() {
	if (SSL_CTX_use_PrivateKey_file(ctx, key, SSL_FILETYPE_PEM) > 0) {
		
	}
	else{
		printf("Error in key\n");
		exit(1);
	}

	if (SSL_CTX_use_certificate_file(ctx, cert, SSL_FILETYPE_PEM) > 0) {
		
	}
	else{
		printf("Error in cert\n");
		exit(1);
	}

	if (SSL_CTX_check_private_key(ctx)) {
		
	}
	else{
		printf("Error in match\n");
		exit(1);
	}
}

void CTX_init() {
	SSL_METHOD *method;
	int check=0;
	OpenSSL_add_all_algorithms();
	check++;
	SSL_load_error_strings();
	check++;
	method = TLSv1_2_server_method();

	if ((ctx = SSL_CTX_new(method)) != NULL) {
		
	}
	else{
		printf("Error ctx\n");
		exit(1);
	}

	check=0;
	load_cert();
}

int main() {


	server_socket.sin_family = AF_INET;
	SSL_library_init();
	server_socket.sin_port = htons(port);
	CTX_init();
	server_socket.sin_addr.s_addr = INADDR_ANY;

	fd = socket(AF_INET, SOCK_STREAM, 0);

	if (fd <=0 ) {
		printf("Error3\n");

	}
	else {
		if(bind(fd, (struct sockaddr *) &server_socket, sizeof(server_socket)) == 0) {
			
		}

		else {
			printf("Error\n");
			exit(1);
		}

		if(listen(fd, 10) == 0) {
			
		}

		else{
			printf("Error\n");
			exit(1);
		}

		while (connection = accept(fd, (struct sockaddr *)NULL, NULL)) {
			SSL *ssl;
			int pid = fork();
			

			if (pid != 0) {
				
			}
			else{
				ssl = SSL_new(ctx);
				SSL_set_fd(ssl, connection);

				if(SSL_accept(ssl) != -1) {
					
				}
				else{
					printf("Error in accepting \n");
					exit(1);
				}

				int bytes;
				while((bytes = SSL_read(ssl, message, sizeof(message))) > 0) {
					message[bytes] = 0;
					int length = 0;
					printf("Message from %d: %s\n", connection, message);

					SSL_write(ssl, message,strlen(message) );
					message[0] = '\0';
				}

				int client_fd = SSL_get_fd(ssl);
				SSL_free(ssl);
				close(client_fd);
			}
		}

		close(fd);
		SSL_CTX_free(ctx);
	}

	return 0;
}
