#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit *display;
    QWidget *centralWidget;
    QGridLayout *layout;

    void addButton(const QString &text, int row, int col, int rowSpan = 1, int colSpan = 1);
    void onButtonClicked(const QString &text);
    int performLogicalOperation(const QString &operation, int lhs, int rhs);
};

#endif // MAINWINDOW_H
