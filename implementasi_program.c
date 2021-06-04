#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int a,b,i;
	double x[100], y[100];
	double x_res, y_res;// Variable for X and f(x)
	double ST[100][100];
	double dx;
	int input = 0;
	double x_temp, y_temp, temp;
	int u = 0;
    char N;

i = 0;
    Menu:
        system("cls");
printf("1. Input Data\n");
printf("2. Lihat Data\n");
printf("3. Interpolasi\n");
printf("4. Keluar / Akhiri\n");
printf("Pilihananda : ");
scanf("%i", &input);

        switch(input){
        case 1 :
goto Input_1;
        case 2 :
goto Input_2;
        case 3 :
goto Input_3;
        case 4 :
exit(4);
default :
goto Menu;
        }
	/* Data x dan f(x) - Jika data telah di define*/
    /*
	y[0] = 256122;
	y[1] = 288687;
	y[2] = 155951;
	y[3] = 153381;
	y[4] = 158525;
	y[5] = 444556;
	y[6] = 387774;
y[7] = 222869;
	y[8] = 140888;
	y[9] = 138057;
	y[10] = 152112;
	y[11] = 78056;


	for(a = 0; a <i; a++) {
        if (y[a] == 0){
            x[a] = 0;
        } else {
            x[a] = a + 1;
        }
	}
    */

    /* Data Input */
    Input_1:
        system("cls");
printf("Input Data : \n");
printf("x = ");
scanf("%lf", &x_temp);
printf("f(x) = ");
scanf("%lf", &y_temp);

if(i> 0) {
            // Sort and fill based on variable "i"
for(a = 0; a <i; a++) {
                if(x[a] >x_temp) {
                    // untuk x
                    temp = x[a];
                    x[a] = x_temp;
x_temp = temp;
                    // untuk f(x)
                    temp = y[a];
                    y[a] = y_temp;
y_temp = temp;
                }
            }
        }
        x[i] = x_temp;
        y[i] = y_temp;
i = i + 1;
goto Menu;

    /* Lihat data */
    Input_2:
if(i == 0) {
printf("Data Kosong.\n Ketiksembaranguntukkembali...");
        } else {
            system("cls");
printf("  i  ||  x  ||  f(x)  \n");
for(a = 0; a <i; a++) {
printf("%i || %.5lf || %.5lf\n", a, x[a], y[a]);
            }
printf("\n");
printf("Ketiksembaranguntukkembali...");
        }
getch();
goto Menu;

	/* Proses Interpolasi */
    Input_3:

        if (i<2){
printf("Maaf, data tidakdapatdiiterasikan\n");
printf("Ketiksembaranguntukkembali...");
getch();
goto Menu;
        }

        /* TabelIterasi */

        for (a = 0; a <i; a++){
            ST[0][a] = y[a];
        }

for(a = 1; a <i; a++){
for(b = 0; b < (i-a); b++) {
                ST[a][b] = (ST[a-1][b+1] - ST[a-1][b]) / (x[b+a] - x[b]);
            }
        }

gotoIn;

        In:
            system("cls");
y_res = 0;
            dx = 1;
printf("x = ");
scanf("%lf", &x_res);

for(a = 0; a <i; a++) {
y_res = y_res + (ST[a][0] * dx);
                dx = dx * (x_res - x[a]);
            }
printf("f(x) = %.5Lf", y_res);
printf("\n\n\n");
goto Choice;
Choice:
printf("UlangLagi? (Y/N): ");
            while ((getchar()) != '\n');
scanf("%c", &N);
            if ((N == 'Y') || (N == 'y')) {
gotoIn;
            } else if ((N == 'N') || (N == 'n')) {
goto Menu;
            } else {
goto Choice;
            }
}
