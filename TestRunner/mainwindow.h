#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private slots:
    void runSelectedTest();
    void onTestFileSelected(QListWidgetItem *currentItem);
    //void onTestDetailSelected(QListWidgetItem *currentItem);
    void runAllTests();
    void resetSelection();
    QStringList getFileNames();

private:
    QListWidget *testFileWidget;        // Lista plików testowych
    QPushButton *runButton;            // Przycisk do uruchamiania wybranego testu
    QPushButton *runAllButton;         // Przycisk do uruchamiania wszystkich testów
    QPushButton *resetButton;          // Przycisk do resetowania zaznaczeń
    QTextEdit *testContentWidget;    // Pole do wyświetlania zawartości pliku testowego
};

#endif // MAINWINDOW_H
