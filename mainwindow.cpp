#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>

#include <QMainWindow>
#include <QTextStream>
#include <QtMessageHandler>
//#include "source.cpp"
#include <stack>

//#include "notepad.cpp"



using namespace std;


//BinarySearchTree BST, *root = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    QWidget *widget = new QWidget;
//    setCentralWidget(widget);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_searchStudent_clicked()
//{
//    int regno = ui->searchRegno->text().toInt();
//    int res = search(regno);
//    if(res == 0){
//        QMessageBox *message = new QMessageBox();
//        message->setText("Student not found!");
//        message->show();
//    }
//    else{
//        QTextStream output(stdout);
//        stack<float> Marks = searchMarks(regno);
////        QString Name = QString::fromStdString(node->name);
////        QString fatherName = QString::fromStdString(node->fatherName);
////        QString regno = QString::number(node->regno);
////        QString dsa = QString::number(node->dsaMarks);
////        QString iwp = QString::number(node->iwpMarks);
////        QString networks = QString::number(node->networksMarks);
////        output << Name << Qt::endl;
////        output << fatherName << Qt::endl ;
////        output << regno << Qt::endl;
////        output << dsa << Qt::endl;
////        output << iwp << Qt::endl;
////        output << networks << Qt::endl;

//         stack<string> info = searchStudent(regno);


//         ui->father_name->setText(QString::fromStdString(info.top()));
//         info.pop();
//         ui->student_name->setText(QString::fromStdString(info.top()));
//         info.pop();

//         string Reg = to_string(regno);
//          ui->reg_no->setText(QString::fromStdString(Reg));

//         string dsa = to_string(Marks.top());
//         ui->dsa_marks->setText(QString::fromStdString(dsa));
//         Marks.pop();
//         string iwp = to_string(Marks.top());
//         ui->iwp_marks->setText(QString::fromStdString(iwp));
//        Marks.pop();
//        string net = to_string(Marks.top());
//        ui->networks_marks->setText(QString::fromStdString(net));



////         string inf = "";
////         inf += "\nStudent Name: " + info.top() + "\n";
////         info.pop();
////         inf += "Father's Name: " + info.top() + "\n";

////         string dsaMarks = to_string(Marks.top());
////         Marks.pop();
////         string iwpMarks = to_string(Marks.top());
////         Marks.pop();
////         string networksMarks = to_string(Marks.top());

////         inf += "\nMarks:\nDSA: " + dsaMarks + "\nIWP: " + iwpMarks + "\nNetworks: " + networksMarks;

////        QString label = QString::fromStdString(inf);

//    }
//}


void MainWindow::on_submitStudent_clicked()
{
    string name = ui->studentName->text().toStdString();
    int regno = ui->regno->text().toInt();
    string fatherName = ui->fatherName->text().toStdString();
    float dsaMarks = ui->dsaMarks->text().toFloat();
    float iwpMarks = ui->iwpMarks->text().toFloat();
    float networkMarks = ui->networksMarks->text().toFloat();
    if(student.add(regno, name, fatherName, dsaMarks, iwpMarks, networkMarks) == 1){
        QMessageBox *message = new QMessageBox();
        message->setText("Inserted!");
        message->show();
        ui->studentName->clear();
        ui->regno->clear();
        ui->fatherName->clear();
        ui->dsaMarks->clear();
        ui->iwpMarks->clear();
        ui->networksMarks->clear();
    }


//    if(BST.(name, fatherName, regno, dsaMarks, iwpMarks, networkMarks)){
//        QMessageBox *message = new QMessageBox();
//        message->setText("Student inserted!");
//        message->show();
//        ui->studentName->clear();
//        ui->regno->clear();
//        ui->fatherName->clear();
//        ui->dsaMarks->clear();
//        ui->iwpMarks->clear();
//        ui->networksMarks->clear();
//    }
//    else{
//        QMessageBox *message = new QMessageBox();
//        message->setText("Error occurred!");
//        message->show();
//    }

//    if(root == NULL){
//        BST.insert(root,regno);
//        QMessageBox *message = new QMessageBox();
//        message->setText("Inserted!");
//        message->show();
//    }
//    else{
//        root = BST.insert(root, regno);
//        QMessageBox *message = new QMessageBox();
//        message->setText("Inserted!");
//        message->show();
//    }
}



void MainWindow::on_searchStudent_clicked(){
    int regno = ui->searchRegno->text().toInt();
    int result = student.search(regno);

//    if(result == 1){
//        QMessageBox *message = new QMessageBox();
//        message->setText("it is there!");
//        message->show();
//    }
//    else
//    {
//        QMessageBox *message = new QMessageBox();
//        message->setText("it is not there!");
//        message->show();
//    }
    if(result == 1){
        stack<string> res = student.Search(regno);
        stack<float> res1= student.Search1(regno);

        ui->networks_marks->setText(QString::number(res1.top()));
        res1.pop();
        ui->iwp_marks->setText(QString::number(res1.top()));
        res1.pop();
        ui->dsa_marks->setText(QString::number(res1.top()));
        res1.top();
        ui->reg_no->setText(QString::fromStdString(res.top()));
        res.pop();
        ui->father_name->setText(QString::fromStdString(res.top()));
        res.pop();
        ui->student_name->setText(QString::fromStdString(res.top()));
        res.pop();
    }
    else{
        QMessageBox *msg = new QMessageBox();
        msg->setText("No student found!");
        msg->show();
    }

}


void MainWindow::openNotepad(){
    Notepad = new notepad;
    Notepad->show();
}


void MainWindow::on_notepadButton_clicked()
{
    openNotepad();
}

void MainWindow::on_pushButton_3_clicked()
{

    int regno_edit = ui->regno_edit->text().toInt();
    stack<string> info = student.Search(regno_edit);
    stack<float> marks = student.Search1(regno_edit);

    info.pop();
    ui->fname_edit->setText(QString::fromStdString(info.top()));
    info.pop();
    ui->name_edit->setText(QString::fromStdString(info.top()));
    info.pop();

    ui->networks_edit->setText(QString::number(marks.top()));
    marks.pop();
    ui->iwp_edit->setText(QString::number(marks.top()));
    marks.pop();
    ui->networks_edit->setText(QString::number(marks.top()));
    marks.pop();
}



void MainWindow::on_deleteStudent_clicked()
{
    int regno = ui->searchRegno->text().toInt();
    if(student.del(regno) == 1){
        QMessageBox *msg = new QMessageBox();
        msg->setText("Student Deleted!");
        msg->show();
    }
    else{
        QMessageBox *msg = new QMessageBox();
        msg->setText("Error in deleting student!");
        msg->show();
    }
}

void MainWindow::openCalculator(){
    calculator = new Calculator;
    calculator->show();
}

void MainWindow::on_pushButton_clicked()
{
    openCalculator();
}
