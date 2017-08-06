#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QObjectUserData>
#include <QSortFilterProxyModel>
#include "itemdelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onButtonClicked(QAbstractButton *button);
    void on_redBtn_clicked();

    void on_allBtn_clicked();

    void on_blueBtn_clicked();

    void on_yellowBtn_clicked();

    void on_setRedBtn_clicked();

private:
    Ui::MainWindow *ui;
    QButtonGroup *m_filterButtonGroup;
    ItemDelegate *m_delegate;                 //委托
    QSortFilterProxyModel* m_proxyModel;
    QStandardItemModel *m_model;
    int totalNum;
    int redNum;
    int blueNum;
    int yellowNum;

    void initData();
    void updateButtonNum();
};

#endif // MAINWINDOW_H
