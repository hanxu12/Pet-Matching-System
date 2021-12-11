#ifndef UPDATEINFOSHELTER_H
#define UPDATEINFOSHELTER_H
#include "usermanager.h"
#include "header.h"
#include <QWidget>
#include "shelterownermain.h"
#include "database.h"

namespace Ui {
class updateinfoshelter;
}

class updateinfoshelter : public QWidget
{
    Q_OBJECT

public:
    explicit updateinfoshelter(QWidget *parent = 0);
    ~updateinfoshelter();

private slots:
    void on_PB_update_clicked(); // updates the information of the user
    void on_back_clicked(); // handles back button functionality

private:
    Ui::updateinfoshelter *ui;
};

#endif // UPDATEINFOSHELTER_H
