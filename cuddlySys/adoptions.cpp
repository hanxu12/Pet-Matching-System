
#include "adoptions.h"
#include "ui_adoptions.h"

/**
 * @brief adoptions::adoptions
 * default constructorr
 * @param parent
 */
adoptions::adoptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adoptions)
{
    ui->setupUi(this);
    currPtr = 0;
    currPage = 1;
    initAdoptionVector();
    if (adoptionVector.size() == 0) {
        totalPages = 1;
    } else {
        totalPages = ceil(adoptionVector.size()/3.0);
    }
    displayCurrPage();
}

/**
 * @brief adoptions::~adoptions
 * default destructor
 */
adoptions::~adoptions()
{
    delete ui;
    //clear vector of pointers to avoid mem leak
    for (auto p : adoptionVector) {
        delete p;
    }
    adoptionVector.clear();
}

/**
 * @brief adoptions::on_back_clicked
 * on clicked takes you back to the pet owner main dashboard
 */
void adoptions::on_back_clicked()
{
    Petowner *pwn = new Petowner();
    pwn->show();
    this->close();
}

//the vector is added from newest history to oldest history
/**
 * @brief adoptions::initAdoptionVector
 * method to initialize the vector with all the pets that were adopted by the user
 */
void adoptions::initAdoptionVector(){
    DataBase db("../../cuddlySys/sysDB.db");
    int maxHistory = db.getMaxHistoryID();
    //iterate over all history ID's
    for (int i = maxHistory; i >= 0; i--) {
        //if the history entry belongs to the user
        if (db.isHistoryValid(i, currUser->getUid())) {
            //if user requested an adoption
            if (db.getAdoptionStatus(i) > 0) {
                PetManager *tmpPet = db.setPet(db.getHistoryPetID(i));
                adoptionVector.push_back(tmpPet);
            }
        }
    }
}

//0 -> not adopted, 1 -> adoption requested, 2-> adoption request rejected, 3->adoption request approved
/**
 * @brief adoptions::adoptionStatus
 * returns the adoption status
 * @param petID used to look up the pet in the databse
 * @return a string that contains information about the
 */
QString adoptions::adoptionStatus(int petID){
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
 * @brief adoptions::displayCurrPage
 * method todisplay the page with all the aopted pets of the user
 * uses the vector of pets primarily to show 3 pets at a time
 */
void adoptions::displayCurrPage(){
    QPixmap pawImg("../../cuddlySys/paw.jpg");
    int idx = currPtr;
    QString adoption1, adoption2, adoption3;
    if (idx < adoptionVector.size()){
        PetManager* tmpPet = adoptionVector.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
            ui->image1->setPixmap(pawImg);
        } else {
            ui->image1->setPixmap(pm);
        }

        ui->viewprofile_1->setVisible(true);
        ui->image1->setScaledContents(true);
        ui->name1->setText(tmpPet->getPetName() + "; " + adoptionStatus(tmpPet->getPetID()));
    } else {
        ui->viewprofile_1->setVisible(false);
        ui->image1->setPixmap(pawImg);
        ui->image1->setScaledContents(true);
        ui->name1->setText("N/A");
    }
    idx += 1;
    if (idx < adoptionVector.size()){
        PetManager* tmpPet = adoptionVector.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
            ui->image2->setPixmap(pawImg);
        } else {
            ui->image2->setPixmap(pm);
        }
        ui->viewprofile_2->setVisible(true);
        ui->image2->setScaledContents(true);
        ui->name2->setText(tmpPet->getPetName() + "; " + adoptionStatus(tmpPet->getPetID()));
    } else {
        ui->viewprofile_2->setVisible(false);
        ui->image2->setPixmap(pawImg);
        ui->image2->setScaledContents(true);
        ui->name2->setText("N/A");
    }
    idx += 1;
    if (idx < adoptionVector.size()){
        PetManager* tmpPet = adoptionVector.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
            ui->image3->setPixmap(pawImg);
        } else {
            ui->image3->setPixmap(pm);
        }
        ui->viewprofile_3->setVisible(true);
        ui->image3->setScaledContents(true);
        ui->name3->setText(tmpPet->getPetName() + "; " + adoptionStatus(tmpPet->getPetID()));
    } else {
        ui->viewprofile_3->setVisible(false);
        ui->image3->setPixmap(pawImg);
        ui->image3->setScaledContents(true);
        ui->name3->setText("N/A");
    }
    ui->page->setText("Page " + QString::number(currPage) + " of " + QString::number(totalPages));
}

/**
 * @brief adoptions::on_prev_clicked
 * go to the previous pet
 */
void adoptions::on_prev_clicked()
{
    if (currPage > 1) {
        currPage -= 1;
        currPtr = currPtr - 3;
        displayCurrPage();
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the first page!"));
    }
}

/**
 * @brief adoptions::on_next_clicked
 * go the the next petpage
 */
void adoptions::on_next_clicked()
{
    if (currPage < totalPages) {
        currPage += 1;
        currPtr = currPtr + 3;
        displayCurrPage();
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the last page!"));
    }
}


/**
 * @brief adoptions::on_viewprofile_1_clicked
 * wheview the pet profile after it has been clicked
 */
void adoptions::on_viewprofile_1_clicked()
{
    enterFrom = "adoption";
    currPet = adoptionVector.at(currPtr);
    petprofile *pp = new petprofile;
    pp->show();
}

/**
 * @brief adoptions::on_viewprofile_2_clicked
 * view the profile of the first pet
 */
void adoptions::on_viewprofile_2_clicked()
{
    enterFrom = "adoption";
    currPet = adoptionVector.at(currPtr+1);
    petprofile *pp = new petprofile;
    pp->show();
}

/**
 * @brief adoptions::on_viewprofile_3_clicked
 * view theprofile of the third pet o the page
 */
void adoptions::on_viewprofile_3_clicked()
{
    enterFrom = "adoption";
    currPet = adoptionVector.at(currPtr+2);
    petprofile *pp = new petprofile;
    pp->show();
}
