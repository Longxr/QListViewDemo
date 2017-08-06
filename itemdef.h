#ifndef ITEMDEF_H
#define ITEMDEF_H

#include <QMetaType>

typedef enum{
    S_RED,
    S_BLUE,
    S_YELLOW,
} ItemStatus;

// 设备信息
struct ItemData{
    QString name;
    QString tel;
};

Q_DECLARE_METATYPE(ItemData)

#endif // ITEMDEF_H
