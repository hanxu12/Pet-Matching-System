#include "usermanager.h"

/**
 * @brief Constructor for the class
 */
UserManager::UserManager() {}

/**
 * @brief Updates uid of the user
 * @param uidcpy
 */
void UserManager::setUid(int uidcpy) {
    this->uid=uidcpy;
}

/**
 * @brief Returns uid of the user
 * @return
 */
int UserManager::getUid(){
    return uid;
}

/**
 * @brief updates the username of the user
 * @param usernameCpy
 */
void UserManager::setUsername(QString usernameCpy){
    this->username=usernameCpy;
}

/**
 * @brief returns the username of the user
 * @return
 */
QString UserManager::getUsername(){
    return username;
}

/**
 * @brief updates the password of the user
 * @param passwordCpy
 */
void UserManager::setPassword(QString passwordCpy){
    this->password = passwordCpy;
}

/**
 * @brief returns the password of the user
 * @return
 */
QString UserManager::getPassword() {
    return password;
}

/**
 * @brief updates the phone number of the user
 * @param phoneNoCpy
 */
void UserManager::setPhoneNo(QString phoneNoCpy){
    this->phoneNo = phoneNoCpy;
}

/**
 * @brief returns the phone number of the user
 * @return
 */
QString UserManager::getPhoneNo() {
    return phoneNo;
}

/**
 * @brief updates the location of the user
 * @param locationCpy
 */
void UserManager::setLocation(QString locationCpy){
    this->location=locationCpy;
}

/**
 * @brief returns the location of the user
 * @return
 */
QString UserManager::getLocation(){
    return location;
}

/**
 * @brief updates the display name of the user
 * @param nameCpy
 */
void UserManager::setName(QString nameCpy) {
    this->name = nameCpy;
}

/**
 * @brief sets the display name of the user
 * @return
 */
QString UserManager::getName() {
    return name;
}

/**
 * @brief updates type of user
 * @param userTypeCpy
 */
void UserManager::setUserType(int userTypeCpy) {
    this->userType = userTypeCpy;
}

/**
 * @brief returns type of user
 * @return
 */
int UserManager::getUserType() {
    return userType;
}

/**
 * @brief updates gender of the user
 * @param genderCpy
 */
void UserManager::setGender(QString genderCpy) {
    this->gender = genderCpy;
}

/**
 * @brief returns the gender of the user
 * @return
 */
QString UserManager::getGender() {
    return gender;
}

/**
 * @brief updates the description of the user
 * @param bioCpy
 */
void UserManager::setBio(QString bioCpy){
    this->bio = bioCpy;
}

/**
 * @brief returns the description of the user
 * @return
 */
QString UserManager::getBio(){
    return bio;
}

/**
 * @brief returns the age preference of the user
 * @return
 */
QString UserManager::getUserAgePref(){
    return agePref;
}

/**
 * @brief updates the breed preference of the user
 * @param pref
 */
void UserManager::setUserBreedPref(QString pref){
    this->breedPref = pref;
}

/**
 * @brief returns the breed preference of the user
 * @return
 */
QString UserManager::getUserBreedPref(){
    return breedPref;
}

/**
 * @brief updates the pet color preference of the user
 * @param pref
 */
void UserManager::setUserColorPref(QString pref){
    this->colorPref = pref;
}

/**
 * @brief returns the color preference
 * @return
 */
QString UserManager::getUserColorPref(){
    return colorPref;
}

/**
 * @brief updates species preference
 * @param pref
 */
void UserManager::setUserspeciesPref(QString pref) {
    this->speciesPref=pref;
}

/**
 * @brief returns species preference
 * @return
 */
QString UserManager::getUserspeciesPref(){
    return speciesPref;
}

/**
 * @brief updates age preference of the user
 * @param pref
 */
void UserManager::setUserAgePref(QString pref){
    this->agePref = pref;
}

/**
 * @brief updates the weight preference
 * @param pref
 */
void UserManager::setUserWeightPref(QString pref){
    this->weightPref = pref;
}

/**
 * @brief returns the weight preference
 * @return
 */
QString UserManager::getUserWeightPref(){
    return weightPref;
}

/**
 * @brief updates user zip code
 * @param zip
 */
void UserManager::setUserZipCode(int zip){
    this->zipcode = zip;
}

/**
 * @brief returns user zip code
 * @return
 */
int  UserManager::getUserZipCode(){
    return zipcode;
}

/**
 * @brief updates user address
 * @param addr
 */
void UserManager::setUserAddress(QString addr){
    this->address = addr;
}

/**
 * @brief returns user address
 * @return
 */
QString UserManager::getUserAddress(){
    return address;
}

/**
 * @brief updates user's location preference
 * @param pref
 */
void UserManager::setUserLocPref(QString pref){
    this->locPref = pref;
}

/**
 * @brief returns location preference
 * @return
 */
QString UserManager::getUserLocPref(){
    return locPref;
}

/**
 * @brief updates user's pet rescued preference
 * @param pref
 */
void UserManager::setUserRescuePref(int pref){
    this->rescuePref = pref;
}

/**
 * @brief returns user's pet rescued preference
 * @return
 */
int UserManager::getUserRescuePref(){
    return rescuePref;
}

/**
 * @brief updates user's disease preference
 * @param pref
 */
void UserManager::setUserDiseasePref(int pref){
    this->diseasePref=pref;
}

/**
 * @brief returns the user disease preference
 * @return
 */
int UserManager::getUserDiseasePref(){
    return diseasePref;
}
