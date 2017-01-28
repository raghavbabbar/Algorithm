//
//  main.cpp
//  InfixTopost
//
//  Created by raghav babbar on 16/01/17.
//  Copyright © 2017 raghav babbar. All rights reserved.

#include <iostream>
#include <stack>
using namespace  std;
char getBracket(char c)
{if(c==']')
    return '[';
else if(c=='}')
    return '{';
    return '(';
    
}
bool isOPerator(char c)
{
    return ((c=='+'||c=='-'||c=='/'||c=='*')?true:false);
    
}
bool isOPerand(char c)
{return (((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='1'&&c<='9')||(c=='0'))?true:false);
}
int getW8(char c)
{if(c=='+'||c=='-')
    return 0;
else return 1;
}
int compare(char a, char b)
{int aa=getW8(a);
    int bb=getW8(b);
    return (aa>=bb)?true:false;
}

bool isBracket(char c)
{
    return (c=='('||c=='['||c=='{'||c=='}'||c==']'||c==')')?true:false;
}
string infixToPostfix(string str)
{
    string r="";
    stack <char> stk;
    
    
    for(int i=0;str[i]!='\0';i++)
    {
        if(isOPerand(str[i]))
        {  // cout<<"\n pushing operand ===>"<<str[i];
            r+=str[i];
        }
        else if(isOPerator(str[i]))
        {
            while(1)
            {
                if(!stk.empty()&&!(isBracket(stk.top()))&&compare(stk.top(), str[i]))
                {r+=stk.top();
                    stk.pop();
                }
                else break;
            }
            stk.push(str[i]);
        }
        
        else if(isBracket(str[i]))
        {
            if(str[i]=='['||str[i]=='{'||str[i]=='(')
            {stk.push(str[i]);
                // cout<<"\n pusing  bracket "<<str[i];
                
            } else
            {char b=getBracket(str[i]);
                //   cout<<b<<"\n";
                
                while(true)
                {if(stk.top()==b)
                {
                    stk.pop();
                    break;
                    }
                    r+=stk.top();
                    stk.pop();
                    }
                    }
                    }
                    }
    
    while (!stk.empty())
    {
        r+=stk.top();
        stk.pop();
    }
    
    return r;

}/////////
/////
///////////upper function are for converting the expression into postfix notation.
////
////////
typedef struct node
{
    char d;
    node *left;
    node *right;

}node;
node* make_node(char c)
{node*ptr=(node*)malloc(sizeof(node));
    ptr->d=c;
    ptr->right=ptr->left=NULL;
return ptr;
}
node * expressionTree(string str)
{
node *r,*l;
    stack<node*> stk;
    for(int i=0;str[i]!='\0';i++)
    {node *p;
        if(isOPerand(str[i]))
        {    p=make_node(str[i]);
            stk.push(p);
        }
        else
        {p=make_node(str[i]);
            l=stk.top();
            stk.pop();
            r=stk.top();
            stk.pop();
            p->left=l;
            p->right=r;
            stk.push(p);
        }
    
    
    
    }
    return stk.top();
}
void infixNotation(node *root)
{
if(root)
{infixNotation(root->left);
cout<<" "<<root->d;
infixNotation(root->right);

}

}
void preFix(node *root)
{
if(root)
{cout<<" "<<root->d;
    preFix(root->left);
    preFix(root->right);


}
}
int main()
{
    node * root_node_of_expression_tree;
    string s;
    cin>>s;
    string postFixstr=infixToPostfix(s);
    cout<<"\nInfix to POSTFIX_NOTATION="<<postFixstr;
    root_node_of_expression_tree=expressionTree(postFixstr);
    cout<<"\n PREFIX_NOTATION";
    preFix(root_node_of_expression_tree);
    cout<<"\n INFIX_NOTATION";
    infixNotation(root_node_of_expression_tree);

    
    
    return 0;
}
