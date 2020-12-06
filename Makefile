all:client server

server:server.cc
	gcc -o server server.cc -lpthread
client:client.cc
	gcc -o client client.cc
clean:
	rm server client
1:
	./server 10080
2:
	./client localhost 10080
