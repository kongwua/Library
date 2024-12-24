//
// Created by recatu on 2024/11/1.
//
//用于存放用户和图书相关的类定义
#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include <iostream>
#include <fstream>
#include <Qdebug>
#include <QDate>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <iomanip>

using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::cout;
using std::cerr;
using std::endl;
#define DIVIDER ',' //设置分隔符为逗号

class BookInfo;		// 图书信息类
class UserInfo;		// 用户类

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
            if (p->next != list.head) output << ",";
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
//通用链队列节点
template<class Q> struct QNode {
    Q elem;            // 队列元素
    QNode<Q> *next;
    friend ostream &operator <<(ostream &output, const QNode &qnode) {// 重载输出流
        output << qnode.elem;
        return output;
    }

    friend ostream &operator <<(ostream &output, const QNode *&qnode) {//
        output << qnode->elem;
        return output;
    }
};
//通用链队列
template<class Q> class Queue {
private:
    QNode<Q> *front;//队列头指针
    QNode<Q> *rear;//队列尾指针
public:
    // 初始化队列
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {}
    friend ostream &operator <<(ostream &output, const Queue &queue) {
        output << '[';
        for (QNode<Q> *p = queue.front; p != nullptr; p = p->next) {
            output << *p;
            if (p->next != nullptr) output << ", ";
        }
        output << ']';
        return output;
    }

    friend ostream &operator <<(ostream &output, const Queue *&queue) {
        output << '[';
        for (QNode<Q> *p = queue->front; p != nullptr; p = p->next) {
            output << *p;
            if (p->next != nullptr) output << ", ";
        }
        output << ']';
        return output;
    }
    int size() {
        // 计算队列长度
        if (rear==nullptr||front==nullptr) return 0;
        int count = 0;
        for (QNode<Q> *p = front; p != nullptr; p = p->next)
            count++;
        return count;
    }
    bool isEmpty() {
        // 判断队列是否为空
        return front == nullptr;
    }
    bool enqueue(Q &val) {
        // 入队操作
        QNode<Q> *item = new QNode<Q>;
        if (!item) {
            cerr << "内存分配失败.请检查剩余内存是否充足。" << endl;
            return false;
        }
        item->elem = val;
        item->next = nullptr;
        if (front == nullptr) {
            front = rear = item;
        } else {
            rear->next = item;
            rear = item;
        }
        return true;
    }
    bool dequeue(Q& val) {
        // 出队操作
        if (front == nullptr) {
            cerr << "队列为空。" << endl;
            return false;
        }
        QNode<Q> *item = front;
        val = item->elem;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete item;
        return true;
    }
    QNode<Q>* getFront() {
        // 返回队首元素
        if (front == nullptr) {
            cerr << "队列为空。" << endl;
            return nullptr;
        }
        return front;
    }
    void clear() {
        // 清空队列
        while (front == nullptr) {
            Q temp;
            dequeue(temp);
        }
    }
};



class UserInfo {
public:
    string ID;					    // 用户id
    string password;				// 密码
    int type;						// 用户类型
    double fine=0;					// 罚款
    List<Node<BookInfo>*> books;	// 已借阅的书籍
    List<Node<BookInfo>*> reserveBooks; //预约的书籍
    List<string> booksISBN;//记录借阅的书籍ISBN，存储在文件中


    UserInfo(): ID(""),type(-1),fine(0) {}

    UserInfo(string id): ID(id), type(0) {}

    UserInfo(string reader, int _type):
            ID(reader), type(_type) {}

    UserInfo(string reader, string pwd, int _type,double _fine):
            ID(reader), password(pwd), type(_type),fine(_fine) {}

    UserInfo(string reader, int _type, List<string> booksisbn):
            ID(reader), type(_type), booksISBN(booksisbn) {}
    UserInfo(string reader, string pwd, int _type,double _fine,List<string> booksisbn):
            ID(reader), password(pwd), type(_type),fine(_fine), booksISBN(booksisbn) {}
    //初始化时fine没有初始值，可能会出错
    UserInfo(string reader, string pwd, int _type, List<string> booksisbn):
            ID(reader), password(pwd), type(_type), booksISBN(booksisbn) {}

    ~UserInfo() {}

    friend ostream &operator <<(ostream &output, const UserInfo &reader) {
        output << "{\"" << reader.ID << "\", \"" << reader.password << "\", "
               << ", " << reader.type << ", ";
        {
            output << std::fixed << std::setprecision(2) << reader.fine;
        }
        output<< reader.booksISBN <<"}";
        return output;
    }

    friend ostream &operator <<(ostream &output, const UserInfo *&reader) {
        output << "{\"" << reader->ID << "\", \"" << reader->password << "\", "
               << ", " << reader->type << ", " ;
        {
            output << std::fixed << std::setprecision(2) << reader->fine;
        }
        output<< reader->booksISBN<<"}";
        return output;
    }

};

class BookInfo {
public:
    string name;					// 书名
    string isbn;					// ISBN
    int quantity;					// 数量
    double price;					// 价格
    List<Node<UserInfo>*> readers;	// 借阅该书的读者
    Queue<QNode<UserInfo>*> reserveReaders;    //预约队列,当可借阅书数量为0时启用
    List<string> readersID;//借阅者的id，存储在文件中


    BookInfo(): isbn(), quantity(-1),price(0) {}

    BookInfo(string id): isbn(id), quantity(1) {}

    BookInfo(string book,string isbn_num, int num):
            name(book), isbn(isbn_num), quantity(num) {}
    BookInfo(string book, string isbn_num, int num, double price):
            name(book), isbn(isbn_num), quantity(num), price(price) {}
    BookInfo(string book, string isbn_num, int num,double price, List<string> users):
            name(book),isbn(isbn_num), quantity(num),price(price), readersID(users) {}

    ~BookInfo() {}

    friend ostream &operator <<(ostream &output, const BookInfo &book) {
        output << "{\"" << book.name << "\", " << book.isbn << ", "
               << book.quantity << ", " ;
            {
            output << std::fixed << std::setprecision(2) << book.price;
            }
             output <<   ", " << book.readers
               << ", " << book.reserveReaders;
        output << "}";
        return output;
    }

    friend ostream &operator <<(ostream &output, const BookInfo *&book) {
        output << "{\"" << book->name << "\", " << book->isbn << ", "
               << book->quantity << ", " ;
        {
            output << std::fixed << std::setprecision(2) << book->price;
        }
             output << ", " << book->readers
                    << ", " << book->reserveReaders << "}";
        return output;
    }

};

class ReserveInfo {
    //存储预约信息
public:
    string readerID;
    string bookISBN;
    ReserveInfo(): readerID(""), bookISBN("") {}
    ReserveInfo(string reader, string bookisbn): readerID(reader), bookISBN(bookisbn) {}
    ~ReserveInfo() {}
    friend ostream &operator <<(ostream &output, const ReserveInfo &reserve) {
        output << "{\"" << reserve.readerID << "\", " <<reserve.bookISBN << "}";
        return output;
    }
    friend ostream &operator <<(ostream &output, const ReserveInfo *&reserve) {
        output << "{\"" << reserve->readerID << "\", " <<reserve->bookISBN << "}";
        return output;
    }
    bool operator ==(const ReserveInfo &reserve) const{
        return (this->readerID == reserve.readerID && this->bookISBN == reserve.bookISBN);
    }
};

class RecordInfo{
    //存储借阅信息,用来实现逾期罚款功能
public:
    string readerID;//借阅者id
    string bookISBN;//书籍isbn
    QDate returnTime;//归还时间
    RecordInfo(): readerID(""), bookISBN(""), returnTime() {}
    RecordInfo(string reader, string bookisbn):
            readerID(reader), bookISBN(bookisbn) {}
    RecordInfo(string reader, string bookisbn, QDate returntime):
            readerID(reader), bookISBN(bookisbn), returnTime(returntime) {}
    ~RecordInfo() {}
    friend ostream &operator <<(ostream &output, const RecordInfo &record) {
        output << "{\"" << record.readerID << "\", " << record.bookISBN << "\", " << record.returnTime.toString().toStdString() << "}";
        return output;
    }
    friend ostream &operator <<(ostream &output, const RecordInfo *record) {
        output << "{\"" << record->readerID << "\", " << record->bookISBN << "\", " << record->returnTime.toString().toStdString() << "}";
        return output;
    }

};

class Library {
public:
    List<BookInfo> books;// 图书信息链表
    List<UserInfo> users;// 用户信息链表
    List<ReserveInfo> reserves;//预约信息链表
    List<RecordInfo> records;//借阅信息链表
    QDate currentTime;//当前日期
    int days=30;//借阅期限为30天
    const char *bookPath;//图书信息文件路径
    const char *userPath;//用户信息文件路径
    const char *reservePath;//预约信息文件路径
    const char *recordPath;//借阅信息文件路径
    char DIVIDE_CHAR;//分隔符

    Library() {
        currentTime = QDate::currentDate();
        DIVIDE_CHAR =DIVIDER;//设置分隔符为逗号
    }

    Library(const char *userFile, const char *bookFile,const char *reserveFile,const char *recordFile) {
        DIVIDE_CHAR = DIVIDER;
        read(userFile, bookFile, reserveFile, recordFile);
        currentTime = QDate::currentDate();//初始化当前日期
    };

    ~Library() {}
    // 从文件读取数据
    int read(const char *userFile, const char *bookFile,const char *reserveFile,const char *recordFile) {
        //读取成功返回0，失败返回1
        bookPath = bookFile;
        userPath = userFile;
        reservePath = reserveFile;
        recordPath = recordFile;
        int userState = userDataReader(userFile);
        int bookState = bookDataReader(bookFile);
        int reserveState = reserveDataReader(reserveFile);
        int recordState = recordDataReader(recordFile);

        if (userState || bookState|| reserveState||recordState) {
            cerr << "未读取到数据。" << endl;
            return 1;
        }
        // 预处理编号数据，添加节点指针到链表中
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            // 遍历图书链表，添加节点指针到bookInfo读者链表
            auto readersID = p->elem.readersID;
            for (auto *q = readersID.begin(); q != readersID.end(); q = q->next) {
                p->elem.readers.append(findUser(q->elem));
            }
            readersID.clear();
        }
        for (auto *p = users.begin(); p != users.end(); p = p->next) {
            // 遍历用户链表，添加节点指针到userInfo书籍链表
            auto booksID = p->elem.booksISBN;
            for (auto *q = booksID.begin(); q != booksID.end(); q = q->next) {
                p->elem.books.append(findBookbyISBN(q->elem));
            }
            booksID.clear();
        }
        for(auto *p = reserves.begin(); p!= reserves.end(); p = p->next){
            //遍历预约链表，添加节点指针到reserveInfo读者链表
            auto readerID = p->elem.readerID;
            auto bookISBN = p->elem.bookISBN;
            auto reserveUser = findUser(readerID);
            QNode<UserInfo> *reserveNode = new QNode<UserInfo>;
            reserveNode->elem = reserveUser->elem;//转换为QNode类型
            auto reserveBook = findBookbyISBN(bookISBN);
            if(reserveUser && reserveBook){
                //信息都存在
                reserveUser->elem.reserveBooks.append(reserveBook);
                reserveBook->elem.reserveReaders.enqueue(reserveNode);
            }
        }
        for(auto *p=records.begin();p!=records.end();p=p->next){
            //遍历借阅记录链表，将逾期未归还的记录添加到用户罚款中
            if(p->elem.returnTime<currentTime){
                //逾期
                auto user = findUser(p->elem.readerID);
                auto book = findBookbyISBN(p->elem.bookISBN);
                if(user && book){
                    user->elem.fine += book->elem.price;
                } else{
                    cerr << "借阅记录中读者或书籍不存在。" << endl;
                }
            }
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
            output << p->elem.ID<< DIVIDE_CHAR << p->elem.password
                   <<  DIVIDE_CHAR << p->elem.type<< DIVIDE_CHAR <<p->elem.fine;
            auto books = p->elem.books;
            for (auto *q = books.begin(); q != books.end(); q = q->next) {
                Node<BookInfo> *book = q->elem;
                output << DIVIDE_CHAR << book->elem.isbn;
            }
            output << endl;
        }
        return 0;
    }
    int writeReserve(const char *reserveFile){
        //写入预约信息
        ofstream output(reserveFile);
        if (!output) {
            cerr << "无法写入文件。请检查文件\"" << reserveFile << "\"是否被占用。" << endl;
            return 1;
        }
        for(auto *p = reserves.begin(); p!= reserves.end(); p = p->next){
            output << p->elem.readerID<< DIVIDE_CHAR << p->elem.bookISBN << endl;
        }
        return 0;
    }
    int writeRecord(const char *recordFile){
        //写入借阅信息
        ofstream output(recordFile);
        if (!output) {
            cerr << "无法写入文件。请检查文件\"" << recordFile << "\"是否被占用。" << endl;
            return 1;
        }
        for(auto *p = records.begin(); p!= records.end(); p = p->next){
            output << p->elem.readerID << DIVIDE_CHAR << p->elem.bookISBN << DIVIDE_CHAR << p->elem.returnTime.toString("yyyy-MM-dd").toStdString() << endl;
        }
        return 0;
    }

    // 按编号查找图书
    Node<BookInfo>* findBookbyISBN(string isbn) {
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            //遍历图书链表，直到找到目标图书
            if (p->elem.isbn == isbn) return p;
        }
        return nullptr;
    }
    // 按id查找用户
    Node<UserInfo>* findUser(string id) {
        for (auto *p = users.begin(); p != users.end(); p = p->next) {
            //遍历用户链表，直到找到目标用户
            if (p->elem.ID == id) return p;
        }
        return nullptr;
    }
    // 按名称查找图书
    Node<BookInfo>* findBookbyName(string name) {
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            //遍历图书链表，直到找到目标图书
            if (p->elem.name == name) return p;
        }
        return nullptr;
    }
    //查找借阅记录
    Node<RecordInfo>* findRecord(string readerID, string bookISBN){
        for(auto *p = records.begin(); p!= records.end(); p = p->next){
            //遍历借阅记录链表，直到找到目标记录
            if(p->elem.readerID == readerID && p->elem.bookISBN == bookISBN){
                return p;}
            }
        return nullptr;
    }
    // 按名称查找图书（模糊查找），返回一个链表，存有目标图书的节点指针
    List<Node<BookInfo>*> fuzzyFindBook(string name) {
        List<Node<BookInfo>*> ret;
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            //遍历图书链表，查找名称包含name的图书
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
    // 添加借阅信息
    Node<RecordInfo>* add(RecordInfo record){
        return records.append(record);
    }
    Node<ReserveInfo>* addReserve(ReserveInfo reserve) {
        //增加预约信息，同时更新用户链表和图书链表中的预约信息
        auto book = findBookbyISBN(reserve.bookISBN);
        auto user = findUser(reserve.readerID);
        if(!book || !user) return nullptr;
        if(book->elem.quantity>(book->elem.readers.size()+book->elem.reserveReaders.size())){
            return nullptr;//数量足够，不需要预约
        }
        auto data = new QNode<UserInfo>;
        data->elem = user->elem;
        book->elem.reserveReaders.enqueue(data);//进队
        user->elem.reserveBooks.append(book);
        return reserves.append(reserve);
    }
    Node<ReserveInfo>* delReserve(ReserveInfo reserve){
        //删除预约信息，同时更新用户链表和图书链表中的预约信息
        auto book = findBookbyISBN(reserve.bookISBN);
        auto user = findUser(reserve.readerID);
        if(!book || !user) return nullptr;
        auto data = book->elem.reserveReaders.getFront()->elem;
        if(data->elem.ID!= reserve.readerID) return nullptr;//不是最先的预约者
        QNode<UserInfo> *node;
        book->elem.reserveReaders.dequeue(node);
        user->elem.reserveBooks.delByValue(book);
        reserves.delByValue(reserve);
        Node<ReserveInfo>* p = new Node<ReserveInfo>;
        p->elem = reserve;
        return p;
    }
    // 删除图书节点，force=true 开启强制删除
    Node<BookInfo>* del(Node<BookInfo>* book, bool force = false) {
        if (book == nullptr) {
            cerr << "不存在符合条件的图书。" << endl;
            return nullptr;
        }
        auto readers = book->elem.readers;//获取读者链表
        if (!readers.isEmpty()) {
            cerr << "[警告] 现在还有 " << readers.size() << " 名用户未还该书 《"
                 << book->elem.name << "》(" << book->elem.isbn << ")。" << endl;
            if (!force) return nullptr;
        }
        for (auto *p = readers.begin(); p != readers.end(); p = p->next) {
            //遍历读者链表，删除读者信息
            Node<UserInfo> *user = p->elem;
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
        auto books = user->elem.books;//获取书籍链表
        if (!books.isEmpty()) {
            cerr << "[警告] 该用户" << user->elem.ID
                  << "未还图书 " << books.size() << " 本。";
            if (!force) return nullptr;
        }
        for (auto *p = books.begin(); p != books.end(); p = p->next) {
            //遍历书籍链表，删除书籍信息
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

    Node<RecordInfo>* delRecord(string readerID, string bookISBN){//根据书名和读者id删除借阅记录
       auto p = findRecord(readerID, bookISBN);
       if(p){
           return records.del(p);
       }
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
        //借书函数  成功返回0，失败返回1,预约返回2,逾期返回3
        if (!userNode || !bookNode) {
            cerr << "不存在符合条件的图书或用户。" << endl;
            return 1;
        }
        if(userNode->elem.fine>0) return 3; //用户有罚款,不能借书
        BookInfo book = bookNode->elem;
        // 判断书是否还有剩余
        int quantity = book.quantity;
        if (quantity <= book.readers.size()) {
          // 图书数量不足
                //预约
                addReserve(ReserveInfo(userNode->elem.ID, bookNode->elem.isbn));
                return 2;
        }
        auto retUser = userNode->elem.books.append(bookNode);
        auto retBook = bookNode->elem.readers.append(userNode);
        //添加借阅记录
        auto record=add(RecordInfo(userNode->elem.ID,
                                   bookNode->elem.isbn,currentTime.addDays(days)));
        // cout << retBook->elem->elem << "借了" << retUser->elem->elem << endl;
        if (!retUser || !retBook||!record) return 1;
        return 0;
    }

    int borrowBookByISBN(string userID, string bookISBN) {
        return borrowBook(findUser(userID), findBookbyISBN(bookISBN));
    }

    int borrowBookByName(string userName, string bookName) {
        return borrowBook(findUser(userName), findBookbyName(bookName));
    }

    int returnBook(Node<UserInfo>* userNode, Node<BookInfo>* bookNode) {
        if (!userNode || !bookNode) {
            cerr << "不存在符合条件的图书或用户。" << endl;
            return 1;
        }
        //删除用户信息
        auto retUser = userNode->elem.books.delByValue(bookNode);
        //删除图书信息
        auto retBook = bookNode->elem.readers.delByValue(userNode);
        //删除借阅记录
        auto retRecord= delRecord(userNode->elem.ID,bookNode->elem.isbn);
        if (!retUser || !retBook||!retRecord) return 1;//删除失败

        //还书后，判断是否有预约
        if(bookNode->elem.reserveReaders.size() > 0){
            //有预约，取出最先的预约者
            auto node = bookNode->elem.reserveReaders.getFront();
            auto userid = node->elem->elem.ID;
            //借书
            delReserve(reserves.begin()->elem);//删除预约信息
            //借书
            borrowBookByISBN(userid,bookNode->elem.isbn);
        }
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
            qDebug() << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。";
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
            double price;		// 图书的价格
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

            books.append(BookInfo(name,isbn, quantity, price,IDs));
        }
        input.close();
        return 0;
    }

    int userDataReader(const char *fileName) {
        // 从文件读取用户数据
        ifstream input(fileName);
        if (!input) {
            qDebug() << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。";
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
            double fine;		// 罚款金额
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
                        case 3:
                            fine = atof(buff.data());
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

            users.append(UserInfo(ID, password,type,fine,ISBN));
        }
        input.close();
        return 0;
    }
    int reserveDataReader(const char *fileName) {
        ifstream input(fileName);
        if (!input){
            qDebug() << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。";
            return 1;
        }
        while (!input.eof()) {
            string line;
            getline(input, line);		// 读入一行
            if (line.empty()) continue;	// 若读到空行则跳过
            line += '\n';

            string buff;		// 临时存储块
            string ID;		    // 用户的id
            string bookISBN;	// 预约的图书编号
            int cnt = 0;		// 计算由分隔符隔开的块索引号
            // 处理该行数据，按分隔符分隔处理
            for (string::iterator i = line.begin(); i != line.end(); i++) {
                if (*i == DIVIDE_CHAR || *i == '\n') {
                    switch (cnt) {
                        case 0:
                            ID = buff;
                            buff.clear(); break;
                        default:
                            bookISBN = buff;
                            buff.clear(); break;
                    }
                    cnt++;
                } else {
                    buff += *i;
                }
            }
            reserves.append(ReserveInfo(ID, bookISBN));
        }
        input.close();
        return 0;
    }
    int recordDataReader(const char *fileName) {
        // 从文件读取借阅记录数据
        ifstream input(fileName);
        if (!input) {
            qDebug() << "数据读取失败。请检查文件\"" << fileName << "\"是否存在。";
            return 1;
        }
        while (!input.eof()) {
            string line;
            getline(input, line);		// 读入一行
            if (line.empty()) continue;	// 若读到空行则跳过
            line += '\n';

            string buff;		// 临时存储块
            string ID;		    // 用户的id
            string bookISBN;	// 借阅的图书编号
            string time;		// 归还时间
            int cnt = 0;		// 计算由分隔符隔开的块索引号
            // 处理该行数据，按分隔符分隔处理
            for (string::iterator i = line.begin(); i != line.end(); i++) {
                if (*i ==DIVIDE_CHAR  || *i == '\n') {
                    switch (cnt) {
                        case 0:
                            ID = buff;
                            buff.clear(); break;
                        case 1:
                            bookISBN = buff;
                            buff.clear(); break;
                        default:
                            time = buff;
                            buff.clear(); break;
                    }
                    cnt++;
                } else {
                    buff += *i;
                }
            }
            QString time1= QString::fromStdString(time);//转换为Qstring类型
            QDate date = QDate::fromString(time1, "yyyy-MM-dd");//可能因格式问题导致转换失败
            if(!date.isValid()){
                qDebug() << "日期格式错误，请检查文件\"" << fileName << "\"。";
            }
            records.append(RecordInfo(ID, bookISBN,date));
        }
        input.close();
        return 0;
    }

};

extern Library lib;
extern string login_UserID;
extern bool isAdmin;
#endif //LIBRARY_LIBRARY_H
