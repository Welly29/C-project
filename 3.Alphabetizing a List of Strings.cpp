#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][5000], int n){
// Mendefinisikan variabel untuk loop luar dan dalam dari algoritma bubble sort
    long int i, j;
    char temp[5000];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0){
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main(){
	printf("Enter the number of towns: ");
// membuka file
	FILE *fp;
    fp = fopen ("file.csv", "r");
    if (fp == NULL){
    	printf("The file does not exist!");
	}
// jumlah kota yang akan di input
    long int n;
	scanf("%ld", &n);
    char towns[n][5000];
    long int i;
    for (i = 0; i < n; i++){
        printf("Enter the name of town %d: ", i + 1);
        scanf("%s", towns[i]);
    }
// Memanggil fungsi bubbleSort
    bubbleSort(towns, n);
    printf("Alphabetized list of towns: \n");
    for (i = 0; i < n; i++){
        printf("%s\n", towns[i]);
    }
//menutup file
    fclose(fp);
    return 0;
}
