final:
	g++ -o neofetch src/main.cpp src/ascii_art.cpp src/system_info.cpp
run: 
	./neofetch
clean:
	rm neofetch
