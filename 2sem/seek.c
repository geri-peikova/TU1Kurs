#include<stdio.h>
#include<stdlib.h>

#define NUM_SIZE ((size_t) 10)

void insertStatic();
void insertDynamic();

int main(){
	int arr[NUM_SIZE] = {0};
	int *arr_dyn=(int*)malloc(sizeof(int)*NUM_SIZE);

	FILE* file;
	file = fopen("C:\\Users\\35988\\eclipse-workspace\\numbers.txt","r");

	if(file != NULL)
	{
		insertStatic(&file, arr);
		insertDynamic(&file, &arr_dyn);

		fclose(file);
	}
	printf("%d\n", arr[1]);
	free(arr_dyn);
	return 0;
}

void insertStatic(FILE* file, int arr[]){
	int i=0;
	while(fscanf(file, "%d\n", &arr[i]) != EOF && i < NUM_SIZE)
	{
		i++;
	}
}

void insertDynamic(FILE* file, int *arr_dyn){
	int i=0;
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	arr_dyn = (int *) realloc(arr_dyn, size);
	while(fscanf(file, "%d\n", &arr_dyn[i]) != EOF && i < size)
	{
		i++;
	}
}
//desislav.andreev@gmail.com
