#include "./SLL.h"

static int insert_node(SLL *pSLL, SLLnode pNode) {
	SLLptr pNewNode;
	
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	/*
	if (pNode == NULL) {
		return ER_EMPTYNODE;
	}
	*/
	pNewNode = (SLLptr) Malloc(sizeof(SLLnode));
	*pNewNode = pNode;
	pNewNode->next = pSLL->ptr;
	pSLL->ptr = pNewNode;
	pSLL->size++;
	return TRUE;
}

void Insert_node(SLL *pSLL, SLLnode pNode) {
	int RETURN;
	
	RETURN = insert_node(pSLL, pNode);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("insert_node: ER_EMPTYLIST\n");
		case ER_EMPTYNODE:
			err_msg("insert_node: ER_EMPTYNODE\n");
	}
}

static int get_previous_node(SLL *pSLL, SLLptr pNode, SLLptr *pPreviousNode) {
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	if (pNode == NULL) {
		return ER_EMPTYNODE;
	}
	(*pPreviousNode) = pSLL->ptr;
	while ((*pPreviousNode) != NULL) {
		if ((*pPreviousNode)->next != NULL && (*pPreviousNode)->next == pNode) {
			break;
		}
		(*pPreviousNode) = (*pPreviousNode)->next;
	}
	return TRUE;
}

static void Get_previous_node(SLL *pSLL, SLLptr pNode, SLLptr *pPreviousNode) {
	int RETURN;
	
	RETURN = get_previous_node(pSLL, pNode, pPreviousNode);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("get_previous_node: ER_EMPTYLIST\n");
		case ER_EMPTYNODE:
			err_msg("get_previous_node: ER_EMPTYNODE\n");
	}
}

static int get_node(SLL *pSLL, int key, SLLptr *pNode) {
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	*pNode = pSLL->ptr;
	while (*pNode != NULL) {
		if (*pNode != NULL && (*pNode)->key == key) {
			return TRUE;
		}
		*pNode = (*pNode)->next;
	}
	return ER_EMPTYNODE;
}

void Get_node(SLL *pSLL, int key, SLLptr *pNode) {
	int RETURN;
	
	RETURN = get_node(pSLL, key, pNode);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("get_node: ER_EMPTYLIST\n");
		case ER_EMPTYNODE:
			err_msg("get_node: ER_EMPTYNODE\n");
	}
}

static int free_node(SLL *pSLL, SLLptr pNode) {
	SLLptr pPreviousNode;
	
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	if (pNode == NULL) {
		return ER_EMPTYNODE;
	}
	pSLL->size--;
	Get_previous_node(pSLL, pNode, &pPreviousNode);
	if (pPreviousNode != NULL) {
		pPreviousNode->next = pNode->next;
	} else {
		pSLL->ptr = pNode->next;
	}
	free(pNode);
	return TRUE;
}

void Free_node(SLL *pSLL, SLLptr pNode) {
	int RETURN;
	
	RETURN = free_node(pSLL, pNode);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("free_node: ER_EMPTYLIST\n");
			exit(EXIT_FAILURE);
		case ER_EMPTYNODE:
			err_msg("free_node: ER_EMPTYNODE\n");
	}
}

static int free_list(SLL *pSLL) {
	SLLptr pNode;
	
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	pSLL->size = 0;
	pNode = pSLL->ptr;
	while (pNode != NULL) {
		pSLL->ptr = pNode->next;
		free(pNode);
		pNode = pSLL->ptr;
	}
	return TRUE;
}

void Free_list(SLL *pSLL) {
	int RETURN;
	
	RETURN = free_list(pSLL);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("free_list: ER_EMPTYLIST\n");
			exit(EXIT_FAILURE);
	}
}

static int list_info(SLL *pSLL) {
	SLLptr pNode;
	
	if (pSLL == NULL) {
		return ER_EMPTYLIST;
	}
	pNode = pSLL->ptr;
	while (pNode != NULL) {
		print_line(STDOUT_FILENO, "key %d\n", pNode->key);
		pNode = pNode->next;
	}
	return TRUE;
}

void List_info(SLL *pSLL) {
	int RETURN;
	
	RETURN = list_info(pSLL);
	switch (RETURN) {
		case ER_EMPTYLIST:
			err_msg("list_info: ER_EMPTYLIST\n");
			exit(EXIT_FAILURE);
	}
}
