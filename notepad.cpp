#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Notepad{
    private:
        list<char>editor;
        list<char>:: iterator cursor; 
    public:
        Notepad();
        void inserter(char c);
        char deleter();
        void left();
        void right();
        void display();
      
};

Notepad::Notepad(){
    cursor = editor.begin();
}

void Notepad::inserter(char c){
    if(editor.size()==0){
        editor.push_back(c);
    }
    else{
        editor.insert(cursor, c);
    }
    // cursor--;
}

char Notepad::deleter(){
  char temp = '-';
  if (editor.size() and cursor != editor.end()){
    temp = *cursor;
    list<char>::iterator curr;
    curr = cursor;
    cursor--;
    editor.erase(curr);
    cursor++;
  }
  return temp;
}

void Notepad::left(){
    if(cursor==editor.begin()){
        cout<<"The cursor cannot move left, you are at the edge";
    }
    cursor--;
}
void Notepad::right(){
    if(cursor==editor.end()){
        cout<<"The cursor cannot move right, you are at the edge";
        return;
    }
    cursor++;
}
void Notepad::display(){
    cout<<endl;
    cout<<endl;
    cout<<"EDITOR DISPLAY"<<endl;
    list<char>::iterator temp;
    temp = editor.begin();
    while(temp!=editor.end()){
        if(temp==cursor){
            cout<<"_";
        }
        cout<<*temp;
        temp++;
    }
    if(temp == cursor){
        cout<<"_";
    }
    cout<<endl;
}
void printChoices(){
    for(int i=0; i<50; i++) cout<<".";
    cout<<endl;
    cout<<"' _ ' is the cursor"<<endl;
    cout<<"Enter '1' to move the cursor to the left"<<endl;
    cout<<"Enter '2' to move the cursor to the right"<<endl;
    cout<<"Enter '3' to insert a character"<<endl;
    cout<<"Enter '4' to delete the character"<<endl;
    cout<<"Enter '5' to exit"<<endl;
}

int main() {
    Notepad np;
    char choice;
    while(1){
        np.display();
        printChoices();
        cin >> choice;

        switch (choice){
            case '1':
                np.left();
                cout<<endl;
                break;
            case '2':
                np.right();
                cout<<endl;
                break;
            case '3':
                char c;
                cout<<"Enter the character to be inserted: ";
                cin>>c;
                np.inserter(c);
                cout<<endl;
                break;
            case '4':
                char f; 
                f = np.deleter();
                if(f =='-'){
                    cout<<"No character has been deleted"<<endl;
                }
                else{
                    cout<<"The character "<<f<<" has been deleted";
                }
                cout<<endl;
                break;
            case '5':
                exit(1);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}