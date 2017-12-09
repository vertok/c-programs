#include <stdio.h>

int ematrixp(int m[][4])
{ 
    /**
     * die funktion gibt true zurück, wenn m eine Einheitsmatrix ist
     * und sonst false
     * r - Anzahl der Zeilen (rows); c - Anzahl der Spalten (columns)
     * O - false; 1 - true 
     */
    int r=4, c=4;
    int i, j;
    if (r != c) return 0;
    else 
    {
        for (i = 0; i<r; i++) 
        {
            for (j = 0; j<c; j++) 
            {  
                if ((i == j) && (m[i][j] != 1)) 
                    return 0;
                else 
                    if ((i != j) && (m[i][j] != 0)) 
                        return 0;
            }
        }
        return 1;
    }
}

void matrix_eingabe(int m[][4])
{       
    /**
     * Fuktion zur Eingabe der Elemente einer Matrix 
     */
    int r=4, c=4;
    int i, j;
    printf("Geben Sie bitte die Elemente der Matrix m ein:\n");
    for (i = 0; i<r; i++)
    {
        for (j = 0; j<c; j++)
        {
            printf("i = [%d],j = [%d] >", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void matrix_ausgabe(int m[][4])
{
    int r=4, c=4;
    int i,j;
    for(i = 0;i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m [][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};   // Definition einer 4x4-Matrix 
    matrix_ausgabe(m);
    if(ematrixp(m))
        printf("Das ist EINE Einheitsmatrix!\n");
    else
        printf("Das ist KEINE Einheitsmatrix!\n");
    int m2 [4][4];
    
    matrix_eingabe(m2);
    matrix_ausgabe(m2);
    
    if(ematrixp(m2))
        printf("Das ist EINE Einheitsmatrix!\n");
    else
        printf("Das ist KEINE Einheitsmatrix!\n");
    return 0;
}