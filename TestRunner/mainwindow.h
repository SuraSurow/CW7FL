#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void runSelectedTest();
    void runAllTests();
    void resetSelection();

private:
    QListWidget *testListWidget;
    QPushButton *runButton;
    QPushButton *runAllButton;
    QPushButton *resetButton;
};

#endif // MAINWINDOW_H
