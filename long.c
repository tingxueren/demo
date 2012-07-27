#include<stdio.h>
#include<string.h>
void arrayreverse(char *c,unsigned int length)
{char t;
 unsigned int i;
 for(i=0;i<length/2;i++)
  { t=*(c+i);
   *(c+i)=*(c+length-1-i);
   *(c+length-1-i)=t;
   }
   
 }

void alphaarryshift(char *d,unsigned int lengt,char *b)
{
 unsigned int i;
 for(i=0;i<lengt;i++)
   {
    if(((*(d+i)>='A')&&(*(d+i)<='Z'))||((*(d+i)>='a')&&(*(d+i)<='z')))
        { 
  	  if((*(d+i)>='A')&&(*(d+i)<='Z'))
		{
  		  *(d+i)=((*(d+i)-'A'+(i%26))%26)+'A';
		  *(d+i)=*(b+i%5)^(*(d+i)); 
		 }
	   else if(*(d+i)>='a'&& *(d+i)<='z')
		{
		  *(d+i)=(*(d+i)-'a'+26-(i%26)) %26+'a';
		  *(d+i)=*(b+i%5)^(*(d+i)); 
		}
	 }
    }
    
 }

void realphaarryshift(char *a,unsigned int length,char *b)
{
 unsigned int i;
 for(i=0;i<length;i++)
   {
    if(((*(a+i)>='A')&&(*(a+i)<='Z'))||((*(a+i)>='a')&&(*(a+i)<='z')))
        { 
  	  if((*(a+i)>='A')&&(*(a+i)<='Z'))
		{
  		 *(a+i)=*(b+i%5)^(*(a+i)); 
                 *(a+i)=(*(a+i)-'A'+26-(i%26))%26+'A';	 
		 }
	   else if(*(a+i)>='a'&& *(a+i)<='z')
		{
		  *(a+i)=*(b+i%5)^(*(a+i)); 
                  *(a+i)=((*(a+i)-'a'+(i%26))%26)+'a';
		 }
	 }
    }
    
 }

void encryption(FILE *fp,FILE *ft,char *b)
{ 
  unsigned int len;
  char *s = 0;
  rewind(fp);
  rewind(ft);
  while((fgets(s,256,fp))!=NULL)
     {
 	len=strlen(s);
 	printf("Read size:%d\n",len);
	printf("Before encode:\n%s\n",s);

	alphaarryshift(s,len,b);
	printf("After encode:\n%s\n",s);

	arrayreverse(s,len);
	printf("After reverse:\n");
 	printf("%s\n",s);

	fputs(s,ft);     
      }

}

/*void decryption(FILE *fp,FILE *ft,char *b)
{
  unsigned int len;
  char *k;
  rewind(fp);
  rewind(ft);
  while((fgets(k,256,fp))!=NULL)
     {
 	len=strlen(k);
 	printf("Read size:%d\n",len);
	printf("Before encode:\n%s\n",k);

	arrayreverse(k,len);
	printf("After reverse:\n");
 	printf("%s\n",k);

	realphaarryshift(k,len,b);
	printf("After encode:\n%s\n",k);

	fputs(k,ft);     
      }

}
*/
int main(void)
{
  char *b;
  const char *FILENAME="test.txt";
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
      b="jkuer"; 
      
      encryption(fp,fp2,b);
      printf("加密成功！\n");
      fclose(fp);
      fclose(fp2);
     }

  /*if((fp2=fopen(FILENAME2,"r"))==NULL)
  {
    printf("Can not open file %s!\n",FILENAME2);
   }
   else if((fp3=fopen(FILENAME3,"w+"))==NULL)
   {
     printf("Can not open file %s!\n",FILENAME3);
    }
    else
    {
     // printf("请输入5位解密密码：\n");
      b="jkuer"; 
      
      decryption(fp2,fp3,b);
      printf("解密成功！\n");
      fclose(fp2);
      fclose(fp3);
     }*/
     return 0;
}
