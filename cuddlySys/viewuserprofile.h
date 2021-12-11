#ifndef VIEWUSERPROFILE_H
#define VIEWUSERPROFILE_H
#include "database.h"
#include "header.h"
#include <QWidget>

namespace Ui {
class viewuserprofile;
}

class viewuserprofile : public QWidget
{
    Q_OBJECT

public:
    explicit viewuserprofile(QWidget *parent = 0);
    ~viewuserprofile();

private:
    Ui::viewuserprofile *ui;
    void displayUserProfile(); // updates the info and displays it
};

#endif // VIEWUSERPROFILE_H
