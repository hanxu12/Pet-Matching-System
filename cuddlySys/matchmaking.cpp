/**
* matchmaking.cpp
* The source file for matchmaking.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "matchmaking.h"
#include "ui_matchmaking.h"

/**
 * @brief Matchmaking constructor
 * @param parent
 */
matchmaking::matchmaking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matchmaking)
{
    ui->setupUi(this);
    ui->pet_image->setScaledContents(true);
    refreshPet();
}

/**
 * @brief Matchmaking deconstructor
 */
matchmaking::~matchmaking()
{
    delete ui;
}

/**
 * @brief Go to previous interface
 */
void matchmaking::on_back_clicked()
{
    searchWin *searchWindow = new searchWin();
    this->hide();
    searchWindow->show();
}

/**
 * @brief After user decision, display new pet
 */
void matchmaking::refreshPet(){
    QString distString;
    QPixmap pawImg("../../cuddlySys/paw.jpg");
    DataBase db("../../cuddlySys/sysDB.db");
    computeDist cd;
    int petID = pq.top().petid;
    mmPet = db.setPet(petID);
    imgID = 1;
    QPixmap pm(mmPet->getPetImgPath1());
    if (pm.isNull()) {
       ui->pet_image->setPixmap(pawImg);
    } else {
        ui->pet_image->setPixmap(pm);
    }

    //distString = cd.onlineDist(currUser->getLocation(), db.getLoc(db.getPetSid(petID)));
    if (cd.distCal(currUser->getUid(), db.getPetSid(petID)) == -1.0){
        distString = "invalid dist";
    } else {
        distString = QString::number(cd.distCal(currUser->getUid(), db.getPetSid(petID)), 'f', 1);
    }
    ui->pet_name->setText(mmPet->getPetName() + "; " + distString + " km");
}

/**
 * @brief Switch provided pet image (show next picture of pet)
 */
void matchmaking::on_PB_switchImg_clicked()
{
    QPixmap pawImg("../../cuddlySys/paw.jpg");
    imgID = 3 - imgID;
    if (imgID == 1) {
        QPixmap pm(mmPet->getPetImgPath1());
        if (pm.isNull()) {
           ui->pet_image->setPixmap(pawImg);
        } else {
            ui->pet_image->setPixmap(pm);
        }
    } else {
        QPixmap pm(mmPet->getPetImgPath2());
        if (pm.isNull()) {
           ui->pet_image->setPixmap(pawImg);
        } else {
            ui->pet_image->setPixmap(pm);
        }
    }
}

/**
 * @brief Log pet as liked and show next pet.
 * 0 no such entry, 1 dislike, 2 neutral, 3 like.
 */
void matchmaking::on_like_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int petID = pq.top().petid;
    //remove the current pet
    pq.pop();
    if (db.getFavorbyPetID(currUser->getUid(), petID) == 2) {
        //if history entry ("neutral") exists, delete old entry
        db.deleteBrowseHistory(db.getHistoryID(currUser->getUid(), petID));
    }
    db.addBrowseHistory(db.getPetSid(petID), currUser->getUid(), petID, 3, 0);
    if (pq.size() == 1) {
        disableMatchMaking();
    } else {
        refreshPet();
    }
}

/**
 * @brief Log pet as neutraled and show next pet.
 * 0 no such entry, 1 dislike, 2 neutral, 3 like.
 */
void matchmaking::on_neutral_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int petID = pq.top().petid;
    //remove the current pet
    qDebug() << "ab pet's score is "<< pq.top().petScore;
    pq.pop();
    if (db.getFavorbyPetID(currUser->getUid(), petID) == 2) {
        //if history entry ("neutral") exists, delete old entry
        db.deleteBrowseHistory(db.getHistoryID(currUser->getUid(), petID));
    }
    db.addBrowseHistory(db.getPetSid(petID), currUser->getUid(), petID, 2, 0);
    if (pq.size() == 1) {
        disableMatchMaking();
    } else {
        refreshPet();
    }
}

/**
 * @brief Log pet as disliked and show next pet.
 * 0 no such entry, 1 dislike, 2 neutral, 3 like.
 */
void matchmaking::on_dislike_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int petID = pq.top().petid;
    //remove the current pet
    pq.pop();
    if (db.getFavorbyPetID(currUser->getUid(), petID) == 2) {
        //if history entry ("neutral") exists, delete old entry
        db.deleteBrowseHistory(db.getHistoryID(currUser->getUid(), petID));
    }
    db.addBrowseHistory(db.getPetSid(petID), currUser->getUid(), petID, 1, 0);
    if (pq.size() == 1) {
        disableMatchMaking();
    } else {
        refreshPet();
    }
}

/**
 * @brief Request to adopt and show next pet.
 * 0 -> not adopted, 1 -> adoption requested, 2-> adoption request rejected, 3->adoption request approved
 */
void matchmaking::on_request_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to adopt?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        DataBase db("../../cuddlySys/sysDB.db");
        int petID = pq.top().petid;
        //remove the current pet
        pq.pop();
        if (db.getFavorbyPetID(currUser->getUid(), petID) == 2) {
            //if history entry ("neutral") exists, delete old entry
            db.deleteBrowseHistory(db.getHistoryID(currUser->getUid(), petID));
        }
        db.addBrowseHistory(db.getPetSid(petID), currUser->getUid(), petID, 3, 1);
        if (pq.size() == 1) {
            disableMatchMaking();
        } else {
            refreshPet();
        }
        qDebug() << "Yes was clicked";
    } else {
        qDebug() << "Yes was *not* clicked";
    }
}

/**
 * @brief Stop showing pets (reach end of catalog)
 */
void matchmaking::disableMatchMaking(){
    QPixmap pm("../../cuddlySys/noresults.jpg");
    ui->pet_image->setPixmap(pm);
    ui->pet_image->setScaledContents(true);
    ui->pet_name->setText("No results. Please go back.");
    ui->dislike->setVisible(false);
    ui->like->setVisible(false);
    ui->neutral->setVisible(false);
    ui->request->setVisible(false);
    ui->PB_switchImg->setVisible(false);
}

