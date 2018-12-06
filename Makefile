CC=g++
CFLAGS=-I.

vmtranslator: parser.cpp builder.cpp main.cpp
	$(CC) -o vmtranslator main.cpp parser.cpp builder.cpp