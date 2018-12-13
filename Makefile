CC=clang++ -std=gnu++11
CFLAGS=-I.

vmtranslator: parser.cpp writer.cpp main.cpp
	$(CC) -o vmtranslator main.cpp parser.cpp writer.cpp