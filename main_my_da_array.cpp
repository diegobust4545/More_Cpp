// Diego Bustamante
// Lab Partner: Shane Chamberlain
// Section A 340

#include <iostream>
#include "my_da_array.h"


using namespace std;

int main(){
    my_da_array a;
    a.print();

    int num;
    //cout << "Insert value for Nondefault constructor: \n";
    //cin >> num;
    my_da_array b(4);
    b.print();


    b.da_push(8);
    b.da_push(2);
    b.da_push(6);
    b.da_push(2);
    b.da_push(3);
    //b.print();
   
    

    b.print();
    int insertVal = b.da_insert(2,9);
    cout << "Insert Function Test(1 or 0): " << insertVal <<endl;
    b.print();

    int popVal = b.da_pop();
    cout << "Pop Function Test: " << popVal <<endl;
    

    int index = b.get_elem(3);
    cout << "Testing get_elem Function: " << index << endl;
    index = b.get_elem(20);
    cout << "Testing get_elem Function: " << index << endl;
    
    int getVal = b.get_size();
    cout << "Testing get_size Function: " << getVal << endl;

    b.print();

    int maxmin = b.find_maxmin(false);
    cout << "Testing maxmin Function(false): " << maxmin <<endl;
    maxmin = b.find_maxmin(true);
    cout << "Testing maxmin Function(true): " << maxmin <<endl;
    
    
    int exist = b.is_elem(2);
    cout << "Checking Existance of 2: " << exist << endl;
    


    exist = b.is_elem(12);
    cout << "Checking Existance of 12: " << exist << endl;
    


    b.print();
    return 0;
}


// Default Constructor
my_da_array::my_da_array(){
	struc.size = 1;
	int *arraySize = new int[struc.size];
    arraySize[struc.size] = 0;
    struc.test_ptr = &arraySize[struc.size];
}


// Non default Constructor
my_da_array::my_da_array(int num){
	struc.size = 1;
	int *arraySize = new int[struc.size];
    arraySize[struc.size] = num;
    struc.test_ptr = &arraySize[struc.size];
}



// Destructor
my_da_array::~my_da_array(){
	//cout << "Testing Desrtuctor! \n";
}




//prints out the array
void my_da_array::print(){
	//cout <<"Using The Print Function \n";
	for (int j = 0; struc.size>j;j++){
        cout <<struc.test_ptr[j]<< " ";
    }
    cout << endl;
}



// Adds an int into the array
int my_da_array::da_push(int newnum){
	//cout <<"Currenlty Pushing: " << newnum << endl;
	int numReturn;
	try{
		int oldsize = struc.size;
    	int *arraySize = new int[struc.size+1];

    	for (int j = 0; struc.size>=j; j++){
        	arraySize[j] = struc.test_ptr[j];
      	//cout <<"Inside Array Loop: " << arraySize[j] << endl;
    	}
    	arraySize[oldsize] = newnum;
   		struc.size = struc.size + 1;
    	struc.test_ptr = arraySize;	

    	delete [] struc.test_ptr;
    	numReturn = 0;
	}
	catch(int e){
		numReturn = -1;
	}
	return numReturn;

}



// Removes the last int from the Array
int my_da_array::da_pop(){
	int numReturn;
	if (get_size()>1)
	{
		cout <<"Removing last element. \n";
		int oldsize = struc.size;
    	int *arraySize = new int[struc.size];

    	for (int j = 0; struc.size>=j; j++){
        	arraySize[j] = struc.test_ptr[j];
      		//cout <<"Inside Array Loop: " << arraySize[j] << endl;
    	}
    	numReturn = arraySize[get_size()-1];
        //cout << "NNumRehf"<<numReturn << endl;
    	struc.size = struc.size - 1;
    	struc.test_ptr = arraySize;
    	delete [] struc.test_ptr;

	}
	else if(get_size()==1){
		struc.test_ptr[0] = 0;
		numReturn = struc.test_ptr[0];
	}

    return numReturn;

}

int my_da_array::da_insert(int pos, int newInt){
	try{

		int *arraySize = new int[struc.size];
		for (int j = 0; struc.size>j;j++){
        	cout <<arraySize[j]<< " ";
    	}
    	cout << endl;

    	for(int i = struc.size; i > 0; i--) {
    		// 
    		if (i < pos){
    			arraySize[i] = struc.test_ptr[i];
    		}
    		if (i==pos){
    			arraySize[i] = newInt;
    		}
    		if (i>pos){
    			arraySize[i] = struc.test_ptr[i-1];
    		}
    		//cout << "Size: " << i << endl;
    
     	}

		struc.size = struc.size + 1;
	    struc.test_ptr = arraySize;
	    delete [] struc.test_ptr;
		return 1;
    }


	catch(int e){
		return 0;
	}
	return 0;

}

// returns the element of the array at index
int my_da_array::get_elem(int indexNum){
	int reNum;
	if(indexNum<struc.size){
		reNum = struc.test_ptr[indexNum];
	}
	else
		reNum = -1;

	return reNum;

}

// returns the integer size variable.
int my_da_array::get_size(){
	return struc.size;
}

// Finds max and min values accoriding to boolean
int my_da_array::find_maxmin(bool maxmin){
	int numReturn;
	int size = struc.size;
	int *arraySize = new int[size];
    for (int j = 0; struc.size>=j; j++){
        arraySize[j] = struc.test_ptr[j];
      	//cout <<"Inside Array Loop: " << arraySize[j] << endl;
    }
    //sort(arraySize, size+arraySize);

	if (maxmin == true){
		numReturn=0;
		for(int i=0;i<size;i++)
    	{
        	if(arraySize[i]>numReturn){
        		numReturn = arraySize[i];
        	}
    	}
		//cout << "Max Number Return: " << arraySize[struc.size-1] << endl;
	}
	else{
		for(int i=0;i<size;i++)
    	{
        	if(arraySize[i]>numReturn){
        		numReturn = arraySize[i];
        	}
    	}
    	for(int i=0;i<size;i++)
    	{
        	if(arraySize[i]<numReturn){
        		numReturn = arraySize[i];
        	}
    	}
		//cout << "Minumum Number Return: " << arraySize[0] << endl;
	}
	delete [] arraySize;
	return numReturn;
}

// return the index of an element if it exists
int my_da_array::is_elem(int elem){
	int numReturn = -1;
	for(int i =0; i<struc.size; i++){
		if (struc.test_ptr[i] == elem){
			numReturn = i;
			break;
		}
	}
	return numReturn;
}

