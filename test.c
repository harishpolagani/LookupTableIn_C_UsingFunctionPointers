#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//converting variable name to string: Stringizing
#define nameToString(x) #x

//function declatations
int addition(int,int);
int subtraction(int,int);
int multiplication(int,int);
int exitFun();

typedef int (*callback)(int,int);

typedef enum funNo{
ADDITION = 0,
SUBTRACTION,
MULTIPLICATION,
EXIT,
MAXVALUE

}e_funNo;

typedef struct s1_fun{
e_funNo funNo;
callback cb;
char funName[20];
}sfun;


sfun fun_table[MAXVALUE]={
{ADDITION,addition,"addition"},
{SUBTRACTION,subtraction,"subtraction"},
{MULTIPLICATION,multiplication,"multiplication"},
{EXIT,exitFun,"exitFun"}
};

//structure variable de

int main()
{
    sfun *sptr = malloc(sizeof(sfun));
    int choice =0;
    int val1=10,val2=20;
  while(1){
    printf("enter 1.additon \n 2. subtraction \n 3. multiplication \n 4. exit \n ");
    scanf("%d",&choice);
    
    
    sptr->funNo=choice-1;
    
    //here check choice value should not exceed the enum max value and should also match the Vtable id
    if( sptr->funNo < MAXVALUE   && sptr->funNo == fun_table[sptr->funNo].funNo)
    sptr->cb=fun_table[sptr->funNo].cb;
    //sptr->funName=fun_table[sptr->funNo].funName;
    strncpy(sptr->funName,fun_table[sptr->funNo].funName,sizeof(fun_table[sptr->funNo].funName));
    
    //for example printf format: addition of 10 and 20 is = 30
    printf(" %s of %d and %d is = %d \n",sptr->funName,val1,val2,sptr->cb(val1,val2));
   }  
    

return 0;
}


int addition(int val1,int val2)
{
 return val1+val2;
}

int subtraction(int val1,int val2)
{
return val1 - val2;
}
int multiplication(int val1,int val2)
{
return val1*val2;
}
int exitFun()
{
printf(" \n thanks \n exiting from the  program \n "); 
 exit(0);

return -1;
}
