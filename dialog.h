#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

struct sample{
    int size;
    double expected;
    double deviation;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    sample getParam(int i);
    double getALevel();
public slots:
    void checkForm();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
