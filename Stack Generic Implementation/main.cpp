#include<bits/stdc++.h>
#include "Monser.h"
using namespace std;

int precisionCalc(char c)
{
    if(c=='+'|| c=='-')
    {
        return 1;
    }
    else if(c=='/' || c=='*')
    {
        return 2;
    }
    else if(c=='^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string chk)
{
    reverse(chk.begin(),chk.end());
    Stack <char> st;
    string result;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            result += chk[i];
        }
        else if(chk[i]==')')
        {
            st.push(chk[i]);
        }
        else if(chk[i]=='(')
        {
            while(!st.Empty() && st.Top()!=')')
            {
                result += st.pop();
            }
            if(!st.Empty()) st.pop();
        }
        else
        {
            while( precisionCalc(st.Top())>= precisionCalc(chk[i]))
            {
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.Empty())
    {
        result+=st.pop();
    }

    reverse(result.begin(),result.end());

    return result;

}
string infixToPostFix(string chk)
{
    Stack <char> st;
    string result;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            result += chk[i];
        }
        else if(chk[i]=='(')
        {
            st.push(chk[i]);
        }
        else if(chk[i]==')')
        {
            while(!st.Empty() && st.Top()!='(')
            {
                result += st.pop();
            }
            if(!st.Empty()) st.pop();
        }
        else
        {
            while( precisionCalc(st.Top())>= precisionCalc(chk[i]))
            {
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.Empty())
    {
        result+=st.pop();
    }

    return result;

}

int prefixEvaluation(string chk)
{
    Stack<int> st;

    for(int i=chk.length()-1; i>=0; i--)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch(chk[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}

int postfixEvaluation(string chk)
{
    Stack<int> st;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch(chk[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{
    Stack <int>st;
    string str;

    cout<<"Choice 1: Push Into Stack"<<endl
        <<"Choice 2: Pop From Stack"<<endl
        <<"Choice 3: Size Of The Stack "<<endl
        <<"Choice 4: Top Value Of The Stack "<<endl
        <<"Choice 5: Check The Stack Empty Or Not "<<endl
        <<"Choice 6: Display All The Element From Stack"<<endl
        <<"Choice 7: Find The Mid Element From Stack"<<endl
        <<"Choice 8: Calculate the Result Of Prefix Evaluation"<<endl
        <<"Choice 9: Covert Infix to Prefix "<<endl
        <<"Choice 10: Calculate the Result of Postfix  Evaluation"<<endl
        <<"Choice 11: Convert Infix to Postfix "<<endl
        <<"Choice 0: Exit"<<endl
        <<endl;

    int choice  = 1,val;
    while(choice!=0)
    {
        cout<<"\nEnter Next Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the value you want to push: ";
            cin>>val;
            st.push(val);
            break;
        case 2:
            val = st.pop();
            if(val==-1)
            {
                cout<<"Stack Underflow || There is no element \n";

            }
            else
            {
                cout<<"Poped value: "<<val<<endl;
            }
            break;
        case 3:
            cout<<"Size of the Stack: "<<st.Size()<<endl;
            break;
        case 4:
            val = st.Top();
            if(val!=-1)
            {
                cout<<"Top Element of the Stack: "<<val<<endl;
            }
            else
            {
                cout<<"Stack Underflow || There is the Element \n";
            }
            break;
        case 5:
            if(st.Empty()>0)
            {
                cout<<"The stack is empty"<<endl;
            }
            else
            {
                cout<<"The stack is not empty"<<endl;
            }
            break;
        case 6:
            if(st.Size()==0)
            {
                cout<<"The Stack In Empty"<<endl;
            }
            else
            {
                while(st.Empty() != true)
                {
                    cout<<st.pop()<<" ";
                }
                cout<<endl;
            }
            break;
        case 7:
            cout<<"Mid Element: "<<st.Mid()<<endl;
            break;
        case 8:
            cout<<"Enter the prefix Notation: ";
            cin>>str;
            int result;
            result =  prefixEvaluation(str);
            cout<<"Result is "<<result<<endl;
            break;
        case 9:
            cout<<"Enter Infix Notation: ";
            cin>>str;
            str = infixToPrefix(str);
            cout<<"Prefix is: "<<str<<endl;
            cout<<"Result is: "<<prefixEvaluation(str)<<endl;
        case 10:
            cout<<"Enter the Postfix Notation: ";
            cin>>str;
            //int result;
            result =  postfixEvaluation(str);
            cout<<"Result is "<<result<<endl;
            break;
        case 11:
            cout<<"Enter Infix Notation: ";
            cin>>str;
            str = infixToPostFix(str);
            cout<<"Postfix is: "<<str<<endl;
            cout<<"Result is: "<<postfixEvaluation(str)<<endl;
            break;
        default:
            break;
        }
    }

    return 0;
}
