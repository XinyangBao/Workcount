#include <stdio.h>
#include <io.h>
#include <string.h>

//统计文本中的字符数
void c_num(char *file)
{
	FILE *f;
	char*  a = "c_num:";
	f = fopen(file, "r");  //r表示以写的方式读取文件
	char c;   //char
	int num = 0;  //char num
	if(f == NULL) printf("file is null");

	else
		while(!feof(f))  //feof 检查是否到文件的结束位置
		{
			c = fgetc(f);
			if(c != ' ' && c != '\n' && c != '\t') 	num ++;   //判断是否为字符 是就加一
		}
	fclose(f);   //把文件关闭
	printf("字符数: %d", num);
}

//统计文本中的单词数
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
			ch = fgetc(f);  //获取单个字符
			if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
				aword = 1;  //如果一直是字符那末aword值为1
			else if(aword)  //检测到不是字符
			{
				cword ++;  //单词数加一
				aword =0;
			}
		}
	}
	fclose(f);
	printf("单词数: %d", cword);
}

//主函数
int main(int argc, char* argv[])
{
	FILE *fp;
	while(1)
	{
		/*
		argv[0]指向程序运行的全路径名 就是我们在命令行里输入的 WordCount.exe 前面已经有所在路径了 
        argv[1]指向在DOS命令行中执行程序名后的第一个字符串 就是我们输入的  -c  -w 
        argv[2]指向执行程序名后的第二个字符串  就是我们放在相对路径下的那个自己写的文本 
        就是先看有没有那个文本，没有的话重新输入三个参数，continue重新执行if语句 
		*/ 
		if((fp = fopen(argv[2], "r")) == NULL)   //参数r是以只读方式打开 
		{
			printf("FileNull\n\n\n");
			scanf("%s%s%s", argv[0], argv[1], argv[2]);
			continue;
		}
		/*
		strcmp函数的作用是 比较输入的参数和"-w" 是不是一致，如果一致会返回0 ，否则返回1  
		实际就是判断你输入的啥玩意，如果是-w就调用 word_num函数去统计单词数
		如果是 -c 就调用 c_num 函数统计字符数 
		*/ 
		else if(!strcmp(argv[1], "-w")) word_num(argv[2]);
		else if(!strcmp(argv[1], "-c")) c_num(argv[2]);
		else printf("NullPoint\n");
			
		printf("\n\n");
		scanf("%s%s%s",argv[0],argv[1],argv[2]);
	}
	return 0;
}









