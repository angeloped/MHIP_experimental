
#include <stdio.h>


/*
12/11/2022
12/20/2022 (finished)

::SHIFT / ROTATE::
L_LSHIFT - left logical shift
R_LSHIFT - right logical shift
L_ASHIFT - left arithmetic shift
R_ASHIFT - right arithmetic shift
LROT - left rotate
RROT - right rotate


*/


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


///////////////////////////////////////////////////////


//[0x0] L_LSHIFT - left logical shift
//[0x1] R_LSHIFT - right logical shift
int LSHIFT(int mode, int shift, int arr_sz){
	int test[arr_sz] = {1,2,3,4,5}; // sample
	
	for(int i=0; i<arr_sz; i++){
		int index_set = (mode==0x0) ? i : (mode==0x1) ? arr_sz-i-1 : 0;
		int index_get = (mode==0x0) ? i+shift : (mode==0x1) ? (arr_sz-1)-i-shift : 0;
		
		if( i < (arr_sz-shift) ){
			test[index_set] = test[index_get];
		}else{
			test[index_set] = 0;
		}
	}
	
	for(int i=0; i<arr_sz; i++){
		printf("XX %d %d\n", i, test[i]);
	}
	
	return 0;
}


//[0x0] L_ASHIFT - left arithmetic shift
//[0x1] R_ASHIFT - right arithmetic shift
int ASHIFT(int mode, int shift, int arr_sz){
	int test[arr_sz] = {1,2,3,4,5}; // sample
	
	for(int i=0; i<arr_sz; i++){
		int index_set = (mode==0x0) ? i : (mode==0x1) ? arr_sz-i-1 : 0;
		int index_get = (mode==0x0) ? i+shift : (mode==0x1) ? (arr_sz-1)-i-shift : 0;
		
		// N.B. disregarding the mainstream concept of "<<";
		// sign bit will never change on both modes. 
		if( (i < (arr_sz-shift)) && (index_set > 0) ){
			test[index_set] = test[index_get];
		}else if(index_set > 0){
			test[index_set] = 0;
		}
	}
	
	for(int i=0; i<arr_sz; i++){
		printf("XX %d %d\n", i, test[i]);
	}
	
	return 0;
}


//[0x0] L_ROT - left rotate 
//[0x1] R_ROT - right rotate
int ROT(int mode, int shift, int arr_sz){
	int test[arr_sz] = {1,2,3,4,5}; // sample
	
	// this will shorten looping process
	shift = shift % arr_sz;
	
	//int to_swap;
	int hold=0, data=0;
	for(int i=0; i<arr_sz-1; i++){
		// calculating where to begin swapping with
		// mode, index_mx, start, steps
		int to_swap = (mode==0x0) ? (hold+shift)%arr_sz : (mode==0x1) ? (hold-shift)%arr_sz : 0;
		
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
		printf("XX %d %d\n", i, test[i]);
	}
	
	return 0;
}


int main(){
	// mode, shift, arr_sz
	//LSHIFT(0x1, 0, 5);
	//ASHIFT(0x0, 0, 5);
	//ROT(0x0, 1, 5);
	return 0;
}






