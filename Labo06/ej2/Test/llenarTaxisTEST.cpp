#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// Escribir tests aca:

TEST(llenarTaxisTEST, TodasMismoValor){
    int g1=3;
    int g2=3;
    int g3=3;
    int result = llenarTaxis3(g1,g2,g3);
    EXPECT_TRUE(result==6);
}

TEST(llenarTaxisTEST, diferentesYg2Par){
    int g1=1;
    int g2=2;
    int g3=3;
    int result = llenarTaxis3(g1,g2,g3);
    EXPECT_TRUE(result==5);
}

TEST(llenarTaxisTEST, diferentesYg2impar1){
    int g1=2;
    int g2=3;
    int g3=1;
    int result = llenarTaxis3(g1,g2,g3);
    EXPECT_TRUE(result==3);
}

TEST(llenarTaxisTEST, diferentesYg2impar2){
    int g1=3;
    int g2=1;
    int g3=0;
    int result = llenarTaxis3(g1,g2,g3);
    EXPECT_TRUE(result==2);
}