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
void search();
void close_app();
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

void search(){
	int l = 0,h = len_item,mid,flag = 0;
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
			printf("\t\tProduct code: %s\n \tProduct Name: %s\n \tRate: %.2f\n \tQuantity: %d\n \tWeight: %.2f\n \tDescription%s \n", ids[mid].product_code, ids[mid].product_name, ids[mid].rate,ids[mid].quantity, ids[mid].weight, ids[mid].description);
			flag++;
			break;
		}
		else if(strcmp(searchkey, ids[mid].product_code) < 0)
			h = mid-1;
		else if(strcmp(searchkey, ids[mid].product_code) > 0)
			l = mid+1;
	}
}

void saleProduct(){
	printf("\t\tSale Product\n");
	char x[MAX];
	int q=0, size=0,i=1,j,k;
	float total = 0, gtotal =0;

	printf("\t\tEnter \"end\" to back to manu\n");
	for(j=0;i<LNUM;j++){
		int qty = ids[i].quantity;
		printf("%d", qty);

		while(1){

		printf("\t\tENter Item code: ");

		scanf("%s", x);
		if(strcmp(x,"end") == 0){
			system("clear");
			break;
		}
		if(strcmp(x,ids[i].product_code) != 0){
			printf("No Product is found\n");
			option();
		}

		printf("\t\tEnter Quantity: ");
		scanf("%d", &q);

		qty = qty-q;
		if(qty<0){
			system("clear");
			printf("\t\t Out od Stock\n");
			break;
		}
		if(strcmp(ids[i].product_code, x) == 0){
			total = ids[i].rate * q;
			printf("\n\t\t%d", i);
			printf("\t\t%s", ids[i].product_name);
			printf("\t\t%.2f",ids[i].rate);
			printf("\t\t%d",q);
			printf("\t\t%.2f",total);
			gtotal+=total;
			ids[i].quantity-=q;

			i++;
			break;
		}
		
	}
	if(gtotal != 0)
		printf("\n\t\tTOTAL AMOUNT = Rs. %.2f", gtotal);
}
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
		printf("\n\t1.Insert\n\t2.Display\n\t3.Search\n\t4.Delete\n\t5.Close\n\t6.Sale Product\n\n");
		printf("\tEnter Choice from (1-6)\n");
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
		else if(ch == 4){}
		else if(ch == 5){
			system("clear");
			close_app();
			break;
		}
		else if(ch == 6){
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
