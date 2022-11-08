server: 
	./build/rocket_league-server 8080

client: 
	./build/rocket_league localhost 8080

client_gdb:
	gdb ./build/rocket_league

server_gdb:
	gdb ./build/rocket_league-server

pc:
	gdb --tui ./build/rocket_league

ps:
	gdb --tui ./build/rocket_league-server