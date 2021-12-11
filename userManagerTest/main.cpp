/**
* main.cpp
* The main file for the userManagerTest sub-project.
* Methods under the userManager class are tested comprehensively.
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
    //    Configuration s1;
    //    Configuration s2;
};

/**
 * @brief A test method
 * It tests the getUid()/setUid() method under the UserManager class.
 */
TEST(getUid, TESTSIMPLE) {
    UserManager *um = new UserManager;
    for (int i = 0; i <= 100; i++){
        um->setUid(i);
        ASSERT_EQ(um->getUid(), i);
    }
}

/**
 * @brief A test method
 * It tests the getUsername()/setUsername() method under the UserManager class.
 */
TEST(getUsername, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUsername("ABC");
    ASSERT_EQ(um->getUsername(), "ABC");
    um->setUsername("");
    ASSERT_EQ(um->getUsername(), "");
    um->setUsername("ab");
    ASSERT_EQ(um->getUsername(), "ab");
}

/**
 * @brief A test method
 * It tests the getPassword()/setPassword() method under the UserManager class.
 */
TEST(getPassword, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setPassword("ABC");
    ASSERT_EQ(um->getPassword(), "ABC");
    um->setPassword("");
    ASSERT_EQ(um->getPassword(), "");
    um->setPassword("ab");
    ASSERT_EQ(um->getPassword(), "ab");
}

/**
 * @brief A test method
 * It tests the getPhoneNo()/setPhoneNo() method under the UserManager class.
 */
TEST(getPhoneNo, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setPhoneNo("0000000000");
    ASSERT_EQ(um->getPhoneNo(), "0000000000");
    um->setPhoneNo("1234567890");
    ASSERT_EQ(um->getPhoneNo(), "1234567890");
    um->setPhoneNo("4840001234");
    ASSERT_EQ(um->getPhoneNo(), "4840001234");
}

/**
 * @brief A test method
 * It tests the getLocation()/setLocation() method under the UserManager class.
 */
TEST(getLocation, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setLocation("Princeton");
    ASSERT_EQ(um->getLocation(), "Princeton");
    um->setLocation("Harvard");
    ASSERT_EQ(um->getLocation(), "Harvard");
    um->setLocation("Union City");
    ASSERT_EQ(um->getLocation(), "Union City");
}

/**
 * @brief A test method
 * It tests the getName()/setName() method under the UserManager class.
 */
TEST(getName, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setName("ABC");
    ASSERT_EQ(um->getName(), "ABC");
    um->setName("");
    ASSERT_EQ(um->getName(), "");
    um->setName("ab");
    ASSERT_EQ(um->getName(), "ab");
}

/**
 * @brief A test method
 * It tests the getGender()/setGender() method under the UserManager class.
 */
TEST(getGender, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setGender("Male");
    ASSERT_EQ(um->getGender(), "Male");
    um->setGender("Female");
    ASSERT_EQ(um->getGender(), "Female");
    um->setGender("male");
    ASSERT_EQ(um->getGender(), "male");
    um->setGender("other");
    ASSERT_EQ(um->getGender(), "other");
    um->setGender("female");
    ASSERT_EQ(um->getGender(), "female");
}

/**
 * @brief A test method
 * It tests the getUserLocPref()/setUserLocPref() method under the UserManager class.
 */
TEST(getUserLocPref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserLocPref("User A is User A");
    ASSERT_EQ(um->getUserLocPref(), "User A is User A");
    um->setUserLocPref("user b is user b.");
    ASSERT_EQ(um->getUserLocPref(), "user b is user b.");
    um->setUserLocPref("cuser auser buser");
    ASSERT_EQ(um->getUserLocPref(), "cuser auser buser");
    um->setUserLocPref("other kinds of usersssss");
    ASSERT_EQ(um->getUserLocPref(), "other kinds of usersssss");
}

/**
 * @brief A test method
 * It tests the getUserspeciesPref()/setUserspeciesPref() method under the UserManager class.
 */
TEST(getUserspeciesPref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserspeciesPref("Dog");
    ASSERT_EQ(um->getUserspeciesPref(), "Dog");
    um->setUserspeciesPref("Cat");
    ASSERT_EQ(um->getUserspeciesPref(), "Cat");
    um->setUserspeciesPref("Frog");
    ASSERT_EQ(um->getUserspeciesPref(), "Frog");
    um->setUserspeciesPref("Hamster");
    ASSERT_EQ(um->getUserspeciesPref(), "Hamster");
}

/**
 * @brief A test method
 * It tests the getUserBreedPref()/setUserBreedPref() method under the UserManager class.
 */
TEST(getUserBreedPref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserBreedPref("Beagle");
    ASSERT_EQ(um->getUserBreedPref(), "Beagle");
    um->setUserBreedPref("Persian Cat");
    ASSERT_EQ(um->getUserBreedPref(), "Persian Cat");
    um->setUserBreedPref("African Bullfrog");
    ASSERT_EQ(um->getUserBreedPref(), "African Bullfrog");
    um->setUserBreedPref("Bengal");
    ASSERT_EQ(um->getUserBreedPref(), "Bengal");
}

/**
 * @brief A test method
 * It tests the getUserAgePref()/setUserAgePref() method under the UserManager class.
 */
TEST(getUserAgePref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserAgePref("New Born");
    ASSERT_EQ(um->getUserAgePref(), "New Born");
    um->setUserAgePref("1 - 2 years");
    ASSERT_EQ(um->getUserAgePref(), "1 - 2 years");
    um->setUserAgePref("2 - 6 years");
    ASSERT_EQ(um->getUserAgePref(), "2 - 6 years");
    um->setUserAgePref("10 - 14 years");
    ASSERT_EQ(um->getUserAgePref(), "10 - 14 years");
}

/**
 * @brief A test method
 * It tests the getUserWeightPref()/setUserWeightPref() method under the UserManager class.
 */
TEST(getUserWeightPref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserWeightPref("<10 lbs");
    ASSERT_EQ(um->getUserWeightPref(), "<10 lbs");
    um->setUserWeightPref("20-50 lbs");
    ASSERT_EQ(um->getUserWeightPref(), "20-50 lbs");
    um->setUserWeightPref("50-100 lbs");
    ASSERT_EQ(um->getUserWeightPref(), "50-100 lbs");
    um->setUserWeightPref(">100 lbs");
    ASSERT_EQ(um->getUserWeightPref(), ">100 lbs");
}

/**
 * @brief A test method
 * It tests the getUserRescuePref()/setUserRescuePref() method under the UserManager class.
 */
TEST(getUserRescuePref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    for (int i = 0; i<=1 ; i++) {
        um->setUserRescuePref(i);
        ASSERT_EQ(um->getUserRescuePref(),i);
    }
}

/**
 * @brief A test method
 * It tests the getUserDiseasePref()/setUserDiseasePref() method under the UserManager class.
 */
TEST(getUserDiseasePref, TESTSIMPLE) {
    UserManager *um = new UserManager;
    for (int i = 0; i<=1 ; i++) {
        um->setUserDiseasePref(i);
        ASSERT_EQ(um->getUserDiseasePref(),i);
    }
}

/**
 * @brief A test method
 * It tests the getUserZipCode()/setUserZipCode() method under the UserManager class.
 */
TEST(getUserZipCode, TESTSIMPLE) {
    UserManager *um = new UserManager;
    for (int i = 100; i<=1000 ; i++) {
        um->setUserZipCode(i);
        ASSERT_EQ(um->getUserZipCode(),i);
    }
}

/**
 * @brief A test method
 * It tests the getUserType()/setUserType() method under the UserManager class.
 */
TEST(getUserType, TESTSIMPLE) {
    UserManager *um = new UserManager;
    for (int i = 0; i<=3;i++) {
        um->setUserType(i);
        ASSERT_EQ(um->getUserType(), i);
    }
}

/**
 * @brief A test method
 * It tests the getUserAddress()/setUserAddress() method under the UserManager class.
 */
TEST(getUserAddress, TESTSIMPLE) {
    UserManager *um = new UserManager;
    um->setUserAddress("Stanford");
    ASSERT_EQ(um->getUserAddress(), "Stanford");
    um->setUserAddress("Princeton");
    ASSERT_EQ(um->getUserAddress(), "Princeton");
    um->setUserAddress("Columbia");
    ASSERT_EQ(um->getUserAddress(), "Columbia");
    um->setUserAddress("Union city");
    ASSERT_EQ(um->getUserAddress(), "Union city");
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
