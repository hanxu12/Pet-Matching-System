#include "shelterownermain.h"
#include "ui_shelterownermain.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
ShelterOwnerMain::ShelterOwnerMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShelterOwnerMain)
{
    ui->setupUi(this);
    if (currUser->getUserType() == 1) {
        //shelter owner
        ui->title->setText("Sheltwer Owner Dashboard");
    } else if (currUser->getUserType() == 2) {
        //foster parent
        ui->title->setText("Foster Parent Dashboard");
    }

    ui->name->setText(currUser->getName());

    // Sets the placeholder text for the boxes
    ui->bio->setText("User Bio: " + currUser->getBio());
    ui->state->setText("Address: \n" + currUser->getUserAddress() + ", " + currUser->getLocation() + ", " + QString::number(currUser->getUserZipCode()));
    ui->gender->setText("Gender: " + currUser->getGender());
    ui->contact->setText("Phone: " + currUser->getPhoneNo());
}

/**
* @brief Destrcutor for the class
*/
ShelterOwnerMain::~ShelterOwnerMain()
{
    delete ui;
}

/**
 * @brief Handles logout functionality
 */
void ShelterOwnerMain::on_shelter_logout_clicked()
{
    entry *newentry = new entry();
    newentry->show();
    this->close();
}

/**
 * @brief Opens up the inventory for the shelter owner
 */
void ShelterOwnerMain::on_inventory_clicked()
{
    ManagePet *newmp = new ManagePet();
    newmp->show();
    this->close();
}

/**
 * @brief Handles functionality to let user update their profile
 */
void ShelterOwnerMain::on_update_info_clicked()
{
    updateinfoshelter *updateshelter = new updateinfoshelter();
    updateshelter->show();
    this->close();
}

/**
 * @brief Opens page to let owner view incoming requests
 */
void ShelterOwnerMain::on_requests_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    //0 -> not adopted, 1 -> adoption requested
    if (db.countAdoptionReqforShelter(currUser->getUid(), 1)==0) {
        QMessageBox::information(this, tr("Warning"),
                                 tr("This is no pending adoption request!"));
    } else {
        viewrequests *viewReq = new viewrequests();
        viewReq -> show();
        this->close();
    }
}

/**
 * @brief Opens the page to let users view their statistics
 */
void ShelterOwnerMain::on_stats_clicked()
{
    shelterOwnerStats *sos = new shelterOwnerStats;
    sos->show();
}
