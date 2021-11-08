#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

//using boost::format;
using namespace std;
using namespace std::chrono;
vector<microseconds> tim(3); //vector to store best,worst and total running time
int i = 0;


void SingleLoopSort(vector <int>& in) {//method to sort the array

    for (int j = in.size() - 1; j > 0; j--) {
        if (in[j] < in[j - 1]) {
            int temp = in[j];
            in[j] = in[j - 1];
            in[j - 1] = temp;
        }
    }
}

void bubblesort(vector <int>& in) {//method to sort the array
    for (int i = 0; i < in.size(); i++) {
        for (int j = i; j < in.size() - 1; j++) {
            if (in[j] > in[j + 1]) {
                int temp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = temp;
            }
        }
    }
}

bool movMin(vector <int>& in, vector <int>& out) { //method to compare the output and expected output

    if (in == out) {
        return  true;
    }
    else {
        return false;
    }

}//end method movMin

 void  testMovMin(int size) { //method to run the testcase

    vector <int> array;
    
    for (int i = 0; i < size; i++) {//randomly intializing array
        array.push_back(rand() % 100);
    }

    sort(array.begin(), array.end());//sorting the array
    int t = rand() % 100;
    array.push_back(t);

    vector<int> input = array; //input vector
    sort(array.begin(), array.end());
    vector<int> output = array;//output vector

    auto start = high_resolution_clock::now();
    
    SingleLoopSort(input); //sorting the input using Single For Loop

    bool result = movMin(input, output);
    auto stop = high_resolution_clock::now();
    microseconds duration1 = duration_cast<microseconds>(stop - start);
    if (i != 0) {
        if (duration1 > tim[0]) {
            tim[0] = duration1;  //time[0] is used to store worst running time
        }
        else if (duration1 < tim[1]) {
            tim[1] = duration1;    //time[1] is used to store best running time
        }

        tim[2] += duration1; //time[2] is used to store total time of 100 test cases 

    }
    else {
        tim[0] = tim[1] = tim[2] = duration1;
        i++;
    }
    
    
}//end testMovMin

int main() {
    cout << "Time taken to exute the program is given below" << endl; 
        
    

    //auto start, stop, duration1, duration2;
    for (int i = 0; i < 100 ; i++) {

         testMovMin(100000);
    }
    cout << endl << "Input Size: 100,000" << endl;
    cout <<"Best Case Running Time : " << tim[1].count() << " microseconds" << endl;
    cout << "Worst Case Running Time : " << tim[0].count() << " microseconds" << endl;
    cout << "Average Case Running Time : " << tim[2].count() / 100 << " microseconds" << endl;

    cout << endl << "Program finished execution" << endl;
    //system("pause");
    return 0;
}
