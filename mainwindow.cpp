#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemdelegate.h"
#include "itemdef.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initData();

    m_delegate = new ItemDelegate(this);
    m_filterButtonGroup = new QButtonGroup(this);

    // 设置互斥
    m_filterButtonGroup->setExclusive(true);

    m_filterButtonGroup->addButton(ui->redBtn);
    m_filterButtonGroup->addButton(ui->blueBtn);
    m_filterButtonGroup->addButton(ui->yellowBtn);

    // 连接信号槽
    connect(m_filterButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));

    ui->listView->setItemDelegate(m_delegate);       //为视图设置委托
    ui->listView->setSpacing(15);                   //为视图设置控件间距
    m_proxyModel = new QSortFilterProxyModel(ui->listView);
    m_proxyModel->setSourceModel(m_model);
    m_proxyModel->setFilterRole(Qt::UserRole);
    m_proxyModel->setDynamicSortFilter(true);
    ui->listView->setModel(m_proxyModel);                  //为委托设置模型
    ui->listView->setViewMode(QListView::IconMode); //设置Item图标显示
    ui->listView->setDragEnabled(false);            //控件不允许拖动
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initData()
{
    totalNum = 50;
    redNum = 0;
    blueNum = 0;
    yellowNum = 0;

    m_model = new QStandardItemModel();

    for (int i = 0; i < totalNum; ++i) {
        QStandardItem *Item = new QStandardItem;

        ItemData itemData;

        itemData.name = QString("Name %1").arg(i);
        itemData.tel = QString("TEL:1331234567%1").arg(i);
        int randNum = rand()% 4;
        ItemStatus itemStatus;
        switch (randNum) {
        case 0:
            itemStatus = S_RED;
            redNum++;
            break;
        case 1:
            itemStatus = S_BLUE;
            blueNum++;
            break;
        case 2:
            itemStatus = S_YELLOW;
            yellowNum++;
            break;
        }
        Item->setData(itemStatus,Qt::UserRole);  // 单一存取
        Item->setData(QVariant::fromValue(itemData),Qt::UserRole+1);//整体存取

        m_model->appendRow(Item);      //追加Item
    }
}
