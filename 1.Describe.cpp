#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct HousingData{
	char loc1[200];
	char loc2[200];
	int room;
	int bathrooms;
	int carparks;
	char type[200];
	char furnish[200];
	long int price;
	int area;
};

struct HousingData House[5000];
	int calculate;

	int main(){
		FILE *fp;
		fp = fopen ("file.csv","r");
		
		char describe[200];
		fscanf(fp,"%[^\n]\n", describe);
		printf("%s\n", describe);

	while(!feof(fp)){
		
		fscanf(fp,"%[^,],", House[calculate].loc1);
		fscanf(fp,"%[^,],", House[calculate].loc2);
		fscanf(fp,"%ld,", &House[calculate].price);
		fscanf(fp,"%d,", &House[calculate].room);
		fscanf(fp,"%d,", &House[calculate].bathrooms);
		fscanf(fp,"%d,", &House[calculate].carparks);
		fscanf(fp,"%[^,],", House[calculate].type);
		fscanf(fp,"%d,", &House[calculate].area);
		fscanf(fp,"%[^\n]\n", House[calculate].furnish);

		if(strcmp(House[calculate].loc1,"\0") == 0){
			break;
		}
		calculate++;
	}

	int option;
		while(option != 10){
			if(calculate > 1){
				puts("\n======================HOUSING IN MALAYSIA=======================\n");
				puts("==========================YOUR CHOICE========================\n");
				printf("1. Location 1\n");
				printf("2. Location 2\n");
				printf("3. Price\n");
				printf("4. Room\n");
				printf("5. Bathroom\n");
				printf("6. Carparks\n");
				printf("7. Room type\n");
				printf("8. Area\n");
				printf("9. Furnish\n");
				printf("10. Exit\n\n");
				printf("Select to count: ");
				
				scanf("%d", &option);
			
            if(option == 1){
                char a1[5000][200];
            	char finds1[5000][200];
            	int inc1 = 0;
            	int find1[200];
	        		for(int i = 1; i < calculate; i++){
                		strcpy(a1[i], House[i].loc1);
	        		}
				printf("\n\n========LIST========\n====================\n\n");
				
	        	int calculateer1 = 0;
	        		for(int i = 1; i < calculate; i++){
		        		if(strcmp(a1[i],"x") != 0){
			        	char temp1[200];
			        		strcpy(temp1, a1[i]);
			        		calculateer1 = 0;
			        	for(int j = 1; j < calculate; j++){	
				        	if(strcmp(temp1, a1[j]) == 0){
					        	strcpy(a1[j],"x");
					        	calculateer1++;
				        	}
			        	}
			    		printf("%s : %d\n", temp1, calculateer1);
                			inc1++;
                				strcpy(finds1[inc1], temp1);
                				find1[inc1] = calculateer1; 
		        		}   
	        		}
            		printf("Total: %d\n", inc1);
            		
            int max1 = find1[1];
            char maxs1[200];
            int min1 = find1[1];
            char mins1[200];
            int inc11 = inc1;
            	for(int j = 1; j < inc1; j++){
                	if(find1[j] >= max1){
                    	max1 = find1[j];
                    	strcpy(maxs1, finds1[j]);
                	} 
            	}
            	printf("Maximum value: %s with frequency %d\n", maxs1, max1);
            	
				for(int k = inc11; k >= 1; k--){
                	if(find1[k] < min1){
                    	min1 = find1[k];
                    	strcpy(mins1, finds1[k]);
                	}
            	}
            	printf("Minimum value: %s with frequency %d\n", mins1, min1);
            }
				else if(option == 3){
					int min3 = House[1].price;
					int max3 = House[1].price;
						for(int j = 2; j < calculate; j++){
							if(House[j].price < min3){
								min3 = House[j].price;
							}
						}
						for(int j = 2; j < calculate; j++){
							if(House[j].price > max3){
							max3 = House[j].price;
							}
						}
                		printf("\n\n========LIST========\n====================\n\n");
						printf("Minimum value: %d\n", min3);
						printf("Maximum value: %d\n", max3);
			
			int average3 = 0;
				for(int j = 0; j < calculate; j++){
					average3 += House[j].price;
				}
				printf("Average value: %d\n",average3 /= calculate);
				
					}else if(option == 8){
						int min8 = House[1].area;
						int max8 = House[1].area;
							for(int j = 2; j < calculate; j++){
								if(House[j].area < min8){
									min8 = House[j].area;
								}
							}
							for(int j = 2; j < calculate; j++){
								if(House[j].area > max8){
									max8 = House[j].area;
								}
							}
                			printf("\n\n========LIST========\n====================\n\n");
							printf("Minimum area: %d\n", min8);
							printf("Maximum area: %d\n", max8);
							
			int average8 = 0;
				for(int j = 1; j < calculate; j++){
					average8 += House[j].area;
				}
						printf("Area Average: %d\n",average8 /calculate);
            		}
			}
		}
		fclose(fp);
		return 0;
	}
