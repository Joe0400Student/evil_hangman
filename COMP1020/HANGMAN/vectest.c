#include "vector.h"

int main(int argc, char* argv){
	vector v = __init__vector();
	for(int i = 0;i<100;i++){
		insert(v,NULL);
	}
	while(vsize(v)){
		remove(v,0);
	}
	__del__vector(&v);
}
