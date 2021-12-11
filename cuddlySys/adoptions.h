#ifndef ADOPTIONS_H
#define ADOPTIONS_H
#include "petowner.h"
#include "database.h"
#include "petprofile.h"
#include <QWidget>

/**
 *class that shows the adoption history of pet owner
 */
namespace Ui {
class adoptions;
}

class adoptions : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief default constructor makes an instance of the adoptions class
     * @param parent
     */
    explicit adoptions(QWidget *parent = 0);
   /**
     * default destructor
     */
    ~adoptions();

private slots:
    /**
     * @brief on_back_clicked
     * takes you back to the petowner dashboard
     */
    void on_back_clicked();

    /**
     * @brief on_prev_clicked
     * cycle through the pets
     * go back to the previous pet
     */
    void on_prev_clicked();

    /**
     * @brief on_next_clicked
     * cycling through the pet go to the next pet
     */
    void on_next_clicked();

    /**
     * @brief on_viewprofile_1_clicked
     * view the first pet on the page
     */
    void on_viewprofile_1_clicked();

    /**
     * @brief on_viewprofile_2_clicked
     * view the secong pet on the page
     */
    void on_viewprofile_2_clicked();

    /**
     * @brief on_viewprofile_3_clicked
     * view the third pet
     */
    void on_viewprofile_3_clicked();

private:
    /**
     * @brief ui
     * initializtion of  all instances and methods
     */
    Ui::adoptions *ui;
    std::vector<PetManager *> adoptionVector;
    void initAdoptionVector();
    void displayCurrPage();
    int totalPages;
    int currPage;
    int currPtr;
    QString adoptionStatus(int petID);
};

#endif // ADOPTIONS_H
