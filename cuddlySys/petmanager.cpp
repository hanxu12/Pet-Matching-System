/**
* petmanager.cpp
* The source file for management class of pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "petmanager.h"

/**
 * @brief PetManager constructor
 */
PetManager::PetManager()
{
}

/**
 * @brief petID setter method
 */
void PetManager::setPetID(int petid){
    this->petID = petid;
}

/**
 * @brief petID getter method
 */
int PetManager::getPetID(){
    return petID;
}

/**
 * @brief petName setter method
 */
void PetManager::setPetName(QString name){
    this->petName = name;
}

/**
 * @brief petName getter method
 */
QString PetManager::getPetName(){
    return petName;
}

/**
 * @brief petSpecies setter method
 */
void PetManager::setPetSpecies(QString species){
    this->petSpecies = species;
}

/**
 * @brief petSpecies getter method
 */
QString PetManager::getPetSpecies(){
    return petSpecies;
}

/**
 * @brief petBreed setter method
 */
void PetManager::setPetBreed(QString breed){
    this->petBreed = breed;
}

/**
 * @brief petBreed getter method
 */
QString PetManager::getPetBreed(){
    return petBreed;
}

/**
 * @brief petGender setter method
 */
void PetManager::setPetGender(QString gender){
    this->petGender = gender;
}

/**
 * @brief petGender getter method
 */
QString PetManager::getPetGender(){
    return petGender;
}

/**
 * @brief petAge setter method
 */
void PetManager::setPetAge(int age) {
    this->petAge = age;
}

/**
 * @brief petAge getter method
 */
int PetManager::getPetAge(){
    return petAge;
}

/**
 * @brief petShelterID setter method
 */
void PetManager::setPetShelterID(int sid){
    this->petShelterID = sid;
}

/**
 * @brief petShelterID getter method
 */
int PetManager::getPetShelterID(){
    return petShelterID;
}

/**
 * @brief petWeight setter method
 */
void PetManager::setPetWeight(int weight){
    this->petWeight = weight;
}

/**
 * @brief petWeight getter method
 */
int PetManager::getPetWeight(){
    return petWeight;
}

/**
 * @brief petDescription setter method
 */
void PetManager::setPetDescription(QString description){
    this->petDescription = description;
}

/**
 * @brief petDescription getter method
 */
QString PetManager::getPetDescription(){
    return petDescription;
}

/**
 * @brief petColor setter method
 */
void PetManager::setPetColor(QString color){
    this->petColor = color;
}

/**
 * @brief petColor getter method
 */
QString PetManager::getPetColor(){
    return petColor;
}

/**
 * @brief petDisease setter method
 */
void PetManager::setPetDisease(int ifDisease){
    this->isDiseased = ifDisease;
}

/**
 * @brief petDisease getter method
 */
int PetManager::getPetDisease(){
    return isDiseased;
}

/**
 * @brief petRescued setter method
 */
void PetManager::setPetRescue(int ifRescue){
    this->isRescued = ifRescue;
}

/**
 * @brief petRescued getter method
 */
int PetManager::getPetRescue(){
    return isRescued;
}

/**
 * @brief petImgPath1 setter method
 */
void PetManager::setPetImgPath1(QString imgPath1) {
    this->petImgPath1 = imgPath1;
}

/**
 * @brief petImgPath1 getter method
 */
QString PetManager::getPetImgPath1(){
    return petImgPath1;
}

/**
 * @brief petImgPath2 setter method
 */
void PetManager::setPetImgPath2(QString imgPath2){
    this->petImgPath2 = imgPath2;
}

/**
 * @brief petImgPath2 getter method
 */
QString PetManager::getPetImgPath2() {
    return petImgPath2;
}
