#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "dialog.h"
#include "func_hyp.h"
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <vector>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    QTextEdit *reportTextEdit;
    Dialog *reqDialog;
    QAction *enterData;
    QToolBar *enterBar;
signals:

public slots:
    void check_gypothesys();
    void enterDataDialog();
};

#endif // MAINWINDOW_H
