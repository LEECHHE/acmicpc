#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef struct node{
    char data;
    struct node* prev;
    struct node* next;
    node(){}
    node(char data):data(data), prev(NULL), next(NULL) {}
}node;
class str{
public:
    node *head;
    node *cursor;
    str(){
        head = NULL;
        cursor = NULL;
    };
    void push(char a){
        node* n = new node(a);
        if( cursor == NULL ){
            n->next = head;
            if( head != NULL ){
                head->prev = n;
            }
            head = n;
            cursor = n;
            return;
        }
        n->next = cursor->next;
        n->prev = cursor;
        
        cursor->next = n;
        if( n->next != NULL ){
            n->next->prev = n;
        }
        cursor = n;
    }
    void back(){
        if( cursor == NULL ){
            return;
        }
        cursor = cursor->prev;
    }
    void next(){
        if( cursor == NULL ){
            cursor = head;
            return;
        }
        if( cursor->next == NULL ) return;
        cursor = cursor->next;
    }
    void erase(){
        if( cursor == NULL ) return;
        node* next = cursor->next;
        node* removed = cursor;
        
        if( removed->prev != NULL ){
            removed->prev->next = next;
        }
        if( next != NULL ){
            next->prev = removed->prev;
        }
        if( removed == head ){
            head = removed->next;
        }
        cursor = removed->prev;
        delete removed;
    }
};
int main(){
    char seq[100001]; scanf("%s",seq);
    str *input = new str();
    int len = (int)strlen(seq);
    for( int i = 0 ; i < len ; ++i ){
        input->push(seq[i]);
    }
    int n; scanf("%d",&n);
    while(n--){
        char op[2]; scanf("%s", op);
        if( op[0] == 'L' ){
            input->back();
        }
        else if( op[0] == 'D' ){
            input->next();
        }
        else if( op[0] == 'B' ){
            input->erase();
        }
        else{
            char m[2]; scanf("%s", m);
            input->push(m[0]);
        }
    }
    node* p = input->head;
    while(p != NULL){
        printf("%c",p->data);
        p = p->next;
    }
    return 0;
}