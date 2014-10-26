#include "mainwindow.h"


QString step1 = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\"><p>1. Выборочные средние и дисперсии.</p><p>x =%1</p><p>y =%2</p>\
        <p>S<sup>2</sup><sub>x</sub>=%3</p><p>S<sup>2</sup><sub>y</sub>=%4</p>";
QString step2 = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\"><p>2. Расчет статистики Фишера( при уровне значимости %1)</p> <p>Статистика Фишера F = %2</p>\
        <p>Критическое значение статитики Фишера Fкр = %3 </p>";
QString step3Correct = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\">3. Проверка гипотезы о незначимом в статистическом смысле различий выборочных дисперсий.\
        <p>F &lt; Fcr Неравество выполняется, гипотеза потверждена.<\p>";
QString step3Uncorrect = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\">3. Проверка гипотезы о незначимом в статистическом смысле различий выборочных дисперсий.\
        <p>F &lt; Fcr Неравество не выполняется, гипотеза отвергнута.<\p>";
QString step4 = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\"><p>4. Расчет статистики Стьюдента( при уровне значимости %1 ) </p>\
        <p>Статистика Стьюдента t = %2 </p><p>Критическое значение статитики Стьюдента t<sub>кр</sub> = %3</p>";
QString step5Correct = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\"><p>5. Проверка гипотезы о незначимом в статистическом смысле различий выборочных средних.</p>\
        <p> t &lt; t <sub>кр</sub> Неравество выполняется, гопотеза принята.";
QString step5Uncorrect = "<body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400;\
        font-style:normal;\"><p>5. Проверка гипотезы о незначимом в статистическом смысле различий выборочных средних.</p>\
        <p> t &lt; t <sub>кр</sub> Неравество не выполняется, гопотеза отвергунта.";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    reqDialog = new Dialog();
    reportTextEdit = new QTextEdit();
    reportTextEdit->setReadOnly(true);

    enterData = new QAction("Ввести данные", this);
    enterBar = addToolBar("Ввод данных");
    enterBar->addAction(enterData);
    connect(enterData,SIGNAL(triggered()),this,SLOT(enterDataDialog()));
    connect(reqDialog,SIGNAL(accepted()),this,SLOT(check_gypothesys()));
    setCentralWidget(reportTextEdit);
}

void MainWindow::enterDataDialog()
{
    reqDialog->show();

}

void MainWindow::check_gypothesys()
{
    //vector<QString> reportText;


    sample s1 = reqDialog->getParam(1);
    sample s2 = reqDialog->getParam(2);
    double level = reqDialog->getALevel();

    std::vector<double> v1,v2;
    v1 = create_sample(s1.size,s1.expected,s1.deviation,1);
    v2 = create_sample(s2.size,s2.expected,s2.deviation,2);

    double mean_v1 = sample_mean(v1);
    double mean_v2 = sample_mean(v2);

    double g_v1 = sample_variance(v1,mean_v1);
    double g_v2 = sample_variance(v2,mean_v2);

    reportTextEdit->setText(step1.arg(QString::number(mean_v1),QString::number(mean_v2),
                                      QString::number(g_v1),QString::number(g_v2)));
    double F = F_test(g_v1,g_v2);
    double Fcr = F_test_cr(v1.size()-1,v2.size()-1,level);
    reportTextEdit->append(step2.arg(QString::number(level),
                                     QString::number(F),QString::number(Fcr)));
    if(F<Fcr)
    {
        reportTextEdit->append(step3Correct);
        double t = t_test(mean_v1,mean_v2,g_v1,g_v2,v1.size(),v2.size());
        double tcr = t_test_cr(v1.size()+v2.size()-2,level);
        reportTextEdit->append(step4.arg(QString::number(level),QString::number(t),QString::number(tcr)));
        if(t<tcr)
        {
            reportTextEdit->append(step5Correct);
        }else{
            reportTextEdit->append(step5Uncorrect);
        }
    }else{
        reportTextEdit->append(step3Uncorrect);
    }

}


