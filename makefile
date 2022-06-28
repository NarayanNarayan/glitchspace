all:
	g++ lib/filedegenerator.cpp -o test
	./test > output.txt
	cat ./output.txt
clean:
	rm ./output.txt
	rm ./test