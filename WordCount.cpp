#include <stdio.h>
#include <io.h>
#include <string.h>

//ͳ���ı��е��ַ���
void c_num(char *file)
{
	FILE *f;
	char*  a = "c_num:";
	f = fopen(file, "r");  //r��ʾ��д�ķ�ʽ��ȡ�ļ�
	char c;   //char
	int num = 0;  //char num
	if(f == NULL) printf("file is null");

	else
		while(!feof(f))  //feof ����Ƿ��ļ��Ľ���λ��
		{
			c = fgetc(f);
			if(c != ' ' && c != '\n' && c != '\t') 	num ++;   //�ж��Ƿ�Ϊ�ַ� �Ǿͼ�һ
		}
	fclose(f);   //���ļ��ر�
	printf("�ַ���: %d", num);
}

//ͳ���ı��еĵ�����
void word_num(char *file)
{
	FILE *f;
	char*  a = "word_num:";
	f = fopen(file, "r");
	char ch;
	int aword, cword = 0;
	if(f == NULL) printf("file is null");

	else
	{
		while(!feof(f))
		{
			ch = fgetc(f);  //��ȡ�����ַ�
			if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
				aword = 1;  //���һֱ���ַ���ĩawordֵΪ1
			else if(aword)  //��⵽�����ַ�
			{
				cword ++;  //��������һ
				aword =0;
			}
		}
	}
	fclose(f);
	printf("������: %d", cword);
}

//������
int main(int argc, char* argv[])
{
	FILE *fp;
	while(1)
	{
		/*
		argv[0]ָ��������е�ȫ·���� ����������������������� WordCount.exe ǰ���Ѿ�������·���� 
        argv[1]ָ����DOS��������ִ�г�������ĵ�һ���ַ��� �������������  -c  -w 
        argv[2]ָ��ִ�г�������ĵڶ����ַ���  �������Ƿ������·���µ��Ǹ��Լ�д���ı� 
        �����ȿ���û���Ǹ��ı���û�еĻ�������������������continue����ִ��if��� 
		*/ 
		if((fp = fopen(argv[2], "r")) == NULL)   //����r����ֻ����ʽ�� 
		{
			printf("FileNull\n\n\n");
			scanf("%s%s%s", argv[0], argv[1], argv[2]);
			continue;
		}
		/*
		strcmp������������ �Ƚ�����Ĳ�����"-w" �ǲ���һ�£����һ�»᷵��0 �����򷵻�1  
		ʵ�ʾ����ж��������ɶ���⣬�����-w�͵��� word_num����ȥͳ�Ƶ�����
		����� -c �͵��� c_num ����ͳ���ַ��� 
		*/ 
		else if(!strcmp(argv[1], "-w")) word_num(argv[2]);
		else if(!strcmp(argv[1], "-c")) c_num(argv[2]);
		else printf("NullPoint\n");
			
		printf("\n\n");
		scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}









