#include "../Header/chickenkampung.h"
#include "CUnit/Basic.h"

void chickenkampungTest(){
    ChickenKampung c;
    CU_ASSERT_EQUAL(c.isHungry(), true);
    CU_ASSERT_EQUAL(c.getLivingTime(), default_living_time);
    CU_ASSERT_EQUAL(c.isMilk(), false);
    CU_ASSERT_EQUAL(c.isEgg(), true);
    CU_ASSERT_EQUAL(c.isMeat(), true); 
}

void bersuaraTest(){
    ChickenKampung c;
    string s;
    s = c.bersuara();
    CU_ASSERT_EQUAL(s, "pok pok petoook");
}

void getProductTest(){
    ChickenKampung c;

    bool isError = false;
    FarmProduct f;
    try{
        c.setHungry(false);
        f = c.getProduct(true);
        CU_ASSERT_EQUAL(f.getID(), 2);
    }catch(char const* errormsg){
        if (strcmp(errormsg,"ayam kampung ini tidak memiliki produk saat ini\n"))
            isError = true;
    }

    isError = false;
    try{

        c.setHungry(true);
        c.makan();
        f = c.getProduct(false);
        CU_ASSERT_EQUAL(f.getID(), 1);
        
    }catch(char const* errormsg){
        if (strcmp(errormsg,"ayam kampung ini tidak memiliki produk saat ini\n"))
            isError = true;
    }

    isError = false;
    try{

        c.setHungry(false);
        c.makan();
        f = c.getProduct(false);
        CU_ASSERT_EQUAL(f.getID(), 1);
        
    }catch(char const* errormsg){
        if (strcmp(errormsg,"ayam kampung ini tidak memiliki produk saat ini\n"))
            isError = true;
    }

    CU_ASSERT_TRUE(isError);
}

void getIdTest(){
    ChickenKampung c;
    c.setHungry(false);
    CU_ASSERT_EQUAL(c.getId(), 2);
    c.setHungry(true);
    CU_ASSERT_EQUAL(c.getId(), 1);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("chickenkampung.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "chickenkampung", chickenkampungTest)) {
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