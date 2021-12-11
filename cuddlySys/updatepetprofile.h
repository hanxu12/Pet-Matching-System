#ifndef UPDATEPETPROFILE_H
#define UPDATEPETPROFILE_H

#include <QWidget>

namespace Ui {
class updatepetprofile;
}

class updatepetprofile : public QWidget
{
    Q_OBJECT

public:
    explicit updatepetprofile(QWidget *parent = 0);
    ~updatepetprofile();

private:
    Ui::updatepetprofile *ui;
};

#endif // UPDATEPETPROFILE_H
