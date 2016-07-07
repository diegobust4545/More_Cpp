// my_da_array.h
// Header file
#ifndef my_da_array_h
#define my_da_array_h

struct array{
	int *test_ptr;
	int size;
};

class my_da_array{
private:
array struc;


public:
	my_da_array(void);
	my_da_array(int);
	int da_push(int);
	int da_pop();
	int get_elem(int);
    void print(); 
    int get_size();
    int find_maxmin(bool);
    int da_insert(int, int);
    int is_elem(int);
    ~my_da_array(void);
};
#endif // my_da_array_h