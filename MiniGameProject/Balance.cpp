#include <iostream>
using namespace std;
bool balance(string Text,int num);
bool Match(char x , char y);

class stack{
    public:
        int top=-1;
        char arr[15];

        void push(char x){
            if(top >= 15 - 1){
                cout << " Stack FUll ";
                return;
            }
            top++;
            arr[top] = x;
        }
        void pop(){
            if(empty()){
                cout << " Stack EMPTY ";
                return;
            }
            top--;
        }
        char Top(){
            if (!empty()) {
                return arr[top];
            }
            return '\0'; 
        }
        bool empty(){
            return top <= -1;
        }
};
int main(){
    string text;
    cin >> text;
    if(balance(text,text.size())){
        cout << " OK ";
    }
    else { 
        cout << " NOT OK ";
    }

    return 0;
}
bool balance(string Text,int num){
    stack S;
    for(int i = 0 ; i < num ; i ++ ){
        if(Text[i] == '(' || Text[i] == '[' || Text[i] == '{' || Text[i] == '<'){
            if( (Text[i] == '<' && Text[i+1] == '<') ){
                i++;
            }else{
                S.push(Text[i]);
            }
        }else if(Text[i] == ')' || Text[i] == ']' || Text[i] == '}' || Text[i] == '>'){
            if(Match(S.Top() , Text[i]) && !S.empty()){
                S.pop();
            }else return false;
        }
    }
    return S.empty();
}
bool Match(char x , char y){
    return (
            (x=='(' && y==')') ||
            (x=='[' && y==']') ||
            (x=='{' && y=='}') ||
            (x=='<' && y=='>')
           );
}