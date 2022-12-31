#include <stdio.h>

/*
12/18/2022


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
*/


// UNIVERSAL LOGIC GATES TABLE                                                                   [   IDEAL FOR OS BINARY   ]
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

int main(){
	printf("%d\n", GATES(0x6, 1, 0));
	return 0;
}


