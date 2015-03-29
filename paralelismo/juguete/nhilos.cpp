#include <iostream>
#include <pthread.h>
#include <string.h>
using namespace std;
struct thread_data{
	int id;
	long start;
	long end;
};

long ret[NTHREADS];

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
void doWork(int id, long start, long end){
	long x;
	for(x= start; x<=end; x++){
		if(esPrimo(factorial(x))){
			ret[id]++;
		}
	}
}
void *thread_work(void *threadarg){
	struct thread_data *data;
	data = (struct thread_data *) threadarg;
	doWork(data->id, data->start, data->end);
}


int main(){
	int x;
	int salto = NUMBER/NTHREADS;
	pthread_t threads[NTHREADS];
	struct thread_data data[NTHREADS];
	void *status;
	memset(ret, 0, sizeof(ret[0]) * NTHREADS );
	for(x=0; x < NTHREADS; x++){
		
		data[x].id = x;
		data[x].start = x*salto;
		if(x == NTHREADS -1){
			data[x].end = NUMBER;
		}else{
			data[x].end = (x + 1)*salto -1;
		}
		pthread_create(&threads[x], NULL, thread_work, (void *) &data[x]);
	}
	for(x=0; x < NTHREADS; x++){
		pthread_join(threads[x], &status);
	}
	long fret;
	for(x=0; x < NTHREADS; x++){
		fret += ret[x];
	}
	cout << fret << endl;
	
	return 0;
}