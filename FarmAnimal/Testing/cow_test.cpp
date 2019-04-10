#include "../Header/cow.h"
#include "CUnit/Basic.h"

using namespace std;

void cowTest() {
//   Check if first param matches with second[2]
    Cow b;

    CU_ASSERT_EQUAL(b.isMilk(), true);
    CU_ASSERT_EQUAL(b.isEgg(), false);
    CU_ASSERT_EQUAL(b.isMeat(), true); 
    CU_ASSERT_EQUAL(b.isHungry(), true);
    CU_ASSERT_EQUAL(b.getLivingTime(), default_living_time);
}

void bersuaraTest() {
    Cow b;
    string s = b.bersuara();
    CU_ASSERT_EQUAL(s, "Moooo...");
}

void getProductTest(){
    Cow c;

    bool isError = false;
    FarmProduct f;
    try{
        c.setHungry(false);
        f = c.getProduct(true);
        CU_ASSERT_EQUAL(f.getID(), 3);
    }catch(char const* errormsg){
        if (strcmp(errormsg,"Sapi ini tidak mempunyai produk saat ini\n"))
            isError = true;
    }

    isError = false;
    try{
        c.setHungry(true);
        c.makan();
        f = c.getProduct(false);
        CU_ASSERT_EQUAL(f.getID(), 4);
        
    }catch(char const* errormsg){
        if (strcmp(errormsg,"Sapi ini tidak mempunyai produk saat ini\n"))
            isError = true;
    }

    isError = false;
    try{
        c.setHungry(false);
        c.makan();
        f = c.getProduct(false);
        CU_ASSERT_EQUAL(f.getID(), 4);
        
    }catch(char const* errormsg){
        if (strcmp(errormsg,"Sapi ini tidak memiliki produk saat ini\n"))
            isError = true;
    }

    CU_ASSERT_TRUE(isError);
}

void getIdTest(){
    Cow b;
    b.setHungry(true);
    CU_ASSERT_EQUAL(b.getId(), 5);
    b.setHungry(false);
    CU_ASSERT_EQUAL(b.getId(), 6);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("cow.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "cow", cowTest)) {
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