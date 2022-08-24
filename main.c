#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USERNAME "1"
#define PASSWORD "1"
#define MAX 20
#define LNUM 2

struct Items{
	char product_code[MAX];
	char product_name[MAX];
	float rate;
	int quantity;
	float weight;
	char description[30];
};

struct Customer{
	int mobile_no;
	char cust_name[50];
};

struct Items ids[LNUM];

void login();
void option();
int addProduct();
void display();
int search();
void close_app();
void delete();
void update();
void saleProduct();

int len_item;

int main(){
	login();
	return 0;

}

void login(){
	char username[25],password[25];
	printf("\t\tEnter username: ");
	scanf("%s",username);
	printf("\t\tEnter password: ");
	scanf("%s",password);
	while(1){
		if(strcmp(USERNAME,username)==0 && strcmp(PASSWORD,password)==0){
			printf("\t\tLogin Succssful");
			option();
		}
		else{
			login();
			break;
		}
	}
}

int addProduct(){
	char code[MAX];
	int i,j=0;
	for(i=0;i<LNUM;i++){
		printf("\t\tEnter the Product Code: ");
		scanf("%s", code);
		if(strcmp(code,ids[i].product_code) == 0){
			printf("Product code %s is already there.\n",code);
		}
		else{
			strcpy(ids[i].product_code,code);
			printf("\t\tEnter Product Name: ");
			scanf("%s", ids[i].product_name);
			printf("\n\t\tEnter Product Rate: ");
			scanf("%f",&ids[i].rate);
			printf("\n\t\tEnter Quantity: ");
			scanf("%d",&ids[i].quantity);
			printf("\n\t\tEnter product Weight(in grams): ");
			scanf("%f",&ids[i].weight);
			printf("\n\t\tEnter product descriptions: ");
			scanf("%s", ids[i].description);
			system("clear");
		}
		j++;
	}
	return j;
}

void display(){
	printf("\t\tAvailable Products\n");
	int i,ls;
	if(len_item == 0){
		printf("\t\tNo Product is inserted.");
		system("clear");
	}
	else{
		system("clear");
		printf("\t\tCode\t||\tName\t||\tRate\t||\tQuantity\t||\tWeight\t||\tDescrip\n");
		for(i=0;i<LNUM;i++){
			printf("\t\t%s\t||\t%s\t||\t%.2f\t||\t%d\t||\t%.2f\t||\t%s \n", ids[i].product_code, ids[i].product_name, ids[i].rate,ids[i].quantity, ids[i].weight, ids[i].description);
		}
	}
}

 int search(){
	int l = 0,h = len_item,mid,m,flag = 0;
	char searchkey[MAX];
	printf("\t\tEnter \"end\" for back to menu\n");
	printf("\t\tEnter Product code to search: ");
	scanf("%s", searchkey);
	if(strcmp(searchkey, "end") == 0){
		system("clear");
		option();
	}
	system("clear");
	printf("\t\tProduct Information\n");
	
	while(l<=h){
		mid = (l+h)/2;
		if(strcmp(searchkey, ids[mid].product_code) == 0){
			system("clear");
			printf("\t\tProduct code: %s\n \tProduct Name: %s\n \tRate: %.2f\n \tQuantity: %d\n \tWeight: %.2f\n \tDescription: %s \n", ids[mid].product_code, ids[mid].product_name, ids[mid].rate,ids[mid].quantity, ids[mid].weight, ids[mid].description);
			flag++;
			break;
		}
		else if(strcmp(searchkey, ids[mid].product_code) < 0)
			h = mid-1;
		else if(strcmp(searchkey, ids[mid].product_code) > 0)
			l = mid+1;
	}
	return mid;
}

void delete(){
	int i,max=len_item;
	char x[MAX];
	printf("Enter the code to be deleted: ");
	scanf("%s",x);
	
	for(i=0;i<max;i++){
		if(strcmp(x,ids[i].product_code) == 0)
			break;
		else
			printf("There is no record\n");
	}
	for(;i<max;i++)
		ids[i] = ids[i+1];

	max--;

	printf("\t\tSuccessfully deleted\n");
}


void update(){
	int num;
	char pn[MAX],dp[MAX];
	num = search();
	printf("\t\tYour changing the details for Product code: %d\n",num);
	printf("\t\tEnter Product name: ");
	scanf("%s",pn);
	strcpy(ids[num].product_name,pn);
	printf("\n\t\tEnter rate: ");
	scanf("%f",&ids[num].rate);
	printf("\n\t\tEnter Quantity: ");
	scanf("%d",&ids[num].quantity);
	printf("\n\t\tEnter weight: ");
	scanf("%f",&ids[num].weight);
	printf("\n\t\tEnter Description: ");
	scanf("%s",dp);
	strcpy(ids[num].description,dp);
	printf("\t\tUpdated sucessfully!!!\n");
	system("clear");

}

void saleProduct(){
	printf("\t\tSale Product\n");
	char x[MAX];
	int q, qty,i,flag=0;
	printf("\t\tEnter \"end\" to back to manu\n");
	printf("\t\tEnter Item ID: ");
	scanf("%s", x);
	for(i =0; i<len_item; i++){
		if(strcmp(x,ids[i].product_code)==0){
			flag=1;
			int c;
			printf("\nAvailable Products\n");
			printf("\t\tProduct Code: %s\n \t\tProduct Name: %s\n\t\tRate: %.2f\n\t\tQuantity: %d\n\t\tWeight: %.2f\n\t\tDEscription: %s,\n",ids[i].product_code,ids[i].product_name,ids[i].rate,ids[i].quantity,ids[i].weight,ids[i].description);
			printf("\t\tDo you want to purchase %s \n\t\tIf Yes Enter 1 else any other number\n",ids[i].product_name);
			scanf("%d",&c);
			if(c==1){
				printf("Enter Quantity\n");
				scanf("%d",&qty);
				q=ids[i].quantity;
				if(ids[i].quantity > qty){
					printf("%.2f",ids[i].rate);
					printf("Total= %.2f\n",qty*ids[i].rate);
					ids[i].quantity = q-qty;
				}
				else{
					printf("Please Enter available quantity\n");
				}
			}
			break;
		}
	}
	if(flag == 0)
		printf("Enter Code is not found\n");
	

}

void close_app(){
	char ch;
	printf("\n Do you want to close the application?(Y/y)");
	scanf("%s", &ch);
	if(ch == 'Y' || ch == 'y')
		exit(0);
}

void option(){
	int ch;

	while(1){
		printf("\n\t1.Insert\n\t2.Display\n\t3.Search\n\t4.Delete\n\t5.Update\n\t6.Close\n\t7.Sale Product\n\n");
		printf("\tEnter Choice from (1-7)\n");
		scanf("%d", &ch);
		if(ch == 1){
			system("clear");
			len_item = addProduct();
			break;
		}
		else if(ch == 2){
			system("clear");
			display();
			break;
		}
		else if(ch == 3){
			system("clear");
			search();
			break;
		}
		else if(ch == 4){
			system("clear");
			delete();
			break;
		}
		else if(ch == 5){
			system("clear");
			update();
			break;
		}
		else if(ch == 6){
			system("clear");
			close_app();
			break;
		}
		else if(ch == 7){
			system("clear");
			saleProduct();
			break;
		}
		else{
			printf("\nEnter the correct choice: ");
			option();
		}

		}
}
