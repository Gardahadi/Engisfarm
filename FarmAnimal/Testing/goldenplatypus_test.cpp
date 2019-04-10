#include "../Header/goldenplatypus.h"
#include "CUnit/Basic.h"
#include <cstring>

using namespace std;

void goldenplatypusTest() {
    GoldenPlatypus p;

    CU_ASSERT_EQUAL(p.isMilk(), true);
    CU_ASSERT_EQUAL(p.isEgg(), true);
    CU_ASSERT_EQUAL(p.isMeat(), false); 
    CU_ASSERT_EQUAL(p.isHungry(), true);
    CU_ASSERT_EQUAL(p.getLivingTime(), default_living_time);
}

void bersuaraTest() {
    GoldenPlatypus p;
    string s = p.bersuara();
    CU_ASSERT_EQUAL(s, "krrrrrrr...");
}

void getProductTest(){
    GoldenPlatypus p;
    FarmProduct f;
    bool e = false;
    bool k = false;
    p.setHungry(true);
    p.makan();
    try{
        f = p.getProduct(false);
        bool id = false;
        if (f.getID() == 5 || f.getID() == 6)
            id = true;
        CU_ASSERT_TRUE(id);
    }catch (char const* err){
        if(strcmp(err,"GoldenPlatypus ini tidak mempunyai produk saat ini\n")){
            e = true;
        }
        else if(strcmp(err,"kamu tidak boleh membunuh seekor platypus\n")){
            k = true;
        }
    }
    CU_ASSERT_EQUAL(e,false);
    CU_ASSERT_EQUAL(k,false);

    e = false;
    k = false;
    try{
        f = p.getProduct(true);
        bool id = false;
        if (f.getID() == 5 || f.getID() == 6)
            id = true;
    }catch (char const* err){
        if(strcmp(err,"kamu tidak boleh membunuh seekor platypus\n")){
            k = true;
        }
        else if(strcmp(err,"GoldenPlatypus ini tidak mempunyai produk saat ini\n")){
            e = true;
        }
    }
    CU_ASSERT_EQUAL(e,false);
    CU_ASSERT_EQUAL(k,true);

    e = false;
    k = false;
    p.setHungry(true);
    try{
        f = p.getProduct(false);
        bool id = false;
        if (f.getID() == 5 || f.getID() == 6)
            id = true;
    }catch (char const* err){
        if(strcmp(err,"GoldenPlatypus ini tidak mempunyai produk saat ini\n")){
            e = true;
        }
        else if(strcmp(err,"kamu tidak boleh membunuh seekor platypus\n")){
            k = true;
        }
    }
    CU_ASSERT_EQUAL(e,true);
    CU_ASSERT_EQUAL(k,false);
}

void getIdTest(){
    GoldenPlatypus p;
    p.setHungry(true);
    CU_ASSERT_EQUAL(p.getId(), 7);
    p.setHungry(false);
    CU_ASSERT_EQUAL(p.getId(), 8);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("goldenplatypus.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "goldenplatypus", goldenplatypusTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "bersuara", bersuaraTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getProduct", getProductTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "getId", getIdTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}