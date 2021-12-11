/**
* petprofile.cpp
* The source file for viewing and managing pet information.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "petprofile.h"
#include "ui_petprofile.h"

/**
 * @brief PetProfile constructor
 * @param parent
 */
petprofile::petprofile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::petprofile)
{
    ui->setupUi(this);
    imgID = 2;
    displayCurrPet();
    if (enterFrom == "history") {
        ui->adoptionStatus->setVisible(false);
        ui->prevPref->setText("PrevPref: " + favorStatus(currPet->getPetID()));
    }
    else if (enterFrom == "adoption") {
        ui->prefStatus->setVisible(false);
        ui->request->setVisible(false);
        ui->update->setVisible(false);
        ui->prevPref->setVisible(false);
    } else if (enterFrom == "admin") {
        ui->prefStatus->setVisible(false);
        ui->adoptionStatus->setVisible(false);
        ui->request->setVisible(false);
        ui->update->setVisible(false);
        ui->lastViewDT->setVisible(false);
        ui->prevPref->setVisible(false);
    }
}

/**
 * @brief PetProfile deconstructor
 */
petprofile::~petprofile()
{
    delete ui;
}

/**
 * @brief On pet profile view, switch image when pressed
 */
void petprofile::on_PB_switchImg_clicked()
{
    imgID = 3 - imgID;
    if (imgID == 1) {
        QPixmap pm(currPet->getPetImgPath1());
        ui->pet_image->setPixmap(pm);
    } else {
        QPixmap pm(currPet->getPetImgPath2());
        ui->pet_image->setPixmap(pm);
    }
}

/**
 * @brief Display pet profile information and image
 */
void petprofile::displayCurrPet(){
    DataBase db("../../cuddlySys/sysDB.db");
    on_PB_switchImg_clicked();
    ui->petName->setText("Pet Name: " + currPet->getPetName());
    ui->pet_image->setScaledContents(true);
    ui->petInfo->setText("Age "+QString::number(currPet->getPetAge())+"; Weight: " + QString::number(currPet->getPetWeight()));
    ui->petSpecies->setText("Species: " + currPet->getPetSpecies());
    ui->petBreed->setText("Breed: " + currPet->getPetBreed());
    ui->petGender->setText("Gender: " + currPet->getPetGender());
    ui->lastViewDT->setText("Last viewed:" + db.getHistoryDT(db.getHistoryID(currUser->getUid(),currPet->getPetID())));
    if (currPet->getPetDisease() && currPet->getPetRescue()) {
        ui->petOther->setText("Rescued pet with disease.");
    } else if (currPet->getPetRescue()) {
        ui->petOther->setText("Rescued pet with no disease.");
    } else if (currPet->getPetDisease()) {
        ui->petOther->setText("Normal pet with disease");
    } else {
        ui->petOther->setText("Normal pet with no disease");
    }
    ui->adoptionStatus->setText(adoptionStatus(currPet->getPetID()));
    db.updateHistDT(db.getHistoryID(currUser->getUid(),currPet->getPetID()));
}

/**
 * @brief Display pet adoption status.
 * 0 -> not adopted, 1 -> adoption requested, 2-> adoption request rejected, 3->adoption request approved.
 * @param petID
 */
QString petprofile::adoptionStatus(int petID){
    DataBase db("../../cuddlySys/sysDB.db");
    if (db.getAdoptionbyPetID(currUser->getUid(), petID) == 1) {
        return "Pending request";
    } else if (db.getAdoptionbyPetID(currUser->getUid(), petID) == 2) {
        return "Request rejected";
    } else if (db.getAdoptionbyPetID(currUser->getUid(), petID) == 3) {
        return "Request approved";
    }
    return "Unknown error";
}

/**
 * @brief Select new preference of pet
 */

QString petprofile::favorStatus(int petID){
    DataBase db("../../cuddlySys/sysDB.db");
    int tmp = db.getFavorbyPetID(currUser->getUid(), petID);
    if (tmp == 1) {
        return "dislike";
    } else if (tmp == 2) {
        return "neutral";
    } else if (tmp == 3) {
        return "like";
    }
}

void petprofile::on_update_clicked()
{
    if (ui->prefStatus->currentText() == "--Select your new preference--") {
        QMessageBox::information(this, tr("Warning"),
                                 tr("Please enter a new preference!"));
    } else {
        DataBase db("../../cuddlySys/sysDB.db");
        if (ui->prefStatus->currentText() == "Dislike") {
            db.updateHistFavorStatus(db.getHistoryID(currUser->getUid(),currPet->getPetID()),1);
        } else if (ui->prefStatus->currentText() == "Neutral") {
            db.updateHistFavorStatus(db.getHistoryID(currUser->getUid(),currPet->getPetID()),2);
        } else if (ui->prefStatus->currentText() == "Like") {
            db.updateHistFavorStatus(db.getHistoryID(currUser->getUid(),currPet->getPetID()),3);
        }
    }
    this->close();
}

/**
 * @brief Change status of corresponding pet to adoption requested (1)
 */
void petprofile::on_request_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to request adopt?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        db.updateHistAdoptionStatus(db.getHistoryID(currUser->getUid(),currPet->getPetID()), 1);
        this->close();
    }
}
