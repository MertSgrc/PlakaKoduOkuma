#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	//Dosya A�ma ��lemi
	FILE *dosya=fopen("plakalar.txt","w");
	if(dosya == NULL){
		printf("Dosya Olu�turulamad�\n");
		return 1;
	}
	fprintf(dosya,"08 Artvin\n");
	fprintf(dosya,"28 Giresun\n");
	fprintf(dosya,"29 G�m��hane\n");
	fprintf(dosya,"52 Ordu\n");
	fprintf(dosya,"53 Rize\n");
	fprintf(dosya,"61 Trabzon\n");
	fprintf(dosya,"69 Bayburt\n");
	fclose(dosya);
	
	//dosyay� okuyup kullan�c�n�n girdi�i veriye g�re ekrana yaz�lacak olan ilin yaz�lma i�lemi
	int plaka,dosyasehir=0;
	int dosyaplaka;
	char sehir[50];
	
	dosya=fopen("plakalar.txt","r");
	if(dosya == NULL){
		printf("Dosya Acilamadi\n");
		return 1;
	}
	
	printf("Lutfen bir plaka kodu girininiz: ");
	scanf("%d", &plaka);
	
	while(fgets(sehir, sizeof(sehir), dosya) != NULL){
		sscanf(sehir,"%d %s", &dosyaplaka, sehir);
		if(plaka==dosyaplaka){
			printf("%s Dogu Karadeniz bolgesinde yer alir\n",sehir);
			dosyasehir=1;
			break;
		}
	}
	if(dosyasehir==0){
		printf("Hatali Kod Girdiniz\n ");
	}

	fclose(dosya);
	return 0;
}
