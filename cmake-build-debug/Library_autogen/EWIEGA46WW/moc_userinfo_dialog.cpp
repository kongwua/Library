/****************************************************************************
** Meta object code from reading C++ file 'userinfo_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../userinfo_dialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinfo_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS = QtMocHelpers::stringData(
    "userinfo_dialog",
    "buttonBox_accepted",
    "",
    "delete_btn_clicked",
    "changePsw_btn_clicked",
    "on_book_tableView_clicked",
    "QModelIndex",
    "index",
    "on_returnBook_btn_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[16];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[22];
    char stringdata5[26];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS_t qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "userinfo_dialog"
        QT_MOC_LITERAL(16, 18),  // "buttonBox_accepted"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 18),  // "delete_btn_clicked"
        QT_MOC_LITERAL(55, 21),  // "changePsw_btn_clicked"
        QT_MOC_LITERAL(77, 25),  // "on_book_tableView_clicked"
        QT_MOC_LITERAL(103, 11),  // "QModelIndex"
        QT_MOC_LITERAL(115, 5),  // "index"
        QT_MOC_LITERAL(121, 25)   // "on_returnBook_btn_clicked"
    },
    "userinfo_dialog",
    "buttonBox_accepted",
    "",
    "delete_btn_clicked",
    "changePsw_btn_clicked",
    "on_book_tableView_clicked",
    "QModelIndex",
    "index",
    "on_returnBook_btn_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSuserinfo_dialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    1,   47,    2, 0x0a,    4 /* Public */,
       8,    0,   50,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject userinfo_dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSuserinfo_dialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<userinfo_dialog, std::true_type>,
        // method 'buttonBox_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delete_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changePsw_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_book_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_returnBook_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void userinfo_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<userinfo_dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buttonBox_accepted(); break;
        case 1: _t->delete_btn_clicked(); break;
        case 2: _t->changePsw_btn_clicked(); break;
        case 3: _t->on_book_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 4: _t->on_returnBook_btn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *userinfo_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userinfo_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSuserinfo_dialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int userinfo_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
