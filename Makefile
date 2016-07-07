output: main_my_da_array.o
	g++ main_my_da_array.o -o output

main_my_da_array.o: main_my_da_array.cpp
	g++ -c main_my_da_array.cpp

clean:
	rm *.o output