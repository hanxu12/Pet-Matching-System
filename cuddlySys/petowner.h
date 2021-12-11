/**
* petowner.h
* The header file for pet owner dashboard.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef PETOWNER_H
#define PETOWNER_H
#include "entry.h"
#include <QWidget>
#include "managepet.h"
#include "updateinfopetowner.h"
#include "searchwin.h"
#include "history.h"
#include "adoptions.h"
#include "database.h"

namespace Ui {
class Petowner;
}

class Petowner : public QWidget
{
    Q_OBJECT

public:
    explicit Petowner(QWidget *parent = 0);
    ~Petowner();

private slots:
    void on_po_logout_clicked();    //Logout

    void on_update_info_clicked();  //Open update info window

    void on_find_matches_clicked(); //Open search window

    void on_history_clicked();  //Open history window

    void on_adoptions_clicked();    //Open adoptions window

private:
    Ui::Petowner *ui;
    //std::priority_queue<petStruct> pq;
};

#endif // PETOWNER_H
