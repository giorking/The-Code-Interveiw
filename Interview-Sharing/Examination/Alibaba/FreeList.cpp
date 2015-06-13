#include <iostream>

using namespace std;

class FreeList {
public:
    static int free_num = 0;
    class ListNode {
    public:
        ListNode *prev;
        ListNode *next;
        int *add;
        ListNode () {
            this->prev = this->next = NULL;
            this->add = NULL
        }
    }
    ListNode *head, *end;
    FreeList() {
        head = new ListNode();
        end = new end();
        head->next = end;
        end->prev = head;
    }
    ListNode* use_memory() {
        free_num -= 1;
        Listnode *temp = end->prev->prev, *temp1 = end->prev;
        temp->next = end;
        end->prev = temp;
        free_num--;
        return temp1;
    }
    void free(ListNode* node) {
        free_num++;
        Listnode *temp = end->prev;
        temp->next = node;
        node->prev = temp;
        node->next = end;
        end->prev = temp;
    }
}

int main() {
    return 0;
}
