//202110573 윤여헌
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// �� �տ� ��� ���� 
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// �� ���� ��带 ����
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// ��� Ž��
ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	//while (p != NULL) {
	//	if (p->data == x) return p;
	//	p = p->link;
	//}

	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) return p;
	}

	return NULL;  // Ž�� ����
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	for (int i = 10; i < 40; i += 10) {
		head = insert_first(head, i);
		print_list(head);
	}

	int searchvalue = 30;
	ListNode* foundnode = search_list(head, searchvalue);
	if (foundnode != NULL)
		printf("����Ʈ���� %d�� ã�ҽ��ϴ�.\n", foundnode->data);
	else
		printf("����Ʈ���� %d�� ã�� ���߽��ϴ�.\n", searchvalue);

	return 0;
}

