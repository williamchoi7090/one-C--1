#include <bits/stdc++.h>

using namespace std;

int precedence(char cpp){
  if(cpp == '+'||cpp == '-')
  return 1;
  if(cpp == '*'||cpp == '/')
  return 2;
  return 0;
}
int applycpp(int a, int b, char cpp){
  switch(cpp){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
  }
}
int evaluate(string pp){
  int n;
  stack <int> up;
  stack <char> down;
  for(n = 0; n < pp.length(); n++){
    if(pp[n] == ' ')
    continue;
    else if(pp[n] == '('){down.push(pp[n]);
  }
  else if(isdigit(pp[n])){
    int val = 0;
    while(n < pp.length() && isdigit(pp[n])){
      val = (val*10) + (pp[n]-'0');
      n++;
    }
    up.push(val);
    n--;
  }
  else if(pp[n] == ')'){
    while(!down.empty() && down.top() != '('){
      int val2 = up.top();
      up.pop();
      int val1 = up.top();
      up.pop();
      char cpp = down.top();
      down.pop();
      up.push(applycpp(val1, val2, cpp));
    }
    if(!down.empty())
    down.pop();
  }
  else{
    while(!down.empty() && precedence(down.top())>= precedence(pp[n])){
      int val2 = up.top();
      up.pop();
      int val1 = up.top();
      up.pop();
      char cpp = down.top();
      down.pop();
      up.push(applycpp(val1, val2, cpp));
    }
    down.push(pp[n]);
  }
}
while(!down.empty()){
  int val2 = up.top();
  up.pop();     
  int val1 = up.top();
  up.pop();   
  char cpp = down.top();
  down.pop();   
  up.push(applycpp(val1, val2, cpp));
}
return up.top();
}
int main() {
  cout << "25+5*2= " << evaluate("25+5*2") << "\n";
  cout << "25*5+2= " << evaluate("25*5+2") << "\n";
  cout << "25*(2+5)" << evaluate("25*(2+5)") << "\n";
  cout << "25*(5+2)*2= " << evaluate("25*(5+2)*2");
  return 0;
}