#include "AStar.c"
#include <minunit.h>
//Include random ?

MU_TEST(w) {
    printf("-- TESTING w --\n");
    mu_assert_int_eq(1, w(0,0,145,120)); //Tjr égal à 1?? (chiffres randoms)
    printf(" -- TEST PASSED --\n")
}

MU_TEST(voisin) {

}

MU_TEST(check_voisin) {

}

MU_TEST(heuristique) {

}

int main(){

    return 0;
}