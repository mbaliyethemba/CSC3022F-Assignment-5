CFLAGS = -O
CC = g++

pca: driver.o
	$(CC) $(CFLAGS) -o pca driver.o pca.o --std=c++11

driver.o: pca.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

pca.o: pca.h pca.cpp
	$(CC) $(CFLAGS) -c pca.cpp --std=c++11

run:
	./pca

clean:
	rm -f core *.o
