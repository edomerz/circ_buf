/*
	circ_buf
*/
#ifndef __CIRC_BUF_H__
#define __CIRC_BUF_H__

#include <stdio.h>

typedef struct circ_buf_adt circ_buf_t;

/* create circ_buffer capacity in bytes */
circ_buf_t* CircBufCreate(size_t capacity);

/* destroy circ_buf_t */
void CircBufDestroy(circ_buf_t* circ_buffer);

/* – how much space left to write to */
size_t CricBufFreeSpace(const circ_buf_t* circ_buffer);

/* total size of the struct in byts */
size_t CriBufCapacity(const circ_buf_t* circ_buffer); 

/* read from last read do dest buffer, how much to read return how many bytes read */
size_t CircBufRead(circ_buf_t* circ_buffer, void* dst, size_t n_bytes);

/* write to last location from src  return how many bytes were writen */
size_t CircBufWrite(circ_buf_t* circ_buffer, const void* src,  int n_bytes);

/* check if buffer is empty */
int CircBufIsEmpty(const circ_buf_t* circ_buffer);
	
#endif /* ifndef __CIRC_BUF_H__*/
