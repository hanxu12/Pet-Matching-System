#include "viewuserprofile.h"
#include "ui_viewuserprofile.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
viewuserprofile::viewuserprofile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewuserprofile)
{
    ui->setupUi(this);
    displayUserProfile();
}

/**
 * @brief Destructor for the class
 */
viewuserprofile::~viewuserprofile()
{
    delete ui;
}

/**
 * @brief Displays the information of the user
 */
void viewuserprofile::displayUserProfile(){
    DataBase db("../../cuddlySys/sysDB.db");

    if (db.getGroupType(viewUserID) == 1) {
        ui->title->setText("Shelter Owner Profile");
    } else if (db.getGroupType(viewUserID) == 2) {
        ui->title->setText("Foster Parent Profile");
    } else if (db.getGroupType(viewUserID) == 3) {
        ui->title->setText("Potential Pet Owner Profile");
    }

    ui->name->setText(db.getUserName(viewUserID));
    ui->bio->setText("Bio: " + db.getUserBio(viewUserID));
    ui->addr->setText("Address: \n" + db.getUserAddr(viewUserID) + ", " + db.getLoc(viewUserID) + ", " + QString::number(db.getZip(viewUserID)));
    ui->contact->setText("Phone: " + db.getPhoneNo(viewUserID));
    ui->gender->setText("Gender: " + db.getGender(viewUserID));
}
