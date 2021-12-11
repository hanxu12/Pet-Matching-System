/**
* petownerpref.h
* The header file for updating prefernces.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef PETOWNERPREF_H
#define PETOWNERPREF_H
#include "entry.h"
#include "petowner.h"
#include <QWidget>
#include "header.h"
#include "usermanager.h"

namespace Ui {
class PetownerPref;
}

class PetownerPref : public QWidget
{
    Q_OBJECT


public:
    explicit PetownerPref(QWidget *parent = 0);
    int id;  //id to keep track
    ~PetownerPref();
    //void set_id(int id);

private slots:
    void on_PB_update_clicked();    //Open preference update window and store prefernces

private:
    Ui::PetownerPref *ui;
};

#endif // PETOWNERPREF_H
