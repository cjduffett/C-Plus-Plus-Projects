// Carlton Duffett
// October 7, 2013
//
// Simple recursive prime number generator
// simplePrimes.cpp

#include <iostream>

using namespace std;

int main(){
	
	cout << "Generates all prime numbers < n, enter n: ";
	int n;
	cin >> n;
	
	int count = 0;
	
	for (int i = 2; i < n; i++){
		
		bool isPrime = true;
		
		// test if number is prime
		for (int j = 2; j <= i / 2; j++){
			
			if (i%j == 0){
				isPrime = false;
				break;
			}
		}
		
		if (isPrime){
			count ++;
			cout << i << " ";
		}
	}
	
	return 0;
}
