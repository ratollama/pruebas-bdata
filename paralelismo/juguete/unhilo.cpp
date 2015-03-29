#include <iostream>
using namespace std;
long ret;
long esPrimo(long numero){
	long x;
	for(x=2; x< numero; x++){
		if(numero%2 == 0){
			return 0;
		}
	}
	return 1;
}
long factorial(long numero){
	long ret = 1;
	long x = 1;
	for(x=1; x<=numero;x++){
		ret *= x;
	}
	return ret;
}
void doWork(long start, long end){
	long x;
	for(x= start; x<=end; x++){
		if(esPrimo(factorial(x))){
			ret++;
		}
	}
}



int main(){
	doWork(0, NUMBER);
	cout << ret << endl;
	
	return 0;
}