#include<stdio.h>
#include<string.h>
void arrayreverse(char *c,unsigned int length)
{char t;
 unsigned int i;
 for(i=0;i<(length-1)/2;i++)
  { t=*(c+i);
   *(c+i)=*(c+length-2-i);
   *(c+length-2-i)=t;
   }
   
 }

void alphaarryshift(char a[],unsigned int lengt,char *b)
{
 unsigned int i;
 for(i=0;i<lengt;i++)
 {
    if(((a[i]>='A')&&(a[i]<='Z'))||((a[i]>='a')&&(a[i]<='z')))
        { 
          if((a[i]>='A')&&(a[i]<='Z'))
                {
                  a[i]=((a[i]-'A'+(*(b+i%5)%26))%26)+'A';
  		   
                 }
           else if(a[i]>='a'&& a[i]<='z')
                {
                  a[i]=(a[i]-'a'+26-(*(b+i%5)%26)) %26+'a';
		  
                }
         }
   }    
 }

void realphaarryshift(char a[],unsigned int length,char *b)
{
 unsigned int i;
 for(i=0;i<length;i++)
   {
    if(((a[i]>='A')&&(a[i]<='Z'))||((a[i]>='a')&&(a[i]<='z')))
        { 
  	  if((a[i]>='A')&&(a[i]<='Z'))
		{ 
                 a[i]=(a[i]-'A'+26-(*(b+i%5)%26))%26+'A';	 
		 }
	   else if(a[i]>='a'&& a[i]<='z')
		{
                  a[i]=((a[i]-'a'+(*(b+i%5)%26))%26)+'a';
		 }
	 }
    }
    
 }

void encryption(FILE *fp,FILE *ft,char *b)
{ 
  unsigned int len;
  char s[256];
  rewind(fp);
  rewind(ft);
  while((fgets(s,256,fp))!=NULL)
     {
 	len=strlen(s);
 	printf("Read size:%d\n",len-1);
	printf("Before encode:\n%s\n",s);
	alphaarryshift(s,len,b);
	printf("After encode:\n%s\n",s);
	arrayreverse(s,len);
	printf("After reverse:\n%s\n",s);
	fputs(s,ft);     
      }

}

void decryption(FILE *fp,FILE *ft,char *b)
{
  unsigned int len;
  char s[256];
  rewind(fp);
  rewind(ft);
  while((fgets(s,256,fp))!=NULL)
    {
 	len=strlen(s);
 	printf("Read size:%d\n",len-1);
	printf("Before encode:\n%s\n",s);
	arrayreverse(s,len);
	printf("After reverse:\n%s\n",s);
	realphaarryshift(s,len,b);
	printf("After encode:\n%s\n",s);
	fputs(s,ft);     
      }

}

int main(void)
{ int r=0;
  char b[6],p[6];
  const char *FILENAME="text.txt";
  const char *FILENAME2="encode.txt";
  const char *FILENAME3="decode.txt";
  FILE *fp,*fp2,*fp3;
  if((fp=fopen(FILENAME,"r"))==NULL)
  {
    printf("Can not open file %s!\n",FILENAME);
   }
   else if((fp2=fopen(FILENAME2,"w+"))==NULL)
   {
     printf("Can not open file %s!\n",FILENAME2);
    }
    else
    {
      printf("请输入5位加密密码：\n");
      scanf("%s",b); 
      
      encryption(fp,fp2,b);
      printf("加密成功！\n");
      fclose(fp);
      fclose(fp2);
     }

  if((fp2=fopen(FILENAME2,"r"))==NULL)
  {
    printf("Can not open file %s!\n",FILENAME2);
   }
   else if((fp3=fopen(FILENAME3,"w+"))==NULL)
   {
     printf("Can not open file %s!\n",FILENAME3);
    }
    else
    {
     printf("请输入5位解密密码：\n");      
      scanf("%s",p);
      while(b[r]==p[r]&&b[r]!='\0')
      { r++;}
       if(r==5)
	{
        decryption(fp2,fp3,p);
        printf("解密成功！\n");
        fclose(fp2);
        fclose(fp3);
        }      
       else
        {printf("密码错误！\n");
	 }
      }
     return 0;
}
