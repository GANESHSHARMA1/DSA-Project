#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int Total = 0;
/* Define Functions*/
int cnum = 0;
int showPrice();
void addNewroom();
void listAll();
void deleteroom();
void modifyroom();
int findroom();
int prompt();
void Invoice();
/* Define Structures*/
typedef struct room
{
	int number;
	char name[20];
	int phone[15];
	char email[20];
	int Amount;
	struct room* next; /*next is used to navigate through structures.*/
	int count;
} Room;
Room* firstc, * currentc, * newc;
// / pointers /
int main()
{
	int Total;
	time_t t;   // not a primitive datatype
	time(&t);
	FILE* datafile;
	char* filename = "Mydata.txt";
	// / declare file name /
	char ch;
	firstc = NULL;
	datafile = fopen("Mydata.txt", "r"); /* open file for reading*/

	if (datafile)
	{
		firstc = (struct room*)malloc(sizeof(struct room));
		// / use of malloc to set aside memory relative to size of structure room /
		currentc = firstc;
		while (1)
		{

			newc = (struct room*)malloc(sizeof(struct room));
			fread(currentc, sizeof(struct room), 1, datafile);
			if (currentc->next == NULL)
				break;
			currentc->next = newc;
			currentc->count = 0;
			currentc = newc;
		}
		fclose(datafile); /* close file */
		cnum = currentc->number;
	}

	do
	{

		puts("\nWelcome To The hotel THE Taj");
		printf("%s", ctime(&t));
		puts("\n-------------------------------");
		puts("1 - Show Price Details");
		puts("2 - Contact details for Check-in.");
		puts("3 - Check-out from room");
		puts("4 - List all room details");
		puts("5 - Modify room details");
		puts("6 - Find a room detail by name");
		puts("7 - Generate Invoive");
		puts("-- -----------------------------");
		puts("8 - Save and quit\n");
		printf("\tYour choice:");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1:
			puts("\t*****Price Detils****\n");
			Total = showPrice();
			break;
		case 2:
			puts("Contact details for Check-in.\n");
			//addNewroom();
			Total = showPrice();
			printf("Total Price = %d", Total);
			break;
		case 3:
			puts("Check-out from room \n");
			deleteroom();
			break;
		case 4:
			puts("List all room details \n");
			listAll();
			break;
		case 5:
			puts("Modify a room details \n");
			modifyroom();
			break;
		case 6:
			puts("Find a room by name\n");
			findroom();
			break;
		case 7: Invoice();
			break;
		case 8:
			puts("\n\tThanks For Visiting.\n\tVisit Again.\n");
			//exit(0);
			break;
		default:
			puts("Enter an Appropriate option.\n");
			break;
		}
	} while (ch != 8);
	currentc = firstc;
	if (currentc == NULL)
		return (0);
	datafile = fopen("Mydata.txt", "w");
	// / open file to write /
	if (datafile == NULL)
	{
		printf("Error writing to %s\n", filename);
		return (1);
	}
	while (currentc != NULL)
	{
		fwrite(currentc, sizeof(struct room), 1, datafile);
		currentc = currentc->next;
	}
	fclose(datafile);
	// / closes data file /
	return;
}
int showPrice()
{
	int choice, Price, day;
	puts("1. AC Room\t\t 1 bedroom   -> Rs.3500/day");
	puts("2. AC Room\t\t 2 bedroom   -> Rs.5500/day");
	puts("3. AC Room\t\t 3 bedroom   -> Rs.8500/day");
	puts("4. Non-AC Room\t 1 bedroom   -> Rs.1500/day");
	puts("5. NON-AC Room\t 2 bedroom   -> Rs.3500/day");
	puts("6. Non-AC Room\t 3 bedroom   -> Rs.6000/day");
	puts("Enter: \t");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 3500 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	case 2:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 5500 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	case 3:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 8500 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	case 4:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 1500 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	case 5:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 3500 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	case 6:
		printf("\nEnter the Number Of days For Book the Room: \t");
		scanf_s("%d", &day);
		Total = 6000 * day;
		printf("\nYour Room is Booked Successfully.\nPay the Ammount while Check-in = %d.\n", Total);
		break;
	default:printf("\nPlease Enter an Appropriate option.\n");
		break;
	}
	addNewroom();
	return Total;
}
void addNewroom()
{
	newc = (struct room*)malloc(sizeof(struct room));
	if (firstc == NULL)
		firstc = currentc = newc;
	else
	{
		currentc = firstc;
		while (currentc->next != NULL)
			currentc = currentc->next;
		currentc->next = newc;
		currentc = newc;
	}
	cnum++;
	printf("\n\n%27s: %5i\n", "room number", cnum);
	currentc->number = cnum;
	// / cnum is used to give unique room numbers /
	printf("%27s: ", "Enter customer name");
	scanf(" %s", currentc->name);
	printf("%27s: ", "Enter contact Phone number");
	scanf(" %d", currentc->phone);
	printf("%27s: ", "Enter contact email");
	scanf(" %s", currentc->email);
	printf("\n********  room details added  ******** \n\n");
	currentc->count = 0;
	currentc->next = NULL;
}
void listAll() /* list all room details function*/
{
	if (firstc == NULL)
		puts("There are no room details to display!");
	else
	{
		printf("%6s %-20s %-15s %-15s\n", "Acct#", "Name", "Phone", "Email");
		puts("------ -------------------- ------------- -------------------");
		currentc = firstc;
		do
		{
			printf("%6d: %-20s %d %-20s\n",
				currentc->number,
				currentc->name,
				currentc->phone,
				currentc->email);
			/// prints values of number, name, phoneand email /
		} while ((currentc = currentc->next) != NULL);
	}
}
void deleteroom(void)     /*delete contact function */
{
	int record;
	struct room* previousa;
	if (firstc == NULL)
	{
		puts("There are no room details to delete!");
		return;
	}
	listAll(); /* show all records*/
	printf("Enter room number to delete: ");
	scanf("%d", &record);
	currentc = firstc;
	while (currentc != NULL)
	{
		if (currentc->number == record)
		{
			if (currentc == firstc)
				firstc = currentc->next;
			free(currentc);
			printf("room deatils %d deleted!\n", record);
			return;
		}
		else
		{
			currentc = currentc->next;
		}
	}
	printf("room details %d not found!\n", record);
}
void modifyroom() // modify contact function /
{
	int record, result;
	if (firstc == NULL)
	{
		puts("There are no room details to modify!");
		return;
	}

	listAll(); /* show all records */
	printf("Enter room account number to modify or change: ");
	scanf("%d", &record);
	result = findnum(record);
	if (result > 0)
	{
		printf("Contact no %d:\n", currentc->number);
		printf("Name: %s\n", currentc->name);
		if (prompt())
			scanf(" %s", currentc->name);
		printf("Phone: %d\n", currentc->phone);
		if (prompt())
			scanf(" %d", currentc->phone);
		printf("Email: %s\n", currentc->email);
		if (prompt())
			scanf(" %s", currentc->email);
		return;
	}
	printf("room details %d was not found!\n", record);
}
int findnum(int recordnum)
{
	int record;
	record = recordnum;
	currentc = firstc;
	while (currentc != NULL)
	{
		if (currentc->number == record)
		{
			return 1;
		}
		else
		{
			currentc = currentc->next;
		}
	}
	return -1;
}
int findroom() /* find contact function*/
{
	char buff[20];
	if (firstc == NULL)
	{
		puts("There are no room details to find!");
		return 1;
	}
	printf("Enter Your name: ");
	//fflush(stdin);
	/// clears any text from the input stream /
	//gets(buff);
	scanf("%s", &buff);
	currentc = firstc;
	while (currentc != NULL)
	{
		if (strcmp(currentc->name, buff) == 0)
		{
			printf("%6s %-20s %-15s %-15s\n", "Acct#", "Name", "Phone", "Email");
			/// prints table titles /
			printf("%6d: %-20s %-15d %-20s\n",
				currentc->number,
				currentc->name,
				currentc->phone,
				currentc->email);
			return 0;
		}
		else
		{
			currentc = currentc->next;
		}
	}
	printf("contact %s was not found!\n", buff);
	return 1;
}
int prompt()
{
	int a;
	fflush(stdin);
	printf("Update? (1 to update any other key to not)");
	scanf("%d", &a);
	fflush(stdin);
	if (a == 1)
	{
		printf("Enter new value: ");
		return (1);
	}
	else
		return (0);
}

void Invoice()
{
	time_t t;   // not a primitive datatype
	time(&t);
	char buff[20];
	printf("Enter Your name: ");
	scanf("%s", &buff);
	currentc = firstc;
	while (currentc != NULL)
	{
		if (strcmp(currentc->name, buff) == 0)
		{
			printf("\n\n\n-------------------------------------\n");
			printf("\n\t*******************************\n");
			printf("\n\tName : %-20s", currentc->name);
			printf("\n\tContact Number : %-15d", currentc->phone);
			printf("\n\tMail id : %-20s", currentc->email);
			printf("\n\tRoom No. : %6d", currentc->number);
			//printf("\n\tTotal Amount Should be Paid : ");
			printf("\n\tInvoice Generated on : %s", ctime(&t));
			printf("\n\t*******************************\n");
			printf("\nThanks For Visiting.\n\tVisit Again.\n");
			printf("\n-------------------------------------\n");
			break;
		}
		else
		{
			currentc = currentc->next;
		}
	}

}

