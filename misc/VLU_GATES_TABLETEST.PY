

# 12/17/2022
########################################################
# simple form

# OR GATE
table = "000011101111"
#          |  |  |  |

A = "0"
B = "0"


for i in range(0, 12, 3):
	if A==table[i+0] and B==table[i+1]:
		print(table[i+2])
		break


for i in range(4):
	if A==table[i*3+0] and B==table[i*3+1]:
		print(table[i*3+2])
		break


########################################################



# UNIVERSAL LOGIC GATES TABLE                                                                   [   IDEAL FOR OS BINARY   ]
#        |   AND    ||    OR    ||   NAND   ||    NOR   ||    XOR   ||   XNOR   ||NOT||BUFFER|
table = "00001010011100001110111100101110111000101010011000001110111000101010011101100011"
#        |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | | | | |       CONDITION
#        0           12          24          36          48          60          72  76  80


"""
::jump modes::
MODE  in  GATE
[0x0] [2] AND
[0x1] [2] OR
[0x2] [2] NAND
[0x3] [2] NOR
[0x4] [2] XOR
[0x5] [2] XNOR
[0x6] [1] NOT
[0x7] [1] BUFFER
"""
def GATES(mode, A, B):
	#(mode < 0x5) ? 12 : 4;
	#12 if (mode < 0x5) else 4;
	
	for i in range(4):
		if A==table[(mode*12)+(i*3+0)] and B==table[(mode*12)+(i*3+1)]:
			print(table[(mode*12)+(i*3+2)])
			break


GATES(0x1, "0", "1")


########################################################
# CONSIDERING "NOT" AND "BUFFER"


# UNIVERSAL LOGIC GATES TABLE                                                                   [   IDEAL FOR OS BINARY   ]
#        |   AND    ||    OR    ||   NAND   ||    NOR   ||    XOR   ||   XNOR   ||NOT||BUFFER|
table = "00001010011100001110111100101110111000101010011000001110111000101010011101100011"
#        |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  | | | | |       CONDITION
#        0           12          24          36          48          60          72  76  80


"""
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
"""
def GATES(mode, A, B):
	condition = 4 if (mode < 0x5) else 2
	hop = (mode*12) if (mode < 0x5) else 72+((mode-0x5-1)*4)
	
	for i in range(condition):
		if (mode > 0x5) and A==table[hop+(i*2+0)]:
			print(table[hop+(i*2+1)])
			break
		elif A==table[hop+(i*3+0)] and B==table[hop+(i*3+1)]:
			print(table[hop+(i*3+2)])
			break


GATES(0x1, "1", "1")



