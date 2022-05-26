#include "../puntaje.h"
#include "gtest/gtest.h"

// Escribir tests aca:

TEST(puntajeTEST, menosDe10YMultiplo){
    //setup
    int n = 3;
    //exercise
    int result = puntaje(n);
    //check
    EXPECT_TRUE(result==16);
}
TEST(puntajeTEST, menosDe10YNoMultiplo){
    //setup
    int n=4;
    //exercise
    int result = puntaje(n);
    //check
    EXPECT_TRUE(result==(-2));
}
TEST(puntajeTEST, masDe10YMultiplo){
    //setup
    int n=12;
    //exercise
    int result = puntaje(n);
    //check
    EXPECT_TRUE(result==22);
}

TEST(puntajeTEST, masDe10YNoMultiplo){
    //setup
    int n=11;
    //exercise
    int result = puntaje(n);
    //check
    EXPECT_TRUE(result==1);
}