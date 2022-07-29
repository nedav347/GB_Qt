#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
* Домашнее задание к уроку 1
* курса "Разработка программ с графическим интерфейсом на С++"
* автор Недокунев А.В.
* среда разработки:
* MinGW64
* Qt 6.2.3
* Qt Creator 7.0.0
* CMake
* codepage UTF-8
*/

/*
void (MainWindow::*ArrPtrMethod[3])() = //Массив указателей на методы класса MainWindow для вызова методов инициализации вкладок при их смене
{
    &MainWindow::tab1_init,
    &MainWindow::tab2_init,
    &MainWindow::tab3_init
}; // Нестатическая функция-член требует наличия объекта, для которого вызывается. Так что просто так вызвать не получится, нужен объект или статическая функция.
*/

void MainWindow::tab1_init() // инициализация очистка первой вкладки для задания 1
{
    ui->lineEdit->setText(QString::number(0));
    ui->lineEdit_2->setText(QString::number(0));
    ui->lineEdit_3->setText(QString::number(0));
    ui->pushButton->setEnabled(false);
    ui->label_5->setText("Fill coefficients");
}

void MainWindow::tab2_init() // инициализация очистка второй вкладки для задания 2
{
    ui->tab2_inputA->setText(QString::number(0));
    ui->tab2_inputB->setText(QString::number(0));
    ui->tab2_inputAngle->setText(QString::number(0));
    ui->tab2_btnCalc->setEnabled(false);
    ui->tab2_result->setText("Fill data");
    ui->radioButton->setChecked(true);
}

void MainWindow::tab3_init() // инициализация очистка третьей вкладки для задания 3
{
    ui->tab3_plainTextEdit_1->setPlainText("Text for test for plainTextEdit_1");
    ui->tab3_plainTextEdit_2->setPlainText("Text for test for plainTextEdit_2");
}

void MainWindow::on_tW_task1_currentChanged(int index) // выбор вкладки
{
    if (index == 0)
    {
        tab1_init();
    }
    else if (index == 1)
    {
        tab2_init();
    }
    else
    {
        tab3_init();
    }
} // С тремя вкладками это выглядит еще куда ни шло, но представьте, что их у вас 20. Чтобы такого избежать, можно, например, поместить в массив указатели на методы,и вызывать их по индексу.

/* Задание 1
 * Написать программу, которая будет находить корень квадратного уравнения второй степени,
 * входные данные: a, b, c. Если нахождение корня невозможно,
 * выводить сообщение в поле результата (или выводить результат в виде комплексного числа).
 * Учитывать, что число a может быть равно нулю.
*/

double MainWindow::checkField(double value, bool check)
{
    if (check)
    {
        return value;
    }
    else
    {
        return 0.0;
    }
}

void MainWindow::on_pushButton_clicked() // находим корни/корень уравнения
{
    double X1 = 0.0, X2 = 0.0, D = 0.0; // корни и дискриминант
    QString result = ""; // строка результата для вывода в поле

    if (qFuzzyIsNull(tab1A)) // случай, если первый коэффициент равен 0
    {
        X1 = -tab1C / tab1B; // находим корень
        result = "X = " + QString::number(X1); // формируем результат
    }
    else
    {
        D = tab1B*tab1B - 4*tab1A*tab1C; // дискриминант
        if (D > 0) // больше 0 - два корня
        {
            X1 = (-tab1B + sqrt(D))/(2*tab1A);
            X2 = (-tab1B - sqrt(D))/(2*tab1A);
            result = "X1 = " + QString::number(X1) + "; X2 = " + QString::number(X2);
        }
        else if (qFuzzyIsNull(D)) // равен 0 - один корень
        {
            X1 = -tab1B / (2*tab1A);
            result = "X = " + QString::number(X1);
        }
        else // меньше 0 - нет корней
        {
            result = "NO RESULT";
        }
    }
    ui->label_5->setText(result); // выводим результат
}

void MainWindow::checkFill() // проверка полей ввода для активации кнопки <Calc>
{
    bool ok;
    // получаем коэффициенты из полей ввода
    tab1A = ui->lineEdit->text().toDouble(&ok);
    checkField(tab1A, ok);
    tab1B = ui->lineEdit_2->text().toDouble(&ok);
    checkField(tab1B, ok);
    tab1C = ui->lineEdit_3->text().toDouble(&ok);
    checkField(tab1C, ok);
//Лучше при преобразовании QString к число через методы toDouble, toInt и т.д. проверять успешность преобразования. В этих методах имеется опциональный параметр для данной операции.

    if ((qFuzzyIsNull(tab1A) & qFuzzyIsNull(tab1B)) ||
        (qFuzzyIsNull(tab1A) & qFuzzyIsNull(tab1C)) ||
        (qFuzzyIsNull(tab1C) & qFuzzyIsNull(tab1B)))
    {
        ui->label_5->setText("Please, enter correct data...");
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->label_5->setText("");
        ui->pushButton->setEnabled(true);
    }
}

// проверяем поля ввода для активации кнопки "Calc"
void MainWindow::on_lineEdit_editingFinished()
{
    checkFill();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    checkFill();
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    checkFill();
}


void MainWindow::on_pushButton_2_clicked() // очищаем форму
{
    tab1_init();
}

/* Задание 2
 * Расчет стороны треугольника по двум сторонам и углом между ними.
 * Дополнительно: добавить переключатель из QRadioButton для выбора единиц,
 * в каких указан угол: градусах или радианах.
 */

void MainWindow::on_tab2_btnCalc_clicked() // собственно сам расчет при нажатии на кнопку <Calc>
{
    double tAngle = 0.0, tC = 0.0; // искомая третья сторона

    if (ui->radioButton->isChecked()){ // собственно тот самый переключчатель выбора единиц
        tAngle = qDegreesToRadians(tab1C); // поскольку функция qCos() принимает радианы, а выбраны градусы - конвертируем...
    }
    else
    {
        tAngle = tab1C; // выбраны радианы - их и получаем...
    }

    tC = sqrt(tab1A*tab1A + tab1B*tab1B - 2*tab1A*tab1B*qCos(tAngle)); // находим значение третьей стороны по двум известным и углу между ними...
    ui->tab2_result->setText(QString::number(tC)); // выводим найденное значение
}


void MainWindow::on_tab2_btnClear_clicked() // очищаем форму
{
    tab2_init();
}

void MainWindow::tab2_checkFill() // проверка полей ввода для активации кнопки <Calc>
{
    bool ok;
    // получаем коэффициенты из полей ввода
    tab1A = ui->tab2_inputA->text().toDouble(&ok);
    checkField(tab1A, ok);
    tab1B = ui->tab2_inputB->text().toDouble(&ok);
    checkField(tab1B, ok);
    tab1C = ui->tab2_inputAngle->text().toDouble(&ok);
    checkField(tab1C, ok);
//Лучше при преобразовании QString к число через методы toDouble, toInt и т.д. проверять успешность преобразования. В этих методах имеется опциональный параметр для данной операции.

    if (qFuzzyIsNull(tab1A) || qFuzzyIsNull(tab1B) || qFuzzyIsNull(tab1C))
    {
        ui->tab2_result->setText("Enter correct data...");
        ui->tab2_btnCalc->setEnabled(false);
    }
    else
    {
        ui->tab2_result->setText("");
        ui->tab2_btnCalc->setEnabled(true);
    }
}

// проверяем поля ввода для активации кнопки "Calc"
void MainWindow::on_tab2_inputA_editingFinished()
{
    tab2_checkFill();
}

void MainWindow::on_tab2_inputB_editingFinished()
{
    tab2_checkFill();
}

void MainWindow::on_tab2_inputAngle_editingFinished()
{
    tab2_checkFill();
}


/* Задание 3
 * Создать программу, разместить два виджета QPlainTextEdit.
 * Добавить две кнопки:
 * первая кнопка будет добавлять текст из одного текстового виджета в другой,
 * вторая кнопка - заменять текст в одном виджете на текст в другом виджете.
 * Добавить третью кнопку, которая вставляет в один из текстовый виджет текст произвольного html-кода,
 * например <font color='red'>Hello</font> (используйте метод setHtml(QString) ).
 */

void MainWindow::on_tab3_pB_Move_clicked() // первая кнопка
{
    ui->tab3_plainTextEdit_2->setPlainText(ui->tab3_plainTextEdit_1->toPlainText());
}


void MainWindow::on_tab3_pB_Swap_clicked() // вторая кнопка
{
    QString strTemp;
    strTemp = ui->tab3_plainTextEdit_1->toPlainText();
    ui->tab3_plainTextEdit_1->setPlainText(ui->tab3_plainTextEdit_2->toPlainText());
    ui->tab3_plainTextEdit_2->setPlainText(strTemp);
}


void MainWindow::on_tab3_pB_HTML_clicked() // третья кнопка
{
    ui->tab3_plainTextEdit_1->appendHtml("<font color='red'>Text from html code</font>");
}


void MainWindow::on_tab3_pB_Clear_clicked() // кнопка очистки_инициализации
{
    tab3_init();
}

