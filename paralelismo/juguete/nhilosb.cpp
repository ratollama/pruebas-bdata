#include <iostream>
#include <omp.h>
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
	long local_ret;
	int thread_id;
	#pragma omp parallel private(local_ret) reduction(+:ret)
	{
		local_ret = 0;
		thread_id = omp_get_thread_num();
		#pragma omp for
		for(x= start; x<=end; x++){
			if(esPrimo(factorial(x))){
				local_ret++;
			}
		}
		ret += local_ret;
	}
}



int main(){
	doWork(0, NUMBER);
	cout << ret << endl;
	
	return 0;
}