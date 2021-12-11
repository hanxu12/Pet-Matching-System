/**
* petprofile.h
* The header file for viewing and managing pet information.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef PETPROFILE_H
#define PETPROFILE_H
#include <QWidget>
#include "history.h"
#include "header.h"

namespace Ui {
class petprofile;
}

class petprofile : public QWidget
{
    Q_OBJECT

public:
    explicit petprofile(QWidget *parent = 0);
    ~petprofile();

private slots:
    void on_PB_switchImg_clicked(); //On pet profile view, switch image when pressed

    void on_update_clicked();   //Select new preference of pet

    void on_request_clicked();  //Change status of corresponding pet to adoption requested (1)

private:
    Ui::petprofile *ui;
    int imgID;
    void displayCurrPet();  //Display pet profile information and image
    QString adoptionStatus(int petID);  //Display pet adoption status
    QString favorStatus(int petID);
};

#endif // PETPROFILE_H
