#include "mainwindow.h"

#include <iostream>
#include <QStack>
#include <stdexcept>
#include "Calculator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    layout = new QGridLayout(centralWidget);

    // Ekran kalkulatora
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet("font-size: 18px;");
    layout->addWidget(display, 0, 0, 1, 4);

    // Przykładowe przyciski
    addButton("7", 1, 0);
    addButton("8", 1, 1);
    addButton("9", 1, 2);
    addButton("/", 1, 3);

    addButton("4", 2, 0);
    addButton("5", 2, 1);
    addButton("6", 2, 2);
    addButton("*", 2, 3);

    addButton("1", 3, 0);
    addButton("2", 3, 1);
    addButton("3", 3, 2);
    addButton("-", 3, 3);

    addButton("0", 4, 0, 1, 2);
    addButton(".", 4, 2);
    addButton("+", 4, 3);

    addButton("AND", 5, 0);
    addButton("OR", 5, 1);
    addButton("XOR", 5, 2);
    addButton("NOT", 5, 3);
    addButton("MOD", 6, 0);

    addButton("C", 6, 1);
    addButton("=", 6, 3, 1, 2);

    setCentralWidget(centralWidget);
    setWindowTitle("Calculator");
    resize(400, 500);
}

MainWindow::~MainWindow() {
    delete display;
    delete layout;
    delete centralWidget;
}

std::string convertButtonNameToSymbol(const std::string &buttonName) {
    // Map button names to their respective symbols
    static const std::unordered_map<std::string, std::string> buttonToSymbol = {
        {"AND", "&"}, {"OR", "|"}, {"XOR", "^"}, {"NOT", "!"},
        {"+", "+"}, {"-", "-"}, {"*", "*"}, {"/", "/"}, {"MOD", "%"},
        {"0", "0"}, {"1", "1"}, {"2", "2"}, {"3", "3"}, {"4", "4"},
        {"5", "5"}, {"6", "6"}, {"7", "7"}, {"8", "8"}, {"9", "9"},
        {".", "."}
    };

    auto it = buttonToSymbol.find(buttonName);
    return it != buttonToSymbol.end() ? it->second : "";
}
void MainWindow::addButton(const QString &text, int row, int col, int rowSpan, int colSpan) {
    auto *button = new QPushButton(text, this);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button->setStyleSheet("font-size: 16px;");
    layout->addWidget(button, row, col, rowSpan, colSpan);

    connect(button, &QPushButton::clicked, this, [this, text]() {
        onButtonClicked(text);
    });
}


void MainWindow::onButtonClicked(const QString &text) {
    if (text == "C") {
        display->clear();
    } else if (text == "=") {
        std::cout << convertButtonNameToSymbol(display->text().toStdString());
        Calculator a = Calculator(convertButtonNameToSymbol(display->text().toStdString()));
        display->clear();
        display->setText(a.result.data());
        // Możesz dodać tutaj logikę obliczeń
    } else {
        display->setText(display->text() + text);
    }
}
