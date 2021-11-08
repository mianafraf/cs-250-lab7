#include <iostream> 
#include <time.h>

using namespace std;

int main(){
	int x;
	cout << "Enter the number of times dice to be thrown: ";
	cin >> x;
	srand(time(NULL));
	for (int i = 0; i < x; i++){
		
		cout << rand() % 5 + 1 << endl;
	}
	return 0;
}
