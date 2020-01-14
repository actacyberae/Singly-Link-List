#ifndef SLL_LIBRARY
#define SLL_LIBRARY

#include "./lib.h"

#define ER_EMPTYLIST -1
#define ER_EMPTYNODE -2

#define TRUE 1
#define FALSE 0

typedef struct node *SLLptr;

typedef struct node {
	int key;
	struct node *next;
} SLLnode;

typedef struct SLL {
	size_t size;
	SLLptr ptr;
} SLL;

void Insert_node(SLL *pSLL, SLLnode pNode);

void List_info(SLL *pSLL);

void Free_list(SLL *pSLL);

void Free_node(SLL *pSLL, SLLptr pNode);

void Get_node(SLL *pSLL, int pKey, SLLptr *pNode);

#endif
