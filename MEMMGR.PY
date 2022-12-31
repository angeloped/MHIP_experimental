"""
12/01/2022

SEQUENTIAL ACCESS MEMORY SIZE
[00000000]–[99999999]



DATA STRUCTURES


::VARIABLE DATA TYPES::
CODE / TYPE / SIZE / LIMIT / BIN
0x0   CHAR       (9   BITS)    ±255                    (1)11111111–(0)11111111
0x1   INT        (17  BITS)    ±65535                  (1)1111111111111111–(0)1111111111111111
0x2   FLOAT      (33  BITS)    ±42949672.95            (1)11111111111111111111111111111111–(0)11111111111111111111111111111111
0x3   DOUBLE     (65  BITS)    ±18446744073709.551615  (1)1111111111111111111111111111111111111111111111111111111111111111–(0)1111111111111111111111111111111111111111111111111111111111111111
0x4   MORPH INT  (1+N BITS)    ±1+N                    (1)N–(0)N
0X5   MORPH FRC  (1+N+F BITS)  ±1+NE(-F)               (1)1+NE(-F)–(0)1+NE(-F)

::ARRAY DATA TYPES::
CODE / TYPE / SIZE / LIMIT / BIN
0x6   CHAR*       A*(9     BITS)    ±255,..                    { (1)11111111–(0)11111111 ,..}
0x7   INT*        A*(17    BITS)    ±65535,..                  { (1)1111111111111111–(0)1111111111111111 ,..}
0x8   FLOAT*      A*(33    BITS)    ±42949672.95,..            { (1)11111111111111111111111111111111–(0)11111111111111111111111111111111 ,..}
0x9   DOUBLE*     A*(65    BITS)    ±18446744073709.551615,..  { (1)1111111111111111111111111111111111111111111111111111111111111111–(0)1111111111111111111111111111111111111111111111111111111111111111 ,..}
0x10  MORPH INT*  A*(1+N   BITS)    ±1+N,..                    { (1)N–(0)N ,..}
0X11  MORPH FRC*  A*(1+N+F BITS)    ±1+NE(-F),..               { (1)1+NE(-F)–(0)1+NE(-F) ,..}
> https://byjus.com/gate/size-of-data-types-in-c/



::DATA PRIVACY ATTRIBUTES::
CODE / MODE
0x0  GLOBAL
0x1  PRIVATE



::FUNCTION BLOCKS::

1. Function is defined by its own address.
2. Function contains quantity of newly created memory pointers (+pre-existing parameters).
3. Function contains an array of pointers.
4. Function has to map each pointer in order to be accessed.
5. During return, all virtual memory in the function will be removed.




::MEMORY ARCHITECTURE:: (SAMPLES)

VARIABLES:
      ADDR  TYPE  PRIV  SIZE  DATA
  00000000  0x1   0x0   9     (0)11111111
  00000001  0x6   0x1   3     (0)11


ARRAYS:
      ADDR  TYPE  PRIV  SIZE    DATA
  00000010  0x09  0x1   [2]17   (1)1111111111111111,(1)1111111111111111,(1)1111111111111111
  00000011  0x12  0x1   [3]1+1  (0)1,(0)1,(0)1


STATEMENT:


FUNCTION:
	


"""



"""

FNC 0x2 TEST
	SET 0x2 VAR1 ARGV  ; INT VAR1=<ARGV>
	SET 0x2 VAR2 VAR1  ; INT VAR2=VAR1
	SET 0x2 OUTP 0     ; INT OUTP=0
	ADD OUTP VAR1 VAR2 ; OUTP=VAR1+VAR2
	RET 0x2 OUTP       ; RETURN OUTP


CALL TEST() [creates virtual memory allocation]
SAMPLE A:
	SET 0x2  ABCD 0   ; [all-in-all]
	CAL ABCD TEST 123 ; INT ABCD=TEST(123)
SAMPLE B:
	CAL 0x0 TEST 123  ; TEST(123)



(......)

"""





"""

(.......)

"""


"""
STATEMENT MEMORIES::

VARIABLE MEMORY
[MEM_ADDR][SIZE][TYPE][DATA]

FUNCTION MEMORY
[MEM_ADDR][SIZE][TYPE][QTY][INST*1]...[INST*N]

ARRAYS MEMORY
[MEM_ADDR][SIZE][TYPE][QTY][DATA*1]...[DATA*N]

WHILE LOOPING MEMORY
[MEM_ADDR][SIZE][TYPE][QTY][INST*1]...[INST*N]

FOR LOOPING MEMORY
[MEM_ADDR][SIZE][TYPE][QTY][INST*1]...[INST*N]

"""


"""
(.....)

block_limit = 500; // 500 bits
dead_tails = floor(sam_size / block_limit); // 12 bytes
partitions = sam_size % block_limit; // 1 part

(..........)

// RAW DATA AT PARTBLK
//                    n
// [...........][...........][.............]
//  mem_addr[9]    size[9]       data[n]

"""


"""
BUT THE MEMORY DOESN'T CARE ABOUT "STATEMENT MEMORY"

THEREFORE, IT WILL BE READ LIKE THIS:
[MEM_ADDR][SIZE][ALLOCATED SPACE]

"""


# magic start bit
MAGIC = 9

SAM = "000001110"

def SAM_DELETE(memaddr):
	pass
	# (.......)
	# find memory address
	# sorted L/R overwrite

def SAM_ACCESS(memaddr):
	pass
	# (.......)
	# find memory address
	# get memory size
	# grab the sized data

def SAM_WRITE(size):
	# (.......)
	# find free space (L/R)
	# register data















