#ifndef ADMINUPDATESHELTER_H
#define ADMINUPDATESHELTER_H

#include <QWidget>
#include "usermanager.h"
#include "header.h"
#include "manageusers.h"
#include "database.h"

namespace Ui {
/**
 *class for the updating the shelter owner properties as an admn
 */
class adminUpdateShelter;
}

class adminUpdateShelter : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief adminUpdateShelter
     *  default constructor
     * @param parent
     */
    explicit adminUpdateShelter(QWidget *parent = 0);
    /** default destructor
      */
    ~adminUpdateShelter();

private slots:
    /**
     * @brief on_PB_update_clicked
     * button clicked updated the properties of the shelter owner
     *
     */
    void on_PB_update_clicked();
    /**
     * @brief on_back_clicked
     * button clicked takes the user back to the manage users page
     */
    void on_back_clicked();

private:
    /**
     * @brief ui
     * pointer that points to the ui
     */
    Ui::adminUpdateShelter *ui;
};

#endif // ADMINUPDATESHELTER_H
