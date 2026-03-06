#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createCircularList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }
 
    tail->next = head;
    return head;
}


void traverseCircularList(struct Node* head, int n) {
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* head = createCircularList(arr, n);
    traverseCircularList(head, n);

    return 0;
}
