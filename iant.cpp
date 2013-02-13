#include "stdafx.h"
#include <iostream>

using namespace std;


int createFile(char fname[20], char ftype[5])
{
	char finaltype[25];
	strcpy_s(finaltype, sizeof(finaltype), fname);
	strcat_s(finaltype, ftype);

	FILE *noob;
	try
	{
		fopen_s(&noob, finaltype, "w+");
		fprintf(noob, "Hi, this will be the source file.");
		fclose(noob);
		printf("File successfully created.\n");
	}
	catch(...)
	{
		printf("An error has occured.");
		return 1;
	}
	return 0;
}

void askNewFile()
{
	char file[20];
	char fileActualType[5];
	char fileTypeBuffer[5];
	char * fileType;
	fileTypeBuffer[0] = '.';
	
	printf("Enter a new file name: ");
	cin >> file;
	printf("\n");
	printf("Enter a file type: ");
	cin >> fileActualType;
	strcpy(fileTypeBuffer + 1, fileActualType);
	fileType = fileTypeBuffer;
	
	createFile(file, fileType);
}
