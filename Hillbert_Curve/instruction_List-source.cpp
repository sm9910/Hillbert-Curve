//Driver: Johan Mireles
//Navigator: Shawn Mishra

#include "instruction_list.h"
#include <unordered_map>
#include <iostream>
#include <iterator>

ostream& operator<<(ostream& out, const InstructionList& l){
    
    if(l.head == NULL){
        out << "The list is empty";
        return out;
    }
    
    auto iter = l.begin();
    for(auto iter : l){
        switch(iter){
            case 0:
                out<< "F " ;
                break;
            case 1:
                out << "L ";
                break;
            case 2:
                out<< "R ";
                break;
            case 3:
                out << "O ";
                break;
            case 4:
                out << "E ";
                break;
            default:
                out<<"Invalid move ";
                break;
            
        }
        
    }

    return out;
}

void InstructionList::append(hilbert_t m){

    node_t* newNode = new node();
     
    tail = head;
     
    newNode->move = m;
    newNode->next = nullptr;
     
    if (head == NULL){   
        head = newNode;   
        return;   
    } 
        
    while (tail->next != NULL)   
        tail++;  
            
     tail->next = newNode;
     tail = newNode;
        return;   
        

}

void InstructionList::substitute(const unordered_map<hilbert_t, const InstructionList*>& sub){
    node_t* curr = this->head;
    node_t* temp; 
    node_t* prev = new node();
    int count = 1;
    
    while(curr != NULL){
        if(curr->move == ODD){
            temp = curr->next;
            InstructionList* oddCopy = new InstructionList;
            for(InstructionList::iterator it = sub.at(ODD)->begin(); it != NULL; ++it){
                oddCopy->append(*it);
            }
            if(count==1){
                this->head = oddCopy->head;
                oddCopy->tail->next = temp;
            }
            else{
            prev->next = oddCopy->head;
            oddCopy->tail->next = temp;
            }
        }
        else if(curr->move == EVEN){
            temp = curr->next;
            InstructionList* evenCopy = new InstructionList;
            for(InstructionList::iterator it = sub.at(EVEN)->begin(); it != NULL; ++it){
                evenCopy->append(*it);
            }
            if(count==1){
                this->head = evenCopy->head;
                evenCopy->tail->next = temp;
            }
            else{
            prev->next = evenCopy->head;
            evenCopy->tail->next = temp;
            }
        }
        else{
            prev = curr;
        }
        count++;
        curr = curr->next;
    }
    return;
}

InstructionList :: ~InstructionList(){
    struct node* temp;
    while (head != NULL){
        temp = head->next;
        delete head;
        head = temp;
    }
         delete temp;
         delete head;
}
