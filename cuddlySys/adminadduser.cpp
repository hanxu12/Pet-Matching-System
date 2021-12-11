/**
* adminadduser.cpp
* The source file for the admin group to add users.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "adminadduser.h"
#include "ui_adminadduser.h"

/**
 * @brief A default constructor.
 * It construct a new adminAddUser object.
 */
adminAddUser::adminAddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminAddUser)
{
    ui->setupUi(this);
    ui->LE_username->setPlaceholderText("New username");
    ui->LE_password->setPlaceholderText("New password");
    ui->LE_confirmPass->setPlaceholderText("Confirm new password");
    ui->LE_name->setPlaceholderText("New Display Name");
    ui->LE_phoneno->setPlaceholderText("New Contact Info");
    ui->LE_address->setPlaceholderText("New Address");
    ui->LE_zipcode->setPlaceholderText("New zip code");
    ui->LE_bio->setPlaceholderText("New Bio/Description");
    switchVisibility(false);

}

/**
 * @brief A destructor.
 * It destructs an adminAddUser object.
 */      
adminAddUser::~adminAddUser()
{
    delete ui;
}

/**
 * @brief A function
 * It adds a single user to the system when the button is clicked.
 */
void adminAddUser::on_PB_createAcc_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QString username, pass, rePass, phoneNo, Bio, location, accType, gender, name, address;
    int zip;
    int newUID;
    UserManager *tmpUser = new UserManager;
    //obtain personal info
    username = ui->LE_username->text();
    pass = ui->LE_password->text();
    rePass = ui->LE_confirmPass->text();
    name = ui->LE_name->text();
    phoneNo = ui->LE_phoneno->text();
    Bio = ui->LE_bio->text();
    accType = ui->CB_AccType->currentText();
    gender = ui->CB_Gender->currentText();
    location = ui->CB_State->currentText();
    zip = ui->LE_zipcode->text().toInt();
    address = ui->LE_address->text();

    //1. whether the passwords match? (failed register)
    if (QString::compare(pass,rePass,Qt::CaseSensitive) != 0) {  //password not equal
        QMessageBox::information(this, tr("Registration Warning"),
                                 tr("Passwords do not match!"));
    }
    //2. whether the username already exists? (failed register)
    else if (db.exist(username)) {
        QMessageBox::information(this, tr("Registration Warning"),
                                 tr("Username already exists!"));
    } else  //(register)
    {
        tmpUser->setUsername(username);
        tmpUser->setPassword(pass);
        tmpUser->setName(name);
        tmpUser->setBio(Bio);
        tmpUser->setPhoneNo(phoneNo);
        tmpUser->setLocation(location);
        tmpUser->setGender(gender);
        tmpUser->setUserZipCode(zip);
        newUID = db.getMaxUid()+1;
        tmpUser->setUid(newUID);
        tmpUser->setUserAddress(address);
        ui->QL_registerStatus->setText("You may register"); //you may register
        if (accType == "Potential Pet Owner"){
            tmpUser->setUserType(3);
            tmpUser->setUserLocPref(ui->radius->currentText());
            tmpUser->setUserspeciesPref(ui->species->currentText());
            tmpUser->setUserBreedPref(ui->Breed->text());
            tmpUser->setUserColorPref(ui->color->currentText());
            tmpUser->setUserWeightPref(ui->weight->currentText());
            tmpUser->setUserAgePref(ui->age->currentText());
            if (ui->isRescued->checkState()){
                tmpUser->setUserRescuePref(1);
            } else {
                tmpUser->setUserRescuePref(0);
            }
            if (ui->isDiseased->checkState()){
                tmpUser->setUserDiseasePref(1);
            } else {
                tmpUser->setUserDiseasePref(0);
            }
            db.addUser(tmpUser);
            db.insertPerf(tmpUser);
            this->close();
        } else if (accType == "Foster Parent") {
            tmpUser->setUserType(2);
            db.addUser(tmpUser);
            this->close();

        } else if (accType == "Shelter Owner") {
            tmpUser->setUserType(1);
            db.addUser(tmpUser);
            this->close();
        }
        ManageUsers *mu = new ManageUsers;
        mu->show();
    }
}

/**
 * @brief A function
 * It detects the "potential pet owner" selection, then
 * it displays the potential pet owner preference fields
 * @param index the comboBox's index
 */
void adminAddUser::on_CB_AccType_currentIndexChanged(int index)
{
    if (ui->CB_AccType->currentText() == "Potential Pet Owner") {
        switchVisibility(true);
    } else {
        switchVisibility(false);
    }
}

/**
 * @brief A function
 * It switches displays/undisplays the potential pet owner preferences fields 
 * based on the input T/F boolval.
 * @param boolval true (display) or false (hide)
 */
void adminAddUser::switchVisibility(bool boolval) {
    ui->prefLabel->setVisible(boolval);
    ui->radius->setVisible(boolval);
    ui->species->setVisible(boolval);
    ui->Breed->setVisible(boolval);
    ui->color->setVisible(boolval);
    ui->age->setVisible(boolval);
    ui->weight->setVisible(boolval);
    ui->rescue->setVisible(boolval);
    ui->disease->setVisible(boolval);
    ui->isRescued->setVisible(boolval);
    ui->isDiseased->setVisible(boolval);
}

/**
 * @brief A function
 * It returns to the previous interface once "back" button is clicked.
 */
void adminAddUser::on_back_clicked()
{
    ManageUsers *mu = new ManageUsers;
    mu->show();
    this->close();
}
