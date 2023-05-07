//
//  LinkedList.c
//  Linked-List-Practice
//
//  Created by 이규진 on 2023/05/06.
//

#include "LinkedList.h"

// 노드 생성
Node* SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode -> Data = NewData;
    NewNode -> NextNode = NULL;
    
    return NewNode;
}

// 노드 삭제
void SLL_DestroyNode(Node* Node){
    free(Node);
}

// 맨 뒤에 노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode){
    // 만약 아무것도 없다면 헤드로 선언
    if((*Head) == NULL) {
        *Head = NewNode;
    } else {
        // 뭐가 있다면 꼬리로 이동
        Node* Tail = (*Head);
        
        while(Tail -> NextNode != NULL) {
            Tail = Tail -> NextNode;
        }
        
        Tail -> NextNode = NewNode;
    }
}

// 특정 위치에 추가
void SLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode -> NextNode = Current -> NextNode;
    Current -> NextNode = NewNode;
}

// 새로운 머리 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead){
    if(Head == NULL) {
        (*Head) = NewHead;
    } else {
        NewHead -> NextNode = (*Head);
        (*Head) = NewHead;
    }
}

// 노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove){
    // 제거하려는 노드가 Head일 경우
    if (Remove == (*Head)) {
        (*Head) = Remove -> NextNode;
    } else {
        // 중간이나 끝일경우
        Node* Current = *Head;
        while(Current != NULL && Current -> NextNode != Remove) {
            Current = Current -> NextNode;
        }
        
        if (Current != NULL) Current -> NextNode = Remove -> NextNode;
    }
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0){
        Current = Current -> NextNode;
    }
    
    return Current;
}

// 노드 숫자 세기
int SLL_GetNodeCount(Node* Head){
    Node* Current = Head;
    int count = 0;
    while(Current != NULL) {
        Current = Current -> NextNode;
        count++;
    }
    
    return count;
}
