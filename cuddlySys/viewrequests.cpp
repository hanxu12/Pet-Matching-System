#include "viewrequests.h"
#include "ui_viewrequests.h"


/**
 * @brief Constructor for the method
 * @param parent
 */
viewrequests::viewrequests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewrequests)
{
    ui->setupUi(this);
    initReqVector();
    currPg = 1;
    displayCurrReq(currPg);
}

/**
 * @brief Destructor for the class
 */
viewrequests::~viewrequests()
{
    delete ui;
}

/**
 * @brief Hanldes back button functionality
 */
void viewrequests::on_back_clicked()
{
    ShelterOwnerMain *som = new ShelterOwnerMain();
    som->show();
    this->close();
}

/**
 * @brief Initializes vector to store all requests
 */
void viewrequests::initReqVector(){
    DataBase db("../../cuddlySys/sysDB.db");
    int maxHistory = db.getMaxHistoryID();

    //store relevant historyID into the vector
    for (int i = maxHistory; i>= 0; i--) {
        if (db.isPendingRequest(i, currUser->getUid())) {
            reqVector.push_back(i);
        }
    }

    totalPgs = reqVector.size();
    qDebug() << totalPgs;
}

/**
 * @brief Displays the current request on the screen
 * @param pgno
 */
void viewrequests::displayCurrReq(int pgno){
    DataBase db("../../cuddlySys/sysDB.db");

    QPixmap pawImg("../../cuddlySys/paw.jpg");
    currPet = db.setPet(db.getHistoryPetID(reqVector.at(pgno-1)));

    QPixmap pm(currPet->getPetImgPath1());

    if (pm.isNull()) {
        ui->image->setPixmap(pawImg);
    } else {
        ui->image->setPixmap(pm);
    }

    ui->image->setScaledContents(true);
    viewUserID = db.getHistoryPID(reqVector.at(pgno-1));
    ui->reqInfo->setText(currPet->getPetName()+ " was requested by " + db.getUserName(viewUserID));
    ui->reqPageNo->setText("Request " + QString::number(currPg) + " of " + QString::number(totalPgs));
}

/**
 * @brief Handles going to the previous page of the requests
 */
void viewrequests::on_prev_clicked()
{
    if (currPg > 1) {
        currPg -= 1;
        qDebug() << currPg;
        displayCurrReq(currPg);
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the first page!"));
    }
}

/**
 * @brief Handles going to the next page of requests
 */
void viewrequests::on_next_clicked()
{
    if (currPg < totalPgs) {
        displayCurrReq(++currPg);
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the last page!"));
    }
}

/**
 * @brief Handles the user requesting to see the pet profile
 */
void viewrequests::on_viewpet_clicked()
{
    viewPetReq *vpr = new viewPetReq;
    vpr->show();
}

/**
 * @brief Handles the user requesting to the see the requestee
 */
void viewrequests::on_viewprofile_clicked()
{
    viewuserprofile *vup = new viewuserprofile;
    vup->show();
}

//1 -> adoption requested, 2-> adoption request rejected, 3->adoption request approved
/**
 * @brief Handles the functionality of accepting the request
 */
void viewrequests::on_accept_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to accept request?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        DataBase db("../../cuddlySys/sysDB.db");
        db.updateHistAdoptionStatus(reqVector.at(currPg-1), 3);
    }
}

/**
 * @brief Handles the functionality of rejecting the request
 */
void viewrequests::on_reject_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to reject request?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        DataBase db("../../cuddlySys/sysDB.db");
        db.updateHistAdoptionStatus(reqVector.at(currPg-1), 2);
    }
}

/**
 * @brief Handles the functionality of pending/delaying the request
 */
void viewrequests::on_pending_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to change back the request to pending?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        DataBase db("../../cuddlySys/sysDB.db");
        db.updateHistAdoptionStatus(reqVector.at(currPg-1), 1);
    }
}
