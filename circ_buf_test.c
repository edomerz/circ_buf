#include "circ_buf.h"
#include <stdlib.h>
	
int main(int argc, char* argv[], char** envp)
{
	size_t capacity = 0;
	size_t size = 0;
	circ_buf_t* buf = NULL;
	int isEmpty = -1;
	char* str = "abcde";
	int n_bytes = 3;
	int var = 0;
		
	if(argc != 2)
	{
		printf("Usage:./circ_buf (uint64)capacity in bytes\n");
		return(-1);
	}
	capacity = atol(argv[1]);
	printf("\ncapacity: %lu\n", capacity);
	
	/* CircBufCreate - create circ_buffer capacity in bytes */
	buf = CircBufCreate(capacity);
	
	/*CricBufFreeSpace – how much space left to write to */
	size =  CricBufFreeSpace(buf);
	printf("\nsize:%lu\n", size);
	
	/* total size of the struct in byts */
	capacity = CriBufCapacity(buf);
	printf("\nbuf->capacity:%lu\n", capacity);
	
	/*CircBufIsEmpty - check if buffer is empty */
	isEmpty =  CircBufIsEmpty(buf);
	printf("\nis empty:%d\n", isEmpty);

	 var = CircBufWrite(buf, (void*)str,  n_bytes);
	 printf("\nbytes copied:%d\n", var);
	
	/*CircBufDestroy -  destroy circ_buf_t */
	CircBufDestroy(buf);
	
	return(0);
}
