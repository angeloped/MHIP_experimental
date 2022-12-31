
#include <stdio.h>

/*
V-LU (VIRTUAL LOGICAL UNIT)
12/11/2022


This unit is divided into two parts:
[A] LOGIC GATES
[B] BIT SHIFT/ROTATE

::LOGIC GATES::
NOT
BUFFER
AND
OR
NAND
NOR
XOR
XNOR



TRUTH TABLE:
Example: (AND GATE)
  A     B     C     D
[000] [010] [100] [111]

Table:
AND           OR          
000010100111  000011101111

NAND          NOR
001011101110  001010100110

XOR           XNOR
000011101110  001010100111

NOT           BUFFER
0110          0011


::SHIFT / ROTATE::
L_LSHIFT - left logical shift
R_LSHIFT - right logical shift
L_ASHIFT - left arithmetic shift
R_ASHIFT - right arithmetic shift
LROT - left rotate
RROT - right rotate


*/



//////////////////////////////////////////////////////
/// Math Caulculations ///////////////////////////////
//////////////////////////////////////////////////////


double max(double num1, double num2){
	return (num1 > num2 ) ? num1 : num2;
}


double min(double num1, double num2){
	return (num1 > num2 ) ? num2 : num1;
}


///////////////////////////////////////////////////////
// 12/18/2022 /////////////////////////////////////////
// UNIVERSAL LOGIC GATES FUNCTION /////////////////////                [   IDEAL FOR OS BINARY   ]
///////////////////////////////////////////////////////
//               |         AND         | |          OR         | |         NAND        | |         NOR         | |         XOR         | |         XNOR        | | NOT | | BUFFER|
int table[80] = {0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,0,1,1};
//               |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |   |   |   |   |
//               0                       12                      24                      36                      48                      60                      72      76      80


/*
::jump modes::
MODE  in  GATE
[0x0] [2] AND
[0x1] [2] OR
[0x2] [2] NAND
[0x3] [2] NOR
[0x4] [2] XOR
[0x5] [2] XNOR
[0x6] [1] NOT    (B is ignored)
[0x7] [1] BUFFER (B is ignored)
*/
int GATES(int mode, int A, int B){
	int condition = (mode < 0x5) ? 4 : 2;
	int hop = (mode < 0x5) ? (mode*12) : 72+((mode-0x5-1)*4);
	
	for(int i=0; i<condition; i++){
		if((mode > 0x5) && A==table[hop+(i*2+0)]){
			return table[hop+(i*2+1)];
		}else if(A==table[hop+(i*3+0)] && B==table[hop+(i*3+1)]){
			return table[hop+(i*3+2)];
		}
	}
	return -1;
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




int test[5] = {1,1,1,1,1};
int save[1];

int main(){
	// mode, shift, arr_sz
	//LSHIFT(0x1, 0, 5);
	//ASHIFT(0x0, 0, 5);
	//ROT(0x0, 1, 5);
	//printf("%d\n", GATES(0x0, 0, 1));
	
	return 0;
}






