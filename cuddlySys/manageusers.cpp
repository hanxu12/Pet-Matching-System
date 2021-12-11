/**
* manageuser.cpp
* The source file for managing users.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "manageusers.h"
#include "ui_manageusers.h"

/**
 * @brief ManageUsers constructor
 */
ManageUsers::ManageUsers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);
    currPtr= 0;
    currPage = 1;
    initUserVector();
    if (userVector.size() == 0) {
        totalPage = 1;
    } else {
        totalPage = ceil((userVector.size()/3.0));
    }
    displayCurrPage();
}

/**
 * @brief ManageUsers deconstructor
 */
ManageUsers::~ManageUsers()
{
    delete ui;
}

/**
 * @brief Switch to pet management interface
 */
void ManageUsers::on_pushButton_1_clicked()
{
    ManagePet *mp = new ManagePet();
    mp->show();
    this->close();
}

/**
 * @brief Logout
 */
void ManageUsers::on_pushButton_2_clicked()
{
    entry *newentry = new entry();
    newentry -> show();
    this->close();
}

/**
 * @brief Import entries from selected csv file.
 * Add user to database and log username, password, group, name, gender,
 * bio, phone number, address, state, and zipcode
 */
void ManageUsers::on_addBulk_clicked()
{
    QString filter = "CSV File (*.csv) ;; All File (*.*)";
    QString file_name = QFileDialog::getOpenFileName(this, "open a file", "..", filter);
    QFile f(file_name);
    DataBase db("../../cuddlySys/sysDB.db");
    if (!f.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this, "title", "file not open");
    }
    //QTextStream in(&file);
    //QString text = in.readAll();
    QTextStream ts (&f);
    //Travel through the csv file "excel.csv"
    while(!ts.atEnd()){
        QByteArray line = f.readLine();
        QString tmpStr = QString(line);
        QStringList tmpList = tmpStr.split(QLatin1Char(','));
        //wordList.append(line.split(',').first());
        QString username = QString::fromUtf8(tmpList.at(0).toUtf8());
        if (db.exist(username)) {
            continue;
        }
        QString password = QString::fromUtf8(tmpList.at(1).toUtf8());
        QString userGroup = QString::fromUtf8(tmpList.at(2).toUtf8());
        QString name = QString::fromUtf8(tmpList.at(3).toUtf8());
        QString gender = QString::fromUtf8(tmpList.at(4).toUtf8());
        QString bio = QString::fromUtf8(tmpList.at(5).toUtf8());
        QString phone = QString::fromUtf8(tmpList.at(6).toUtf8());
        QString address = QString::fromUtf8(tmpList.at(7).toUtf8());
        QString state = QString::fromUtf8(tmpList.at(8).toUtf8());
        int zipcode = tmpList.at(9).trimmed().toInt();
        UserManager *tmpUser = new UserManager;
        tmpUser->setUid(db.getMaxUid()+1);
        tmpUser->setUsername(username);
        tmpUser->setPassword(password);
        tmpUser->setName(name);
        tmpUser->setBio(bio);
        tmpUser->setGender(gender);
        tmpUser->setPhoneNo(phone);
        tmpUser->setUserAddress(address);
        tmpUser->setLocation(state);
        tmpUser->setUserZipCode(zipcode);
        if (userGroup.toLower() == "shelter owner"){
            tmpUser->setUserType(1);
            db.addUser(tmpUser);
        } else if (userGroup.toLower() == "foster parent") {
            tmpUser->setUserType(2);
            db.addUser(tmpUser);
        } else if ((userGroup.toLower() == "potential pet owner")) {
            tmpUser->setUserType(3);
            tmpUser->setUserLocPref(QString::fromUtf8(tmpList.at(10).toUtf8()));
            tmpUser->setUserspeciesPref(QString::fromUtf8(tmpList.at(11).toUtf8()));
            tmpUser->setUserBreedPref(QString::fromUtf8(tmpList.at(12).toUtf8()));
            tmpUser->setUserColorPref(QString::fromUtf8(tmpList.at(13).toUtf8()));
            tmpUser->setUserAgePref(QString::fromUtf8(tmpList.at(14).toUtf8()));
            tmpUser->setUserWeightPref(QString::fromUtf8(tmpList.at(15).toUtf8()));
            QString rescue = QString::fromUtf8(tmpList.at(16).toUtf8());
            QString disease = QString::fromUtf8(tmpList.at(17).trimmed().toUtf8());
            if (rescue.toLower() == "yes") {
                tmpUser->setUserRescuePref(1);
            } else {
                tmpUser->setUserRescuePref(0);
            }
            if (disease.toLower() == "yes") {
                tmpUser->setUserDiseasePref(1);
            } else {
                tmpUser->setUserDiseasePref(0);
            }
            db.addUser(tmpUser);
            db.insertPerf(tmpUser);
        }
        delete tmpUser;
    }
    f.close ();
    this->close();
    ManageUsers *mu = new ManageUsers;
    mu->show();
}

/**
 * @brief Initiate user management list interface
 */
void ManageUsers::initUserVector(){
    DataBase db("../../cuddlySys/sysDB.db");
    int max = db.getMaxUid();
    for (int i = 2; i <= max; i++) {
        if (db.userExists(i)) {
            userVector.push_back(i);
        }

    }
    while ((userVector.size() == 0) || !(userVector.size() % 3 == 0)){
        userVector.push_back(-1);
    }
    qDebug() << "userVector size = " << userVector.size();
}

/**
 * @brief Display user group (shelter owner, foster parent, potential pet owner)
 * @param uid
 */
QString ManageUsers::displayUserType(int uid){
    DataBase db("../../cuddlySys/sysDB.db");
    if (db.getGroupType(uid) == 1) {
        return "Shelter Owner";
    } else if (db.getGroupType(uid) == 2) {
        return "Foster Parent";
    } else {
        return "Potential Pet Owner";
    }
}

/**
 * @brief Show users on the page with corresponding information.
 * Displays three users per page.
 */
void ManageUsers::displayCurrPage(){
    ui->checkBox1->setChecked(false);
    ui->checkBox2->setChecked(false);
    ui->checkBox3->setChecked(false);
    DataBase db("../../cuddlySys/sysDB.db");
    QPixmap male("../../cuddlySys/male.jpg");
    QPixmap female("../../cuddlySys/female.jpg");
    QPixmap other("../../cuddlySys/other.jpg");
    QPixmap invalid("../../cuddlySys/invalid.png");
    //idx starts from 1, so ignores admin (uid 1)
    int idx = currPtr;
    if (userVector.at(idx)== -1){
        ui->checkBox1->setVisible(false);
        ui->name1->setText("N/A");
        ui->type1->setText("N/A");
        ui->image1->setPixmap(invalid);
    }
    else {
        ui->checkBox1->setVisible(true);
        int uid = userVector.at(idx);
        if (db.getGender(uid) == "Male") {
            ui->image1->setPixmap(male);
        } else if (db.getGender(uid) == "Female") {
            ui->image1->setPixmap(female);
        } else {
            ui->image1->setPixmap(other);
        }
        ui->image1->setScaledContents(true);
        ui->name1->setText(db.getUserName(uid));
        ui->type1->setText(displayUserType(uid));
    }
    idx += 1;
    if (userVector.at(idx)== -1){
        ui->checkBox2->setVisible(false);
        ui->name2->setText("N/A");
        ui->type2->setText("N/A");
        ui->image2->setPixmap(invalid);
    }
    else {
        ui->checkBox2->setVisible(true);
        int uid = userVector.at(idx);
        if (db.getGender(uid) == "Male") {
            ui->image2->setPixmap(male);
        } else if (db.getGender(uid) == "Female") {
            ui->image2->setPixmap(female);
        } else {
            ui->image2->setPixmap(other);
        }
        ui->image2->setScaledContents(true);
        ui->name2->setText(db.getUserName(uid));
        ui->type2->setText(displayUserType(uid));
    }
    idx += 1;
    if (userVector.at(idx)== -1){
        ui->checkBox3->setVisible(false);
        ui->name3->setText("N/A");
        ui->type3->setText("N/A");
        ui->image3->setPixmap(invalid);
    }
    else {
        ui->checkBox3->setVisible(true);
        int uid = userVector.at(idx);
        if (db.getGender(uid) == "Male") {
            ui->image3->setPixmap(male);
        } else if (db.getGender(uid) == "Female") {
            ui->image3->setPixmap(female);
        } else {
            ui->image3->setPixmap(other);
        }
        ui->image3->setScaledContents(true);
        ui->name3->setText(db.getUserName(uid));
        ui->type3->setText(displayUserType(uid));
    }
    ui->page->setText("Page " + QString::number(currPage) + " of " + QString::number(totalPage));
}

/**
 * @brief Go to previous page of pets on user management interface
 */
void ManageUsers::on_prev_clicked()
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
 * @brief Go to next page of pets on user management interface
 */
void ManageUsers::on_next_clicked()
{
    if (currPage < totalPage) {
        currPage += 1;
        currPtr = currPtr + 3;
        displayCurrPage();
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the last page!"));
    }
}

/**
 * @brief View selected user information
 */
void ManageUsers::on_viewSelect_clicked()
{
    if ((ui->checkBox1->checkState() && ui->checkBox2->checkState()) || (ui->checkBox1->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (!ui->checkBox1->checkState() && !ui->checkBox2->checkState() && !ui->checkBox3->checkState())){
        QMessageBox::information(this, tr("Checkbox Warning"),
                                 tr("You need to check a single checkbox to view userprofile!"));
    } else{
        if (ui->checkBox1->checkState()) {
            viewUserID = userVector.at(currPtr);
        }
        if (ui->checkBox2->checkState()) {
            viewUserID = userVector.at(currPtr+1);
        }
        if (ui->checkBox3->checkState()) {
            viewUserID = userVector.at(currPtr+2);
        }
        viewuserprofile *vup = new viewuserprofile;
        vup->show();
    }
}

/**
 * @brief Remove selected user from system
 */
void ManageUsers::on_removeSelect_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to delete user?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {

        if (ui->checkBox1->checkState()) {
            qDebug() << "deleted ptr" << userVector.at(currPtr);
            db.deleteUser(userVector.at(currPtr));
            userVector.at(currPtr) = -1;
        }
        if (ui->checkBox2->checkState()) {
            qDebug() << "deleted ptr" << userVector.at(currPtr+1);
            db.deleteUser(userVector.at(currPtr+1));
            userVector.at(currPtr+1) = -1;
        }
        if (ui->checkBox3->checkState()) {
            qDebug() << "deleted ptr" << userVector.at(currPtr+2);
            db.deleteUser(userVector.at(currPtr+2));
            userVector.at(currPtr+2) = -1;
        }
        displayCurrPage();
    }
}

/**
 * @brief Add single user to system
 */
void ManageUsers::on_addSingle_clicked()
{
    adminAddUser *aau = new adminAddUser;
    aau->show();
    this->close();
}

/**
 * @brief Update information of selected user
 */
void ManageUsers::on_updateSelect_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    if ((ui->checkBox1->checkState() && ui->checkBox2->checkState()) || (ui->checkBox1->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (!ui->checkBox1->checkState() && !ui->checkBox2->checkState() && !ui->checkBox3->checkState())){
        QMessageBox::information(this, tr("Checkbox Warning"),
                                 tr("You need to check a single checkbox to update user!"));
    } else{
        if (ui->checkBox1->checkState()) {
            viewUserID = userVector.at(currPtr);
        }
        if (ui->checkBox2->checkState()) {
            viewUserID = userVector.at(currPtr+1);
        }
        if (ui->checkBox3->checkState()) {
            viewUserID = userVector.at(currPtr+2);
        }
        if (db.getGroupType(viewUserID) == 1 || db.getGroupType(viewUserID) == 2) {
            //shelter owner/foster parents
            adminUpdateShelter *updateShelter = new adminUpdateShelter;
            updateShelter->show();
            this->hide();
        } else {
            //potential pet owners update profile
            adminUpdatePetOwner *updatePetOwner = new adminUpdatePetOwner;
            updatePetOwner->show();
            this->close();
        }
    }
}
