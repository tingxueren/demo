/* 
整数的划分问题。  
如，对于正整数n=6，可以分划为：  
6  
5+1  
4+2, 4+1+1  
3+3, 3+2+1, 3+1+1+1  
2+2+2, 2+2+1+1, 2+1+1+1+1  
1+1+1+1+1+1+1  
现在的问题是，对于给定的正整数n,编写算法打印所有划分。 
用户从键盘输入 n （范围1~10） 
程序输出该整数的所有划分。 
*/  
  
  
#include<stdio.h>  
#include<string.h>  
  
//计算划分种数  
int divideNumber(int n,int m)  
{  
    if(m==1 || n==1)  
        return 1;  
    if(n<m)  
        return divideNumber(n,n);  
    else if(n==m)  
        return divideNumber(n,m-1)+1;  
    else  
        return divideNumber(n-m,m)+divideNumber(n,m-1);  
}  
  
//输出划分结果  
void divide(char *s,int first,int other)  
{  
    int i;   
    static char t[50];//保存上一次的输出结果  
    char temp[50],str[3]={0};  
    if(other==0){  
         if(s[0]==t[0])  
            printf(",%s",s);  
         else  
             printf("%s",s);   
         strcpy(t,s);  
    }  
    for(i=other;i>=1;i--){  
        if(i>first)  
            continue;  
        strcpy(temp,s);  
        str[0]='+';  
        str[1]=i+'0';  
        strcat(s,str);  
        divide(s,i,other-i);  
        strcpy(s,temp);  
    }  
}  
  
void main()  
{  
    int i;  
    int n;  
    char s[50]={0};  
    char str[3]={0};  
    scanf("%d",&n);  
    printf("划分种数：%d\n",divideNumber(n,n));  
    for(i=n;i>=1;i--){  
        if(i==n)  
            printf("%d",n);  
        else{  
            s[0]=0;  
            str[0]='0'+i;  
            strcat(s,str);  
            divide(s,i,n-i);     
        }  
        puts("");       
    }  
} 
