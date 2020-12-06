all:client server

server:server.o Shuffle.o
	g++ -o server server.o Shuffle.o -lpthread
client:client.cc
	g++ -o client client.cc
server.o:server.cc
	g++ -c server.o server.cc
client.o:client.cc
	g++ -c client.o client.cc
Shuffle.o:Shuffle.cc
	g++ -c -o Shuffle.o Shuffle.cc

clean:
	rm server client *.o
1:
	./server 10080
2:
	./client localhost 10080
