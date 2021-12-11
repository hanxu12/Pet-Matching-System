#ifndef UPDATEINFOPETOWNER_H
#define UPDATEINFOPETOWNER_H
#include "usermanager.h"
#include "database.h"
#include "petowner.h"
#include <QWidget>
#include <QString>

namespace Ui {
class updateinfopetowner;
}

class updateinfopetowner : public QWidget
{
    Q_OBJECT

public:
    explicit updateinfopetowner(QWidget *parent = 0);
    ~updateinfopetowner();

private slots:
    void on_PB_update_clicked(); // updates the profile info of the user
    void on_back_clicked(); // handles back button functionality

private:
    Ui::updateinfopetowner *ui;
};

#endif // UPDATEINFOPETOWNER_H
