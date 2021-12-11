/**
* main.cpp
* The main file for the petManagerTest sub-project.
* Methods under the petManager class are tested comprehensively.
* @author  Team2_1
* @version 1.0
* @since   2021-5-18
*/

#include <iostream>
#include "gtest/gtest.h"
#include "../cuddlySys/database.h"
#include "../cuddlySys/usermanager.h"
#include "../cuddlySys/petmanager.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    FooTest() {
        // You can do set-up work for each test here.
    }
    virtual ~FooTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }
    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.
    /** replace with your own **/
};

/**
 * @brief A test method
 * It tests the getPetID()/setPetID() method under the PetManager class.
 */
TEST(petID, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    for (int i = 0; i <= 100; i++){
        pm->setPetID(i);
        ASSERT_EQ(pm->getPetID(), i);
    }
}

/**
 * @brief A test method
 * It tests the setPetName()/getPetName() method under the PetManager class.
 */
TEST(petName, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetName("ABC");
    ASSERT_EQ(pm->getPetName(), "ABC");
    pm->setPetName("");
    ASSERT_EQ(pm->getPetName(), "");
    pm->setPetName("ab");
    ASSERT_EQ(pm->getPetName(), "ab");
}

/**
 * @brief A test method
 * It tests the setPetSpecies()/getPetSpecies() method under the PetManager class.
 */
TEST(petSpecies, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetSpecies("ABC");
    ASSERT_EQ(pm->getPetSpecies(), "ABC");
    pm->setPetSpecies("");
    ASSERT_EQ(pm->getPetSpecies(), "");
    pm->setPetSpecies("ab");
    ASSERT_EQ(pm->getPetSpecies(), "ab");
}

/**
 * @brief A test method
 * It tests the setPetBreed()/getPetBreed() method under the PetManager class.
 */
TEST(petBreed, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetBreed("ABC");
    ASSERT_EQ(pm->getPetBreed(), "ABC");
    pm->setPetBreed("");
    ASSERT_EQ(pm->getPetBreed(), "");
    pm->setPetBreed("ab");
    ASSERT_EQ(pm->getPetBreed(), "ab");
}

/**
 * @brief A test method
 * It tests the setPetGender()/getPetGender() method under the PetManager class.
 */
TEST(petGender, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetGender("Male");
    ASSERT_EQ(pm->getPetGender(), "Male");
    pm->setPetGender("Female");
    ASSERT_EQ(pm->getPetGender(), "Female");
    pm->setPetGender("male");
    ASSERT_EQ(pm->getPetGender(), "male");
    pm->setPetGender("female");
    ASSERT_EQ(pm->getPetGender(), "female");
}

/**
 * @brief A test method
 * It tests the setPetAge()/getPetAge() method under the PetManager class.
 */
TEST(petAge, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    for (int i = 0; i <= 100; i++){
        pm->setPetAge(i);
        ASSERT_EQ(pm->getPetAge(), i);
    }
}

/**
 * @brief A test method
 * It tests the setPetShelterID()/getPetShelterID() method under the PetManager class.
 */
TEST(petSID, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    for (int i = 0; i <= 1000; i++){
        pm->setPetShelterID(i);
        ASSERT_EQ(pm->getPetShelterID(), i);
    }
}

/**
 * @brief A test method
 * It tests the setPetWeight()/getPetWeight() method under the PetManager class.
 */
TEST(petWeight, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    for (int i = 0; i <= 100; i++){
        pm->setPetWeight(i);
        ASSERT_EQ(pm->getPetWeight(), i);
    }
}

/**
 * @brief A test method
 * It tests the setPetDescription()/getPetDescription() method under the PetManager class.
 */
TEST(petDescription, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetDescription("Pet A is Pet");
    ASSERT_EQ(pm->getPetDescription(), "Pet A is Pet");
    pm->setPetDescription("");
    ASSERT_EQ(pm->getPetDescription(), "");
    pm->setPetDescription("pet b is not pet");
    ASSERT_EQ(pm->getPetDescription(), "pet b is not pet");
    pm->setPetDescription("pet c and PET AAAA");
    ASSERT_EQ(pm->getPetDescription(), "pet c and PET AAAA");
}

/**
 * @brief A test method
 * It tests the setPetColor()/getPetColor() method under the PetManager class.
 */
TEST(petColor, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetColor("White");
    ASSERT_EQ(pm->getPetColor(), "White");
    pm->setPetColor("Black");
    ASSERT_EQ(pm->getPetColor(), "Black");
    pm->setPetColor("Brown");
    ASSERT_EQ(pm->getPetColor(), "Brown");
    pm->setPetColor("Blue");
    ASSERT_EQ(pm->getPetColor(), "Blue");
}

/**
 * @brief A test method
 * It tests the setPetDisease()/getPetDisease() method under the PetManager class.
 */
TEST(petDisease, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetDisease(1);
    ASSERT_EQ(pm->getPetDisease(), 1);
    pm->setPetDisease(0);
    ASSERT_EQ(pm->getPetDisease(), 0);
}


/**
 * @brief A test method
 * It tests the setPetRescue()/getPetRescue() method under the PetManager class.
 */
TEST(petRescue, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetRescue(1);
    ASSERT_EQ(pm->getPetRescue(), 1);
    pm->setPetRescue(0);
    ASSERT_EQ(pm->getPetRescue(), 0);
}

/**
 * @brief A test method
 * It tests the setPetImgPath1()/getPetImgPath1() method under the PetManager class.
 */
TEST(petImgPath1, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetImgPath1("../../cuddlySys/petImg/Nona_img.jpg");
    ASSERT_EQ(pm->getPetImgPath1(), "../../cuddlySys/petImg/Nona_img.jpg");
    pm->setPetImgPath1("../../cuddlySys/petImg/Lauren_img.jpg");
    ASSERT_EQ(pm->getPetImgPath1(), "../../cuddlySys/petImg/Lauren_img.jpg");
    pm->setPetImgPath1("../../cuddlySys/petImg/Lewis_img.jpg");
    ASSERT_EQ(pm->getPetImgPath1(), "../../cuddlySys/petImg/Lewis_img.jpg");
    pm->setPetImgPath1("../../cuddlySys/petImg/Garnett_img.jpg");
    ASSERT_EQ(pm->getPetImgPath1(), "../../cuddlySys/petImg/Garnett_img.jpg");
}

/**
 * @brief A test method
 * It tests the setPetImgPath2()/getPetImgPath2() method under the PetManager class.
 */
TEST(petImgPath2, TESTSIMPLE) {
    PetManager *pm = new PetManager;
    pm->setPetImgPath2("../../cuddlySys/petImg/Nona_img.jpg");
    ASSERT_EQ(pm->getPetImgPath2(), "../../cuddlySys/petImg/Nona_img.jpg");
    pm->setPetImgPath2("../../cuddlySys/petImg/Lauren_img.jpg");
    ASSERT_EQ(pm->getPetImgPath2(), "../../cuddlySys/petImg/Lauren_img.jpg");
    pm->setPetImgPath2("../../cuddlySys/petImg/Lewis_img.jpg");
    ASSERT_EQ(pm->getPetImgPath2(), "../../cuddlySys/petImg/Lewis_img.jpg");
    pm->setPetImgPath2("../../cuddlySys/petImg/Garnett_img.jpg");
    ASSERT_EQ(pm->getPetImgPath2(), "../../cuddlySys/petImg/Garnett_img.jpg");
}

/**
 * @brief The main function
 * Methods under the engine class are tested.
 * @param argc argument count
 * @param argv argument values
 * @return int returned integer of main function
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
