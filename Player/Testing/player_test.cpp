#include "../Header/player.h"
#include "../../FarmAnimal/Header/bull.h"
#include "../../FarmAnimal/Header/platypus.h"
#include "../../Product/Header/beefomellete.h"
#include "../../Product/Header/chickenegg.h"
#include "../../Product/Header/chickenmeat.h"
#include "../../Product/Header/cowmeat.h"
#include "../../Product/Header/cowmilk.h"
#include "../../Product/Header/platypusegg.h"
#include "../../Product/Header/platypusmilk.h"
#include "../../Product/Header/plachicksoup.h"
#include "../../Product/Header/platycowpancake.h"
#include "CUnit/Basic.h"
#include <sstream>

void playerTest(){
    Player p;
    CU_ASSERT_EQUAL(p.getWater(),DEFWATER);
    CU_ASSERT_EQUAL(p.getMoney(),DEFMONEY);
}

void talkTest(){
    Player p;
    Bull b;
    string s = p.talk(&b);
    CU_ASSERT_EQUAL(s, "(Manly) Moooo...");
    Platypus pl;
    s = p.talk(&pl);
    CU_ASSERT_EQUAL(s, "krrrrrrr...");
}

void interactTest(){
    Player p;
    Bull* b;
    b = new Bull();
    Platypus* pl;
    pl = new Platypus();
    bool e = false;

    try{
        p.interact(b);
    }catch (char const* err){
        if(strcmp(err,"Tidak bisa berinteraksi dengan animal yang meat producing only\n")){
            e = true;
        }
    }

    CU_ASSERT_TRUE(p.getInventory().isEmpty());
    CU_ASSERT_TRUE(e);

    e = false;

    try{
        bool id;
        p.interact(pl);
    }catch (char const* err){
        if(strcmp(err,"Tidak bisa berinteraksi dengan animal yang meat producing only\n")){
            e = true;
        }
    }

    CU_ASSERT_TRUE(e);

    // for (int i=1; i<MAXBAG; i++){
    //     Platypus* p1;
    //     p.interact(p1);
    // }

    // e = false;
    // try{
    //     Platypus* p2;
    //     p.interact(p2);
    // }catch(char const* err){
    //     if(strcmp(err, "Inventory penuh\n")){
    //         e = true;
    //     }
    // }
    // CU_ASSERT_TRUE(e);
}

void killTest(){
    Player p;
    Bull* b1;
    b1 = new Bull();
    p.kill(b1);
    CU_ASSERT_EQUAL(p.getInventory().getElmt(0).getID(), 3); 
    for (int i=1; i<MAXBAG; i++){
        Bull* b;
        b = new Bull();
        p.kill(b);
    }

    bool isError = false;
    try{
        Bull* b;
        b = new Bull();
        p.kill(b);
    }catch(char const* e){
        if(strcmp(e, "Inventory penuh\n")){
            isError = true;
        }
    }
    CU_ASSERT_TRUE(isError);
}

void renderTest(){
    Player p;
    CU_ASSERT_EQUAL(p.render(),22);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // Add a suite to the registry
    pSuite = CU_add_suite("player.cpp", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "player", playerTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "talk", talkTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "interact", interactTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "render", renderTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "kill", killTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}