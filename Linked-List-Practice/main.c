//
//  main.c
//  Linked-List-Practice
//
//  Created by 이규진 on 2023/05/06.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    Node* NewNode = SLL_CreateNode(117);
    printf("%d \n", NewNode->Data);
    return 0;
}
