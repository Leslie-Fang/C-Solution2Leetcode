//
// Created by leslie-fang on 2017/6/13.
//
#include <iostream>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
    //在结构体内部定义结构体的构造函数
    //以后的使用 ListNode* last=new ListNode(1);
    //来生成结构体对象
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* c1=l1;
    ListNode* c1last=l1;
    ListNode* c2=l2;
    bool push=false;

    if( c1 == NULL){
        return l2;
    }else if(c2 == NULL){
        return l1;
    }

    while( (c1 != NULL) && (c2 != NULL)){
        if(push){
            c1->val = c1->val+c2->val+1;
        }else{
            c1->val = c1->val+c2->val;
        }
        if(c1->val >= 10){
            c1->val -= 10;
            push =true;
        }else{
            push =false;
        }
        c1last=c1;
        c1 = c1->next;
        c2 = c2->next;
    }
    if((c1 == NULL) && (c2 == NULL)){
        if(push){
            ListNode* last = new ListNode(1);
            c1last->next = last;
        }
        return l1;
    }
    if( c1 == NULL){
        if(push){
            c1last->next=c2;
            c2->val += 1;
            if(c2->val < 10){
                return l1;
            }else{
                c2->val = c2->val -10;
                push = true;
                c1last=c2;
                c2 = c2->next;
                while(c2 != NULL){
                    if(push){
                        c2 -> val += 1;
                        if(c2 -> val >= 10){
                            c2 -> val -=10;
                            push=true;
                            c1last = c2;
                            c2 = c2->next;
                            continue;
                        }else{
                            push=false;
                            return l1;
                        }
                    }
                }
                if(push){
                    ListNode* last=new ListNode(1);
                    //last->val =1;
                    //last->next = NULL;
                    c1last->next = last;
                }
                return l1;
            }
        }else{
            c1last->next=c2;
            return l1;
        }
    }else if(c2 == NULL){
        if(push){
            c1->val +=1;
            if(c1->val >= 10){
                c1->val -=10;
                push=true;
                c1last=c1;
                c1 = c1->next;
                while(c1 != NULL){
                    if(push){
                        c1->val +=1;
                        if(c1->val >= 10){
                            c1->val -=10;
                            push=true;
                            c1last=c1;
                            c1 = c1->next;
                            continue;
                        }else{
                            return l1;
                        };
                    }
                }
                if(push){
                    ListNode* last=new ListNode(1);
                   // last->val =1;
                    //last->next = NULL;
                    c1last->next = last;
                }
                return l1;

            }else{
                return l1;
            }
        }else{
            return l1;
        }
    }
}

int main(){
    ListNode* l1 = new ListNode(5);
    ListNode* l2 =new ListNode(5);
    //l1->val=5;
    //l1->next=NULL;
    //l2->val=5;
    //l2->next=NULL;
    addTwoNumbers(l1, l2);
    while(l1 !=NULL){
        cout<<l1->val<<endl;
        l1=l1->next;
    }
    cout<<"Hello world!"<<endl;
    return 0;
}
