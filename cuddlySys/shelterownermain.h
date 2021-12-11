#ifndef SHELTEROWNERMAIN_H
#define SHELTEROWNERMAIN_H
#include "entry.h"
#include <QWidget>
#include "usermanager.h"
#include "registrationmain.h"
#include "header.h"
#include "database.h"
#include "updateinfoshelter.h"
#include "viewrequests.h"
#include "shelterownerstats.h"

class UserManager;

namespace Ui {
class ShelterOwnerMain;
}

class ShelterOwnerMain : public QWidget
{
    Q_OBJECT

public:
    explicit ShelterOwnerMain(QWidget *parent = 0);
    ~ShelterOwnerMain();

private slots:
    void on_shelter_logout_clicked(); // handles logout functionality

    void on_inventory_clicked(); // opens inventory management page

    void on_update_info_clicked(); // lets user update their info

    void on_requests_clicked(); // shows users the requests

    void on_stats_clicked(); // shows the user's statistics

private:
    Ui::ShelterOwnerMain *ui;
};

#endif // SHELTEROWNERMAIN_H
