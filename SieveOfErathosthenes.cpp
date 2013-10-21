// Sieve Of Eratosthenes
// Introduction to Programming with C++
// Second Edition
// Y. Daniel Liang
// 
// Modified By:
// Carlton Duffett
// October 6, 2013

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	cout << "Find all prime numbers < n, enter n: ";
	int n;
	cin >> n;
	
	bool *primes = new bool[n]; // Prime number Sieve
	
	// Initialize primes[i] to true
	for (int i = 0; i < n; i++){
		primes[i] = true;
	}
	
	// Eliminate non-primes
	for (int k = 2; k <= n / k; k++){
		
		if (primes[k]){
			
			for (int i = k; i <= n / k; i++){
				primes[k * i] = false; // k*i is not a prime number
			}
		}
	}
	
	// Display prime numbers
	const int NUMBER_PER_LINE = 10;
	int count = 0;
	
	for (int i = 2; i < n; i++){
		
		if (primes[i]){
			
			count++;
			if (count%NUMBER_PER_LINE == 0){
				cout << setw(4) << i << endl;
			}else{
				cout << setw(4) << i << " ";
			}
		}
	}
	
	cout << "\n" << count << " is the number of primes < " << n << endl;
	
	delete [] primes;
	
	return 0;	
}