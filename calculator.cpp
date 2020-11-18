#include "calculator.h"
#include "ui_calculator.h"

#include <QPushButton>
// Holds current value of Calculatorulation
double CalculatorVal = 0.0;

// Will define if this was the last math button clicked
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

// Constructor
Calculator::Calculator(QWidget *parent) :

    // Call the QMainWindow constructor
    QMainWindow(parent),

    // Create the UI class and assign it to the ui member
    ui1(new Ui::Calculator)
{

    // Setup the UI
    ui1->setupUi(this);
    // Put 0.0 in Display
    this->setCentralWidget(ui1->CentralWidget);
    ui1->Display->setText(QString::number(CalculatorVal));

    // Will hold references to all the number buttons
    QPushButton *numButtons[10];

    // Cycle through locating the buttons
    for(int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);

        // Get the buttons by name and add to array
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);

        // When the button is released call num_pressed()
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    // Connect signals and slots for math buttons
    connect(ui1->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui1->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui1->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui1->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    // Connect equals button
    connect(ui1->Equals, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));

    // Connect change sign
    connect(ui1->ChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));


}

Calculator::~Calculator()
{
    delete ui1;
}

void Calculator::NumPressed(){

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get number on button
    QString butVal = button->text();

    // Get the value in the display
    QString displayVal = ui1->Display->text();

    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){

        // CalculatorVal = butVal.toDouble();
        ui1->Display->setText(butVal);

    } else {
        // Put the new number to the right of whats there
        QString newVal = displayVal + butVal;

        // Double version of number
        double dblNewVal = newVal.toDouble();

        // CalculatorVal = newVal.toDouble();

        // Set value in display and allow up to 16
        // digits before using exponents
        ui1->Display->setText(QString::number(dblNewVal, 'g', 16));

    }
}

void Calculator::MathButtonPressed(){

    // Cancel out previous math button clicks
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    // Store current value in Display
    QString displayVal = ui1->Display->text();
    CalculatorVal = displayVal.toDouble();

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }

    // Clear display
    ui1->Display->setText("");

}

void Calculator::EqualButtonPressed(){

    // Holds new Calculatorulation
    double solution = 0.0;

    // Get value in display
    QString displayVal = ui1->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || multTrigger || divTrigger ){
        if(addTrigger){
            solution = CalculatorVal + dblDisplayVal;
        } else if(subTrigger){
            solution = CalculatorVal - dblDisplayVal;
        } else if(multTrigger){
            solution = CalculatorVal * dblDisplayVal;
        } else {
            solution = CalculatorVal / dblDisplayVal;
        }
    }

    // Put solution in display
    ui1->Display->setText(QString::number(solution));

}

void Calculator::ChangeNumberSign(){

    // Get the value in the display
    QString displayVal = ui1->Display->text();

    // Regular expression checks if it is a number
    // plus sign
    QRegExp reg("[-+]?[0-9.]*");

    // If it is a number change the sign
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        // Put solution in display
        ui1->Display->setText(QString::number(dblDisplayValSign));
    }

}

void Calculator::on_Clear_clicked()
{
    ui1->Display->setText("");
}
