all:client server

server:server.o Shuffle.o
	g++ -o server server.o Shuffle.o -lpthread
client:client.o NumToCard.o
	g++ -o client client.o NumToCard.o
server.o:server.cc
	g++ -c server.o server.cc
client.o:client.cc
	g++ -c client.o client.cc
Shuffle.o:Shuffle.cc
	g++ -c -o Shuffle.o Shuffle.cc
NumToCard.o:NumToCard.cc
	g++ -c -o NumToCard.o NumToCard.cc

clean:
	rm server client *.o
1:
	./server 10080
2:
	./client localhost 10080
