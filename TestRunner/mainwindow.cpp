#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QProcess>
#include <QVBoxLayout>
#include "TestLoader.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      testFileWidget(new QListWidget(this)),
      runButton(new QPushButton("Run Selected Test", this)),
      runAllButton(new QPushButton("Run All Tests", this)),
      resetButton(new QPushButton("Reset", this)),
      testContentWidget(new QTextEdit(this)) {



    // Konfiguracja okna podglądu
    testContentWidget->setReadOnly(true);
    
    testFileWidget->addItems(getFileNames());

    // Layout
    auto *layout = new QVBoxLayout();
    layout->addWidget(testFileWidget);   // Główna lista plików testowych
    layout->addWidget(testContentWidget);
    layout->addWidget(runButton);
    layout->addWidget(runAllButton);
    layout->addWidget(resetButton);

    auto *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Połączenia sygnałów
    connect(testFileWidget, &QListWidget::currentItemChanged, this, &MainWindow::onTestFileSelected);
    //todo dodasz connect dla testContentWidget !!!!!!
    connect(runButton, &QPushButton::clicked, this, &MainWindow::runSelectedTest);
    connect(runAllButton, &QPushButton::clicked, this, &MainWindow::runAllTests);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetSelection);
}

void MainWindow::runSelectedTest() {


}

QStringList MainWindow::getFileNames() {
    auto *testLoader = new TestLoader();
    std::vector<std::string> nameFiles = testLoader->getNameFiles();

    QStringList testFiles;
    for (const auto &fileName : nameFiles) {
        testFiles.append(QString::fromStdString(fileName));
    }
    return testFiles;
    
}


void MainWindow::onTestFileSelected(QListWidgetItem *currentItem) {
    if (!currentItem) {// Wyczyść szczegóły, jeśli nic nie wybrano
        testContentWidget->clear();
        return;
    }

    QString testFileName = currentItem->text();

    auto * testLoader = new TestLoader();
    std::string path = testLoader->getPathByName(testFileName.toStdString());

    QString filePath = QString::fromStdString(path);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file: " + filePath);
        return;
    }

    QTextStream in(&file);
    //testContentWidget->setPlainText(in.readAll());
    file.close();

}
/*
void MainWindow::onTestFileSelected(QListWidgetItem *currentItem) {
    if (!currentItem) {
        testDetailsWidget->clear(); // Wyczyść szczegóły, jeśli nic nie wybrano
        testContentTextEdit->clear();
        return;
    }

    QString testFileName = currentItem->text();
    QString filePath = "Test/Cases/" + testFileName;  // Ścieżka do pliku testowego

    // Wyświetlanie zawartości pliku w QTextEdit
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file: " + filePath);
        return;
    }

    QTextStream in(&file);
    testContentTextEdit->setPlainText(in.readAll());
    file.close();

    // Przykład: Dodawanie szczegółowych testów do testDetailsWidget
    testDetailsWidget->clear();
    testDetailsWidget->addItem("TestCase1");
    testDetailsWidget->addItem("TestCase2");
    testDetailsWidget->addItem("TestCase3");
}
*/



void MainWindow::runAllTests() {
    //todo zrobic poprsotu iteracje wyszuikwania testów a nie odpalanie od nowa
    QProcess::startDetached("./TestRunner");
}

void MainWindow::resetSelection() {
    testFileWidget->clearSelection();
    testContentWidget->clear();
}

MainWindow::~MainWindow() {}

