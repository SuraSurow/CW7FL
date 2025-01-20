#include "mainwindow.h"
#include <QProcess>
#include <QMessageBox>
#include "TestLoader.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    testListWidget(new QListWidget(this)),
    runButton(new QPushButton("Run Selected Test", this)),
    runAllButton(new QPushButton("Run All Tests", this)),
    resetButton(new QPushButton("Reset", this)) {

    auto *testLoader = new TestLoader();

    testLoader->scanNameFiles();
    std::vector<std::string> nameFiles = testLoader->getNameFiles();

    QStringList testFiles;
    for (const auto& fileName : nameFiles) {
        testFiles.append(QString::fromStdString(fileName));
    }

    testListWidget->addItems(testFiles);

    // Layout
    auto *layout = new QVBoxLayout();
    layout->addWidget(testListWidget);
    layout->addWidget(runButton);
    layout->addWidget(runAllButton);
    layout->addWidget(resetButton);

    auto *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Połączenie sygnałów i slotów
    connect(runButton, &QPushButton::clicked, this, &MainWindow::runSelectedTest);
    connect(runAllButton, &QPushButton::clicked, this, &MainWindow::runAllTests);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetSelection);
}

MainWindow::~MainWindow() {}

void MainWindow::runSelectedTest() {

    QListWidgetItem *currentItem = testListWidget->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "Error", "No test selected!");
        return;
    }

    QString testName = currentItem->text();
    QProcess process;
    process.startDetached("./" + testName);  // Zakładamy, że testy są w tym samym katalogu
}

void MainWindow::runAllTests() {
    for (int i = 0; i < testListWidget->count(); ++i) {
        QListWidgetItem *item = testListWidget->item(i);
        QString testName = item->text();
        QProcess process;
        process.startDetached("./" + testName);  // Zakładamy, że testy są w tym samym katalogu
    }
}

void MainWindow::resetSelection() {
    testListWidget->clearSelection();
}
