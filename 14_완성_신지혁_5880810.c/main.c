#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linearList.h"

listType* makePolynomial(char str[]) {
    listType* poly = createList(100);
    int i = 0, sign = 1;

    while (str[i] != '\0') {
        while (str[i] == ' ') i++;

        sign = 1;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }

        int coef = 0, expo = 0;
        int hasCoef = 0;

        while (isdigit(str[i])) {
            coef = coef * 10 + (str[i] - '0');
            i++;
            hasCoef = 1;
        }

        if (!hasCoef) coef = 1;

        if (str[i] == 'x') {
            i++;
            if (str[i] == '^') {
                i++;
                while (isdigit(str[i])) {
                    expo = expo * 10 + (str[i] - '0');
                    i++;
                }
            }
            else {
                expo = 1;
            }
        }
        else {
            expo = 0;
        }

        elementType term = { coef * sign, expo };
        ordered_insertItem(poly, term);
    }

    return poly;
}

listType* multiplyPolynomials(listType* a, listType* b) {
    listType* result = createList(400);

    for (int i = 0; i <= a->last; i++) {
        elementType t1 = a->array[i];
        for (int j = 0; j <= b->last; j++) {
            elementType t2 = b->array[j];
            elementType temp;
            temp.coef = t1.coef * t2.coef;
            temp.expo = t1.expo + t2.expo;

            
            int found = 0;
            for (int k = 0; k <= result->last; k++) {
                if (result->array[k].expo == temp.expo) {
                    result->array[k].coef += temp.coef;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                ordered_insertItem(result, temp);
            }
        }
    }

    return result;
}

int main() {
    char str1[100], str2[100];

    printf("첫 번째 다항식을 입력하세요 (예: 3x^2+4x+1): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("두 번째 다항식을 입력하세요 (예: 2x^2+5x+3): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    listType* poly1 = makePolynomial(str1);
    listType* poly2 = makePolynomial(str2);
    listType* result = multiplyPolynomials(poly1, poly2);

    printf("\n[곱셈 결과]\n");
    printList(result);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(result);

    return 0;
}
