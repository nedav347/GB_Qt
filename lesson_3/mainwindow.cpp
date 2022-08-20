#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonSave, &QPushButton::clicked, this, &MainWindow::save);
    connect(ui->pushButtonOpen, &QPushButton::clicked, this, &MainWindow::open);
    connect(ui->pushButtonHelp, &QPushButton::clicked, this, &MainWindow::help);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить файл", QDir::current().path(), "Текстовый файл(*.txt)");
    if (filename.length() > 0)
    {
        QFile file(filename);
        if (file.open(QFile::WriteOnly | QFile::NewOnly))
        {
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            file.close();
        }
    }
}

void MainWindow:: open()
{
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::current().path(), "Текстовый файл(*.txt)");
    if (filename.length() > 0)
    {
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
        }
    }

}

void MainWindow::help()
{
   QFile file(":/help");
   if (file.open(QFile::ReadOnly))
   {
       QTextStream stream(&file);
       QMessageBox::about(this, "Справка", stream.readAll());
   }
}
