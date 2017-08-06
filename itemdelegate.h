#ifndef ITEMDELEGATE_H
#define ITEMDELEGATE_H
#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QStandardItemModel>

class ItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
signals:

public:
    explicit ItemDelegate(QObject *parent = 0);
    ~ItemDelegate();

    //重写重画函数
    void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:

};

#endif // ITEMDELEGATE_H
