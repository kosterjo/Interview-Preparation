EXEC   = hashtest
CFLAGS = -std=c++11 -c
LFLAGS = -std=c++11
OBJS   = hashtable.o 

hashtable.o: hashtable.cpp
	g++ hashtable.cpp $(CFLAGS)

hashtest: hash_test.cpp
	g++ $(OBJS) hash_test.cpp $(LFLAGS) -o hashtest

clean:
	rm -f $(OBJS) $(EXEC)