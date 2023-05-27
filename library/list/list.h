/*
 * @author      JAYDEN_NAN
 * @time        2023-05-27 19:31
 */
#ifndef LIST_H_
#define LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

typedef struct ListNode* List;
typedef struct ListNode* ListPos;

List List_Init();
bool List_IsEmpty(List list);
ListPos List_Find(List list, int data);
ListPos List_FindPre(List list, int data);
void List_Add(List list, int data);
void List_Insert(List list, int preData, int data);
void List_Delete(List list, int data);
void List_Change(List list, int curData, int newData);
void List_MakeEmpty(List list);
void List_PrintList(List list);
#endif
