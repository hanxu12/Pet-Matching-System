/**
* main.cpp
* The main file for the DataBaseTest sub-project.
* Methods under the DataBase class are tested comprehensively.
* @author  Team2_1
* @version 3.0
* @since   2021-4-25
*/

#include <iostream>
#include "gtest/gtest.h"
#include "../cuddlySys/database.h"
#include "../cuddlySys/usermanager.h"
#include "../cuddlySys/petmanager.h"
#include <QFile>
#include <QThread>

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
    //DataBase d1;
    //DataBase s2;
};

/**
 * @brief A test method
 * It tests the isValid() method under the Database class.
 */
TEST(isValid, testing) {
    /** replace with your own **/
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.isValid("admin", "admin"), true);
    ASSERT_EQ(db.isValid("jackyard", "12345"), true);
    ASSERT_EQ(db.isValid("parsley", "123"), true);
}

/**
 * @brief A test method
 * It tests the exists() method under the Database class.
 */
TEST(exists, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.exist("admin"),true);
    ASSERT_EQ(db.exist("jackyard"),true);
    ASSERT_EQ(db.exist("parsley"),true);
    ASSERT_EQ(db.exist("sinful"),true);
    ASSERT_EQ(db.exist("jour"),true);
}

/**
 * @brief A test method
 * It tests the userExists() method under the Database class.
 */
TEST(userExists, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    for (int i = 1; i <= 6; i++) {
        if (i == 2) {
            ASSERT_EQ(db.userExists(i),false);
        } else {
            ASSERT_EQ(db.userExists(i),true);
        }
    }
}

/**
 * @brief A test method
 * It tests the petExists() method under the Database class.
 */
TEST(petExists, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    for (int i = 1; i <= 50; i++) {
        if (i == 2 || i == 22 || i == 44) {
            ASSERT_EQ(db.petExists(i),false);
        } else {
            ASSERT_EQ(db.petExists(i),true);
        }
    }
}

/**
 * @brief A test method
 * It tests the countAdoptionReqforShelter() method under the Database class.
 */
TEST(countAdoptionReqforShelter, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.countAdoptionReqforShelter(3,0), 85);
    ASSERT_EQ(db.countAdoptionReqforShelter(3,1), 9);
    ASSERT_EQ(db.countAdoptionReqforShelter(3,2), 2);
    ASSERT_EQ(db.countAdoptionReqforShelter(3,3), 1);
    for (int i = 0; i <= 3; i++) {
    ASSERT_EQ(db.countAdoptionReqforShelter(5,i), 0);
    }
}

/**
 * @brief A test method
 * It tests the countPetsforShelter() method under the Database class.
 */
TEST(countPetsforShelter, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.countPetsforShelter(3), 47);
    ASSERT_EQ(db.countPetsforShelter(5), 0);
}

/**
 * @brief A test method
 * It tests the getUserID() method under the Database class.
 */
TEST(getUserID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserID("admin"),1);
    ASSERT_EQ(db.getUserID("jackyard"),3);
    ASSERT_EQ(db.getUserID("parsley"),4);
    ASSERT_EQ(db.getUserID("sinful"),5);
    ASSERT_EQ(db.getUserID("jour"),6);
}

/**
 * @brief A test method
 * It tests the getUserBio() method under the Database class.
 */
TEST(getUserBio, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserBio(1), "");
    ASSERT_EQ(db.getUserBio(3), "Jack5 is jack");
    ASSERT_EQ(db.getUserBio(5), "I'm Bob P. Lee");
    ASSERT_EQ(db.getUserBio(4), "I'm Robert C. Howard");
    ASSERT_EQ(db.getUserBio(6), "I'm Megan L. Colon");
}

/**
 * @brief A test method
 * It tests the getZip() method under the Database class.
 */
TEST(getZip, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getZip(1), 0);
    ASSERT_EQ(db.getZip(3), 18040);
    ASSERT_EQ(db.getZip(5), 72565);
    ASSERT_EQ(db.getZip(4), 53202);
    ASSERT_EQ(db.getZip(6), 54622);
}

/**
 * @brief A test method
 * It tests the getUserName() method under the Database class.
 */
TEST(getUserName, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserName(1),"admin");
    ASSERT_EQ(db.getUserName(3),"jackyard");
    ASSERT_EQ(db.getUserName(4),"parsley");
    ASSERT_EQ(db.getUserName(5),"sinful");
    ASSERT_EQ(db.getUserName(6),"jour");
}

/**
 * @brief A test method
 * It tests the getGroupType() method under the Database class.
 */
TEST(getGroupType, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getGroupType(1), 0);
    ASSERT_EQ(db.getGroupType(3), 2);
    ASSERT_EQ(db.getGroupType(4), 3);
    ASSERT_EQ(db.getGroupType(5), 1);
    ASSERT_EQ(db.getGroupType(6), 3);
}

/**
 * @brief A test method
 * It tests the getUserBreedPref() method under the Database class.
 */
TEST(getUserBreedPref, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserBreedPref(1), "");
    ASSERT_EQ(db.getUserBreedPref(3), "");
    ASSERT_EQ(db.getUserBreedPref(4), "Persian cat");
    ASSERT_EQ(db.getUserBreedPref(6), "Beagle");
}

/**
 * @brief A test method
 * It tests the getUserSpeciesPref() method under the Database class.
 */
TEST(getUserSpeciesPref, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserSpeciesPref(1), "");
    ASSERT_EQ(db.getUserSpeciesPref(3), "");
    ASSERT_EQ(db.getUserSpeciesPref(4), "Cat");
    ASSERT_EQ(db.getUserSpeciesPref(6), "Dog");
}

/**
 * @brief A test method
 * It tests the getUserColorPref() method under the Database class.
 */
TEST(getUserColorPref, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserColorPref(1), "");
    ASSERT_EQ(db.getUserColorPref(3), "");
    ASSERT_EQ(db.getUserColorPref(4), "White");
    ASSERT_EQ(db.getUserColorPref(6), "Brown");
}

/**
 * @brief A test method
 * It tests the getUserAgePref() method under the Database class.
 */
TEST(getUserAgePref, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserAgePref(1), "");
    ASSERT_EQ(db.getUserAgePref(3), "");
    ASSERT_EQ(db.getUserAgePref(4), "10 - 14 years");
    ASSERT_EQ(db.getUserAgePref(6), "1 - 2 years");
}

/**
 * @brief A test method
 * It tests the getUserWeightPref() method under the Database class.
 */
TEST(getUserWeightPref, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserWeightPref(1), "");
    ASSERT_EQ(db.getUserWeightPref(3), "");
    ASSERT_EQ(db.getUserWeightPref(4), "<10 lbs");
    ASSERT_EQ(db.getUserWeightPref(6), "20 - 50 lbs");
}

/**
 * @brief A test method
 * It tests the getMaxUid() method under the Database class.
 */
TEST(getMaxUid, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getMaxUid(), 6);
}

/**
 * @brief A test method
 * It tests the getMaxPetID() method under the Database class.
 */
TEST(getMaxPetID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getMaxPetID(), 50);
}

/**
 * @brief A test method
 * It tests the getName() method under the Database class.
 */
TEST(getName, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getName(1), "");
    ASSERT_EQ(db.getName(3), "Jack5");
    ASSERT_EQ(db.getName(5), "Bob");
    ASSERT_EQ(db.getName(4), "Robert");
    ASSERT_EQ(db.getName(6), "Megan");
}

/**
 * @brief A test method
 * It tests the getPhoneNo() method under the Database class.
 */
TEST(getPhoneNo, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPhoneNo(1), "");
    ASSERT_EQ(db.getPhoneNo(3), "1321434444");
    ASSERT_EQ(db.getPhoneNo(5), "6153639965");
    ASSERT_EQ(db.getPhoneNo(4), "2623950710");
    ASSERT_EQ(db.getPhoneNo(6), "6086262065");
}

/**
 * @brief A test method
 * It tests the getLoc() method under the Database class.
 */
TEST(getLoc, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getLoc(1), "");
    ASSERT_EQ(db.getLoc(3), "PA");
    ASSERT_EQ(db.getLoc(5), "AR");
    ASSERT_EQ(db.getLoc(4), "WI");
    ASSERT_EQ(db.getLoc(6), "WI");
}

/**
 * @brief A test method
 * It tests the getUserAddr() method under the Database class.
 */
TEST(getUserAddr, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getUserAddr(1), "");
    ASSERT_EQ(db.getUserAddr(3), "Lehigh University");
    ASSERT_EQ(db.getUserAddr(5), "2793 Arlington Avenue. Oxford");
    ASSERT_EQ(db.getUserAddr(4), "4860 Oakridge Farm Lane. Milwaukee");
    ASSERT_EQ(db.getUserAddr(6), "2005 Primrose Lane. Waumandee");
}

/**
 * @brief A test method
 * It tests the getGender() method under the Database class.
 */
TEST(getGender, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getGender(1), "");
    ASSERT_EQ(db.getGender(3), "Other");
    ASSERT_EQ(db.getGender(5), "Male");
    ASSERT_EQ(db.getGender(4), "Male");
    ASSERT_EQ(db.getGender(6), "Female");
}

/**
 * @brief A test method
 * It tests the getPetName() method under the Database class.
 */
TEST(getPetName, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetName(1), "Nona");
    ASSERT_EQ(db.getPetName(6), "Garnett");
    ASSERT_EQ(db.getPetName(35), "Rachael");
    ASSERT_EQ(db.getPetName(49), "Cornell");
    ASSERT_EQ(db.getPetName(50), "Rosamond");
}

/**
 * @brief A test method
 * It tests the getPetSpecies() method under the Database class.
 */
TEST(getPetSpecies, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetSpecies(1), "frog");
    ASSERT_EQ(db.getPetSpecies(6), "dog");
    ASSERT_EQ(db.getPetSpecies(35), "cat");
    ASSERT_EQ(db.getPetSpecies(49), "dog");
    ASSERT_EQ(db.getPetSpecies(31), "rabbit");
    ASSERT_EQ(db.getPetSpecies(36), "hamster");
}

/**
 * @brief A test method
 * It tests the getPetBreed() method under the Database class.
 */
TEST(getPetBreed, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetBreed(1), "African Bullfrog");
    ASSERT_EQ(db.getPetBreed(6), "Beagle");
    ASSERT_EQ(db.getPetBreed(35), "Sphynx");
    ASSERT_EQ(db.getPetBreed(49), "Yorkshire Terrier");
    ASSERT_EQ(db.getPetBreed(31), "Satin");
    ASSERT_EQ(db.getPetBreed(36), "Syrian");
}

/**
 * @brief A test method
 * It tests the getPetGender() method under the Database class.
 */
TEST(getPetGender, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetGender(1), "female");
    ASSERT_EQ(db.getPetGender(6), "female");
    ASSERT_EQ(db.getPetGender(35), "female");
    ASSERT_EQ(db.getPetGender(49), "male");
    ASSERT_EQ(db.getPetGender(31), "male");
    ASSERT_EQ(db.getPetGender(36), "female");
}

/**
 * @brief A test method
 * It tests the getPetDescription() method under the Database class.
 */
TEST(getPetDescription, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetDescription(1), "A small green african bullfrog");
    ASSERT_EQ(db.getPetDescription(6), "A large brown beagle");
    ASSERT_EQ(db.getPetDescription(35), "A medium pink sphynx cat");
    ASSERT_EQ(db.getPetDescription(49), "A small brown yorkshire terrier");
    ASSERT_EQ(db.getPetDescription(31), "A small brown disabled satin rabbit");
    ASSERT_EQ(db.getPetDescription(36), "A large brown syrian hamster");
}

/**
 * @brief A test method
 * It tests the getPetSid() method under the Database class.
 */
TEST(getPetSid, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    for (int i = 1; i <= 50; i++) {
        if (i == 2 || i == 22 || i==44){
            continue;
        }
        ASSERT_EQ(db.getPetSid(1), 3);
    }
}

/**
 * @brief A test method
 * It tests the getPetDisease() method under the Database class.
 */
TEST(getPetDisease, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetDisease(1), 0);
    ASSERT_EQ(db.getPetDisease(6), 1);
    ASSERT_EQ(db.getPetDisease(35), 1);
    ASSERT_EQ(db.getPetDisease(49), 0);
    ASSERT_EQ(db.getPetDisease(50), 0);
}

/**
 * @brief A test method
 * It tests the getPetRescue() method under the Database class.
 */
TEST(getPetRescue, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetRescue(1), 1);
    ASSERT_EQ(db.getPetRescue(6), 0);
    ASSERT_EQ(db.getPetRescue(35), 1);
    ASSERT_EQ(db.getPetRescue(49), 0);
    ASSERT_EQ(db.getPetRescue(50), 0);
}

/**
 * @brief A test method
 * It tests the getPetAge() method under the Database class.
 */
TEST(getPetAge, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetAge(1), 10);
    ASSERT_EQ(db.getPetAge(6), 4);
    ASSERT_EQ(db.getPetAge(35), 6);
    ASSERT_EQ(db.getPetAge(49), 5);
    ASSERT_EQ(db.getPetAge(50), 7);
}

/**
 * @brief A test method
 * It tests the getPetWeight() method under the Database class.
 */
TEST(getPetWeight, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetWeight(1), 7);
    ASSERT_EQ(db.getPetWeight(6), 16);
    ASSERT_EQ(db.getPetWeight(35), 8);
    ASSERT_EQ(db.getPetWeight(49), 7);
    ASSERT_EQ(db.getPetWeight(50), 6);
}

/**
 * @brief A test method
 * It tests the getPetColor() method under the Database class.
 */
TEST(getPetColor, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetColor(1), "green");
    ASSERT_EQ(db.getPetColor(6), "brown");
    ASSERT_EQ(db.getPetColor(35), "pink");
    ASSERT_EQ(db.getPetColor(49), "brown");
    ASSERT_EQ(db.getPetColor(31), "brown");
    ASSERT_EQ(db.getPetColor(28), "black");
}

/**
 * @brief A test method
 * It tests the getPetImg1() method under the Database class.
 */
TEST(getPetImg1, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetImg1(1), "petImg/1_1.jpg");
    ASSERT_EQ(db.getPetImg1(6), "petImg/6_1.jpg");
    ASSERT_EQ(db.getPetImg1(35), "petImg/35_1.jpg");
    ASSERT_EQ(db.getPetImg1(49), "petImg/49_1.jpg");
    ASSERT_EQ(db.getPetImg1(31), "petImg/31_1.jpg");
    ASSERT_EQ(db.getPetImg1(28), "petImg/28_1.jpg");
}

/**
 * @brief A test method
 * It tests the getPetImg2() method under the Database class.
 */
TEST(getPetImg2, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetImg2(1), "petImg/1_2.jpg");
    ASSERT_EQ(db.getPetImg2(6), "petImg/6_2.jpg");
    ASSERT_EQ(db.getPetImg2(35), "petImg/35_2.jpg");
    ASSERT_EQ(db.getPetImg2(49), "petImg/49_2.jpg");
    ASSERT_EQ(db.getPetImg2(31), "petImg/31_2.jpg");
    ASSERT_EQ(db.getPetImg2(28), "petImg/28_2.jpg");
}

/**
 * @brief A test method
 * It tests the getHistoryID() method under the Database class.
 */
TEST(getHistoryID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getHistoryID(4, 3), 2);
    ASSERT_EQ(db.getHistoryID(4, 15), 4);
    ASSERT_EQ(db.getHistoryID(4, 31), 5);
    ASSERT_EQ(db.getHistoryID(4, 79), 124);
    ASSERT_EQ(db.getHistoryID(4, 55), 175);
    ASSERT_EQ(db.getHistoryID(4, 14), 280);
}

/**
 * @brief A test method
 * It tests the getMaxHistoryID() method under the Database class.
 */
TEST(getMaxHistoryID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getMaxHistoryID(), 280);
}

/**
 * @brief A test method
 * It tests the isHistoryValid() method under the Database class.
 */
TEST(isHistoryValid, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.isHistoryValid(2, 4), true);
    ASSERT_EQ(db.isHistoryValid(131, 4), true);
    ASSERT_EQ(db.isHistoryValid(280, 4), true);
    for (int i = 281; i<=1000; i++) {
        ASSERT_EQ(db.isHistoryValid(i, 4), false);
    }
}

/**
 * @brief A test method
 * It tests the isPendingRequest() method under the Database class.
 */
TEST(isPendingRequest, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.isPendingRequest(2, 3), true);
    ASSERT_EQ(db.isPendingRequest(4, 3), true);
    ASSERT_EQ(db.isPendingRequest(14, 3), false);
    ASSERT_EQ(db.isPendingRequest(15, 3), false);
    ASSERT_EQ(db.isPendingRequest(143, 3), false);
    ASSERT_EQ(db.isPendingRequest(270, 3), false);
    ASSERT_EQ(db.isPendingRequest(280, 3), false);
    for (int i = 281; i<=1000; i++) {
        ASSERT_EQ(db.isHistoryValid(i, 3), false);
    }
}

/**
 * @brief A test method
 * It tests the getHistoryPetID() method under the Database class.
 */
TEST(getHistoryPetID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getHistoryPetID(2), 3);
    ASSERT_EQ(db.getHistoryPetID(4), 15);
    ASSERT_EQ(db.getHistoryPetID(5), 31);
    ASSERT_EQ(db.getHistoryPetID(6), 30);
    ASSERT_EQ(db.getHistoryPetID(12), 45);
    ASSERT_EQ(db.getHistoryPetID(274), 36);
    ASSERT_EQ(db.getHistoryPetID(279), 29);
    ASSERT_EQ(db.getHistoryPetID(280), 14);
}

/**
 * @brief A test method
 * It tests the getAdoptionStatus() method under the Database class.
 */
TEST(getAdoptionStatus, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getAdoptionStatus(2), 1);
    ASSERT_EQ(db.getAdoptionStatus(4), 1);
    ASSERT_EQ(db.getAdoptionStatus(5), 1);
    ASSERT_EQ(db.getAdoptionStatus(6), 1);
    ASSERT_EQ(db.getAdoptionStatus(16), 2);
    ASSERT_EQ(db.getAdoptionStatus(274), 0);
    ASSERT_EQ(db.getAdoptionStatus(279), 0);
    ASSERT_EQ(db.getAdoptionStatus(280), 0);
}

/**
 * @brief A test method
 * It tests the getAdoptionbyPetID() method under the Database class.
 */
TEST(getAdoptionbyPetID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getAdoptionbyPetID(4,3), 1);
    ASSERT_EQ(db.getAdoptionbyPetID(4,15), 1);
    ASSERT_EQ(db.getAdoptionbyPetID(4,43), 2);
    ASSERT_EQ(db.getAdoptionbyPetID(4,42), 3);
    ASSERT_EQ(db.getAdoptionbyPetID(4,41), 2);
    ASSERT_EQ(db.getAdoptionbyPetID(4,8), 0);
    ASSERT_EQ(db.getAdoptionbyPetID(4,32), 0);
    ASSERT_EQ(db.getAdoptionbyPetID(4, 14), 0);
}

/**
 * @brief A test method
 * It tests the getFavorbyHistID() method under the Database class.
 */
TEST(getFavorbyHistID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getFavorbyHistID(2), 3);
    ASSERT_EQ(db.getFavorbyHistID(7), 3);
    ASSERT_EQ(db.getFavorbyHistID(98), 2);
    ASSERT_EQ(db.getFavorbyHistID(16), 3);
    ASSERT_EQ(db.getFavorbyHistID(274), 1);
}

/**
 * @brief A test method
 * It tests the getFavorbyPetID() method under the Database class.
 */
TEST(getFavorbyPetID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getFavorbyPetID(4,3), 3);
    ASSERT_EQ(db.getFavorbyPetID(4,2), 2);
    ASSERT_EQ(db.getFavorbyPetID(4,50), 3);
    ASSERT_EQ(db.getFavorbyPetID(4,84), 2);
    ASSERT_EQ(db.getFavorbyPetID(4,61), 2);
    ASSERT_EQ(db.getFavorbyPetID(4,36), 1);
    ASSERT_EQ(db.getFavorbyPetID(4,14), 2);
}

/**
 * @brief A test method
 * It tests the getHistoryPID() method under the Database class.
 */
TEST(getHistoryPID, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getHistoryPID(2), 4);
    ASSERT_EQ(db.getHistoryPID(4), 4);
    ASSERT_EQ(db.getHistoryPID(5), 4);
    ASSERT_EQ(db.getHistoryPID(16), 4);
    ASSERT_EQ(db.getHistoryPID(131), 4);
    ASSERT_EQ(db.getHistoryPID(210), 4);
    ASSERT_EQ(db.getHistoryPID(279), 4);
    ASSERT_EQ(db.getHistoryPID(280), 4);
}

/**
 * @brief A test method
 * It tests the getHistoryDT() method under the Database class.
 */
TEST(getHistoryDT, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getHistoryDT(2), "2021-05-17 18:58:30");
    ASSERT_EQ(db.getHistoryDT(4), "2021-05-17 18:58:34");
    ASSERT_EQ(db.getHistoryDT(5), "2021-05-17 18:58:36");
    ASSERT_EQ(db.getHistoryDT(16), "2021-05-17 18:59:05");
    ASSERT_EQ(db.getHistoryDT(131), "2021-05-17 23:28:16");
    ASSERT_EQ(db.getHistoryDT(210), "2021-05-17 23:31:30");
    ASSERT_EQ(db.getHistoryDT(279), "2021-05-18 09:09:04");
    ASSERT_EQ(db.getHistoryDT(280), "2021-05-18 09:09:05");
}

/**
 * @brief A test method
 * It tests the getPetIDfromHist() method under the Database class.
 */
TEST(getPetIDfromHist, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    ASSERT_EQ(db.getPetIDfromHist(2), 3);
    ASSERT_EQ(db.getPetIDfromHist(4), 15);
    ASSERT_EQ(db.getPetIDfromHist(5), 31);
    ASSERT_EQ(db.getPetIDfromHist(16), 41);
    ASSERT_EQ(db.getPetIDfromHist(131), 81);
    ASSERT_EQ(db.getPetIDfromHist(210), 23);
    ASSERT_EQ(db.getPetIDfromHist(279), 29);
    ASSERT_EQ(db.getPetIDfromHist(280), 14);
}

/**
 * @brief A test method
 * It tests the getLat() method under the Database class.
 * Please note that this test takes ~1 min.
 */
TEST(getLat, testing) {
   DataBase db("../../cuddlySys/sysDBTest1bk.db");
   QFile f("../../cuddlySys/zipcodeTest.csv");
   f.open(QIODevice::ReadOnly);
   QTextStream ts (&f);
   //Travel through the csv file "excel.csv"
   while(!ts.atEnd()){
       QByteArray line = f.readLine();
       QString tmpStr = QString(line);
       QStringList tmpList = tmpStr.split(QLatin1Char(','));
       int zipcode = tmpList.at(0).toInt();
       double lat = tmpList.at(1).toDouble();
       ASSERT_EQ(QString::number(db.getLat(zipcode)),QString::number(lat));
   }
   f.close();
}

/**
 * @brief A test method
 * It tests the getLon() method under the Database class.
 * Please note that this test takes ~1 min.
 */
TEST(getLon, testing) {
   DataBase db("../../cuddlySys/sysDBTest1bk.db");
   QFile f("../../cuddlySys/zipcodeTest.csv");
   f.open(QIODevice::ReadOnly);
   QTextStream ts (&f);
   qDebug() << "test";
   //Travel through the csv file "excel.csv"
   while(!ts.atEnd()){
       QByteArray line = f.readLine();
       QString tmpStr = QString(line);
       QStringList tmpList = tmpStr.split(QLatin1Char(','));
       int zipcode = tmpList.at(0).toInt();
       double lon = tmpList.at(2).trimmed().toDouble();
       ASSERT_EQ(QString::number(db.getLon(zipcode)),QString::number(lon));
   }
   f.close();
}

/**
 * @brief A test method
 * It tests the addBrowseHist(),updateHistAdoptionStatus(),updateHistFavorStatus(),updateHistDT() method
 *  under the Database class.
 */
TEST(addBrowseHist, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    db.addBrowseHistory(50, 100, 200, 0, 0);
    int histID = db.getHistoryID(100, 200);
    //add entry
    ASSERT_EQ(db.isHistoryValid(histID, 100), true);
    QString oldDT = db.getHistoryDT(histID);
    qDebug() << oldDT;
    for (int i = 1000; i >= 0; i--) {
        db.updateHistAdoptionStatus(histID, i);
        ASSERT_EQ(db.getAdoptionStatus(histID), i);
    }
    for (int j = 1000; j >= 0; j--) {
        db.updateHistFavorStatus(histID, j);
        ASSERT_EQ(db.getFavorbyHistID(histID), j);
    }
    db.updateHistDT(histID);
    QString newDT = db.getHistoryDT(histID);
    qDebug() << newDT;
    ASSERT_NE(oldDT, newDT);
    db.deleteBrowseHistory(histID);
    //the entry is gone
    ASSERT_EQ(db.isHistoryValid(histID, 100), false);
}

/**
 * @brief A test method
 * It tests the addUser()/deleteUser() method under the Database class.
 */
TEST(addUser1, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    UserManager* tmpUser = new UserManager();
    int oldMax = db.getMaxUid();
    tmpUser->setUid(oldMax+1);
    tmpUser->setUsername("Babbo");
    tmpUser->setPassword("123");
    tmpUser->setName("BABO");
    tmpUser->setBio("MIDFNUDISFSIFND");
    tmpUser->setPhoneNo("238472834");
    tmpUser->setUserAddress("111 Quad Dr");
    tmpUser->setLocation("PA");
    tmpUser->setUserZipCode(18042);
    tmpUser->setGender("male");
    tmpUser->setUserType(1);
    db.addUser(tmpUser);
    ASSERT_EQ(db.exist("Babbo"),true);
    ASSERT_EQ(db.getUserID("Babbo"), oldMax+1);
    ASSERT_EQ(db.getName(oldMax+1), "BABO");
    ASSERT_EQ(db.getUserName(oldMax+1), "Babbo");
    ASSERT_EQ(db.getUserBio(oldMax+1), "MIDFNUDISFSIFND");
    ASSERT_EQ(db.getPhoneNo(oldMax+1), "238472834");
    ASSERT_EQ(db.getUserAddr(oldMax+1), "111 Quad Dr");
    ASSERT_EQ(db.getLoc(oldMax+1), "PA");
    ASSERT_EQ(db.getZip(oldMax+1), 18042);
    ASSERT_EQ(db.getGender(oldMax+1), "male");
    ASSERT_EQ(db.getGroupType(oldMax+1), 1);
    db.deleteUser(oldMax+1);
    ASSERT_EQ(db.exist("Babbo"),false);
    ASSERT_EQ(db.getMaxUid(), oldMax);
}

/**
 * @brief A test method
 * It tests the addUser()/deleteUser() method under the Database class.
 */
TEST(addUser2, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    UserManager* tmpUser = new UserManager();
    int oldMax = db.getMaxUid();
    tmpUser->setUid(oldMax+1);
    tmpUser->setUsername("Abbo");
    tmpUser->setPassword("12345");
    tmpUser->setName("Abbo Man");
    tmpUser->setBio("Abbo Abbo");
    tmpUser->setPhoneNo("039473824");
    tmpUser->setUserAddress("Union City");
    tmpUser->setLocation("NJ");
    tmpUser->setUserZipCode(70877);
    tmpUser->setGender("female");
    tmpUser->setUserType(2);
    db.addUser(tmpUser);
    ASSERT_EQ(db.exist("Abbo"),true);
    ASSERT_EQ(db.getUserID("Abbo"), oldMax+1);
    ASSERT_EQ(db.getName(oldMax+1), "Abbo Man");
    ASSERT_EQ(db.getUserName(oldMax+1), "Abbo");
    ASSERT_EQ(db.getUserBio(oldMax+1), "Abbo Abbo");
    ASSERT_EQ(db.getPhoneNo(oldMax+1), "039473824");
    ASSERT_EQ(db.getUserAddr(oldMax+1), "Union City");
    ASSERT_EQ(db.getLoc(oldMax+1), "NJ");
    ASSERT_EQ(db.getZip(oldMax+1), 70877);
    ASSERT_EQ(db.getGender(oldMax+1), "female");
    ASSERT_EQ(db.getGroupType(oldMax+1), 2);
    db.deleteUser(oldMax+1);
    ASSERT_EQ(db.exist("Abbo"),false);
    ASSERT_EQ(db.getMaxUid(), oldMax);
}

/**
 * @brief A test method
 * It tests the addUser()/deleteUser() method under the Database class.
 */
TEST(addUser3, testing) {
    DataBase db("../../cuddlySys/sysDBTest1bk.db");
    UserManager* tmpUser = new UserManager();
    int oldMax = db.getMaxUid();
    tmpUser->setUid(oldMax+1);
    tmpUser->setUsername("Cbbo");
    tmpUser->setPassword("54321");
    tmpUser->setName("Cbbo Girl");
    tmpUser->setBio("Cbbo CABC");
    tmpUser->setPhoneNo("909473362");
    tmpUser->setUserAddress("San Diago");
    tmpUser->setLocation("CA");
    tmpUser->setUserZipCode(91901);
    tmpUser->setGender("female");
    tmpUser->setUserType(3);
    tmpUser->setUserspeciesPref("Cat");
    tmpUser->setUserAgePref("10 - 14 years");
    tmpUser->setUserBreedPref("Persian cat");
    tmpUser->setUserColorPref("White");
    tmpUser->setUserWeightPref("<10 lbs");
    tmpUser->setUserLocPref(">20 miles");
    tmpUser->setUserRescuePref(1);
    tmpUser->setUserDiseasePref(1);
    db.addUser(tmpUser);
    db.insertPerf(tmpUser);
    ASSERT_EQ(db.exist("Cbbo"),true);
    ASSERT_EQ(db.getUserID("Cbbo"), oldMax+1);
    ASSERT_EQ(db.getName(oldMax+1), "Cbbo Girl");
    ASSERT_EQ(db.getUserName(oldMax+1), "Cbbo");
    ASSERT_EQ(db.getUserBio(oldMax+1), "Cbbo CABC");
    ASSERT_EQ(db.getPhoneNo(oldMax+1), "909473362");
    ASSERT_EQ(db.getUserAddr(oldMax+1), "San Diago");
    ASSERT_EQ(db.getLoc(oldMax+1), "CA");
    ASSERT_EQ(db.getZip(oldMax+1), 91901);
    ASSERT_EQ(db.getGender(oldMax+1), "female");
    ASSERT_EQ(db.getGroupType(oldMax+1), 3);
    ASSERT_EQ(db.getUserSpeciesPref(oldMax+1), "Cat");
    ASSERT_EQ(db.getUserColorPref(oldMax+1), "White");
    ASSERT_EQ(db.getUserAgePref(oldMax+1), "10 - 14 years");
    ASSERT_EQ(db.getUserBreedPref(oldMax+1), "Persian cat");
    ASSERT_EQ(db.getUserWeightPref(oldMax+1), "<10 lbs");
    ASSERT_EQ(db.getUserLocPref(oldMax+1), ">20 miles");
    ASSERT_EQ(db.getUserRescuePref(oldMax+1), 1);
    ASSERT_EQ(db.getUserDiseasePref(oldMax+1), 1);
    db.deleteUser(oldMax+1);
    ASSERT_EQ(db.exist("Cbbo"),false);
    ASSERT_EQ(db.getMaxUid(), oldMax);
}


/**
 * @brief The main function
 * Methods under the engine class are tested.
 * @param argc argument count
 * @param argv argument values
 * @return int returned integer of main function
 */
int main(int argc, char **argv) {
    if (QFile::exists("../../cuddlySys/sysDBTest1bk.db"))
    {
        QFile::remove("../../cuddlySys/sysDBTest1bk.db");
    }
    QFile::copy("../../cuddlySys/sysDBTest1.db", "../../cuddlySys/sysDBTest1bk.db");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
