#include "searchwin.h"
#include "ui_searchwin.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
searchWin::searchWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchWin)
{
    ui->setupUi(this);
    //ui->keywords->setPlaceholderText("Enter your keywords");
    ui->Breed->setPlaceholderText("Breed");
}

/**
 * @brief Destructor for the class
 */
searchWin::~searchWin()
{
    delete ui;
}

/**
 * @brief Handles back button operations
 */
void searchWin::on_back_clicked()
{
    Petowner *petOwner = new Petowner();
    this->hide();
    petOwner -> show();
}

/**
 * @brief Handles the functionality of the search button
 */
void searchWin::on_search_2_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int uid = currUser->getUid();
    UserManager * tmpUser = new UserManager;
    tmpUser->setUserLocPref(ui->radius->currentText());
    tmpUser->setUserspeciesPref(ui->species->currentText());
    tmpUser->setUserBreedPref(ui->Breed->text());
    tmpUser->setUserColorPref(ui->color->currentText());
    tmpUser->setUserAgePref(ui->age->currentText());
    tmpUser->setUserWeightPref(ui->weight->currentText());

    // handles rescue preference
    if (ui->isRescued->checkState()) {
        tmpUser->setUserRescuePref(1);
    } else {
        tmpUser->setUserRescuePref(0);
    }

    // handles diseased preference
    if (ui->isDiseased->checkState()){
        tmpUser->setUserDiseasePref(1);
    } else {
        tmpUser->setUserDiseasePref(0);
    }

    while (!pq.empty()){
        pq.pop();
    }

    int max = db.getMaxPetID();

    //add all pets into the Priority Queue
    for (int i = 1; i <= max; i++) {
        if (db.petExists(i)) {
            //has not accessed such pet or "neutral" it before
            if ((db.getFavorbyPetID(uid, i) == 0) || (db.getFavorbyPetID(uid, i) == 2)){
                petStruct tmp = {i, computePetScore(tmpUser, db.setPet(i))};
                //qDebug() << "curr score" << computePetScore(db.setPet(i));
                pq.push(tmp);
                //test the priority queue and push w/ score 0;
            }
        }
    }

    //push a last useless pet(no results)
    pq.push(petStruct{-1, -1});
    matchmaking *mm = new matchmaking();
    this->hide();
    mm -> show();
    delete tmpUser;
}

/**
 * @brief Handles "I'm feeling lucky" functionality
 */
void searchWin::on_lucky_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int uid = currUser->getUid();

    while (!pq.empty()){
        pq.pop();
    }

    int max = db.getMaxPetID();

    //add all pets into the Priority Queue
    for (int i = 1; i <= max; i++) {
        if (db.petExists(i)) {
            //has not accessed such pet or "neutral" it before
            if ((db.getFavorbyPetID(uid, i) == 0) || (db.getFavorbyPetID(uid, i) == 2)){
                petStruct tmp = {i, 1};
                qDebug() << tmp.petid;
                pq.push(tmp);
                qDebug() << pq.top().petid;
                //test the priority queue and push w/ score 0;
            }
        }
    }

    //push a last useless pet(no results)
    pq.push(petStruct{-1, -1});
    matchmaking *mm = new matchmaking();
    this->hide();
    mm -> show();
}

/**
 * @brief Calculates the score of pets to match with users
 * @param user
 * @param pet
 * @return
 */
int searchWin::computePetScore(UserManager *user, PetManager *pet){
    //computeDist cd;
    //score to be returned
    int score = 0;

    //checking if the species match, unmatch return 0
    if (user->getUserspeciesPref().toLower() != pet->getPetSpecies().toLower()){
        return 0;
    } else {
        score += 100;
    }

    //checking if breed match
    if (user->getUserBreedPref().toLower() == pet->getPetBreed().toLower()){
        score += 10;
    }

    //adding a score of 10 if color matches
    if (user->getUserColorPref().toLower() == pet->getPetColor().toLower()){
        score = score + 10;
    }

    //code for the location match, we add 2 to the score
    //if (cd.distCal(currUser->getUid(), pet->getPetID()))

    //adding a score of 1 if age falls withing range
    if (user->getUserAgePref()== "New Born" && pet->getPetAge()<1){
        score = score +5;
    } else if (user->getUserAgePref()== "1 - 2 years" && pet->getPetAge()>=1 &&  pet->getPetAge()<=2 ){
        score = score +5;
    } else if (user->getUserAgePref()== "2 - 6 years" && pet->getPetAge()>=2 &&  pet->getPetAge()<=6 ){
        score = score +5;
    } else if (user->getUserAgePref()== "6 - 10 years" && pet->getPetAge()>=6 &&  pet->getPetAge()<=10 ){
        score = score +5;
    } else if (user->getUserAgePref()== "10 - 14 years" && pet->getPetAge()>=10 &&  pet->getPetAge()<=14 ){
        score = score +5;
    } else if (user->getUserAgePref()== "14 years and older" && pet->getPetAge()>=14 ){
        score = score +5;
    }

    //adding a score of 5 if weight falls within range
    if (user->getUserWeightPref()== "<10 lbs" && pet->getPetWeight()<10){
        score = score +5;
    } else if (user->getUserWeightPref()== "10 - 20 lbs" && pet->getPetWeight()>=10 && pet->getPetWeight()<=20){
        score = score +5;
    } else if (user->getUserWeightPref()== "20 - 30 lbs" && pet->getPetWeight()>=20 && pet->getPetWeight()<=30){
        score = score +5;
    } else if (user->getUserWeightPref()== "30 - 50 lbs" && pet->getPetWeight()>=30 && pet->getPetWeight()<=50){
        score = score +5;
    } else if (user->getUserWeightPref()== "50 - 100 lbs" && pet->getPetWeight()>=50 && pet->getPetWeight()<=100){
        score = score +5;
    } else if (user->getUserWeightPref()== "> 100 lbs" && pet->getPetWeight()>=100){
        score = score +5;
    }

    if (user->getUserRescuePref() == pet->getPetRescue()){
        score = score + 5;
    }

    if (user->getUserDiseasePref() == pet->getPetDisease()){
        score = score + 5;
    }

    return score;
}
