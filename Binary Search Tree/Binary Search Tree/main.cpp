//
//  main.cpp
//  Binary Search Tree
//
//  
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include<iostream.h>
#include<conio.h>
#include<alloc.h>

struct tree
{
    int data;
    tree *left;
    tree *right;
}*sptr,*q;
void rightcheck();
void leftcheck();
void search();

int insdata;
tree *node;
void main()
{
    clrscr();
    node=new tree;
    cout<<"   PLEASE  PUT  THE root->>";
    cin>>node->data;
    sptr=node;
    q=sptr;
    node->left=NULL;
    node->right=NULL;
    cout<<"   GIVE THE child->>";
    cin>>insdata;
    search();
    while(insdata!=0)
	{
        if(insdata>sptr->data)
            rightcheck();
        else
            leftcheck();
	    cout<<"   GIVE  THE  child->>";
	    cin>>insdata;
	    search();
	    sptr=node;
    }
    getch();
}
void rightcheck()
{
    if(sptr->right==NULL)
    {
	    cout<<"    "<<insdata<<" IS THE  RIGHT  child of "<<q->data<<endl;
	    sptr->right=new tree;
	    sptr=sptr->right;
	    sptr->data=insdata;
	    sptr->left=NULL;
	    sptr->right=NULL;
	    q=node;
    }
    else
    {
        if(insdata>sptr->data)
        {
            sptr=sptr->right;
            q=sptr;
            if(insdata>sptr->data)
                rightcheck();
            else
                leftcheck();
        }
        else
        {
            sptr=sptr->left;
            q=sptr;
            leftcheck();
        }
    }
}
void leftcheck()
{
    if(sptr->left==NULL)
    {
        cout<<"   "<<insdata<<" IS THE LEFT child of "<<q->data<<endl;
        sptr->left=new tree;
        sptr=sptr->left;
        sptr->data=insdata;
        sptr->right=NULL;
        sptr->left=NULL;
        q=node;
    }
    else{
        if(insdata<sptr->data)
        {
            sptr=sptr->left;
            q=sptr;
            if(insdata>sptr->data)
                rightcheck();
            else
                leftcheck();
        }
        else
        {
            sptr=sptr->right;
            q=sptr;
            rightcheck();}
    }
}

void search()
{
    sptr=node;
    while(sptr!=NULL)
	{
        if(insdata==sptr->data)
	    {
            cout<<"This is not insertable.";
            cout<<"\nInsert child ";
            cin>>insdata;
            search();
            break;
	    }
        else
        {
            if(insdata>sptr->data)
                sptr=sptr->right;
            else
                sptr=sptr->left;
        }
    }
    sptr=node;
    
}

