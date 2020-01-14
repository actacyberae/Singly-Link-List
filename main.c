#include <stdio.h>
#include <math.h>
#include "./libs/lib.h"
#include "./libs/SLL.h"

int
main (int argc, char *argv[]) {
	int index;
	SLL pSLL = {0, NULL};
	SLLnode _node;
	SLLnode _node2;
	SLLptr pEmptyNode;
	
	_node.key = 4;
	_node2.key = 5;
	Insert_node(&pSLL, _node);
	Insert_node(&pSLL, _node2);
	List_info(&pSLL);
	Get_node(&pSLL, 4, &pEmptyNode);
	Free_node(&pSLL, pEmptyNode);
	Get_node(&pSLL, 2, &pEmptyNode);
	Free_node(&pSLL, pEmptyNode);
	List_info(&pSLL);
	Free_list(&pSLL);
	return 0;
}
