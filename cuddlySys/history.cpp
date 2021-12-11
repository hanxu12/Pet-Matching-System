/**
* history.cpp
* The source file for pet view history.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "history.h"
#include "ui_history.h"

/**
 * @brief History constructor
 */
history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    currPtr = 0;
    currPage = 1;
    initHistoryVector();
    if (petHistory.size() == 0) {
        totalPages = 1;
    } else {
        totalPages = ceil(petHistory.size()/3.0);
    }
    displayCurrPage();
}

/**
 * @brief History deconstructor
 */
history::~history()
{
    delete ui;
    for (auto p : petHistory)
    {
      delete p;
    }
    petHistory.clear();
}

/**
 * @brief Close current interface and go to pet owner interface
 */
void history::on_back_clicked()
{
    Petowner *pom = new Petowner();
    pom->show();
    this->close();
}

/**
 * @brief Initiate pet view history interface
 */
void history::initHistoryVector(){
    DataBase db("../../cuddlySys/sysDB.db");
    int maxHistory = db.getMaxHistoryID();
    //iterate thru all historyID's
    for (int i = 1; i <= maxHistory; i++) {
        if (db.isHistoryValid(i, currUser->getUid())){
            PetManager *tmpPet = db.setPet(db.getHistoryPetID(i));
            petHistory.push_back(tmpPet);
        }
    }
    //displaying history from latest to oldest by default
    std::reverse(petHistory.begin(), petHistory.end());
}

/**
 * @brief Display user pet view history.
 * Displays three pets per page.
 */
void history::displayCurrPage(){
    QPixmap pawImg("../../cuddlySys/paw.jpg");  //default image
    int idx = currPtr;
    qDebug() << petHistory.size();
    qDebug() << idx;
    if (idx < petHistory.size()){
        PetManager* tmpPet = petHistory.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
           ui->image1->setPixmap(pawImg);
        } else {
           ui->image1->setPixmap(pm);
        }
        ui->viewprofile_1->setVisible(true);
        ui->image1->setScaledContents(true);
        ui->name1->setText(tmpPet->getPetName());
    } else {
        ui->viewprofile_1->setVisible(false);
        ui->image1->setPixmap(pawImg);
        ui->image1->setScaledContents(true);
        ui->name1->setText("N/A");
    }
    idx += 1;
    if (idx < petHistory.size()){
        PetManager* tmpPet = petHistory.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
           ui->image2->setPixmap(pawImg);
        } else {
           ui->image2->setPixmap(pm);
        }
        ui->viewprofile_2->setVisible(true);
        ui->image2->setScaledContents(true);
        ui->name2->setText(tmpPet->getPetName());
    } else {
        ui->viewprofile_2->setVisible(false);
        ui->image2->setPixmap(pawImg);
        ui->image2->setScaledContents(true);
        ui->name2->setText("N/A");
    }
    idx += 1;
    if (idx < petHistory.size()){
        PetManager* tmpPet = petHistory.at(idx);
        QPixmap pm(tmpPet->getPetImgPath1());
        if (pm.isNull()) {
           ui->image3->setPixmap(pawImg);
        } else {
           ui->image3->setPixmap(pm);
        }
        ui->viewprofile_3->setVisible(true);
        ui->image3->setScaledContents(true);
        ui->name3->setText(tmpPet->getPetName());
    } else {
        ui->viewprofile_3->setVisible(false);
        ui->image3->setPixmap(pawImg);
        ui->image3->setScaledContents(true);
        ui->name3->setText("N/A");
    }
    ui->page->setText("Page " + QString::number(currPage) + " of " + QString::number(totalPages));
}

/**
 * @brief Previous page on pet view history interface
 */
void history::on_prev_clicked()
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
 * @brief Next page on pet view history interface
 */
void history::on_next_clicked()
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
 * @brief Show pet info of first pet on current page
 */
void history::on_viewprofile_1_clicked()
{
    enterFrom = "history";
    currPet = petHistory.at(currPtr);
    petprofile *pp = new petprofile;
    pp->show();
}

/**
 * @brief Show pet info of second pet on current page
 */
void history::on_viewprofile_2_clicked()
{
    enterFrom = "history";
    currPet = petHistory.at(currPtr+1);
    petprofile *pp = new petprofile;
    pp->show();
}

/**
 * @brief Show pet info of third pet on current page
 */
void history::on_viewprofile_3_clicked()
{
    enterFrom = "history";
    currPet = petHistory.at(currPtr+2);
    petprofile *pp = new petprofile;
    pp->show();
}
