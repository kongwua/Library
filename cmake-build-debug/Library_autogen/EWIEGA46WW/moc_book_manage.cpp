/****************************************************************************
** Meta object code from reading C++ file 'book_manage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../book_manage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'book_manage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBook_manageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBook_manageENDCLASS = QtMocHelpers::stringData(
    "Book_manage",
    "on_addBook_btn_clicked",
    "",
    "on_search_btn_clicked",
    "on_book_tableView_clicked",
    "QModelIndex",
    "index",
    "on_book_tableView_doubleClicked",
    "on_bookInfo_btn_clicked",
    "on_borrowBook_btn_clicked",
    "on_returnBook_btn_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBook_manageENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[12];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[26];
    char stringdata5[12];
    char stringdata6[6];
    char stringdata7[32];
    char stringdata8[24];
    char stringdata9[26];
    char stringdata10[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBook_manageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBook_manageENDCLASS_t qt_meta_stringdata_CLASSBook_manageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "Book_manage"
        QT_MOC_LITERAL(12, 22),  // "on_addBook_btn_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 21),  // "on_search_btn_clicked"
        QT_MOC_LITERAL(58, 25),  // "on_book_tableView_clicked"
        QT_MOC_LITERAL(84, 11),  // "QModelIndex"
        QT_MOC_LITERAL(96, 5),  // "index"
        QT_MOC_LITERAL(102, 31),  // "on_book_tableView_doubleClicked"
        QT_MOC_LITERAL(134, 23),  // "on_bookInfo_btn_clicked"
        QT_MOC_LITERAL(158, 25),  // "on_borrowBook_btn_clicked"
        QT_MOC_LITERAL(184, 25)   // "on_returnBook_btn_clicked"
    },
    "Book_manage",
    "on_addBook_btn_clicked",
    "",
    "on_search_btn_clicked",
    "on_book_tableView_clicked",
    "QModelIndex",
    "index",
    "on_book_tableView_doubleClicked",
    "on_bookInfo_btn_clicked",
    "on_borrowBook_btn_clicked",
    "on_returnBook_btn_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBook_manageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    1,   58,    2, 0x0a,    3 /* Public */,
       7,    0,   61,    2, 0x0a,    5 /* Public */,
       8,    0,   62,    2, 0x0a,    6 /* Public */,
       9,    0,   63,    2, 0x0a,    7 /* Public */,
      10,    0,   64,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Book_manage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBook_manageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBook_manageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBook_manageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Book_manage, std::true_type>,
        // method 'on_addBook_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_search_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_book_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_book_tableView_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bookInfo_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_borrowBook_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_returnBook_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Book_manage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Book_manage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addBook_btn_clicked(); break;
        case 1: _t->on_search_btn_clicked(); break;
        case 2: _t->on_book_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->on_book_tableView_doubleClicked(); break;
        case 4: _t->on_bookInfo_btn_clicked(); break;
        case 5: _t->on_borrowBook_btn_clicked(); break;
        case 6: _t->on_returnBook_btn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Book_manage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Book_manage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBook_manageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Book_manage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
