#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QVBoxLayout>
#include<qlineedit.h>
#include<QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

#include "notepad.h"
#include "source2.cpp"
#include "calculator.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Student student;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submitStudent_clicked();

    void on_searchStudent_clicked();

    void on_notepadButton_clicked();

    void on_pushButton_3_clicked();

    void on_deleteStudent_clicked();

    void on_pushButton_clicked();

private:
    notepad *Notepad;
    Calculator *calculator;

private:
    Ui::MainWindow *ui;
    QString currentFile = "";

public slots:
    void openNotepad();
    void openCalculator();

};
#endif // MAINWINDOW_H
