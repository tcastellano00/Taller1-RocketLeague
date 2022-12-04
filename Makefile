server: 
	./build/rocket_league-server 8081

server_leaks:
	valgrind -s --track-origins=yes --tool=memcheck ./build/rocket_league-server 8080

client: 
	./build/rocket_league localhost 8081

client_gdb:
	gdb ./build/rocket_league

client_leaks:
	valgrind -s --track-origins=yes --tool=memcheck ./build/rocket_league localhost 8080

server_gdb:
	gdb ./build/rocket_league-server

test:
	./build/tests

pc:
	gdb --tui ./build/rocket_league

ps:
	gdb --tui ./build/rocket_league-server