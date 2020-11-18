#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QVBoxLayout>
#include<qlineedit.h>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>


namespace Ui {
class notepad;
}

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::notepad *ui;
    QString currentFile = "";
};

#endif // NOTEPAD_H
