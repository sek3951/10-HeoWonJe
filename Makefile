all:client server

server:server.c
	gcc -o server server.c -lpthread
client:client.c
	gcc -o client client.c
clean:
	rm server client
1:
	./server 10080
2:
	./client localhost 10080
