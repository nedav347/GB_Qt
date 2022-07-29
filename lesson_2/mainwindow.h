#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QListView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void tab1_onCorrectButton();
    void tab1_onClearButton();

    void tab2_onListView(const QModelIndex &index);
    void tab2_onPushButton_UP();
    void tab2_onPushButton_DOWN();
    void tab2_onPushButton_Del();
    void tab2_onPushButton_Save();
    void tab2_onPushButton_NewEdit();
    void on_tab2_checkBox_IconView_stateChanged(int arg1);

    void tab3_onPushButton_Select();
    void tab3_onPushButton_ClearSel();

private:
    Ui::MainWindow *ui;
    QStandardItemModel mymodel;
    QStandardItemModel mymodel1;
};
#endif // MAINWINDOW_H

class InsertSpecials
{
public:
    InsertSpecials(QString inStr);
    ~InsertSpecials();
    QString FindAndRepace(); //(QString origStr);
private:
    QString origStr;
    const QString strShruggie = "#@shruggie@";
    const QString charShruggie = QChar(8254) + QString("\\_(") + QChar(12484) + QString(")_/") + QChar(8254);
    const QString strCopyright = "#@COPYRIGHT@";
    const QChar charCopyright = QChar(169);
    const QString strPromille = "#@PROMILLE@";
    const QChar charPromille = QChar(8240);
    const QString strTrademark ="#@TRADEMARK@";
    const QChar charTrademark = QChar(174);
    const QString strEuro = "#@EURO@";
    const QString strEuro_long = "#@евро@";
    const QChar charEuro = QChar(8364);
    const QString strRub = "#@RUB@";
    const QString strRub_short = "#@руб.@";
    const QString strRub_long = "#@рубль@";
    const QString strRub_long_singular = "#@рубля@";
    const QString strRub_long_plural = "#@рублей@";
    const QChar charRub = QChar(8381);
};
