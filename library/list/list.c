#include "list.h"
/*
 * @brief           Initialize a list
 * @return          the dummy head of the list
 * @author          JAYDEN_NAN
 */
List List_Init() {
    List newList = (List)malloc(sizeof(struct ListNode));
    if (newList == NULL) {
        printf("Out of Space!!\n");
        return NULL;
    }
    newList->next = NULL;
    return newList;
}

/*
 * @brief           Determine whether the list is empty
 * @parameter list  the list which need to be processed
 * @return          true->the list is empty; false-> the list is not empty
 * @author          JAYDEN_NAN
 */
bool List_IsEmpty(List list) {
    if (list == NULL || list->next == NULL)
        return true;
    return false;
}

/*
 * @brief           Find data from the list
 * @parameter list  the list which need to be processed
 * @parameter data  the data which need to be found
 * @return          the location of the data
 *                  if the list does not has the data, return NULL
 * @author          JAYDEN_NAN
 */
ListPos List_Find(List list, int data) {
    if (List_IsEmpty(list))
        return NULL;
    ListPos findPos = list->next;
    while (findPos != NULL && findPos->data != data) 
        findPos = findPos->next;
    return findPos;
}

/*
 * @brief           Find data from the list
 * @parameter list  the list which need to be processed
 * @parameter data  the data which need to be found
 * @return          the pre-location of the data
 *                  if the list does not have the data, return NULL
 * @author          JAYDEN_NAN
 */
ListPos List_FindPre(List list, int data) {
    if (List_IsEmpty(list))
        return NULL;
    ListPos findPrePos = list;
    while (findPrePos->next != NULL && findPrePos->next->data != data)
        findPrePos = findPrePos->next;
    if (findPrePos->next == NULL)
        findPrePos = NULL;
    return findPrePos;
}

/*
 * @brief           Add data at the beginning of the list
 * @parameter list  The list which need to be processed
 * @data            The data which need to be add to the list
 * @return          NULL
 * @author          JAYDEN_NAN
 */
void List_Add(List list, int data) {
    if (list == NULL) {
        printf("The list is error!\n");
        return;
    }
    ListPos addPos = (ListPos)malloc(sizeof(struct ListNode));
    if (addPos == NULL) {
        printf("Out of Space!\n");
        return;
    }
    addPos->data = data;
    addPos->next = list->next;
    list->next = addPos;
}

void List_Insert(List list, int preData, int data) {
    ListPos insertPos = List_Find(list, preData);
    if (insertPos == NULL) {
        printf("The specified data was not found.Failed to insert!\n");
        return;
    }
    ListPos insertNode = (ListPos)malloc(sizeof(struct ListNode));
    insertNode->data = data;
    insertNode->next = insertPos->next;
    insertPos->next = insertNode;
}
void List_Delete(List list, int data) {
    ListPos delPrePos = List_FindPre(list, data);
    if (delPrePos == NULL) {
        printf("The list does no have such data!\n");
        return;
    }
    
    ListPos delPos = delPrePos->next;
    delPrePos->next = delPos->next;
    free(delPos);
}

void List_Change(List list, int curData, int newData) {
    ListPos changePos = List_Find(list, curData);
    if (changePos == NULL) {
        printf("The specified data was not found.\n");
        return;
    }
    changePos->data = newData;
}

void List_MakeEmpty(List list) {
    ListPos freePos = list;
    while (list != NULL) {
        list = list->next;
        free(freePos);
        freePos = list;
    }
}

void List_PrintList(List list) {
    ListPos printNode = list->next;
    while (printNode != NULL) {
        printf("%d\t", printNode->data);
        printNode = printNode->next;
    }
    putchar('\n');
}
