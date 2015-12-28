#include <stdlib.h>
#include <assert.h>
#include "circ_buf.h"

typedef struct circ_buf_adt
{
	size_t capacity;
	size_t read_i; 		/* last read localtion */
	size_t size; 		/* how much is written to the buffer */
	size_t buf[1]; 		/* the buffer */

}circ_buf_adt;
		
/* create circ_buffer capacity in bytes */
circ_buf_t* CircBufCreate(size_t capacity)
{
	circ_buf_t* circ_buf = (circ_buf_t*)malloc(sizeof(circ_buf_t) + capacity - sizeof(size_t));
	assert(circ_buf);
	
	circ_buf->capacity = capacity;
	circ_buf->read_i = 0;
	circ_buf->size = 0;
	
	
	return(circ_buf);
}

/* destroy circ_buf_t */
void CircBufDestroy(circ_buf_t* circ_buf)
{
	free(circ_buf);

	return;
}

/* – how much space left to write to */
size_t CricBufFreeSpace(const circ_buf_t* circ_buf)
{
	return(circ_buf->capacity - circ_buf->size);
}

/* total size of the struct in byts */
size_t CriBufCapacity(const circ_buf_t* circ_buf)
{
	return(circ_buf->capacity);
}

/* read from last read do dest buffer, how much to read return how many bytes read */
size_t CircBufRead(circ_buf_t* circ_buf, void* dst, size_t n_bytes)
{
	return(-1);
}

/* write to last location from src  return how many bytes were writen */
size_t CircBufWrite(circ_buf_t* circ_buf, const void* src,  int n_bytes)
{
	int i = 0;
	if( (circ_buf->capacity - circ_buf->size) >= n_bytes )
	{
		while(n_bytes > 0)
		{
			char* src_tmp = (char*)src;
			printf("1: %c\n", *(src_tmp + i));
			
			printf("2: %c\n", *(*(char**)&src + i) );
			
			--n_bytes;
			++i;
		}
		
		return(i);
	}
	/*
	while(circ_buf->capacity - circ_buf->size > 0)
	{
		
	}
	*/
	return(-3);
}

/* check if buffer is empty */
int CircBufIsEmpty(const circ_buf_t* circ_buf)
{
	return(circ_buf->size == 0);
}
