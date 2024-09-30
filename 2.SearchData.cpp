#include <stdio.h>
#include <string.h>

char loc1[4000][300]; 
char loc2[4000][300];
char room[4000][300];
char bathrooms[4000][300];
char carparks[4000][300];
char type[4000][300];
char furnish[4000][300];
char price[4000][300];
char area[4000][300];

int main() {
	FILE *housingData = fopen("file.csv", "r");
	
	int Baris = 0;
	if(housingData == NULL) {
		puts("Data does not exist!");
		return 0;
	} else {
		while(!feof(housingData)) {
			if(Baris == 0) {
				char head[2300];
				fscanf(housingData, "%[^\n]\n", head);
			}else{
				fscanf(housingData, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", 
				loc1[Baris], loc2[Baris], price[Baris], room[Baris], bathrooms[Baris], 
				carparks[Baris], type[Baris], area[Baris], furnish[Baris]);
			}
			Baris++;
		}
	}
	
	char dataX[255], NameColumn[255];
	printf("Type \"[DataX] in [NameColumn]\" to search: ");
	scanf("%s in %[^\n]", dataX, NameColumn);
	getchar();
	puts("");
	
	if(strcmp(NameColumn, "loc1") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(loc1[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "loc2") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(loc2[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "room") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(room[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "bathrooms") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(bathrooms[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "carparks") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(carparks[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "type") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(type[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else if(strcmp(NameColumn, "furnish") == 0) {
		int found = 0;
		for(int i = 1; i < Baris; i++) {
			if(strstr(furnish[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", 
				loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (Baris - 1)) && (found == 0)) {
				printf("Data \"%s\" do not exist!\n", dataX);
			}
		}
	} else {
		printf("Column \"%s\" do not exist!\n", NameColumn);
	}
	
	fclose(housingData);
	
	return 0;
}
