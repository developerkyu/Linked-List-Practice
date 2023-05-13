//
//  main.c
//  Linked-List-Practice
//
//  Created by 이규진 on 2023/05/06.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
    int count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;
    
    // 노드 5개 추가
    for(int i = 0; i < 5; i++){
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);
    
    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);
    
    count = SLL_GetNodeCount(List);
    
    // 링크드 리스트 출력
    for(int i = 0; i < count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d \n", i, Current -> Data);
    }
    
    // 두 번째 노드 뒤에 3000 삽입
    printf("\nInserting 3000 After [2]...\n\n");
    
    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    
    SLL_InsertAfter(Current, NewNode);
    
    count = SLL_GetNodeCount(List);
    
    // 링크드 리스트 출력
    for(int i = 0; i < count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d \n", i, Current -> Data);
    }
    
    
    // 리스트에서 모든 노드 제거
    for(int i = 0; i < count; i++){
        Current = SLL_GetNodeAt(List, i);
        
        if(Current != NULL){
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
        
    }
    
    return 0;
}
