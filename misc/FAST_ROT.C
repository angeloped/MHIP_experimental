#include <stdio.h>

//https://gist.github.com/angeloped/80e65fa9e3c354ed5a81b2d8aec18f0d
// 12/21/2022
// calculating where to begin swapping with
//[0x0] LTR - left to right
//[0x1] RTL - right to left
int predict_swap(int mode, int index_mx, int start, int steps){
	if(mode==0x0){
		return (start+steps)%index_mx;
	}else if(mode==0x1){
		return (start-steps)%index_mx;
	}
	return 0;
}


int ROTX(int mode, int shift, int arr_sz){
	int test[arr_sz] = {1,2,3,4,5}; // sample
	
	// this will shorten looping process
	shift = shift % arr_sz;
	
	int hold=0, data=0;
	for(int i=0; i<arr_sz-1; i++){
		// predicting swap position index
		// mode, index_mx, start, steps
		//int to_swap = predict_swap(mode, arr_sz, hold, shift); //(it depends on you)
		int to_swap = (mode==0x0) ? (start+steps)%index_mx : (mode==0x1) ? (start-steps)%index_mx : 0;
		
		// register data to buff
		data = test[to_swap];
		
		// swapping process
		test[to_swap] = test[hold];
		test[hold] = data;
		
		// the index that's been switched with
		// is the next thing to process
		hold = to_swap;
	}
	
	for(int i=0; i<arr_sz; i++){
		printf("%d %d\n", i, test[i]);
	}
	
	return 0;
}


int main(){
	ROTX(0x0, 0, 5);
	
	return 0;
}
