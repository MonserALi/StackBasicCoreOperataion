#include<bits/stdc++.h>
#include "Monser.h"
using namespace std;

int main()
{
    Stack <int>st;
    cout<<"Choice 1: Push Into Stack"<<endl
        <<"Choice 2: Pop From Stack"<<endl
        <<"Choice 3: Size Of The Stack "<<endl
        <<"Choice 4: Top Value Of The Stack "<<endl
        <<"Choice 5: Check The Stack Empty Or Not "<<endl
        <<"Choice 6: Display All The Element From Stack"<<endl
        <<"Choice 7: Find The Mid Element From Stack"<<endl
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
            cout<<st.Mid()<<endl;
            break;
        default:
            break;

        }

    }

    return 0;
}
