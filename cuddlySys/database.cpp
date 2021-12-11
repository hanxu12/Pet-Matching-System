/**
* database.cpp
* The source file for the database class
*
* @author  Team2_1
* @version 2.0
* @since   2021-4-18
*/

#include "database.h"

/**
 * @brief A default constructor.
 * It construct a new database object.
 */
DataBase::DataBase(const QString path)
{
    if (QSqlDatabase::contains()){
        mydb = QSqlDatabase::database();
    }
    else {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(path);
        if(mydb.open())
        {
            qDebug()<<"open success";
        }
        else
        {
            qDebug()<<"open failed";
        }
    }
}

/**
 * @brief A function
 * It checks if the user credential is valid
 * @param username the user's username
 * @param password the user's password
 * @return true the user credential is valid
 * @return false the user credential is invalid
 */
bool DataBase::isValid(QString username, QString password){
    QSqlQuery qry;
    qry.prepare("SELECT usergroup from user WHERE username = (:username) AND password = (:password)");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        qDebug()<<"Correct Match";
        return true;
    }else{
        qDebug()<<"Not a Correct Match";
        return false;
    }
}

/**
 * @brief A function
 * It checks whether a specific user exists inside the DB
 * by its username
 * @param username the user's username 
 * @return true the user exists
 * @return false the user does not exists
 */
bool DataBase::exist(QString username){
    QSqlQuery qry;
    qry.prepare("SELECT usergroup from user WHERE username = (:username)");
    qry.bindValue(":username", username);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        return true;
    }
    return false;
}

/**
 * @brief A function
 * It checks whether a specific user exists inside the DB
 * by its uid
 * @param uid the user's user ID 
 * @return true the user exists
 * @return false the user does not exists
 */
bool DataBase::userExists(int uid) {
    QSqlQuery qry;
    qry.prepare("SELECT usergroup from user WHERE uid = (:uid)");
    qry.bindValue(":uid", uid);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        return true;
    }
    return false;
}


/**
 * @brief A function
 * It checks whether a specific pet exists inside the DB
 * by its pet id
 * @param uid the pet's pet ID 
 * @return true the pet exists
 * @return false the pet does not exists
 */
bool DataBase::petExists(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT sid from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        return true;
    }
    return false;
}

/**
 * @brief A function 
 * It counts the number of a particular adoption requests (approval/ pending/ reject) under a shelter
 * @param sid the shelter's shelter id
 * @param adoptionStatus the adoption status (0 - not adopted, 1 - adoption requested, 2-> adoption request rejected, 3->adoption request approved)
 * @return int the total number of a particular adoption requests
 */
int DataBase::countAdoptionReqforShelter(int sid, int adoptionStatus){
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(petid) FROM browsehistory WHERE sid = (:sid) AND adoptionstatus = (:adoptionstatus)");
    qry.bindValue(":sid", sid);
    qry.bindValue(":adoptionstatus", adoptionStatus);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}
/**
 * @brief A function
 * It counts the number of pets under a specific shelter
 * @param sid the shelter's ID
 * @return int the number of pets under it
 */
int DataBase::countPetsforShelter(int sid){

    QSqlQuery qry;
    qry.prepare("SELECT COUNT(petid) FROM Pets WHERE sid = (:sid)");
    qry.bindValue(":sid", sid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It adds a single pet to the DB
 * @param user A PetManager instance (a single pet)
 */  
void DataBase::addPet(PetManager *pet) {
    //QString name, species, breed, gender, int size, description, color, imagepath;
    QSqlQuery qry;
    qry.prepare("INSERT INTO PETS(name, species, breed, gender, description, sid, rescue, disease, age, weight, color, imagepath1, imagepath2) values(:name, :species, :breed, :gender, :description, :sid, :rescue, :disease, :age, :weight, :color, :imagepath1, :imagepath2)");
    qry.bindValue(":name", pet->getPetName());
    qry.bindValue(":species", pet->getPetSpecies());
    qry.bindValue(":breed", pet->getPetBreed());
    qry.bindValue(":gender", pet->getPetGender());
    qry.bindValue(":age", pet->getPetAge());
    qry.bindValue(":weight", pet->getPetWeight());
    qry.bindValue(":sid", pet->getPetShelterID());
    qry.bindValue(":description", pet->getPetDescription());
    qry.bindValue(":color", pet->getPetColor());
    qry.bindValue(":disease", pet->getPetDisease());
    qry.bindValue(":rescue", pet->getPetRescue());
    qry.bindValue(":imagepath1", pet->getPetImgPath1());
    qry.bindValue(":imagepath2", pet->getPetImgPath2());
    qry.exec();
}

/**
 * @brief A function
 * It updates a single pet inside the DB
 * @param user A PetManager instance (a single pet)
 */ 
void DataBase::updatePet(PetManager *pet){
    QSqlQuery qry;
    qry.prepare("UPDATE Pets SET name = :name, species = :species, breed = :breed, gender = :gender, description = :description, sid = :sid, age = :age, weight = :weight, color = :color, rescue = :rescue, disease = :disease, imagepath1 = :imagepath1, imagepath2 = :imagepath2 WHERE petid = :petid");
    qry.bindValue(":petid", pet->getPetID());
    qry.bindValue(":name", pet->getPetName());
    qry.bindValue(":species", pet->getPetSpecies());
    qry.bindValue(":breed", pet->getPetBreed());
    qry.bindValue(":gender", pet->getPetGender());
    qry.bindValue(":description", pet->getPetDescription());
    qry.bindValue(":sid", pet->getPetShelterID());
    qry.bindValue(":age", pet->getPetAge());
    qry.bindValue(":weight", pet->getPetWeight());
    qry.bindValue(":color", pet->getPetColor());
    qry.bindValue(":rescue", pet->getPetRescue());
    qry.bindValue(":disease", pet->getPetDisease());
    qry.bindValue(":imagepath1", pet->getPetImgPath1());
    qry.bindValue(":imagepath2", pet->getPetImgPath2());
    qry.exec();
}

/**
 * @brief A function
 * It retrieves the user's UserID by its username from the DB
 * @param username the user's username
 * @return int the user's User ID
 */
int DataBase::getUserID(QString username){
    int uid;
    if(this->exist(username)){
        QSqlQuery qry;
        qry.prepare("SELECT uid from user WHERE username = (:username)");
        qry.bindValue(":username", username);
        qry.exec();
        qry.next();
        uid = qry.value(0).toInt();
        qDebug()<<"This user's uid is: "<< uid;
        return uid;
    }
    qDebug()<<"User does not exsit";
    return -1;
}

/**
 * @brief A function
 * It retrieves the user's bio by its user id from the DB
 * @param uid user id
 * @return QString the user's bio
 */
QString DataBase::getUserBio(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT Bio FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT Bio FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray bio = qry.value(0).toByteArray();
    qDebug()<<"This user's bio is: "<< bio;
    return QString::fromUtf8(bio);
}

/**
 * @brief A function
 * It retrieves the user's zipcode by its user id from the DB
 * @param uid user id
 * @return QString the user's zipcode
 */
int DataBase::getZip(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT zipcode FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT zipcode FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the user's username by its user id from the DB
 * @param uid user id
 * @return QString  user's username
 */
QString DataBase::getUserName(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT username from user WHERE uid = (:uid)");
    qry.bindValue(":uid", uid);
    qry.exec();
    qry.next();
    QByteArray username = qry.value(0).toByteArray();
    //qDebug()<<"This user's username is: "<< username;
    return QString::fromUtf8(username);
}

/**
 * @brief A function
 * It retrieves the user's category (admin/potential pet owner/ shelter owner/ foster parent)
 * from the DB by the user's ID
 * @param uid user ID
 * @return int the user's category(0-admin/1-shelter owner/2-foster parents/3-potential pet owner)
 */
int DataBase::getGroupType(int uid){
    int groupType;
    if(this->exist(getUserName(uid))){
        QSqlQuery qry;
        qry.prepare("SELECT usergroup from user WHERE uid = (:uid)");
        qry.bindValue(":uid", uid);
        qry.exec();
        qry.next();
        groupType = qry.value(0).toInt();
        //qDebug()<<"This user is of type: "<< groupType;
        return groupType;
    }
    return -1;
}

/**
 * @brief A function
 * It retrieves a potential pet owner's breed preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's breed preference
 */    
QString DataBase::getUserBreedPref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT breedpreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray breed = qry.value(0).toByteArray();
    //qDebug()<<"This user's username is: "<< username;
    return QString::fromUtf8(breed);
}

/**
 * @brief A function
 * It retrieves a potential pet owner's species preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's species preference
 */
QString DataBase::getUserSpeciesPref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT speciespreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray species = qry.value(0).toByteArray();
    //qDebug()<<"This user's username is: "<< username;
    return QString::fromUtf8(species);
}
    
/**
 * @brief A function
 * It retrieves a potential pet owner's color preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's color preference
 */    
QString DataBase::getUserColorPref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT colorpreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray species = qry.value(0).toByteArray();
    return QString::fromUtf8(species);
}

/**
 * @brief A function
 * It retrieves a potential pet owner's location(radius) preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's location preference
 */       
QString DataBase::getUserLocPref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT locationpreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray species = qry.value(0).toByteArray();
    return QString::fromUtf8(species);
}

/**
 * @brief A function
 * It retrieves a potential pet owner's age preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's age preference
 */         
QString DataBase::getUserAgePref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT agepreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray age = qry.value(0).toByteArray();
    //qDebug()<<"This user's username is: "<< username;
    return QString::fromUtf8(age);
}

/**
 * @brief A function
 * It retrieves a potential pet owner's weight preference by its user id from the DB
 * @param uid user id
 * @return QString the potential pet owner's weight preference
 */ 
QString DataBase::getUserWeightPref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT weightpreference from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    QByteArray weight = qry.value(0).toByteArray();
    //qDebug()<<"This user's username is: "<< username;
    return QString::fromUtf8(weight);
}

/**
 * @brief A function
 * It retrieves a potential pet owner's preference of rescued pet
 * by its user id from the DB
 * @param uid user id
 * @return QString whether the potential pet owner wants a rescued pet
 */         
int DataBase::getUserRescuePref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT rescue from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves a potential pet owner's preference of diseased pet
 * by its user id from the DB
 * @param uid user id
 * @return QString whether the potential pet owner wants a diseased pet
 */          
int DataBase::getUserDiseasePref(int uid){
    QSqlQuery qry;
    qry.prepare("SELECT disease from Preferences WHERE pid = (:pid)");
    qry.bindValue(":pid", uid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the maximum user uid inside the system
 * @return int the maximum user uid
 */
int DataBase::getMaxUid(){
    QSqlQuery qry5;
    qry5.prepare("SELECT uid FROM user ORDER BY uid DESC LIMIT 1;");
    qry5.exec();
    qry5.next();
    qDebug() << qry5.value(0).toInt() << endl;
    return qry5.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the maximum pet uid inside the system
 * @return int the maximum pet uid
 */    
int DataBase::getMaxPetID() {
    QSqlQuery qry;
    qry.prepare("SELECT IFNULL(petid,0) FROM Pets ORDER BY petid DESC LIMIT 1;");
    qry.exec();
    qry.next();
    //qDebug() << qry.value(0).toInt() << endl;
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves a user's name by its user ID from the DB
 * @param uid the user's uid
 * @return int the user's Name
 */   
QString DataBase::getName(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT Name FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT Name FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray name = qry.value(0).toByteArray();
    qDebug()<<"This user's name is: "<< name;
    return QString::fromUtf8(name);
}

/**
 * @brief A function
 * It retrieves the user's phone number by its user id from the DB
 * @param uid user id
 * @return QString user's phone number
 */
QString DataBase::getPhoneNo(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT PhoneNumber FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT PhoneNumber FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray phoneno = qry.value(0).toByteArray();
    qDebug()<<"This user's phone number is: "<< phoneno;
    return QString::fromUtf8(phoneno);
}

/**
 * @brief A function
 * It retrieves the user's living state by its user id from the DB
 * @param uid user id
 * @return QString user's living state
 */
QString DataBase::getLoc(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT State FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT State FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray state = qry.value(0).toByteArray();
    return QString::fromUtf8(state);
}

/**
 * @brief A function
 * It retrieves the user's specific address by its user id from the DB
 * @param uid user id
 * @return QString user's specific address
 */
QString DataBase::getUserAddr(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT address FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT address FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray address = qry.value(0).toByteArray();
    return QString::fromUtf8(address);
}

/**
 * @brief A function
 * It retrieves the user's gender by its user id from the DB
 * @param uid user id
 * @return QString the user's gender
 */
QString DataBase::getGender(int uid){
    QSqlQuery qry;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {
        qry.prepare("SELECT Gender FROM shelterowner WHERE sid = (:sid);");
        qry.bindValue(":sid", uid);
    } else if (getGroupType(uid) == 3) {
        qry.prepare("SELECT Gender FROM PotentialPetOwner WHERE pid = (:pid);");
        qry.bindValue(":pid", uid);
    }
    qry.exec();
    qry.next();
    QByteArray gender = qry.value(0).toByteArray();
    return QString::fromUtf8(gender);
}

/**
 * @brief A function
 * It adds a single user to the DB
 * @param user A UserManager instance (a single user)
 */
void DataBase::addUser(UserManager *user){
    if (!exist(user->getUsername())) {
        QSqlQuery qry2, qry3;
        int userID = user->getUid();
        int userGroup = user->getUserType();
        int zip = user->getUserZipCode();
        QString username = user->getUsername();
        QString pass = user->getPassword();
        QString phoneNo = user->getPhoneNo();
        QString gender = user->getGender();
        QString name = user->getName();
        QString location = user->getLocation();
        QString bio = user->getBio();
        QString address = user->getUserAddress();

        qry2.prepare("INSERT INTO user (username, password, usergroup) VALUES (:uname, :pass, :ugroup)");
        qry2.bindValue(":uname", username);
        qry2.bindValue(":pass", pass);

        if (userGroup == 3){
            qry2.bindValue(":ugroup", userGroup);
            qry2.exec();
            qry3.prepare("INSERT INTO PotentialPetOwner (pid, Name, State, PhoneNumber, Bio, Gender, zipcode, address) VALUES (:pid, :name, :state, :phone, :bio, :gender, :zipcode, :address)");
            qry3.bindValue(":pid", userID);
            //set up qry3
            qry3.bindValue(":name", name);
            qry3.bindValue(":state", location);
            qry3.bindValue(":phone", phoneNo);
            qry3.bindValue(":gender", gender);
            qry3.bindValue(":bio", bio);
            qry3.bindValue(":zipcode", zip);
            qry3.bindValue(":address", address);
            qry3.exec();

        } else if (userGroup == 2) {
            qry2.bindValue(":ugroup", 2);
            qry2.exec();
            qry3.prepare("INSERT INTO shelterowner (sid, Name, State, PhoneNumber, Bio, isShelter, Gender, zipcode, address) VALUES (:sid, :name, :state, :phone, :bio, :isShelter, :gender, :zipcode, :address)");
            qry3.bindValue(":sid", userID);
            //set up qry3
            qry3.bindValue(":name", name);
            qry3.bindValue(":state", location);
            qry3.bindValue(":phone", phoneNo);
            qry3.bindValue(":gender", gender);
            qry3.bindValue(":bio", bio);
            qry3.bindValue(":isShelter", 0);
            qry3.bindValue(":zipcode", zip);
            qry3.bindValue(":address", address);
            qry3.exec();

        } else if (userGroup == 1) {
            qry2.bindValue(":ugroup", 1);
            qry2.exec();
            qry3.prepare("INSERT INTO shelterowner (sid, Name, State, PhoneNumber, Bio, isShelter, Gender, zipcode, address) VALUES (:sid, :name, :state, :phone, :bio, :isShelter, :gender, :zipcode, :address)");
            qry3.bindValue(":sid", userID);
            //set up qry3
            qry3.bindValue(":name", name);
            qry3.bindValue(":state", location);
            qry3.bindValue(":phone", phoneNo);
            qry3.bindValue(":gender", gender);
            qry3.bindValue(":bio", bio);
            qry3.bindValue(":isShelter", 1);
            qry3.bindValue(":zipcode", zip);
            qry3.bindValue(":address", address);
            qry3.exec();
        }
    }
}

/**
 * @brief A function
 * It updates an existing user inside the DB
 * @param user A UserManager instance(a single user with upated info)
 */
void DataBase::updateUser(UserManager *user){
    QSqlQuery qry2, qry3,qry1;
    int uid = user->getUid();
    int userGroup = user->getUserType();
    int zip = user->getUserZipCode();
    QString username = user->getUsername();
    QString pass = user->getPassword();
    QString phoneNo = user->getPhoneNo();
    QString gender = user->getGender();
    QString name = user->getName();
    QString location = user->getLocation();
    QString bio = user->getBio();
    QString address = user->getUserAddress();

    qry2.prepare("UPDATE user SET username = :uname, password = :pass WHERE uid = :uid");
    qry2.bindValue(":uname", username);
    qry2.bindValue(":pass", pass);
    qry2.bindValue(":uid", uid);
    qry2.exec();

    if (userGroup == 3){
        qry3.prepare("UPDATE PotentialPetOwner SET Name = :name, State = :state, PhoneNumber = :phone, Bio = :bio, Gender = :gender, zipcode = :zipcode, address = :address WHERE pid = :uid");
        qry3.bindValue(":uid", uid);
        qry3.bindValue(":name", name);
        qry3.bindValue(":state", location);
        qry3.bindValue(":phone", phoneNo);
        qry3.bindValue(":bio", bio);
        qry3.bindValue(":gender", gender);
        qry3.bindValue(":zipcode", zip);
        qry3.bindValue(":address", address);
        qry1.prepare("UPDATE Preferences SET locationpreference = :locationpreference, speciespreference = :speciespreference, breedpreference = :breedpreference, colorpreference = :colorpreference, agepreference = :agepreference, weightpreference = :weightpreference, rescue = :rescue, disease = :disease WHERE pid = :uid");
        qry1.bindValue(":uid", uid);
        qry1.bindValue(":locationpreference", user->getUserLocPref());
        qry1.bindValue(":speciespreference", user->getUserspeciesPref());
        qry1.bindValue(":breedpreference", user->getUserBreedPref());
        qry1.bindValue(":colorpreference", user->getUserColorPref());
        qry1.bindValue(":agepreference", user->getUserAgePref());
        qry1.bindValue(":weightpreference", user->getUserWeightPref());
        qry1.bindValue(":rescue", user->getUserRescuePref());
        qry1.bindValue(":disease", user->getUserDiseasePref());
    } else if ((userGroup == 2) || (userGroup == 1))  {
        qry3.prepare("UPDATE shelterowner SET Name = :name, State = :state, PhoneNumber = :phone, Bio = :bio, Gender = :gender, zipcode = :zipcode, address = :address WHERE sid = :uid");
        qry3.bindValue(":uid", uid);
        qry3.bindValue(":name", name);
        qry3.bindValue(":state", location);
        qry3.bindValue(":phone", phoneNo);
        qry3.bindValue(":bio", bio);
        qry3.bindValue(":gender", gender);
        qry3.bindValue(":zipcode", zip);
        qry3.bindValue(":address", address);
    }
    qry3.exec();
    qry1.exec();
}

/**
 * @brief A function
 * It inserts a potential pet owner's preferences to the database
 * @param user A Usermanager instance(a single potential pet owner)
 */
void DataBase::insertPerf(UserManager *user){
    QSqlQuery qry;
    qry.prepare("INSERT INTO Preferences (pid, locationpreference, speciespreference, breedpreference, colorpreference, agepreference, weightpreference, rescue, disease) VALUES (:pid, :locationpreference, :speciespreference, :breedpreference, :colorpreference, :agepreference, :weightpreference, :rescue, :disease)");
    qry.bindValue(":pid", user->getUid());
    //set up qry3
    qry.bindValue(":locationpreference", user->getUserLocPref());
    qry.bindValue(":speciespreference", user->getUserspeciesPref());
    qry.bindValue(":breedpreference", user->getUserBreedPref());
    qry.bindValue(":colorpreference", user->getUserColorPref());
    qry.bindValue(":agepreference", user->getUserAgePref());
    qry.bindValue(":weightpreference", user->getUserWeightPref());
    qry.bindValue(":rescue", user->getUserRescuePref());
    qry.bindValue(":disease", user->getUserDiseasePref());
    //qry.bindValue(":specialpreference", sfeature);
    qry.exec();
}

/**
 * @brief A function
 * It deletes an existing user together with 
 * all its information inside the DB
 * @param uid the user's user ID
 */
void DataBase::deleteUser(int uid){
    QSqlQuery qry2,qry3,qry4,qry5;
    if ((getGroupType(uid) == 1) || (getGroupType(uid) == 2)) {  //if shelterowner/foster parent
        qry3.prepare("DELETE from shelterowner WHERE sid = (:sid)");
        qry3.bindValue(":sid", uid);
        qry3.exec();
    }
    else if (getGroupType(uid) == 3) {  //if potential petowner
        qry4.prepare("DELETE from PotentialPetOwner WHERE pid = (:pid)");
        qry4.bindValue(":pid", uid);
        qry4.exec();
        qry5.prepare("DELETE from Preferences WHERE pid = (:pid)");
        qry5.bindValue(":pid", uid);
        qry5.exec();
    }
    qry2.prepare("DELETE from user WHERE uid = (:uid)");
    qry2.bindValue(":uid", uid);
    qry2.exec();
}

/**
 * @brief A function
 * It deletes a specific pet from the system
 * @param petid the pet's pet id
 */
void DataBase::deletePet(int petid){
    QSqlQuery qry;
    qry.prepare("DELETE from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
}

/**
 * @brief A function
 * It retrieves the pet' name by its petid from the DB
 * @param petid the pet's pet id
 * @return QString the pet's name
 */
QString DataBase::getPetName(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT name from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray name = qry.value(0).toByteArray();
    return QString::fromUtf8(name);
}

/**
 * @brief A function
 * It retrieves the pet' species by its petid from the DB
 * @param petid the pet's pet id
 * @return QString the pet's species
 */    
QString DataBase::getPetSpecies(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT species from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray species = qry.value(0).toByteArray();
    return QString::fromUtf8(species);
}

/**
 * @brief A function
 * It retrieves the pet' breed by its petid from the DB
 * @param petid the pet's pet id
 * @return QString the pet's breed
 */        
QString DataBase::getPetBreed(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT breed from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray breed = qry.value(0).toByteArray();
    return QString::fromUtf8(breed);
}

/**
 * @brief A function
 * It retrieves the pet' gender by its petid from the DB
 * @param petid the pet's pet id
 * @return QString the pet's gender
 */ 
QString DataBase::getPetGender(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT gender from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray gender = qry.value(0).toByteArray();
    return QString::fromUtf8(gender);
}

/**
 * @brief A function
 * It retrieves the pet' description by its petid from the DB
 * @param petid the pet's pet id
 * @return QString the pet's description
 */  
QString DataBase::getPetDescription(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT description from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray description = qry.value(0).toByteArray();
    return QString::fromUtf8(description);
}

/**
 * @brief A function
 * It retrieves the pet's belongings's shelter id from the DB
 * @param petid the pet's pet id
 * @return int the shelter's ID in which the pet belongs to
 */
int DataBase::getPetSid(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT sid from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves whether the pet is a diseased pet from the DB
 * @param petid the pet's pet id
 * @return int  1-pet is diseased, 0-pet is not diseased
 */
int DataBase::getPetDisease(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT disease from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves whether the pet is a rescued pet from the DB
 * @param petid the pet's pet id
 * @return int  1-pet is a rescued pet, 0-pet is not a rescued pet
 */    
int DataBase::getPetRescue(int petid){
    QSqlQuery qry;
    qry.prepare("SELECT rescue from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the pet's age from the DB
 * @param petid the pet's ID
 * @return int the pet's age
 */
int DataBase::getPetAge(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT age from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the pet's weight from the DB
 * @param petid the pet's ID
 * @return int the pet's weight
 */    
int DataBase::getPetWeight(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT weight from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the pet's color from the DB
 * @param petid the pet's ID
 * @return QString the pet's color
 */
QString DataBase::getPetColor(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT color from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray color = qry.value(0).toByteArray();
    return QString::fromUtf8(color);
}

/**
 * @brief A function
 * It retrieves the pet's 1st image file's path from the DB
 * @param petid the pet's ID
 * @return QString the pet's 1st image file's path
 */    
QString DataBase::getPetImg1(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT imagepath1 from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray img1 = qry.value(0).toByteArray();
    return QString::fromUtf8(img1);
}

/**
 * @brief A function
 * It retrieves the pet's 2nd image file's path from the DB
 * @param petid the pet's ID
 * @return QString the pet's 2nd image file's path
 */  
QString DataBase::getPetImg2(int petid) {
    QSqlQuery qry;
    qry.prepare("SELECT imagepath2 from Pets WHERE petid = (:petid)");
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    QByteArray img2 = qry.value(0).toByteArray();
    return QString::fromUtf8(img2);
}

/**
 * @brief A function
 * It retrieves all information of a specific pet and wrap it as a pet instance
 * @param petid the pet's id
 * @return PetManager* a pet instance
 */
PetManager* DataBase::setPet(int petid){
    PetManager *tmpPet = new PetManager;
    tmpPet->setPetID(petid);
    tmpPet->setPetName(getPetName(petid));
    tmpPet->setPetSpecies(getPetSpecies(petid));
    tmpPet->setPetBreed(getPetBreed(petid));
    tmpPet->setPetGender(getPetGender(petid));
    tmpPet->setPetAge(getPetAge(petid));
    tmpPet->setPetWeight(getPetWeight(petid));
    tmpPet->setPetShelterID(getPetSid(petid));
    tmpPet->setPetDescription(getPetDescription(petid));
    tmpPet->setPetColor(getPetColor(petid));
    tmpPet->setPetDisease(getPetDisease(petid));
    tmpPet->setPetRescue(getPetRescue(petid));
    tmpPet->setPetImgPath1(getPetImg1(petid));
    tmpPet->setPetImgPath2(getPetImg2(petid));
    return tmpPet;
}

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
void DataBase::addBrowseHistory(int sid, int pid, int petid, int favorStatus, int adoptionStatus){
    QSqlQuery qry;
    int cnt = 0;
    qry.prepare("SELECT sid from browsehistory WHERE pid = (:pid) and petid = (:petid)");
    qry.bindValue(":pid", pid);
    qry.bindValue(":petid", petid);
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    //if such record does not exist
    if (cnt == 0){
        qry.prepare("INSERT INTO browsehistory (sid, pid, petid, favoredstatus, adoptionstatus) VALUES (:sid, :pid, :petid, :favoredstatus, :adoptionstatus)");
        qry.bindValue(":sid", sid);
        qry.bindValue(":pid", pid);
        qry.bindValue(":petid", petid);
        qry.bindValue(":favoredstatus", favorStatus);
        qry.bindValue(":adoptionstatus", adoptionStatus);
        qry.exec();
    }
}

/**
 * @brief A function
 * It deletes a pet browse history entry from the DB
 * @param historyID the browse history's ID
 */
void DataBase::deleteBrowseHistory(int historyID){
    QSqlQuery qry;
    qry.prepare("DELETE from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
}

/**
 * @brief A function
 * It retrieves the browse history entry's ID 
 * @param pid the potential pet owner's id
 * @param petid the pet's pet id
 * @return int the history entry's ID
 */
int DataBase::getHistoryID(int pid, int petid){
    QSqlQuery qry;
    qry.prepare("SELECT historyID FROM browsehistory WHERE pid = (:pid) AND petid = (:petid)");
    qry.bindValue(":pid", pid);
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It gets the maximum history ID at the DB
 * @return int the maximum history ID
 */
int DataBase::getMaxHistoryID(){
    QSqlQuery qry;
    qry.prepare("SELECT historyID FROM browsehistory ORDER BY historyID DESC LIMIT 1;");
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It checks whether the history is related to a particular potential pet owner
 * @param historyID the history entry ID
 * @param pid the potential pet owner ID
 * @return true the history is relevant to that potential pet owner
 * @return false the history is not relevant to that potential pet owner
 */
bool DataBase::isHistoryValid(int historyID, int pid){
    QSqlQuery qry;
    qry.prepare("SELECT petid from browsehistory WHERE historyID = (:historyID) AND pid = (:pid)");
    qry.bindValue(":historyID", historyID);
    qry.bindValue(":pid", pid);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        //there exists
        return true;
    }else{
        //it does not exist such a history entry
        return false;
    }
}

/**
 * @brief A function
 * It checks whether the history is a pending adoption request
 * @param historyID the history's ID
 * @param sid the shelter's ID
 * @return true the history is a pending adoption request
 * @return false the history is not a pending adoption request
 */
bool DataBase::isPendingRequest(int historyID, int sid) {
    QSqlQuery qry;
    qry.prepare("SELECT petid from browsehistory WHERE historyID = (:historyID) AND sid = (:sid) AND adoptionstatus = (:adoptionstatus)");
    qry.bindValue(":historyID", historyID);
    qry.bindValue(":sid", sid);
    qry.bindValue(":adoptionstatus", 1);
    int cnt = 0;
    if (qry.exec())
    {
        if (qry.next()) {
            cnt += 1;
        }
    }
    if(cnt>0){
        //there exists
        return true;
    }else{
        //it does not exist such a history entry
        return false;
    }
}

/**
 * @brief A function
 * It retrieves the pet id related to that history ID
 * @param historyID the history entry's ID
 * @return int the pet id related to that history ID
 */
int DataBase::getHistoryPetID(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT petid from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the adoption status from the DB by the pet id and potential pet owner's ID
 * @param pid the potential pet owner's id
 * @param petid the pet's pet id
 * @return int the adoption status
 * (0 - not adopted, 1 - adoption requested, 2-> adoption request rejected, 3->adoption request approved)
 */
int DataBase::getAdoptionStatus(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT adoptionstatus from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

int DataBase::getAdoptionbyPetID(int pid, int petid){
    QSqlQuery qry;
    qry.prepare("SELECT adoptionstatus from browsehistory WHERE pid = (:pid) AND petid = (:petid)");
    qry.bindValue(":pid", pid);
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the favor status from the DB by the history ID
 * @param historyID the history entry's ID
 * @return int the favor status (likes-3/neutral-2/dislikes-1)
 */
int DataBase::getFavorbyHistID(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT favoredstatus from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the favor status from the DB by the pet id and potential pet owner's ID
 * @param pid the potential pet owner's id
 * @param petid the pet's pet id
 * @return int the favor status (likes-3/neutral-2/dislikes-1)
 */
int DataBase::getFavorbyPetID(int pid, int petid){
    QSqlQuery qry;
    qry.prepare("SELECT favoredstatus from browsehistory WHERE pid = (:pid) AND petid = (:petid)");
    qry.bindValue(":pid", pid);
    qry.bindValue(":petid", petid);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the potential pet owner id related to a history entry
 * @param historyID a history entry ID
 * @return int the potential pet owner id
 */
int DataBase::getHistoryPID(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT pid from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}

/**
 * @brief A function
 * It retrieves the history's last viewed Date and Time related to that history ID
 * @param historyID the history entry's ID
 * @return int the history's last viewed Date and Time
 */
QString DataBase::getHistoryDT(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT dt from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    QByteArray dt = qry.value(0).toByteArray();
    return QString::fromUtf8(dt);
}

/**
 * @brief A function
 * It updates the adoption status of a particular history
 * @param historyID the browse history's ID
 * @param newStatus  the adoption status of the pet (0 - not adopted, 1 - adoption requested, 
 * 2-> adoption request rejected, 3->adoption request approved)
 */
void DataBase::updateHistAdoptionStatus(int historyID, int newStatus){
    QSqlQuery qry;
    qry.prepare("UPDATE browsehistory SET adoptionstatus = :adoptionstatus WHERE historyID = (:historyID)");
    qry.bindValue(":adoptionstatus", newStatus);
    qry.bindValue(":historyID", historyID);
    qry.exec();
}

/**
 * @brief A function
 * It updates the favor status of a particular history
 * @param historyID the browse history's ID
 * @param newStatus  the favor status of the pet (likes-3/neutral-2/dislikes-1)
 */
void DataBase::updateHistFavorStatus(int historyID, int newFavor){
    QSqlQuery qry;
    qry.prepare("UPDATE browsehistory SET favoredstatus = :favoredstatus WHERE historyID = (:historyID)");
    qry.bindValue(":favoredstatus", newFavor);
    qry.bindValue(":historyID", historyID);
    qry.exec();
}

/**
 * @brief A function
 * It updates the browse history entry's last viewed date and time
 * @param historyID the browse history's ID
 */
void DataBase::updateHistDT(int historyID){
    QSqlQuery qry;
    qry.prepare("UPDATE browsehistory SET dt = strftime('%Y-%m-%d %H:%M:%S', 'now', 'localtime') WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
}

/**
 * @brief A function
 * It retrieves the latitude of a specific zip code
 * @param zip a zipcode
 * @return double the latitude of that zip code
 */
double DataBase::getLat(int zip){
    QSqlQuery qry;
    qry.prepare("SELECT latitude from uszip WHERE zip = (:zip)");
    qry.bindValue(":zip", zip);
    qry.exec();
    qry.next();
    return qry.value(0).toDouble();
}

/**
 * @brief A function
 * It retrieves the longitude of a specific zip code
 * @param zip a zipcode
 * @return double the longitude of that zip code
 */  
double DataBase::getLon(int zip){
    QSqlQuery qry;
    qry.prepare("SELECT longitude from uszip WHERE zip = (:zip)");
    qry.bindValue(":zip", zip);
    qry.exec();
    qry.next();
    return qry.value(0).toDouble();
}

/**
 * @brief A function
 * It retrieves the pet id related to the history
 * @param historyID the history ID
 * @return int the pet id
 */
int DataBase::getPetIDfromHist(int historyID){
    QSqlQuery qry;
    qry.prepare("SELECT petid from browsehistory WHERE historyID = (:historyID)");
    qry.bindValue(":historyID", historyID);
    qry.exec();
    qry.next();
    return qry.value(0).toInt();
}
