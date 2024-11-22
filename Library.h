//
// Created by recatu on 2024/11/1.
//
//用于存放用户和图书相关的类定义
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include "login.h"
#include "admin.h"
#include <iostream>
#include <fstream>

using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::cout;
using std::cerr;
using std::endl;

#define DIVIDER ' ' //设置分隔符为空格

class BookInfo;		// 图书信息类
class UserInfo;		// 用户类

struct USER_data{
    //用户信息结构
    QString ID;//用户ID
    QString password;//用户密码
    int book_borrow;//用户借阅的图书数量
    int user_type;//用户类型,1为管理员，0为普通用户
};
struct USER_NODE{
    //用户节点结构
    USER_data data;
    USER_NODE *next;
};

// 通用链表节点
template<class T> struct Node {
    T elem;			// 链表元素
    Node<T> *prev;	// 前向指针
    Node<T> *next;	// 后向指针

    friend ostream &operator <<(ostream &output, const Node &node) {// 传入节点，重载输出流
        output << node.elem;
        return output;
    }

    friend ostream &operator <<(ostream &output, const Node *&node) {// 传入节点指针重载输出流
        output << node->elem;
        return output;
    }
};
// 通用链表
template<class T> class List {
public:
    // 初始化链表
    List() {
        head = new Node<T>;
        if (!head) {
            cerr << "内存分配失败.请检查剩余内存是否充足。" << endl;
            exit(1);
        }
        head->elem = T();
        head->prev = head;
        head->next = head;
    }

    ~List() {}
    // 重载下标运算符，便于通过下标访问链表元素
    T &operator [](int idx) {
        Node<T> *p = getNode(idx);
        if (!p) return head->elem;
        return p->elem;
    }
    // 重载输出流，输出链表元素
    friend ostream &operator <<(ostream &output, const List &list) {
        output << '[';//链表开始
        for (Node<T> *p = list.head->next; p != list.head; p = p->next) {
            output << *p;//遍历链表，输出元素
            if (p->next != list.head) output << ", ";
        }
        output << ']';//链表结束
        return output;
    }

    // 获得链表长度
    int size() {
        int ret = 0;
        for (Node<T> *p = head->next; p != head; p = p->next)
            ret++;
        return ret;
    }
    // 判断链表是否为空，空则返回true
    bool isEmpty() {
        return head->next == head;
    }
    // 根据索引值获取节点指针，若获取失败返回空指针
    Node<T>* getNode(int idx) {
        Node<T> *ret = nullptr;
        int len = size();
        if (idx < 0 || idx > len) {
            cerr << "无效的索引值。" << endl;
            return nullptr;
        }
        int i = 1;
        for (Node<T> *p = head->next; p != head; p = p->next, i++) {
            if (i == idx) {
                ret = p;
                break;
            }
        }
        return ret;
    }
    // 在指定节点后插入节点，返回插入的元素的指针，若插入失败返回空指针
    Node<T>* add(T val, Node<T> *pos) {
        Node<T> *item = new Node<T>;
        if (!item) {
            cerr << "内存分配失败.请检查剩余内存是否充足。" << endl;
            return nullptr;
        }
        item->elem		 = val;
        item->next		 = pos->next;
        pos->next		 = item;
        item->next->prev = item;
        item->prev		 = pos;
        return item;
    }

    Node<T>* add(T val, int pos) {
        return add(val, getNode(pos));
    }
    // 在链表末尾插入元素
    Node<T>* append(T val) {
        return add(val, head->prev);
    }
    // 删除指定位置的节点，返回被删除节点后一个节点的指针，若删除失败返回空指针
    Node<T>* del(Node<T> *pos) {
        if (pos == nullptr) {
            return nullptr;
        }
        if (pos == head) {
            cerr << "不能删除链表头元素。" << endl;
            return nullptr;
        }
        pos->prev->next = pos->next;
        pos->next->prev = pos->prev;
        Node<T> *ret = pos->next;
        delete pos;
        return ret;
    }

    Node<T>* del(int pos) {
        return del(getNode(pos));
    }
    // 删除第一个值为val的节点
    Node<T>* delByValue(T val) {
        return del(find(val));
    }
    // 删除末尾元素
    Node<T>* pop() {
        return del(head->prev);
    }
    // 修改链表元素，若修改成功返回改节点指针，若修改失败则返回空指针
    Node<T>* modify(Node<T> *pos, T val) {
        if (pos == nullptr) {
            return nullptr;
        }
        if (pos == head) {
            cerr << "不能修改链表头元素。" << endl;
            return nullptr;
        }
        pos->elem = val;
        return pos;
    }

    Node<T>* modify(int pos, T val) {
        //修改指定位置的元素
        return modify(getNode(pos), val);
    }
    // 查找第一个值为val的节点
    Node<T>* find(T val) {
        for (Node<T> *p = head->next; p != head; p = p->next) {
            if (p->elem == val) return p;
        }
        return nullptr;
    }
    // 清空并重置链表
    int clear() {
        for (Node<T> *p = head->prev->prev; p != head->prev; p = p->prev)
            delete p->next;
        head->prev = head;
        head->next = head;
        return 0;
    }
    // 返回链表第一个节点的指针
    Node<T>* begin() {
        return head->next;
    }
    // 返回链表最后一个节点的后一个元素的指针（即头节点的指针）
    Node<T>* end() {
        return head;
    }

private:
    Node<T> *head;

};

class UserInfo {
public:
    string ID;					    // 用户id
    string password;				// 密码
    int type;						// 用户类型
    List<Node<BookInfo>*> books;	// 已借阅的书籍
    List<string> booksID;

    UserInfo(): type(-1) {}

    UserInfo(string id): ID(id), type(0) {}

    UserInfo(string reader, int _type):
            ID(reader), type(_type) {}

    UserInfo(string reader, string pwd, int _type):
            ID(reader), password(pwd), type(_type) {}

    UserInfo(string reader, int _type, List<string> books):
            ID(reader), type(_type), booksID(books) {}

    UserInfo(string reader, string pwd, int _type, List<string> books):
            ID(reader), password(pwd),type(_type), booksID(books) {}

    ~UserInfo() {}

    friend ostream &operator <<(ostream &output, const UserInfo &reader) {
        output << "{\"" << reader.ID << "\", \"" << reader.password << "\", "
               << ", " << reader.type << ", " << reader.booksID << "}";
        return output;
    }

    friend ostream &operator <<(ostream &output, const UserInfo *&reader) {
        output << "{\"" << reader->ID<< "\", \"" << reader->password << "\", "
               << ", " << reader->type << ", " << reader->booksID << "}";
        return output;
    }

};

class BookInfo {
public:
    string name;					// 书名
    string isbn;					// ISBN
    int quantity;					// 数量
    float price;					// 价格
    List<Node<UserInfo>*> readers;	// 借阅该书的读者
    List<string> readersID;

    BookInfo(): isbn(nullptr), quantity(-1) {}

    BookInfo(string id): isbn(id), quantity(1) {}

    BookInfo(string book,string isbn_num, int num):
            name(book), isbn(isbn_num), quantity(num) {}
    BookInfo(string book, string isbn_num, int num, float price):
            name(book), isbn(isbn_num), quantity(num), price(price) {}
    BookInfo(string book, string isbn_num, int num, List<string> users):
            name(book),isbn(isbn_num), quantity(num), readersID(users) {}

    ~BookInfo() {}

    friend ostream &operator <<(ostream &output, const BookInfo &book) {
        output << "{\"" << book.name << "\", " << book.isbn << ", "
               << book.quantity << ", " << book.readers;
        output << "}";
        return output;
    }

    friend ostream &operator <<(ostream &output, const BookInfo *&book) {
        output << "{\"" << book->name << "\", " << book->isbn << ", "
               << book->quantity << ", " << book->readers << "}";
        return output;
    }

};

class Library {
public:
    List<BookInfo> books;
    List<UserInfo> users;
    const char *bookPath;
    const char *userPath;
    char DIVIDE_CHAR;

    Library() {

        DIVIDE_CHAR =DIVIDER;
    }

    Library(const char *userFile, const char *bookFile) {
        DIVIDE_CHAR = DIVIDER;
        read(userFile, bookFile);
    };

    ~Library() {}
    // 从文件读取数据
    int read(const char *userFile, const char *bookFile) {
        bookPath = bookFile;
        userPath = userFile;
        int userState = userDataReader(userFile);
        int bookState = bookDataReader(bookFile);
        if (userState || bookState) {
            cerr << "未读取到数据。" << endl;
            return 1;
        }
        // 预处理编号数据，添加节点指针到链表中
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            auto readersID = p->elem.readersID;
            for (auto *q = readersID.begin(); q != readersID.end(); q = q->next) {
                p->elem.readers.append(findUser(q->elem));
            }
            readersID.clear();
        }
        for (auto *p = users.begin(); p != users.end(); p = p->next) {
            auto booksID = p->elem.booksID;
            for (auto *q = booksID.begin(); q != booksID.end(); q = q->next) {
                p->elem.books.append(findBookbyISBN(q->elem));
            }
            booksID.clear();
        }
        return 0;
    }
    // 写入文件信息
    int writeBook(const char *bookFile) {
        ofstream output(bookFile);
        if (!output) {
            cerr << "无法写入文件。请检查文件\"" << bookFile << "\"是否被占用。" << endl;
            return 1;
        }
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            output << p->elem.name << DIVIDE_CHAR << p->elem.isbn << DIVIDE_CHAR
                   << p->elem.quantity<< DIVIDE_CHAR << p->elem.price;
            auto readers = p->elem.readers;
            for (auto *q = readers.begin(); q != readers.end(); q = q->next) {
                Node<UserInfo> *user = q->elem;
                output << DIVIDE_CHAR << user->elem.ID;
            }
            output << endl;
        }
        return 0;
    }

    int writeUser(const char *userFile) {
        ofstream output(userFile);
        if (!output) {
            cerr << "无法写入文件。请检查文件\"" << userFile << "\"是否被占用。" << endl;
            return 1;
        }
        for (auto *p = users.begin(); p != users.end(); p = p->next) {
            output << p->elem.ID<< DIVIDE_CHAR << p->elem.password << DIVIDE_CHAR
                   <<  DIVIDE_CHAR << p->elem.type;
            auto books = p->elem.books;
            for (auto *q = books.begin(); q != books.end(); q = q->next) {
                Node<BookInfo> *book = q->elem;
                output << DIVIDE_CHAR << book->elem.isbn;
            }
            output << endl;
        }
        return 0;
    }
    // 按编号查找图书
    Node<BookInfo>* findBookbyISBN(string isbn) {
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            if (p->elem.isbn == isbn) return p;
        }
        return nullptr;
    }
    // 按id查找用户
    Node<UserInfo>* findUser(string id) {
        for (auto *p = users.begin(); p != users.end(); p = p->next) {
            if (p->elem.ID == id) return p;
        }
        return nullptr;
    }
    // 按名称查找图书
    Node<BookInfo>* findBookbyName(string name) {
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            if (p->elem.name == name) return p;
        }
        return nullptr;
    }
    // 按名称查找图书（模糊查找），返回一个链表，存有目标图书的节点指针
    List<Node<BookInfo>*> fuzzyFindBook(string name) {
        List<Node<BookInfo>*> ret;
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            if (p->elem.name.find(name) != string::npos) {
                ret.append(p);
            }
        }
        return ret;
    }

    // 添加图书信息
    Node<BookInfo>* add(BookInfo book) {
        return books.append(book);
    }
    // 添加用户信息
    Node<UserInfo>* add(UserInfo user) {
        return users.append(user);
    }
    // 删除图书节点，force=true 开启强制删除
    Node<BookInfo>* del(Node<BookInfo>* book, bool force = false) {
        if (book == nullptr) {
            cerr << "不存在符合条件的图书。" << endl;
            return nullptr;
        }
        auto readers = book->elem.readers;
        if (!readers.isEmpty()) {
            cerr << "[警告] 现在还有 " << readers.size() << " 名用户未还该书 《"
                 << book->elem.name << "》(" << book->elem.isbn << ")。" << endl;
            if (!force) return nullptr;
        }
        for (auto *p = readers.begin(); p != readers.end(); p = p->next) {
            Node<UserInfo> *user = p->elem;
            // cerr << "[警告] 用户 " << user->elem.name << "(" << user->elem.identifier << ") 未还该书." << endl;
            user->elem.books.delByValue(book);
        }
        return books.del(book);
    }
    // 删除用户节点，force=true 开启强制删除,并强制归还该书
    Node<UserInfo>* del(Node<UserInfo>* user, bool force = false) {
        if (user == nullptr) {
            cerr << "不存在符合条件的用户。" << endl;
            return nullptr;
        }
        auto books = user->elem.books;
        if (!books.isEmpty()) {
            cerr << "[警告] 该用户" << user->elem.ID
                  << "未还图书 " << books.size() << " 本。";
            if (!force) return nullptr;
        }
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            Node<BookInfo> *book = p->elem;
            book->elem.readers.delByValue(user);
        }
        return users.del(user);
    }


    Node<BookInfo>* delBookbyISBN(string isbn, bool force = false) {//删除指定编号的图书
        return del(findBookbyISBN(isbn), force);
    }

    Node<UserInfo>* delUser(string id, bool force = false) {
        return del(findUser(id), force);
    }

    Node<BookInfo>* delBookbyName(string name, bool force = false) {//删除指定名称的图书
        return del(findBookbyName(name), force);
    }

    Node<BookInfo>* modify(Node<BookInfo>* src, BookInfo target) {
        return books.modify(src, target);
    }

    Node<UserInfo>* modify(Node<UserInfo>* src, UserInfo target) {
        return users.modify(src, target);
    }

    Node<BookInfo>* updateBookbyISBN(string isbn, BookInfo target) {
        return books.modify(findBookbyISBN(isbn), target);
    }

    Node<UserInfo>* updateUser(string id, UserInfo target) {
        return users.modify(findUser(id), target);
    }

    Node<BookInfo>* updateBookbyName(string name, BookInfo target) {
        return books.modify(findBookbyName(name), target);
    }

    int borrowBook(Node<UserInfo>* userNode, Node<BookInfo>* bookNode) {
        if (!userNode || !bookNode) {
            cerr << "不存在符合条件的图书或用户。" << endl;
            return 1;
        }
        BookInfo book = bookNode->elem;
        // 判断书是否还有剩余
        int quantity = book.quantity;
        if (quantity <= book.readers.size()) {
            cerr << "[信息] 该书 《" << book.name << "》(" << book.isbn << ") 已经被借完了。" << endl;
            return 1;
        }
        auto retUser = userNode->elem.books.append(bookNode);
        auto retBook = bookNode->elem.readers.append(userNode);
        // cout << retBook->elem->elem << "借了" << retUser->elem->elem << endl;
        if (!retUser || !retBook) return 1;
        return 0;
    }

    int borrowBookbyISBN(string userID,string bookISBN) {
        return borrowBook(findUser(userID), findBookbyISBN(bookISBN));
    }

    int borrowBookbyName(string userName, string bookName) {
        return borrowBook(findUser(userName), findBookbyName(bookName));
    }

    int returnBook(Node<UserInfo>* userNode, Node<BookInfo>* bookNode) {
        if (!userNode || !bookNode) {
            cerr << "不存在符合条件的图书或用户。" << endl;
            return 1;
        }
        auto retUser = userNode->elem.books.delByValue(bookNode);
        auto retBook = bookNode->elem.readers.delByValue(userNode);
        if (!retUser || !retBook) return 1;
        return 0;
    }

    int returnBookbyISBN(string userID, string bookISBN) {
        return returnBook(findUser(userID), findBookbyISBN(bookISBN));
    }

    int returnBookbyName(string userID, string bookName) {
        return returnBook(findUser(userID), findBookbyName(bookName));
    }
    // 判断用户是否为管理员
    bool isAdmin(Node<UserInfo>* user) {
        return user->elem.type == 1;
    }
    // 密码验证，判断是否登录成功
    bool login(string userID, string password) {
        auto result = findUser(userID);
        if (result) {
            return result->elem.password == password;
        } else {
            return false;
        }
    }

protected:
    int bookDataReader(const char *fileName) {
        ifstream input(fileName);
        if (!input) {
            cerr << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。" << endl;
            return 1;
        }
        while (!input.eof()) {
            string line;
            getline(input, line);		// 读入一行
            if (line.empty()) continue;	// 若读到空行则跳过
            line += '\n';

            string buff;		// 临时存储块
            string name;		// 图书的名称
            int cnt = 0;		// 计算由分隔符隔开的块索引号
            string isbn;		// 图书的编号
            int quantity;		// 图书的数量
            float price;		// 图书的价格
            List<string> IDs;		// 借阅图书的用户编号
            // 处理该行数据，按分隔符分隔处理
            for (string::iterator i = line.begin(); i != line.end(); i++) {
                if (*i == DIVIDE_CHAR || *i == '\n') {
                    switch (cnt) {
                        case 0:
                            name = buff;
                            buff.clear(); break;
                        case 1:
                            isbn = buff;
                            buff.clear(); break;
                        case 2:
                            quantity = atoi(buff.data());
                            buff.clear(); break;
                        case 3:
                            price = atof(buff.data());
                            buff.clear(); break;
                        default:
                            string id = buff.data();
                            if (!id.empty()) IDs.append(id);
                            buff.clear(); break;
                    }
                    cnt++;
                } else {
                    buff += *i;
                }
            }

            books.append(BookInfo(name,isbn, quantity, IDs));
        }
        input.close();
        return 0;
    }

    int userDataReader(const char *fileName) {
        ifstream input(fileName);
        if (!input) {
            cerr << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。" << endl;
            return 1;
        }
        while (!input.eof()) {
            string line;
            getline(input, line);		// 读入一行
            if (line.empty()) continue;	// 若读到空行则跳过
            line += '\n';

            string buff;		// 临时存储块
            string ID;		    // 用户的id
            string password;	// 用户的密码
            int cnt = 0;		// 计算由分隔符隔开的块索引号
            int type;		// 用户类型 0：非管理员；1：管理员
            List<string> ISBN;		// 用户借阅的图书编号
            // 处理该行数据，按分隔符分隔处理
            for (string::iterator i = line.begin(); i != line.end(); i++) {
                if (*i == DIVIDE_CHAR || *i == '\n') {
                    switch (cnt) {
                        case 0:
                            ID = buff;
                            buff.clear(); break;
                        case 1:
                            password = buff;
                            buff.clear(); break;
                        case 2:
                            type = atoi(buff.data());
                            buff.clear(); break;
                        default:
                            string isbn = buff;
                            if (!isbn.empty()) ISBN.append(isbn);
                            buff.clear(); break;
                    }
                    cnt++;
                } else {
                    buff += *i;
                }
            }

            users.append(UserInfo(ID, password,type,ISBN));
        }
        input.close();
        return 0;
    }

};

extern Library lib;
extern string login_UserID;
extern bool isLoginAdmin;
#endif //LIBRARY_LIBRARY_H
