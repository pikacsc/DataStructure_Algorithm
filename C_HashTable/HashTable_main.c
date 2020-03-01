/*

HashTable - employee Info Dictionary

Open Addressing
BinarySearch

*/

#define UID_MAX 30
#define BUCKET_MAX 30
#define PHONE_MAX 16
#define PHONE_MIN 10
#define NAME_MAX 30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum eTeam
{
	DEV_1 = 1,
	DEV_2 = 2,
	DESIGN_1 = 3,
	DESIGN_2 = 4,
};

enum ePosition
{
	DEVLEOPER = 1,
	DESIGNER = 2,
	PRODUCER = 3,
	DIRECTOR = 4
};

typedef struct _tagUserData
{
	char name[NAME_MAX];
	char phone[PHONE_MAX];
	enum ePosition pos;
	size_t salary;
} UserData;

typedef struct _tagBucket
{
	char uid[UID_MAX];
	UserData uData;
} Bucket;

typedef struct _tagHashTable
{
	Bucket* buckets;
	size_t size;
	size_t capacity;
} UserDict;

void InitDict(UserDict* uDict);
size_t HashFunc(char* uid, size_t capacity);
void Insert(UserDict* uDict);
UserData MakeUser();
bool IsStringOnly(char* str);
bool IsNumberOnly(char* str);
bool IsSuitableID(char* str);
char* ePosToString(size_t ePos);
void Display(UserDict* uDict);
void Search(UserDict* uDict);
bool Find(UserDict* uDict, char* uid, Bucket** targetBucket);
void Update(UserDict* uDict);
void Remove(UserDict* uDict);

int main(void)
{
	UserDict uDict;
	InitDict(&uDict);
	bool onLoop = true;
	size_t input = 0;
	while (onLoop)
	{
		printf("\nEmployee Dictionary 1.0.0.0 - JasonChoi\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.Display\n");
		printf("4.Update\n");
		printf("5.Remove\n");
		printf("0.Quit\n");
		printf(">>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 0:
			onLoop = false;
			break;
		case 1:
			Insert(&uDict);
			break;
		case 2:
			Search(&uDict);
			break;
		case 3:
			Display(&uDict);
			break;
		case 4:
			Update(&uDict);
			break;
		case 5:
			Remove(&uDict);
			break;
		default:
			printf("\nWrong input please try again\n");
			break;
		}
	}
	free(uDict.buckets);
	return 0;
}

void InitDict(UserDict* uDict)
{
	uDict->buckets = (Bucket*)calloc(BUCKET_MAX, sizeof(Bucket));
	uDict->size = 0;
	uDict->capacity = BUCKET_MAX;
}

size_t HashFunc(char* uid, size_t capacity)
{
	size_t index = 0;
	for (size_t i = 0; i < strlen(uid); i++)
	{
		index += (size_t)uid[i];
	}
	return index % capacity;
}


void Insert(UserDict* uDict)
{
	rewind(stdin);
	if (uDict->size >= uDict->capacity)
	{
		printf("\nuser dictionary already full, remove some data\n");
		return;
	}

	char uid [UID_MAX] = { 0 };
	while (1)
	{
		uid[0] = '\0';
		printf("\nInput user id\n>>");
		scanf_s("%[^\n]%*c", uid, UID_MAX);
		if (IsSuitableID(uid) == true)
			break;
		printf("\nWrong input for ID, make sure no empty space\n");
	}

	size_t i = HashFunc(uid, uDict->capacity);

	if (strcmp(uDict->buckets[i].uid, uid) == 0)
	{
		printf("\nthat id user already exist\n");
		return;
	}
	UserData newUser = MakeUser();
	for (; i < uDict->capacity; i++)
	{
		if (strlen(uDict->buckets[i].uid) == 0)
		{
			strcpy_s(uDict->buckets[i].uid, UID_MAX, uid);
			uDict->buckets[i].uData = newUser;
			uDict->size++;
			printf("\nData Inserted\n");
			break;
		}
	}
}

UserData MakeUser()
{
	rewind(stdin);
	UserData newUser = { 0 };
	char buffer[50];
	size_t input = 0;
	bool flag;
	while (1)
	{
		buffer[0] = '\0';
		printf("\ninput new employee's name\n>>");
		scanf_s("%[^\n]%*c", buffer, NAME_MAX);
		flag = IsStringOnly(buffer);
		if (flag == true)
		{
			strcpy_s(newUser.name, NAME_MAX, buffer);
			break;
		}
		printf("\nWrong input, string only, try again\n");
		continue;
	}
	rewind(stdin);

	while (1)
	{
		buffer[0] = '\0';
		printf("\ninput new employee's phone number\n>>");
		scanf_s("%s", buffer, PHONE_MAX);
		if (IsNumberOnly(buffer) == false)
		{
			printf("\nWrong input, number only, try again\n");
			continue;
		}
		else if (strlen(buffer) < PHONE_MIN)
		{
			printf("\nWrong input, length should be more then 10\n");
			continue;
		}
		else
		{
			strcpy_s(newUser.phone, PHONE_MAX, buffer);
			break;
		}
	}
	rewind(stdin);


	while (1)
	{
		rewind(stdin);
		printf("\n1.Developer\n");
		printf("2.Designer\n");
		printf("3.Producer\n");
		printf("4.Director\n");
		printf("choose postion\n>>");
		scanf_s("%d", &input);
		if (input == DEVLEOPER)
		{
			newUser.pos = DEVLEOPER;
			break;
		}
		else if (input == DESIGNER)
		{
			newUser.pos = DESIGNER;
			break;
		}
		else if (input == PRODUCER)
		{
			newUser.pos = PRODUCER;
			break;
		}
		else if (input == DIRECTOR)
		{
			newUser.pos = DIRECTOR;
			break;
		}
		else
		{
			printf("\nWrong Input please try again\n");
			continue;
		}
	}
	rewind(stdin);

	while (1)
	{
		buffer[0] = '\0';
		printf("\ninput new employee's salary\n>> USD ");
		scanf_s("%s", buffer, sizeof(buffer));
		flag = IsNumberOnly(buffer);
		if (flag == true)
			break;
		printf("\nWrong input, numbers only, try again\n");
		continue;
	}

	newUser.salary = (size_t)atoi(buffer);
	
	return newUser;
}


bool IsStringOnly(char* str)
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
			continue;
		else if (0 > str[i] - 48)
			break;
		else if (i == (strlen(str) - 1))
			return true;
	}
	return false;
}

bool IsNumberOnly(char* str)
{
	size_t aschii = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		aschii = (size_t)str[i];
		if (aschii < 48 || aschii > 57)
			break;
		else if (i == (strlen(str) - 1))
			return true;
	}
	return false;
}

bool IsSuitableID(char* str)
{
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
			return false;
	}
	return true;
}

char* ePosToString(size_t ePos)
{
	switch (ePos)
	{
	case DEVLEOPER:
		return "Developer";
		break;	
	case DESIGNER:
		return "Designer";
		break;	
	case PRODUCER:
		return "Producer";
		break;
	case DIRECTOR:
		return "Director";
		break;
	default:
		return NULL;
		break;
	}
}

void Display(UserDict* uDict)
{
	printf("\nsize : %d\n",uDict->size);
	printf("capacity : %d\n",uDict->capacity);
	printf("Index\tID\t\tNAME\t\t\tPHONE\t\t\tPOSITION\tSALARY($)\n");
	UserData uData;
	for (size_t i = 0; i < uDict->capacity; i++)
	{
		uData = uDict->buckets[i].uData;
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t$ %d\n", i, uDict->buckets[i].uid, uData.name, uData.phone, ePosToString(uData.pos), uData.salary);
	}
}

void Search(UserDict* uDict)
{
	Bucket *targetBucket = NULL;
	char uid[UID_MAX] = { 0 };
	while (1)
	{
		rewind(stdin);
		uid[0] = '\0';
		printf("\ninput user ID\n>>");
		scanf_s("%s", uid, UID_MAX);
		if (IsSuitableID(uid) == false)
			printf("\nWrong input, ID can't contain empty space\n");
		else
			break;
	}
	
	if (Find(uDict,uid,&targetBucket) == true)
	{
		printf("\nFound User!\n");
		printf("Index\tID\t\tNAME\t\t\tPHONE\t\t\tPOSITION\tSALARY($)\n");
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t$ %d\n", HashFunc(targetBucket->uid,uDict->capacity), 
												targetBucket->uid, 
											targetBucket->uData.name, 
											targetBucket->uData.phone, 
											ePosToString(targetBucket->uData.pos), 
											targetBucket->uData.salary);
	}
	else
	{
		printf("\nCan't find user\n");
	}

}

bool Find(UserDict* uDict,char* uid,Bucket** targetBucket)
{
	//Binary Search
	Bucket* buckets = &(uDict->buckets[0]);
	size_t startIdx = 0;
	size_t endIdx = uDict->capacity - 1;
	size_t midIdx = (size_t)(endIdx * 0.5f);
	Bucket headBucket = { 0 };
	size_t compare = 0;
	size_t hashIdx = HashFunc(uid, uDict->capacity);
	size_t tryCount = 0;

	if (strlen(buckets[hashIdx].uid) == 0)
			return false;
	else if (strcmp(buckets[hashIdx].uid, uid) == 0)
	{
		*targetBucket = &buckets[hashIdx];
		return true;
	}


	while (startIdx <= endIdx)
	{	
		printf("\nBinary Searching count %d\n", ++tryCount);
		headBucket = buckets[midIdx];
		compare = strcmp(headBucket.uid, uid);
		switch (compare)
		{
		case 0:
			if(targetBucket != NULL)
				*targetBucket = &buckets[midIdx];
			return true;
			break;
		case 1:
			endIdx = midIdx - 1;
			break;
		case -1:
			startIdx = midIdx + 1;
			break;
		default:
			midIdx++;
			break;
		}
		midIdx = (size_t)(startIdx + (endIdx - startIdx) * 0.5f);
	}
	return false;
}

void Update(UserDict* uDict)
{
	if (uDict->size == 0)
	{
		printf("\nNo data in Employee Dictionary\n");
		return;
	}
	char uid[UID_MAX] = { 0 };
	Bucket* targetBucket = NULL;
	rewind(stdin);

	while (1)
	{
		uid[0] = '\0';
		printf("\ninput the user id\n>>");
		scanf_s("%s", uid, UID_MAX);
		if (IsSuitableID(uid) == false)
		{
			printf("\nWrong input,make sure no empty space in ID\n");
			continue;
		}
		else
			break;
	}

	if(Find(uDict,uid,&targetBucket) == true)
	{
		printf("Index\tID\t\tNAME\t\t\tPHONE\t\t\tPOSITION\tSALARY($)\n");
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t$ %d\n", HashFunc(targetBucket->uid, uDict->capacity),
			targetBucket->uid,
			targetBucket->uData.name,
			targetBucket->uData.phone,
			ePosToString(targetBucket->uData.pos),
			targetBucket->uData.salary);
		targetBucket->uData = MakeUser();
		return;
	}
	else
	{
		printf("\nCan't find user\n");
		return;
	}

}

void Remove(UserDict* uDict)
{
	if (uDict->size == 0)
	{
		printf("\nNo data in Employee Dictionary\n");
		return;
	}
	char uid[UID_MAX] = { 0 };
	Bucket* targetBucket = NULL;
	UserData nullData = { 0 };
	char YorN = 0;
	rewind(stdin);

	while (1)
	{
		uid[0] = '\0';
		printf("\ninput the user id\n>>");
		scanf_s("%s", uid, UID_MAX);
		if (IsSuitableID(uid) == false)
		{
			printf("\nWrong input,make sure no empty space in ID\n");
			continue;
		}
		else
			break;
	}


	if (Find(uDict, uid, &targetBucket) == true)
	{
		rewind(stdin);
		printf("Index\tID\t\tNAME\t\t\tPHONE\t\t\tPOSITION\tSALARY($)\n");
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t$ %d\n", HashFunc(targetBucket->uid, uDict->capacity),
			targetBucket->uid,
			targetBucket->uData.name,
			targetBucket->uData.phone,
			ePosToString(targetBucket->uData.pos),
			targetBucket->uData.salary);
		while (1)
		{
			printf("\nAre you sure want to remove this user?\ny or n >>");
			scanf_s("%c", &YorN, sizeof(char));
			if (YorN == 'Y' || YorN == 'y')
			{
				targetBucket->uData = nullData;
				targetBucket->uid[0] = '\0';
				uDict->size--;
				return;
			}
			else if (YorN == 'N' || YorN == 'n')
			{
				break;
			}
			else
			{
				printf("\nWrong Input, y or n only\n");
				continue;
			}
		}
	}
	else
	{
		printf("\nCan't find user\n");
		return;
	}
}
