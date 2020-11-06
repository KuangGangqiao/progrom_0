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
//ʵ�ֺ��� - �򵥵Ľ���int char str��������
void ezprintf(const char word[],void *arr[]){
	
	 int flag = 0;        //������־λ ��1��������%
	 const char* p = NULL;
	 int i=0;  
	   
	for (p = &word[0]; '\0' != *p; p++)
	{
		switch (*p)
		{
			case '%':
				if (1 != flag)      //������־λ ��1
				{
					flag = 1;
				}
				break;
			case 'x':              //���16�����޷�����������
				if (flag)          //�����Ҫ����
				{
					flag = 0;
			    intToHexChar(*((unsigned int*)arr[1]));     //���ʮ�������� 
					
				}
				else               //�粻��Ҫ������ֱ�����'x'
				{
				    putchar('x');	           
				}
				break;
			case 'c':               //���char����
				if (flag)
				{
					flag = 0;
					putchar(*((char*)arr[2]));         //����ַ� 
				}
				else       //�粻��Ҫ������ֱ�����'c' 
				{
				  	putchar('c');  
				} 
				break;
			case 's'://���str����
				if (flag)
				{
					flag= 0;
					for(i=0;i<6;i++){     //���ڲ����Ǳ亯���������������������д���� 
						putchar(*((const char*)arr[0]+i));  //����ַ��� 
					} 
				}
				else 
				{
				    putchar('s');       //ֱ�����'s'
				} 
				break;
			default:
				if (flag)
				{
				flag = 0;
				} 
				else
				{
			        putchar(*p);  	//ֱ�Ӱ��ַ����
				} 
				break;
		}
	}
}
//ת��16������
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
	  	putchar(Hex[k]+87);  //ת��ΪСд��ĸ�� 
	}
	  }  
}
