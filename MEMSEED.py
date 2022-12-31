"""
12/01/2022
"""



# DECIMAL TO BIT COUNT
def DTBC(decimal):
	i = 0
	while 1:
		# (2**i) = pow(2, i) - bin exponentiation
		if decimal < (2**i):
			return i
		
		i += 1

def BTD(binary):
	decimal = 0
	
	###################
	bits = len(binary)
	###################
	
	for c in range(0, bits):
		digit = int(binary[c])
		if bool(digit):
			decimal += pow(2, bits-1-c)
	
	return decimal


def DTB(decimal):
	aaaa = []
	
	# decimal to bit count
	dtbc = DTBC(decimal)
	
	for c in range(1, dtbc+1):
		k = decimal >> dtbc-c
		if (k & 1):
			aaaa.append(1)
		else:
			aaaa.append(0)
	
	return "".join([str(i) for i in aaaa])



# 1023
decimal = BTD("1111111111")
binary = DTB(decimal)
bytcnt = DTBC(decimal)
print(decimal, binary, bytcnt)



# maximum MEMADDR_SIZE is also the total size of the entire virtual SAM
MEMADDR_SIZE = decimal       # 1023 BITS
MEMCONFIGURE = DTBC(decimal) # 10  BITS (0000000000-1111111111)


SECT_LIMIT   = 5000  # 500 BITS



#######################################

#                           limit
DYNAMIC_MEM = MEMADDR_SIZE - MEMCONFIGURE

# DEAD MEMORY BLOCK (REMAINDER)
DEAD_BLK = DYNAMIC_MEM  % (SECT_LIMIT+MEMCONFIGURE)

# CONFIG-MEMORY SECTOR COUNT
MEMSECT_CNT = DYNAMIC_MEM // (SECT_LIMIT+MEMCONFIGURE)

# CONFIG+MEMORY SECTOR SIZE
MEMSECT_BLK = int( (DYNAMIC_MEM - DEAD_BLK) / MEMSECT_CNT )

# EACH MEMORY SECTOR SIZE
MEMSECT_SZ = MEMSECT_BLK - MEMCONFIGURE

print(DEAD_BLK)

#######################################

#            LIMIT
VECTOR  = MEMCONFIGURE

#                             END(S)           
VECTOR2 = VECTOR + (MEMCONFIGURE * MEMSECT_CNT) 

#               INIT
START = VECTOR2 + 1


#######################################


# sample memory (delete later)
SAM = ""
# ADD LIMIT BITS
SAM += "0" * MEMCONFIGURE
# ADD END BITS
for a in range(MEMSECT_CNT):
	# ADD MEMORY SECTOR BITS
	SAM += ( ("1" if a%2==0 else "0") * MEMCONFIGURE )
# ADD MEMORY SECTOR BITS
for b in range(MEMSECT_CNT):
	SAM += ( ("0" if b%2==0 else "1") * MEMSECT_SZ )
# ADD DEAD BLOCK
SAM += ( ("1" if b%2==0 else "0") * DEAD_BLK )
print(SAM)


#modify
SAM = list(SAM)
SAM[1] = "1"
SAM = "".join(SAM)

#######################################

SECTOR = 10

# MEMORY SECTOR SURFING

SURF_MEMENDS = VECTOR + (MEMCONFIGURE * (SECTOR-1))

SURF_MEMSECT = VECTOR2 + (MEMSECT_SZ * (SECTOR-1))


# MEMORY ADDRESS PARTS
# [A] [B]
# 001x002
# A - memory sector/group
# B - individual memory address



#[mem_addr][mem_sz][data]
#   ???       7      65


# how many blocks could be fit inside the sector
MEMADDR_BLOCK_SZ = MEMSECT_SZ // (7+65)


print("The total allocation for 7+65 is:", MEMSECT_SZ)

while 1:
	ALL_MEM_ADDR_ALLOC = ( DTBC(MEMADDR_BLOCK_SZ) * MEMADDR_BLOCK_SZ ) # total "memory address" (bits) of all blocks
	ALL_MEM_SZ_DAT_ALLOC = ( MEMADDR_BLOCK_SZ * (7+65) )  # total "mem_sz+data" (bits) of all blocks
	
	if (ALL_MEM_ADDR_ALLOC + ALL_MEM_SZ_DAT_ALLOC) <= MEMSECT_SZ:
		break
	
	MEMADDR_BLOCK_SZ -= 1
	

print("The total allocation for 7+65 is:", MEMADDR_BLOCK_SZ)



print(SURF_MEMENDS, SURF_MEMSECT)
print(SAM[SURF_MEMENDS], SAM[SURF_MEMSECT])



# GETSTREAM CONFIG
data = ""
for i in range(MEMCONFIGURE):
	data += SAM[SURF_MEMENDS+i]
print(data)

# GETSTREAM SECTOR


# REGISTER UNUSEDMEM
# 

# CRAWL THROUGH THE ENTIRE MEMORY
for i in range(len(SAM)):
	pass

# CRAWL THROUGH THE ENTIRE MEMORY (MEMSTART)
for i in range(MEMADDR_SIZE*4, len(SAM)):
	pass



"""
Professor Farnsworth: "Amy, technology isn't intrinsically good or evil. It's how it's used. Like the Death Ray."
-- Futurama 
"""
