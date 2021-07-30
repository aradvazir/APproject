server: server.cpp
	g++ -std=c++11 -o server server.cpp -lpthread -I.
	g++ -std=c++11 -o cli client.cpp -lpthread -I.
	./server
	rm server
client:
	./cli