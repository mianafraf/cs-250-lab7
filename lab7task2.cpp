#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void bubblesort(vector <int> &in){//method to sort the array
	for (int i = 0; i < in.size(); i++){
		for (int j = 0; j < in.size() - 1; j++){
			if (in[j]>in[j + 1]){
				int temp = in[j];
				in[j] = in[j + 1];
				in[j + 1] = temp;
			}
		}
	}
}
bool movMin(vector <int> &in, vector <int> &out){ //method to compare the output and expected output

	if (in == out){
		return  true;
	}
	else{
		return false;
	}

}//end method movMin

void print(vector<int> in, vector<int> out)//method to print
{
	cout << "Expected Output        : Output " << endl;
	for (int i = 0; i < in.size(); i++){
		cout << out[i] << "	                " << in[i] << endl;
	}

}

void testMovMin(){ //method t run the testcase

	srand(time(NULL));

	int range = rand() % 100 + 1;
	vector <int> array;

	for (int i = 0; i <range; i++){//randomly intializing array
		array.push_back(rand() % 100);
	}

	sort(array.begin(), array.end());//sorting the array
	int t = rand() % 100;
	array.push_back(t);

	vector<int> input = array; //input vector
	bubblesort(input); //sorting the input using bubblesort

	sort(array.begin(), array.end());
	vector<int> output = array;//output vector

	bool result = movMin(input, output);
	if (result){
		cout << endl << "Test Case Passed" << endl;
		print(input, output);

	}
	if (!result){
		cout << "Test Case Failed" << endl;
		print(input, output);
	}
}//end testMovMin

int main(){
	testMovMin();
	system("pause");
	return 0;
}
