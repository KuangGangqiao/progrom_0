#include<stdio.h>
void ezprintf(const char word[],void *arr[]);
unsigned char intToHexChar(unsigned int c);
int main(void){

	const char format[] = "Welcome to %s, do you like %x%c\n";
	
	const char str[] = "CredO~";
	unsigned int int32 = 0xbeef;
	char ch = '?';

	void * args[] = {
		(void*)str,
		(void*)&int32,
		(void*)&ch
	};
	
	  ezprintf(format, args);


} 
//实现函数 - 简单的解析int char str三种数据
void ezprintf(const char word[],void *arr[]){
	
	 int flag = 0;        //解析标志位 置1表明遇到%
	 const char* p = NULL;
	 int i=0;  
	   
	for (p = &word[0]; '\0' != *p; p++)
	{
		switch (*p)
		{
			case '%':
				if (1 != flag)      //解析标志位 置1
				{
					flag = 1;
				}
				break;
			case 'x':              //输出16进制无符号整数数据
				if (flag)          //如果需要解析
				{
					flag = 0;
			    intToHexChar(*((unsigned int*)arr[1]));     //输出十六进制数 
					
				}
				else               //如不需要解析则直接输出'x'
				{
				    putchar('x');	           
				}
				break;
			case 'c':               //输出char数据
				if (flag)
				{
					flag = 0;
					putchar(*((char*)arr[2]));         //输出字符 
				}
				else       //如不需要解析则直接输出'c' 
				{
				  	putchar('c');  
				} 
				break;
			case 's'://输出str数据
				if (flag)
				{
					flag= 0;
					for(i=0;i<6;i++){     //由于不考虑变函数参数的情况，就在这里写死了 
						putchar(*((const char*)arr[0]+i));  //输出字符串 
					} 
				}
				else 
				{
				    putchar('s');       //直接输出's'
				} 
				break;
			default:
				if (flag)
				{
				flag = 0;
				} 
				else
				{
			        putchar(*p);  	//直接按字符输出
				} 
				break;
		}
	}
}
//转换16进制数
unsigned char intToHexChar(unsigned int c){
	  int k;
	  int j=0;
	  int Hex[4];
	  for(k=0;k<4;k++){
	  	j=c%16;
	  	Hex[k]=j;
	  	c=c/16;
	} 
	for(k=3;k>=0;k--){
		if(Hex[k]>9){
	  	putchar(Hex[k]+87);  //转化为小写字母， 
	}
	  }  
}
