#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <strings.h>
#include <unistd.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/socket.h>


#define M_LINE  511
#define MAX_SOCKET 1024

char *EXIT_STRING = "exit"; 
char *START_STRING = "Connected to Server \n"; 

int max_fdp1;				
int n_user = 0;			
int n_chat = 0;			
int client_sock_list[MAX_SOCKET];		
char ip_list[MAX_SOCKET][20];		
int listen_sock;			
void addClient(int s, struct sockaddr_in *new_client_addr);   
int get_max();				
void removeClient(int s);	
int tcp_listen(int host, int port, int backlog); 
void err_quit(char *msg) { perror(msg); exit(1); }

time_t ct;
struct tm tm;

// Thread
void *thread_function(void *arg)
{
	int i;
	while (1)
	{
		char buf_msg[M_LINE + 1];
		printf("server > ");
		fgets(buf_msg, M_LINE, stdin); 
		
		if (!strcmp(buf_msg, "\n")) continue;   
		
		else if (!strcmp(buf_msg, "n_user\n"))
			printf("Now Chatting play User = %d\n", n_user);
		
		else if (!strcmp(buf_msg, "ip_list\n"))
			for (i = 0; i < n_user; i++)
				printf("%s\n", ip_list[i]);
		else 
			printf("Error\n");
	}
}


// Main
int main(int argc, char *argv[])
{
	struct sockaddr_in client_addr;
	char buf[M_LINE + 1]; 
	int i, j, nbyte, accp_sock, addrlen = sizeof(struct
		sockaddr_in);
	fd_set read_fds;	
	pthread_t a_thread;

	if (argc != 2)
	{
		printf("Using :%s port\n", argv[0]);
		exit(0);
	}

	// tcp_listen(host, port, backlog) method call
	listen_sock = tcp_listen(INADDR_ANY, atoi(argv[1]), 5);

	// Create Thread
	pthread_create(&a_thread, NULL, thread_function, (void *)NULL);
	while (1)
	{
		FD_ZERO(&read_fds);
		FD_SET(listen_sock, &read_fds);
		
		for (i = 0; i < n_user; i++)
			FD_SET(client_sock_list[i], &read_fds);

		max_fdp1 = get_max() + 1;	
		
		if (select(max_fdp1, &read_fds, NULL, NULL, NULL) < 0)
			err_quit("select fail");

		if (FD_ISSET(listen_sock, &read_fds))
		{
			accp_sock = accept(listen_sock,
				(struct sockaddr*)&client_addr, &addrlen);
				
			if (accp_sock == -1) err_quit("accept fail");
			addClient(accp_sock, &client_addr);
			send(accp_sock, START_STRING, strlen(START_STRING), 0);
			ct = time(NULL);			
			tm = *localtime(&ct);
			write(1, "\033[0G", 4);	
				
			printf("[%02d:%02d:%02d]  ", tm.tm_hour, tm.tm_min, tm.tm_sec);
			printf("Connect New User, Now Chatting User = %d\n", n_user);

			fprintf(stderr, "server>"); 
		}

		// Client to Message at All CLient Publisher
		for (i = 0; i < n_user; i++)
		{
			if (FD_ISSET(client_sock_list[i], &read_fds))
			{
				n_chat++;		
				nbyte = recv(client_sock_list[i], buf, M_LINE, 0);
				
				if (nbyte <= 0)
				{ 
					removeClient(i);
					continue;
				}
				buf[nbyte] = 0;
				
				if (strstr(buf, EXIT_STRING) != NULL)
				{
					removeClient(i);	
					continue;
				}
				
				// All User Publisher
				for (j = 0; j < n_user; j++)
					send(client_sock_list[j], buf, nbyte, 0);
					
				printf("\033[0G");		
				printf("%s", buf);		
				fprintf(stderr, "server>"); 
			}
		}
	}
	return 0;
}


// New User Connect
void addClient(int s, struct sockaddr_in *new_client_addr)
{
	char buf[20];
	inet_ntop(AF_INET, &new_client_addr->sin_addr, buf, sizeof(buf));
	write(1, "\033[0G", 4);		
	printf("===============================================\n");
	printf("\n[ New User: %s ]\n", buf); 

	client_sock_list[n_user] = s;
	strcpy(ip_list[n_user], buf);
	n_user++; 
}


// Chatting Leave
void removeClient(int s)
{
	close(client_sock_list[s]);
	if (s != n_user - 1)
	{ 
		client_sock_list[s] = client_sock_list[n_user - 1];
		strcpy(ip_list[s], ip_list[n_user - 1]);
	}
	n_user--; 
	ct = time(NULL);		
	tm = *localtime(&ct);
	write(1, "\033[0G", 4);	
	
	printf("[%02d:%02d:%02d]", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("User Chatting leave.... Now User Count = %d\n", n_user);
	fprintf(stderr, "[ Server ]"); 
}

// Max Socket Number find
int get_max()
{

	int max = listen_sock;
	int i;
	for (i = 0; i < n_user; i++)
		if (client_sock_list[i] > max)
			max = client_sock_list[i];
	return max;
}


// listen socket create && listen
int  tcp_listen(int host, int port, int backlog)
{
	int sd;
	struct sockaddr_in server_addr;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("socket fail");
		exit(1);
	}

	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(host);
	server_addr.sin_port = htons(port);
	
	if (bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("bind fail");  exit(1);
	}

	listen(sd, backlog);
	return sd;
}


