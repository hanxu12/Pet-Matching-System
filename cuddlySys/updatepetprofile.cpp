#include "updatepetprofile.h"
#include "ui_updatepetprofile.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
updatepetprofile::updatepetprofile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatepetprofile)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor for the class
 */
updatepetprofile::~updatepetprofile()
{
    delete ui;
}
