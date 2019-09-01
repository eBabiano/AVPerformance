/****************************************************************************
** Meta object code from reading C++ file 'BenchmarkingWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "BenchmarkingWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BenchmarkingWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget_t {
    QByteArrayData data[4];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget_t qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget = {
    {
QT_MOC_LITERAL(0, 0, 43),
QT_MOC_LITERAL(1, 44, 10),
QT_MOC_LITERAL(2, 55, 0),
QT_MOC_LITERAL(3, 56, 4)
    },
    "src::view::gui::widgets::BenchmarkingWidget\0"
    "plotSignal\0\0plot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_src__view__gui__widgets__BenchmarkingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void src::view::gui::widgets::BenchmarkingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BenchmarkingWidget *_t = static_cast<BenchmarkingWidget *>(_o);
        switch (_id) {
        case 0: _t->plotSignal(); break;
        case 1: _t->plot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BenchmarkingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BenchmarkingWidget::plotSignal)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject src::view::gui::widgets::BenchmarkingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget.data,
      qt_meta_data_src__view__gui__widgets__BenchmarkingWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *src::view::gui::widgets::BenchmarkingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *src::view::gui::widgets::BenchmarkingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_src__view__gui__widgets__BenchmarkingWidget.stringdata))
        return static_cast<void*>(const_cast< BenchmarkingWidget*>(this));
    if (!strcmp(_clname, "container::Container"))
        return static_cast< container::Container*>(const_cast< BenchmarkingWidget*>(this));
    if (!strcmp(_clname, "util::Observer<model::events::BenchmarkUpdatedEvent>"))
        return static_cast< util::Observer<model::events::BenchmarkUpdatedEvent>*>(const_cast< BenchmarkingWidget*>(this));
    if (!strcmp(_clname, "util::Observer<model::av::events::AVStarted>"))
        return static_cast< util::Observer<model::av::events::AVStarted>*>(const_cast< BenchmarkingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int src::view::gui::widgets::BenchmarkingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void src::view::gui::widgets::BenchmarkingWidget::plotSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
