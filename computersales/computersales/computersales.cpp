// computersales.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
#include "iostream"
using namespace std;

struct Computer{
	char model[20];
	int total;
}computers[100];

int modelCount = 0;

void list();
void enterWarehouse();
void outWarehouse();
void input(struct Computer &computer);
int find(char* model);

int main()
{
	char str[100];
	do{
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)查看库存"<<endl;
		cout<<"2)电脑入库"<<endl;
		cout<<"3)售出"<<endl;
		cout<<"4)退出程序"<<endl;

		cin>>str;
		if(strlen(str)!=1){
			cout<<"error"<<endl;
			str[0]='5';
		}
		
		else if(str[0]<=48||str[0]>52){
			cout<<"error2"<<endl;
			str[0]='5';
		}
		else
		switch(str[0]){
		case '1':
			list();
			break;
		case '2':
			enterWarehouse();
			break;
		case '3':
			outWarehouse();
			break;
		case '4':
			return 0;
		default:
			cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}

void list(){
	cout<<"-------库存-------"<<endl;
	cout<<"型号\t"<<"数量"<<endl;
	for(int i=0;i<modelCount;i++){
		cout<<computers[i].model<<"\t"<<computers[i].total<<endl;
	}
	cout<<"-------库存-------"<<endl;
}
void enterWarehouse(){
	struct Computer computer;
	input(computer);

	int i = find(computer.model);
	if(i == modelCount){
		strcpy_s(computers[i].model , computer.model);
		computers[i].total = computer.total;
		modelCount++;
	}else{
		computers[i].total += computer.total;
	}
}

void outWarehouse(){
	struct Computer computer;
	input(computer);

	int i = find(computer.model); 
	if (i==0) {
		cout<<"型号错误！"<<endl;
	}
	else{
		if(computers[i].total<computer.total){
			cout<<"error3"<<endl;
		}
		else
		computers[i].total -= computer.total;
	}
}

void input(struct Computer &computer){ 
	cout<<"型号：";
	cin>>computer.model;

	cout<<"数量：";
	cin>>computer.total;
}

int find(char* model){
	int i;
	for(i=0;i<modelCount;i++){
		if(strcmp(computers[i].model,model) == 0){
			break;
		}
	}
	return i;
}