#include "stacktype.cpp"
#include <iostream>
using namespace std;

int main() {
  StackType<int> st;
  string exp;

  cout << "Enter postfix expression: ";
  getline(cin, exp);

  bool hasSpace = false;
  for (int i = 0; i < exp.length(); i++) {
    if (exp[i] == ' ') {
      hasSpace = true;
      break;
    }
  }

  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];

    if (ch == ' ')
      continue;

    if (isdigit(ch)) {
      if (hasSpace) {
    
        int num = 0;
        while (i < exp.length() && isdigit(exp[i])) {
          num = num * 10 + (exp[i] - '0');
          i++;
        }
        st.Push(num);
        i--;
      } else {
       
        st.Push(ch - '0');
      }
    } else {
      if (st.IsEmpty()) {
        cout << "Invalid expression" << endl;
        return 0;
      }
      int val1 = st.Top();
      st.Pop();

      if (st.IsEmpty()) {
        cout << "Invalid expression" << endl;
        return 0;
      }
      int val2 = st.Top();
      st.Pop();

      int result;

      if (ch == '+')
        result = val2 + val1;
      else if (ch == '-')
        result = val2 - val1;
      else if (ch == '*')
        result = val2 * val1;
      else if (ch == '/')
        result = val2 / val1;
      else {
        cout << "Invalid expression" << endl;
        return 0;
      }

      st.Push(result);
    }
  }

  if (st.IsEmpty()) {
    cout << "Invalid expression" << endl;
    return 0;
  }

  int ans = st.Top();
  st.Pop();

  if (!st.IsEmpty())
    cout << "Invalid expression" << endl;
  else
    cout << "Result: " << ans << endl;

  return 0;
}