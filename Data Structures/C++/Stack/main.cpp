/*********************
Name: Arjun Devireddy
Coding 04
Purpose: This program extensively tests the stack data type.
**********************/

#include "main.h"

int main(){
    Stack s;
    
    //Checks isEmpty and peek at empty stack and full stack, tests overflow
    for(int i = 0; i < MAX * 10; i++){   
        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.push(i)){
            cout << "Success" << endl;
        }
        else{
            cout << "Overflow error" << endl;
        }
        
    }

    //Checks isEmpty and peek at empty stack and full stack, tests overflow, different order
    for(int i = 0; i < MAX * 10; i++){   
        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        if(s.push(i)){
            cout << "Success" << endl;
        }
        else{
            cout << "Overflow error" << endl;
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }           
    }

    //Checks isEmpty and peek at empty stack, tests underflow
    for(int i = 0; i < MAX * 10; i++){
        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        try{
            s.pop();
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }
    }

    //Checks isEmpty and peek at empty stack, tests underflow, different order
    for(int i = 0; i < MAX * 10; i++){
        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        try{
            s.pop();
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }
    }
    //Tests all functions together at an empty state and 1 element state
    for(int i = 0; i < MAX * 10; i++){   
        if(s.push(i)){
            cout << "Success" << endl;
        }
        else{
            cout << "Overflow error" << endl;
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        try{
            s.pop();
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }
        
    }

    //Tests all functions together at an empty state to full state
    for(int i = 0; i < MAX * 10; i++){   
        try{
            s.pop();
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

         if(s.push(i)){
            cout << "Success" << endl;
        }
        else{
            cout << "Overflow error" << endl;
        }

        if(s.isEmpty()){
            cout << "The stack is empty" << endl;
        }
        else{
            cout << "The stack is not empty" << endl;
        }

        try{
            cout << s.peek() << endl;
        }
        catch(int e){
            if(e == -1){
                cout << "Underflow error" << endl;
            }
        }

         if(s.push(i)){
            cout << "Success" << endl;
        }
        else{
            cout << "Overflow error" << endl;
        }
        
    }
    
}   