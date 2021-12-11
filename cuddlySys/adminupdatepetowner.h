#ifndef ADMINUPDATEPETOWNER_H
#define ADMINUPDATEPETOWNER_H
#include "database.h"
#include "manageusers.h"
#include <QWidget>

namespace Ui {
class adminUpdatePetOwner;
}


/**
 * @brief The adminUpdatePetOwner class
 * used for the admin to update the preferences of a user
 */
class adminUpdatePetOwner : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief adminUpdatePetOwner
     * default constructor to make an instance
     * @param parent
     */
    explicit adminUpdatePetOwner(QWidget *parent = 0);
    /**
      default destructor to destruct an instance of this class
      */
    ~adminUpdatePetOwner();


private slots:
/**
     * @brief on_back_clicked
     when the button is clicked it takes you back to the manage users page
     */
    void on_back_clicked();

    /**
     * @brief on_PB_update_clicked
     * button to be clicked when the preferences have been updated
     */
    void on_PB_update_clicked();

private:
    /**
     * @brief ui
     * a reference to point to the ui
     */
    Ui::adminUpdatePetOwner *ui;
};

#endif // ADMINUPDATEPETOWNER_H
