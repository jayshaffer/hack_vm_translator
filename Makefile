CC=g++ -stdlib=libc++
CFLAGS=-I.

vmtranslator: parser_result.cpp parser.cpp writer.cpp main.cpp
	$(CC) -o vmtranslator main.cpp parser.cpp writer.cpp parser_result.cpp