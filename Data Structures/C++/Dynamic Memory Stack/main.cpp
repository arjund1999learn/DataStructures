/*
 Name: Arjun Devireddy
 Coding 05
 Purpose: This program thoroughly tests the dynamic stack ADT.
*/

#include "main.h"

int main(int argc, char **argv) {

    srand(time(NULL));
   
    if(argc == 2 && isdigit(*argv[1])){ 
    
        int stackSize;
        if(atoi(argv[1]) >= 2){
            stackSize = atoi(argv[1]);
        }
        else{
            stackSize = 10;
        }
        
        Stack s(stackSize);
        Data temp;
        int value;
        int choice;

        cout << "Empty tests:" << endl;
        if(s.isEmpty()){
            cout << "The stack is empty." << endl;
        }
        else{
            cout << "The stack is not empty." << endl;
        }

        if(s.peek(temp)){
        cout << "peeked: " << temp.information << endl;
        } 
        else {
            cout << "peek underflow error: stack is empty" << endl;
        }

        if(s.pop(temp)){
        cout << "popped: " << temp.information << endl;
        } 
        else {
            cout << "pop underflow error: stack is empty" << endl;
        }
    
        cout << "Testing full operations." << endl;

        string strtemp;

        for (int i = 0; i < stackSize * MULTIPLIER; i++) {
            value = i%2 ? -i : i;
            rand_string(&strtemp);
            if (s.push(value, strtemp)) {
                cout << "pushed: " << value << ", " << strtemp << endl;
            } 
            else if(value <= 0) {
                cout << "Value error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else if(strtemp.empty()){
                cout << "Empty string error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else{
                cout << "Overflow error: " << value << ", " << strtemp << " not pushed" << endl;
            }
        }

        if (s.isEmpty()) {
        cout << "The stack is empty." << endl;
        } 
        else {
            cout << "The stack is not empty." << endl;
        }

        cout << "Testing peek and pop at full, and emptying stack" << endl;
        for (int i = 0; i < stackSize * MULTIPLIER; i++) {
            if(s.peek(temp)){
                cout << "peeked: " << temp.information << endl;
            } 
            else {
                cout << "peek underflow error: stack is empty" << endl;
            }

            if(s.pop(temp)){
                cout << "popped: " << temp.information << endl;
            } 
            else {
                cout << "pop underflow error: stack is empty" << endl;
            }
        }

        cout << "Testing functions at mid stack" << endl;

        for (int i = 0; i < int(stackSize / NARROW); i++) {
            value = i + 1;
            rand_string(&strtemp);
            if (s.push(value, strtemp)) {
                cout << "pushed: " << value << ", " << strtemp << endl;
            } 
            else if(value <= 0) {
                cout << "Value error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else if(strtemp.empty()){
                cout << "Empty string error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else{
                cout << "Overflow error: " << value << ", " << strtemp << " not pushed" << endl;
            }
        }

        for (int i = 0; i < stackSize * MULTIPLIER; i++) {
            if(s.isEmpty()){
            cout << "The stack is empty." << endl;
            }
            else{
                cout << "The stack is not empty." << endl;
            }

            if(s.peek(temp)){
                cout << "peeked: " << temp.information << endl;
            } 
            else {
                cout << "peek underflow error: stack is empty" << endl;
            }

            if(s.pop(temp)){
                cout << "popped: " << temp.information << endl;
            } 
            else {
                cout << "pop underflow error: stack is empty" << endl;
            }

            value = i + 1;
            rand_string(&strtemp);
            if (s.push(value, strtemp)) {
                cout << "pushed: " << value << ", " << strtemp << endl;
            } 
            else if(value <= 0) {
                cout << "Value error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else if(strtemp.empty()){
                cout << "Empty string error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else{
                cout << "Overflow error: " << value << ", " << strtemp << " not pushed" << endl;
            }   
        }

        cout << "Random testing: " << endl;

        while(!s.isEmpty()){
            s.pop(temp);
        }

        for (int i = 0; i < int(stackSize / NARROW); i++) {
            value = i + 1;
            rand_string(&strtemp);
            if (s.push(value, strtemp)) {
                cout << "pushed: " << value << ", " << strtemp << endl;
            } 
            else if(value <= 0) {
                cout << "Value error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else if(strtemp.empty()){
                cout << "Empty string error: " << value << ", " << strtemp << " not pushed" << endl;
            }
            else{
                cout << "Overflow error: " << value << ", " << strtemp << " not pushed" << endl;
            }
        }

        for (int i = 0; i < stackSize * MULTIPLIER; i++) {
            int choice = rand() % CHOICES + 1;
            switch (choice) {
                case 1:
                case 2:
                    value = i + 1;
                    rand_string(&strtemp);
                    if (s.push(value, strtemp)) {
                        cout << "pushed: " << value << ", " << strtemp << endl;
                    } 
                    else if(value <= 0) {
                        cout << "Value error: " << value << ", " << strtemp << " not pushed" << endl;
                    }
                    else if(strtemp.empty()){
                        cout << "Empty string error: " << value << ", " << strtemp << " not pushed" << endl;
                    }
                    else{
                        cout << "Overflow error: " << value << ", " << strtemp << " not pushed" << endl;
                    }
                    break;
                case 3:
                case 4:
                    if(s.pop(temp)){
                        cout << "popped: " << temp.information << endl;
                    } 
                    else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                    break;
                case 5:
                    // peek
                    if(s.peek(temp)){
                        cout << "popped: " << temp.information << endl;
                    } 
                    else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                    break;
                    break;
                case 6:
                    if (s.isEmpty()) {
                        cout << "stack is empty" << endl;
                    } else {
                        cout << "stack is NOT empty" << endl;
                    }
                    break;
            }
        }

        


       

    /* ***************************************************************
     * Throughly test your stack. You must perform an exhaustive series
     * of tests on your stack. Show all possible ways your stack can be used
     * and abused and prove that your stack can gracefully handle ALL cases.
     * You must use automated testing (no user input). First cover all
     * explicit cases which you can think of, then execute random operations.
     * When generating test data, use random ints for ids and random short
     * strings for string. There is a string generator made for you in the
     * functions module. You are free to use it or make your own.
     * ***************************************************************/

    /* ***************************************************************
     * Below is some sample code for the random string function. It's
     * only here to demonstrate the function. DELETE it once you study
     * it and understand it and can use it yourself in your code.
     * ***************************************************************/
    
    // make 20 random strings, store them, display them
    
    }
    else{
        cout << "Please enter only one parameter at the command line which represents an int for the stack size" << endl;
    }
    return 0;
}
