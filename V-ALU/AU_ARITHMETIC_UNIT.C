#include <stdio.h>

//verify https://www.ecalculator.co/calc/binary-calculator
/*
V-AU (VIRTUAL ARITHMETIC UNIT)
12/08/2022

ADD
SUB
MUL
DIV

*/



void ADD(){
	int bits = 5;
	int carry[bits+1] = {0,0,0,0,0,0}; // carry
	int sum[bits]   = {0,0,0,0,0};     // sum
	int binA[bits]  = {0,1,0,1,1};     // addend
	int binB[bits]  = {0,1,0,0,1};     // addend
	
	for(int i=bits-1; i>=0; i--){
		// half-adder
		carry[i] = ( binA[i] & binB[i] );
		sum[i]   = ( binA[i] ^ binB[i] );
		
		// half-adder (full)
		carry[i] = ( carry[i+1] & sum[i] ) | carry[i];
		sum[i]   = ( carry[i+1] ^ sum[i] );
		
		printf("%d - %d | %d %d = %d                 %d\n", i, carry[i+1], binA[i], binB[i], sum[i],  ( carry[i+1] & sum[i] ) );
	}
}



void SUB(){
	int bits = 5;
	int borrow[bits+1] = {0,0,0,0,0,0}; // borrow
	int diff[bits]  = {0,0,0,0,0};      // difference
	int binA[bits]  = {1,1,0,1,1};      // minuend
	int binB[bits]  = {0,1,0,0,1};      // subtrahend
	
	for(int i=bits-1; i>=0; i--){
		// half-subtractor
		borrow[i] = ( (!binA[i]) & binB[i] );
		diff[i]   = ( binA[i] ^ binB[i] );
		
		// half-subtractor (full)
		borrow[i] = ( borrow[i+1] & diff[i] ) | borrow[i];
		diff[i]   = ( borrow[i+1] ^ diff[i] );
		
		printf("%d - %d | %d %d = %d                 %d\n", i, borrow[i+1], binA[i], binB[i], diff[i],  ( borrow[i+1] & diff[i] ) );
	}
}



void MUL(){
	int bits = 5;
	int carry[bits+1] = {0,0,0,0,0,0}; // carry
	
	int buffr[bits]   = {0,0,0,0,0};   // buffer
	
	int prdct[bits]   = {0,0,0,0,0};   // product
	int binA[bits]  = {0,1,0,1,1};     // multiplicand
	int binB[bits]  = {0,1,0,0,1};     // multiplier
	
	for(int i=bits-1; i>=0; i--){
		// clear buffer and carry
		//for(int iii=0; iii<5; iii++){buffr[iii] = 0;}
		for(int iii=0; iii<6; iii++){carry[iii] = 0;}
		
		// format buffer then add with the product
		//                     v (not 0)
		for(int ii=bits-1; ii>=((bits-1)-i); ii--){
			
			// half-adder
			//                                A           |          B
			carry[ii-(bits-1-i)] = ( binA[ii] & binB[i] ) & buffr[ii-(bits-1-i)];
			buffr[ii-(bits-1-i)] = ( binA[ii] & binB[i] ) ^ buffr[ii-(bits-1-i)];
			
			// half-adder (full)
			//                                  A           |          B             |           C
			carry[ii-(bits-1-i)] = ( carry[ii-(bits-1-i)+1] & buffr[ii-(bits-1-i)] ) | carry[ii-(bits-1-i)+1];
			buffr[ii-(bits-1-i)] = ( carry[ii-(bits-1-i)+1] ^ buffr[ii-(bits-1-i)] );
			
			//     v (bits-1)-((bits-1)-i)
			//buffr[ii-(bits-1-i)] = ( binA[ii] & binB[i] );
			
		}
		
		// print buffer
		for(int iii=0; iii<5; iii++){printf("%d", buffr[iii]);}
		printf("    %d     \n",i);
	}
}



void DIV(){}




int main(){
	ADD();
	//SUB();
	//MUL();
}
