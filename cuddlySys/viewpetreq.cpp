#include "viewpetreq.h"
#include "ui_viewpetreq.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
viewPetReq::viewPetReq(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewPetReq)
{
    ui->setupUi(this);
    imgID = 2;
    displayCurrPet();
}

/**
 * @brief Destructor for the class
 */
viewPetReq::~viewPetReq()
{
    delete ui;
}

/**
 * @brief Updates the information for pet
 */
void viewPetReq::displayCurrPet(){
    on_PB_switchImg_clicked();
    ui->petName->setText(currPet->getPetName());
    ui->pet_image->setScaledContents(true);
    ui->petInfo->setText("Age "+QString::number(currPet->getPetAge())+"; Weight: " + QString::number(currPet->getPetWeight()));
    ui->petSpecies->setText(currPet->getPetSpecies());
    ui->petBreed->setText(currPet->getPetBreed());
    ui->petGender->setText(currPet->getPetGender());
}

/**
 * @brief Handles the switching of pet images when user clicks
 */
void viewPetReq::on_PB_switchImg_clicked()
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
