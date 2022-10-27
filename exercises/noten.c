#include <stdio.h>

int is_in_range(int note) {
    return note >= 0 && note <= 5;
}

int main() {

    int first =  -1, second = -1, third = -1;
    int rest = -1;
    printf("\nNoten: ");
    scanf("%d%d%d%d", &first, &second, &third, &rest);

    if ((rest != -1) || (first == -1) || (second == -1) || (third == -1)) printf("Erwarte genau 3 Noten!");

    if (!(is_in_range(first))) {
        printf("Erste Note muss zwischen 1 und 5 liegen!");
    }
    if (!(is_in_range(second))) {
        printf("Zweite Note muss zwischen 1 und 5 liegen!");
    }
    if (!(is_in_range(third))) {
        printf("Dritte Note muss zwischen 1 und 5 liegen!");
    }




}