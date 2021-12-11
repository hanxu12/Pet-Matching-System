/**
* database.h
* The header file for the database class
*
* @author  Team2_1
* @version 2.0
* @since   2021-4-18
*/

#ifndef DATABASE_H
#define DATABASE_H

#include<QDebug>
#include<QString>
#include <QtSql>
#include <QSqlDatabase>
#include<QSqlQueryModel>
#include "usermanager.h"
#include "petmanager.h"
#include "header.h"

class DataBase
{
/**
 * @brief Database class.
 * It contains all the methods relevant to database operations.
 */      
public:
    /**
     * @brief A default constructor.
     * It construct a new database object.
     */
    DataBase(const QString path);

    QSqlDatabase mydb;
    //user relevant
    /**
     * @brief A function
     * It retrieves the user's username by its user id from the DB
     * @param uid user id
     * @return QString  user's username
     */
    QString getUserName(int uid);
    /**
     * @brief A function
     * It retrieves a user's name by its user ID from the DB
     * @param uid the user's uid
     * @return int the user's Name
     */        
    QString getName(int uid);    
    /**
     * @brief A function
     * It retrieves the user's phone number by its user id from the DB
     * @param uid user id
     * @return QString user's phone number
     */
    QString getPhoneNo(int uid);
    /**
     * @brief A function
     * It retrieves the user's living state by its user id from the DB
     * @param uid user id
     * @return QString user's living state
     */
    QString getLoc(int uid);
    /**
     * @brief A function
     * It retrieves the user's specific address by its user id from the DB
     * @param uid user id
     * @return QString user's specific address
     */
    QString getUserAddr(int uid);
    /**
     * @brief A function
     * It retrieves the user's gender by its user id from the DB
     * @param uid user id
     * @return QString the user's gender
     */
    QString getGender(int uid);
    /**
     * @brief A function
     * It retrieves the user's bio by its user id from the DB
     * @param uid user id
     * @return QString the user's bio
     */
    QString getUserBio(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's breed preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's breed preference
     */    
    QString getUserBreedPref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's species preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's species preference
     */     
    QString getUserSpeciesPref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's color preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's color preference
     */         
    QString getUserColorPref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's age preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's age preference
     */         
    QString getUserAgePref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's weight preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's weight preference
     */            
    QString getUserWeightPref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's location(radius) preference by its user id from the DB
     * @param uid user id
     * @return QString the potential pet owner's location preference
     */                
    QString getUserLocPref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's preference of rescued pet
     * by its user id from the DB
     * @param uid user id
     * @return QString whether the potential pet owner wants a rescued pet
     */         
    int getUserRescuePref(int uid);
    /**
     * @brief A function
     * It retrieves a potential pet owner's preference of diseased pet
     * by its user id from the DB
     * @param uid user id
     * @return QString whether the potential pet owner wants a diseased pet
     */          
    int getUserDiseasePref(int uid);
    /**
     * @brief A function
     * It retrieves the user's zipcode by its user id from the DB
     * @param uid user id
     * @return QString the user's zipcode
     */
    int getZip(int uid);
    /**
     * @brief A function
     * It retrieves the user's UserID by its username from the DB
     * @param username the user's username
     * @return int the user's User ID
     */
    int getUserID(QString username);
    /**
     * @brief A function
     * It adds a single user to the DB
     * @param user A UserManager instance (a single user)
     */
    void addUser(UserManager *user);
    /**
     * @brief A function
     * It updates an existing user inside the DB
     * @param user A UserManager instance(a single user with upated info)
     */
    void updateUser(UserManager *user);
    /**
     * @brief A function
     * It deletes an existing user together with 
     * all its information inside the DB
     * @param uid the user's user ID
     */
    void deleteUser(int uid);
    /**
     * @brief A function
     * It inserts a potential pet owner's preferences to the database
     * @param user A Usermanager instance(a single potential pet owner)
     */
    void insertPerf(UserManager *user);
    /**
     * @brief A function
     * It checks if the user credential is valid
     * @param username the user's username
     * @param password the user's password
     * @return true the user credential is valid
     * @return false the user credential is invalid
     */
    bool isValid(QString username, QString password);
    /**
     * @brief A function
     * It checks whether a specific user exists inside the DB
     * by its username
     * @param username the user's username 
     * @return true the user exists
     * @return false the user does not exists
     */
    bool exist(QString username);
    /**
     * @brief A function
     * It retrieves the user's category (admin/potential pet owner/ shelter owner/ foster parent)
     * from the DB by the user's ID
     * @param uid user ID
     * @return int the user's category(0-admin/1-shelter owner/2-foster parents/3-potential pet owner)
     */
    int getGroupType(int uid);
    /**
     * @brief A function
     * It retrieves the maximum user uid inside the system
     * @return int the maximum user uid
     */
    int getMaxUid();
    /**
     * @brief A function
     * It checks whether a specific user exists inside the DB
     * by its uid
     * @param uid the user's user ID 
     * @return true the user exists
     * @return false the user does not exists
     */
    bool userExists(int uid);

    //pet relevant
    /**
     * @brief A function
     * It checks whether a specific pet exists inside the DB
     * by its pet id
     * @param uid the pet's pet ID 
     * @return true the pet exists
     * @return false the pet does not exists
     */
    bool petExists(int petid);
    /**
     * @brief A function
     * It adds a single pet to the DB
     * @param user A PetManager instance (a single pet)
     */    
    void addPet(PetManager *pet);
    /**
     * @brief A function
     * It updates a single pet inside the DB
     * @param user A PetManager instance (a single pet)
     */     
    void updatePet(PetManager *pet);
    /**
     * @brief A function
     * It retrieves the maximum pet uid inside the system
     * @return int the maximum pet uid
     */    
    int getMaxPetID();

    /**
     * @brief A function
     * It retrieves the pet' name by its petid from the DB
     * @param petid the pet's pet id
     * @return QString the pet's name
     */
    QString getPetName(int petid);
    /**
     * @brief A function
     * It retrieves the pet' species by its petid from the DB
     * @param petid the pet's pet id
     * @return QString the pet's species
     */    
    QString getPetSpecies(int petid);
    /**
     * @brief A function
     * It retrieves the pet' breed by its petid from the DB
     * @param petid the pet's pet id
     * @return QString the pet's breed
     */        
    QString getPetBreed(int petid);
    /**
     * @brief A function
     * It retrieves the pet' gender by its petid from the DB
     * @param petid the pet's pet id
     * @return QString the pet's gender
     */            
    QString getPetGender(int petid);
    /**
     * @brief A function
     * It retrieves the pet' description by its petid from the DB
     * @param petid the pet's pet id
     * @return QString the pet's description
     */     
    QString getPetDescription(int petid);
    /**
     * @brief A function
     * It retrieves whether the pet is a diseased pet from the DB
     * @param petid the pet's pet id
     * @return int  1-pet is diseased, 0-pet is not diseased
     */
    int getPetDisease(int petid);
    /**
     * @brief A function
     * It retrieves whether the pet is a rescued pet from the DB
     * @param petid the pet's pet id
     * @return int  1-pet is a rescued pet, 0-pet is not a rescued pet
     */    
    int getPetRescue(int petid);
    /**
     * @brief A function
     * It retrieves the pet's belongings's shelter id from the DB
     * @param petid the pet's pet id
     * @return int the shelter's ID in which the pet belongs to
     */
    int getPetSid(int petid);
    /**
     * @brief A function
     * It retrieves the pet's age from the DB
     * @param petid the pet's ID
     * @return int the pet's age
     */
    int getPetAge(int petid);
    /**
     * @brief A function
     * It retrieves the pet's weight from the DB
     * @param petid the pet's ID
     * @return int the pet's weight
     */    
    int getPetWeight(int petid);
    /**
     * @brief A function
     * It retrieves the pet's color from the DB
     * @param petid the pet's ID
     * @return QString the pet's color
     */
    QString getPetColor(int petid);
    /**
     * @brief A function
     * It retrieves the pet's 1st image file's path from the DB
     * @param petid the pet's ID
     * @return QString the pet's 1st image file's path
     */    
    QString getPetImg1(int petid);
    /**
     * @brief A function
     * It retrieves the pet's 2nd image file's path from the DB
     * @param petid the pet's ID
     * @return QString the pet's 2nd image file's path
     */     
    QString getPetImg2(int petid);
    /**
     * @brief A function
     * It retrieves all information of a specific pet and wrap it as a pet instance
     * @param petid the pet's id
     * @return PetManager* a pet instance
     */
    PetManager* setPet(int petid);
    /**
     * @brief A function
     * It counts the number of pets under a specific shelter
     * @param sid the shelter's ID
     * @return int the number of pets under it
     */
    int countPetsforShelter(int sid);
    /**
     * @brief A function
     * It deletes a specific pet from the system
     * @param petid the pet's pet id
     */
    void deletePet(int petid);

    //browse history relevant
    /**
     * @brief A function
     * It adds a pet browse history entry into the DB
     * @param sid the shelter ID
     * @param pid the potential pet owner's id
     * @param petid the pet's petID
     * @param favorStatus whether the potential pet owner likes(3)/neutral(2)/dislikes(1) the pet
     * @param adoptionStatus the adoption status of the pet (0 - not adopted, 1 - adoption requested, 
     * 2-> adoption request rejected, 3->adoption request approved)
     */
    void addBrowseHistory(int sid, int pid, int petid, int favorStatus, int adoptionStatus);
    /**
     * @brief A function
     * It deletes a pet browse history entry from the DB
     * @param historyID the browse history's ID
     */
    void deleteBrowseHistory(int historyID);
    /**
     * @brief A function
     * It updates the adoption status of a particular history
     * @param historyID the browse history's ID
     * @param newStatus  the adoption status of the pet (0 - not adopted, 1 - adoption requested, 
     * 2-> adoption request rejected, 3->adoption request approved)
     */
    void updateHistAdoptionStatus(int historyID, int newStatus);
    /**
     * @brief A function
     * It updates the favor status of a particular history
     * @param historyID the browse history's ID
     * @param newStatus  the favor status of the pet (likes-3/neutral-2/dislikes-1)
     */
    void updateHistFavorStatus(int historyID, int newFavor);
    /**
     * @brief A function
     * It updates the browse history entry's last viewed date and time
     * @param historyID the browse history's ID
     */
    void updateHistDT(int historyID);
    /**
     * @brief A function
     * It retrieves the browse history entry's ID 
     * @param pid the potential pet owner's id
     * @param petid the pet's pet id
     * @return int the history entry's ID
     */
    int getHistoryID(int pid, int petid);
    /**
     * @brief A function
     * It gets the maximum history ID at the DB
     * @return int the maximum history ID
     */
    int getMaxHistoryID();
    /**
     * @brief A function
     * It checks whether the history is related to a particular potential pet owner
     * @param historyID the history entry ID
     * @param pid the potential pet owner ID
     * @return true the history is relevant to that potential pet owner
     * @return false the history is not relevant to that potential pet owner
     */
    bool isHistoryValid(int historyID, int pid);
    /**
     * @brief A function
     * It checks whether the history is a pending adoption request
     * @param historyID the history's ID
     * @param sid the shelter's ID
     * @return true the history is a pending adoption request
     * @return false the history is not a pending adoption request
     */
    bool isPendingRequest(int historyID, int sid);
    /**
     * @brief A function
     * It retrieves the pet id related to that history ID
     * @param historyID the history entry's ID
     * @return int the pet id related to that history ID
     */
    int getHistoryPetID(int historyID);
    /**
     * @brief A function
     * It retrieves the adoption status related to that history ID
     * (0 - not adopted, 1 - adoption requested, 2-> adoption request rejected, 3->adoption request approved)
     * @param historyID the history entry's ID
     * @return int the adoption status related to that history ID
     */    
    int getAdoptionStatus(int historyID);
    /**
     * @brief A function
     * It retrieves the adoption status from the DB by the pet id and potential pet owner's ID
     * @param pid the potential pet owner's id
     * @param petid the pet's pet id
     * @return int the adoption status
     * (0 - not adopted, 1 - adoption requested, 2-> adoption request rejected, 3->adoption request approved)
     */
    int getAdoptionbyPetID(int pid, int petid);
    /**
     * @brief A function
     * It retrieves the favor status from the DB by the history ID
     * @param historyID the history entry's ID
     * @return int the favor status (likes-3/neutral-2/dislikes-1)
     */
    int getFavorbyHistID(int historyID);
    /**
     * @brief A function
     * It retrieves the favor status from the DB by the pet id and potential pet owner's ID
     * @param pid the potential pet owner's id
     * @param petid the pet's pet id
     * @return int the favor status (likes-3/neutral-2/dislikes-1)
     */
    int getFavorbyPetID(int pid, int petid);
    /**
     * @brief A function
     * It retrieves the potential pet owner id related to a history entry
     * @param historyID a history entry ID
     * @return int the potential pet owner id
     */
    int getHistoryPID(int historyID);
    /**
     * @brief A function
     * It retrieves the history's last viewed Date and Time related to that history ID
     * @param historyID the history entry's ID
     * @return int the history's last viewed Date and Time
     */
    QString getHistoryDT(int historyID);
    /**
     * @brief A function
     * It retrieves the pet id related to the history
     * @param historyID the history ID
     * @return int the pet id
     */
    int getPetIDfromHist(int historyID);
    /**
     * @brief A function 
     * It counts the number of a particular adoption requests (approval/ pending/ reject) under a shelter
     * @param sid the shelter's shelter id
     * @param adoptionStatus the adoption status (0 - not adopted, 1 - adoption requested, 2-> adoption request rejected, 3->adoption request approved)
     * @return int the total number of a particular adoption requests
     */
    int countAdoptionReqforShelter(int sid, int adoptionStatus);

    //zipcode relevant
    /**
     * @brief A function
     * It retrieves the latitude of a specific zip code
     * @param zip a zipcode
     * @return double the latitude of that zip code
     */
    double getLat(int zip);
    /**
     * @brief A function
     * It retrieves the longitude of a specific zip code
     * @param zip a zipcode
     * @return double the longitude of that zip code
     */    
    double getLon(int zip);
private:
};

#endif // DATABASE_H
