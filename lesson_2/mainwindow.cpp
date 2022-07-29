/*
* Домашнее задание к уроку 2
* курса "Разработка программ с графическим интерфейсом на С++"
* автор Недокунев А.В.
* среда разработки:
* MinGW64
* Qt 6.2.3
* Qt Creator 7.0.0
* CMake
* codepage UTF-8
*/

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab2_listView->setModel(&mymodel);
    ui->tab2_listView->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tab3_tableView->setModel(&mymodel1);
    ui->tab3_tableView->setSelectionMode(QAbstractItemView::MultiSelection);

    mymodel.appendRow(new QStandardItem(QIcon("./C++.png"), "C++")); // заполняем listview на вкладке 2
    mymodel.appendRow(new QStandardItem(QIcon("./Pyton.png"), "Pyton"));
    mymodel.appendRow(new QStandardItem(QIcon("./Java.png"), "Java"));
    mymodel.appendRow(new QStandardItem(QIcon("./C#.png"), "C#"));
    mymodel.appendRow(new QStandardItem(QIcon("./PHP.png"), "PHP"));
    mymodel.appendRow(new QStandardItem(QIcon("./JavaScript.png"), "JavaScript"));

    QList<QStandardItem *> tab3_list1; // заполняем таблицу на владке 3
    tab3_list1.append(new QStandardItem("№"));
    tab3_list1.append(new QStandardItem("Имя компьютера"));
    tab3_list1.append(new QStandardItem("IP адрес"));
    tab3_list1.append(new QStandardItem("MAC адрес"));
    mymodel1.appendRow(tab3_list1);
    QList<QStandardItem *> tab3_list2;
    tab3_list2.append(new QStandardItem("10318566"));
    tab3_list2.append(new QStandardItem("АРМ Экономиста 1"));
    tab3_list2.append(new QStandardItem("192.168.6.132"));
    tab3_list2.append(new QStandardItem("a0-b1-c2-d3-c4-00"));
    mymodel1.appendRow(tab3_list2);
    QList<QStandardItem *> tab3_list3;
    tab3_list3.append(new QStandardItem("10318566"));
    tab3_list3.append(new QStandardItem("АРМ Экономиста 2"));
    tab3_list3.append(new QStandardItem("192.168.6.133"));
    tab3_list3.append(new QStandardItem("a0-b1-c2-d3-c4-01"));
    mymodel1.appendRow(tab3_list3);
    QList<QStandardItem *> tab3_list4;
    tab3_list4.append(new QStandardItem("10318566"));
    tab3_list4.append(new QStandardItem("АРМ Экономиста 3"));
    tab3_list4.append(new QStandardItem("192.168.6.134"));
    tab3_list4.append(new QStandardItem("a0-b1-c2-d3-c4-02"));
    mymodel1.appendRow(tab3_list4);
    QList<QStandardItem *> tab3_list5;
    tab3_list5.append(new QStandardItem("10318566"));
    tab3_list5.append(new QStandardItem("АРМ бухгалтера 1"));
    tab3_list5.append(new QStandardItem("192.168.6.135"));
    tab3_list5.append(new QStandardItem("a0-b1-c2-d3-c4-03"));
    mymodel1.appendRow(tab3_list5);
    QList<QStandardItem *> tab3_list6;
    tab3_list6.append(new QStandardItem("10318566"));
    tab3_list6.append(new QStandardItem("АРМ бухгалтера 2"));
    tab3_list6.append(new QStandardItem("192.168.6.136"));
    tab3_list6.append(new QStandardItem("a0-b1-c2-d3-c4-04"));
    mymodel1.appendRow(tab3_list6);
    QList<QStandardItem *> tab3_list7;
    tab3_list7.append(new QStandardItem("10318566"));
    tab3_list7.append(new QStandardItem("АРМ бухгалтера 3"));
    tab3_list7.append(new QStandardItem("192.168.6.137"));
    tab3_list7.append(new QStandardItem("a0-b1-c2-d3-c4-05"));
    mymodel1.appendRow(tab3_list7);
    QList<QStandardItem *> tab3_list8;
    tab3_list8.append(new QStandardItem("10318566"));
    tab3_list8.append(new QStandardItem("АРМ бухгалтера 4"));
    tab3_list8.append(new QStandardItem("192.168.6.138"));
    tab3_list8.append(new QStandardItem("a0-b1-c2-d3-c4-06"));
    mymodel1.appendRow(tab3_list8);
    QList<QStandardItem *> tab3_list9;
    tab3_list9.append(new QStandardItem("10318566"));
    tab3_list9.append(new QStandardItem("АРМ бухгалтера 5"));
    tab3_list9.append(new QStandardItem("192.168.6.139"));
    tab3_list9.append(new QStandardItem("a0-b1-c2-d3-c4-07"));
    mymodel1.appendRow(tab3_list9);
    QList<QStandardItem *> tab3_list10;
    tab3_list10.append(new QStandardItem("10318566"));
    tab3_list10.append(new QStandardItem("АРМ Секретаря"));
    tab3_list10.append(new QStandardItem("192.168.6.140"));
    tab3_list10.append(new QStandardItem("a0-b1-c2-d3-c4-08"));
    mymodel1.appendRow(tab3_list10);
    QList<QStandardItem *> tab3_list11;
    tab3_list11.append(new QStandardItem("10318566"));
    tab3_list11.append(new QStandardItem("АРМ заместителя"));
    tab3_list11.append(new QStandardItem("192.168.6.141"));
    tab3_list11.append(new QStandardItem("a0-b1-c2-d3-c4-09"));
    mymodel1.appendRow(tab3_list11);
    QList<QStandardItem *> tab3_list12;
    tab3_list12.append(new QStandardItem("10318566"));
    tab3_list12.append(new QStandardItem("АРМ начальника"));
    tab3_list12.append(new QStandardItem("192.168.6.142"));
    tab3_list12.append(new QStandardItem("a0-b1-c2-d3-c4-10"));
    mymodel1.appendRow(tab3_list12);
    ui->tab3_tableView->resizeColumnToContents(0); // выравниваем колонки по содержимому
    ui->tab3_tableView->resizeColumnToContents(1);
    ui->tab3_tableView->resizeColumnToContents(2);
    ui->tab3_tableView->resizeColumnToContents(3);


    connect(ui->tab1_correctButton, &QPushButton::clicked, this, &MainWindow::tab1_onCorrectButton);
    connect(ui->tab1_clearButton, &QPushButton::clicked, this, &MainWindow::tab1_onClearButton);

    connect(ui->tab2_listView, &QListView::clicked, this, &MainWindow::tab2_onListView);
    connect(ui->tab2_pushButton_UP, &QPushButton::clicked, this, &MainWindow::tab2_onPushButton_UP);
    connect(ui->tab2_pushButton_DOWN, &QPushButton::clicked, this, &MainWindow::tab2_onPushButton_DOWN);
    connect(ui->tab2_pushButton_Del, &QPushButton::clicked, this, &MainWindow::tab2_onPushButton_Del);
    connect(ui->tab2_pushButton_Save, &QPushButton::clicked, this, &MainWindow::tab2_onPushButton_Save);
    connect(ui->tab2_pushButton_NewEdit, &QPushButton::clicked, this, &MainWindow::tab2_onPushButton_NewEdit);
    connect(ui->tab2_checkBox_IconView, &QCheckBox::stateChanged, this, &MainWindow::on_tab2_checkBox_IconView_stateChanged);

    connect(ui->tab3_pushButton_Select, &QPushButton::clicked, this, &MainWindow::tab3_onPushButton_Select);
    connect(ui->tab3_pushButton_ClearSel, &QPushButton::clicked, this, &MainWindow::tab3_onPushButton_ClearSel);

    setWindowTitle("Lesson 2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * 1. Написать класс, который будет вставлять в текст спецсимволы (4–5).
 * Пригодится для символов, для которых нет клавиши на клавиатуре,
 * но они часто используются в тексте:
 * © — знак охраны авторского права,
 * ‰ — промилле, ®,
 * € — евро,
 * ₽ — рубль.
 * Например, ввод рубля в программе #@RUB@, или руб. (автоматически заменить на знак).
*/



InsertSpecials::InsertSpecials(QString inStr)
{
    origStr = inStr;
}

InsertSpecials::~InsertSpecials()
{

}

QString InsertSpecials::FindAndRepace() //(QString origStr)
{
    QString result;
    result = origStr; // здесь надо переделать, а то если будет 100500 замен придется 100500 повторять... (в цикле перебирать из массива/вектора pair/tuple/struct)
    result.replace(strShruggie, charShruggie);
    result.replace(strCopyright, charCopyright);
    result.replace(strPromille, charPromille);
    result.replace(strTrademark, charTrademark);
    result.replace(strEuro, charEuro);
    result.replace(strEuro_long, charEuro);
    result.replace(strRub, charRub);
    result.replace(strRub_short, charRub);
    result.replace(strRub_long, charRub);
    result.replace(strRub_long_singular, charRub);
    result.replace(strRub_long_plural, charRub);
    return result;
}

void MainWindow::tab1_onCorrectButton()
{
    InsertSpecials iS(ui->tab1_plainTextEdit->toPlainText());
    ui->tab1_plainTextEdit->setPlainText(iS.FindAndRepace());
}

void MainWindow::tab1_onClearButton()
{
    ui->tab1_plainTextEdit->setPlainText("");
}

/*
 * 2. Создать список с названиями языков программирования (С++, Python, Java, C#, PHP, JavaScript).
 * Для каждого элемента списка рядом отобразить иконку с логотипом языка программирования.
 * Предусмотреть возможно изменения текста в каждом элементе списка.
 * Добавить возможность перемещения элементов в списке.
 * Создать кнопку для добавления нового языка программирования в список.
 * Иконку для него поставить любую (по-умолчанию).
 * Создать кнопку для удаления элемента из списка (в этом случае элемент должен быть выбран).
 * Создать CheckBox и когда будет стоять галочка, отобразить список в режиме иконок (нужен метод setViewMode()).
 * Когда галочка не стоит, то список должен отображаться в обычном режиме.
*/

void MainWindow::tab2_onListView(const QModelIndex &index)
{
    if (!index.isValid()) return;
//    tab2_ListIndex = index;
    ui->tab2_lineEdit->setText(index.data().toString()); // помещаем текст из выделенного элемента в поле для редактирования
}

void MainWindow::tab2_onPushButton_UP() // перемещаем выделенный элемент на строку вверх
{
    if (!ui->tab2_listView->currentIndex().isValid()) return; // если с выделением что-то не так (индекс текущей строки) ничего не делаем
    if (ui->tab2_listView->currentIndex().row() == 0) return; // если выделена верхняя строка ничего не делаем
    QList<QStandardItem *> list = mymodel.takeRow(ui->tab2_listView->currentIndex().row()); // удаляем выбранную строку без удаления элементов строки и возвращает список указателей на удаленные элементы
    mymodel.insertRow(ui->tab2_listView->currentIndex().row() - 1, list); // вставляем строку на одну выше удаленной (строка, что была выше сдвигается вниз) и заполняем ее элементами удаленной
    QModelIndex idx = mymodel.index(ui->tab2_listView->currentIndex().row() - 2, 0); // текущий индех стал на один больше из-за вставленной строки
    if ( idx.isValid() )
        ui->tab2_listView->setCurrentIndex(idx); // делаем вставленную строку текущей
}

void MainWindow::tab2_onPushButton_DOWN() // перемещаем выделенный элемент на строку вниз
{
    if (!ui->tab2_listView->currentIndex().isValid()) return;
    if (ui->tab2_listView->currentIndex().row() + 1 == mymodel.rowCount()) return;
    QList<QStandardItem *> list = mymodel.takeRow(ui->tab2_listView->currentIndex().row());
    mymodel.insertRow(ui->tab2_listView->currentIndex().row() + 1, list); // из-за удаленной строки строка снизу сдвинулась вверх (на место текущей), поэтому вставляем сразу после текущей
    QModelIndex idx = mymodel.index(ui->tab2_listView->currentIndex().row() + 1, 0);
    if ( idx.isValid())
        ui->tab2_listView->setCurrentIndex(idx);
}

void MainWindow::tab2_onPushButton_Del() // удаляем выделенный элемент
{
    if (!ui->tab2_listView->currentIndex().isValid()) return;
    mymodel.removeRow(ui->tab2_listView->currentIndex().row());
}

void MainWindow::tab2_onPushButton_Save() // сохраняем изменененный текст элемента
{
    mymodel.setData(ui->tab2_listView->currentIndex(), ui->tab2_lineEdit->text(), Qt::EditRole);
}

void MainWindow::tab2_onPushButton_NewEdit() // добавляем новый элемент из поля для редактирования с иконкой по умолчанию
{
    mymodel.appendRow(new QStandardItem(QIcon("./default.png"), ui->tab2_lineEdit->text()));
}

void MainWindow::on_tab2_checkBox_IconView_stateChanged(int arg1) // переключаем режим отображения список / иконки
{
    if (arg1)
    {
        ui->tab2_listView->setViewMode(QListView::IconMode);
    }
    else
    {
        ui->tab2_listView->setViewMode(QListView::ListMode);
    }
}

/*
 * 3. (*) Создать таблицу со столбцами: No, Имя компьютера, IP адрес, MAC адрес. Заполнить таблицу данными.
 * Предусмотреть возможность выбора нескольких строк в таблице (они могут идти не подряд).
 * Для выделенных строк, по нажатию на кнопку покрасить задний фон в другой цвет.
*/

void MainWindow::tab3_onPushButton_Select()
{
    QBrush br;
    switch(ui->tab3_comboBox->currentIndex()) // берем цвет из выпадающего списка
    {
        case 0:
            br = Qt::red;
            break;
        case 1:
            br = Qt::green;
            break;
        case 2:
            br = Qt::blue;
            break;
        case 3:
            br = Qt::cyan;
            break;
        case 4:
            br = Qt::magenta;
            break;
        case 5:
            br = Qt::yellow;
            break;
        case 6:
            br = Qt::gray;
            break;
        default:
            br = Qt::red;
    }

    QModelIndexList idxs = ui->tab3_tableView->selectionModel()->selectedIndexes(); // получаем список индексов выбранных элементов, и да, если в строке выбрано несколько элементов, будем красить строку несколько раз
    for (int i = 0; i < idxs.size(); i++)
    {
        for (int j = 0; j < mymodel1.columnCount(); j++)
        {
            mymodel1.setData(mymodel1.index(idxs.at(i).row(), j), br, Qt::BackgroundRole); // красим элементы во всех колонках строки очередного выделенного элемента
        }
    }
    ui->tab3_tableView->clearSelection(); // не забываем снять выбор со всех элементов
}

void MainWindow:: tab3_onPushButton_ClearSel() // красим все элементы таблицы в дефолтовый цвет
{
    for (int i = 0; i < mymodel1.rowCount(); i++)
    {
        for (int j = 0; j < mymodel1.columnCount(); j++)
        {
            mymodel1.setData(mymodel1.index(i, j), QBrush( Qt::white ), Qt::BackgroundRole);
        }
    }
    ui->tab3_tableView->clearSelection(); // и не забываем снять, на всякий случай, выбор со всех элементов
}
