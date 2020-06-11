// laba 3 c
// elvina fedorinchik
/* На шахматной доске находятся король и несколько
ферзей другого цвета.Проверить, находится ли король под угрозой и
если да, кто ему угрожает.Положение фигур задано массивом 
k(8, 8) : 0 – клетка пуста, 1 – король, 2 – ферзь.
*/

#include <stdio.h>


const int FieldSize = 8;

int* LeftThreats(int* field, int posX, int posY) {
    int* tmp = Malloc(FieldSize * FieldSize * sizeof(int));
    int i, j;
    for (i = 0; i < FieldSize; i++)
        for (j = 0; j < FieldSize; j++)
            tmp[i * FieldSize + j] = 0;
    tmp[posX * FieldSize + posY] = 2;
    int dx, dy;
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++) {
            int tx = posX + dx, ty = posY + dy;
            while (OkPos(tx, ty) && !field[tx * FieldSize + ty]) {
                tx += dx;
                ty += dy;
            }
            if (OkPos(tx, ty) && field[tx * FieldSize + ty] == 1) {
                tmp[tx * FieldSize + ty] = 1;
            }
        }
    return tmp;
}

int main(void) {

    FILE* doso4ka = NULL;
    if (fopen_s(doso4ka, "D:\\labs 2 sem C\\laba_3\\laba_3\\doso4ka.txt", "r")) {
        perror("Cannot open file.\n");
        exit(-3);
    }

    int* field = Malloc(FieldSize * FieldSize * sizeof(int));
    int i, j;
    for (i = 0; i < FieldSize; i++)
        for (j = 0; j < FieldSize; j++) {
            int tmp;
            tmp = StringReadInt(doso4ka, 0, 2);
            field[i * FieldSize + j] = tmp;
        }

    for (i = 0; i < FieldSize; i++) {
        for (j = 0; j < FieldSize; j++)
            printf("%d ", field[i * FieldSize + j]);
        printf("\n");
    }
    printf("\n");

    int KingPosX = -1, KingPosY = -1;
    for (i = 0; i < FieldSize; i++)
        for (j = 0; j < FieldSize; j++)
            if (field[i * FieldSize + j] == 2) {
                if (KingPosX != -1) {
                    FatalError("Le Roi est mort, vive le Roi!");
                }
                KingPosX = i;
                KingPosY = j;
            }
    if (KingPosX == -1) {
        FatalError("Le Roi est mort.");
    }

    int* Ans = LeftThreats(field, KingPosX, KingPosY);
    for (i = 0; i < FieldSize; i++) {
        for (j = 0; j < FieldSize; j++) {
            switch (Ans[i * FieldSize + j]) {
            case 0:
                printf("#");
                break;
            case 1:
                printf("Q");
                break;
            case 2:
                printf("K");
                break;
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
