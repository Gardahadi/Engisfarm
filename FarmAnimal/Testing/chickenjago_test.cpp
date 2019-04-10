#include "../Header/chickenjago.h"
#include "CUnit/Basic.h"
#include <cstring>

void chickenjagoTest(){
    ChickenJago c;

    CU_ASSERT_EQUAL(c.isHungry(), true);
    CU_ASSERT_EQUAL(c.getLivingTime(), default_living_time);
    CU_ASSERT_EQUAL(c.isMilk(), false);
    CU_ASSERT_EQUAL(c.isEgg(), false);
    CU_ASSERT_EQUAL(c.isMeat(), true); 
}

void bersuaraTest(){
    ChickenJago c;
    string s = c.bersuara();
    CU_ASSERT_EQUAL(s, "kukuruyuuuuuk");
}

void getProductTest(){
    ChickenJago b;
    FarmProduct f;
    bool e = false;
    try{
        f = b.getProduct(true);
        CU_ASSERT_EQUAL(f.getID(), 2);
    }catch (char const* err){
        if(strcmp(err, "ChickenJago tidak memiliki telur\n")){
            e = true;
        }
    }

    e = false;

    try{
        f = b.getProduct(false);
    }catch (char const* err){
        if(strcmp(err, "ChickenJago tidak memiliki telur\n")){
            e = true;
        }
    }
    
    CU_ASSERT_TRUE(e);
}

void getIdTest(){
    ChickenJago c;
    CU_ASSERT_EQUAL(c.getId(), 3);
    c.setHungry(false);
    CU_ASSERT_EQUAL(c.getId(), 4);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("chickenjago.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "chickenjago", chickenjagoTest)) {
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